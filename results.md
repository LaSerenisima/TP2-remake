// ============================================================================
// NodeMCU-32S / ESP32 + MPU6050 + 2 flexores SpectraSymbol 0225
// RECONOCIMIENTO LOCAL DE 8 GESTOS - VERSION AJUSTADA CON CALIBRACION
//
// Bluetooth permanece DESACTIVADO. Los resultados salen solamente por USB
// (Monitor Serie a 115200 baudios).
//
// PINES:
//   Flexor F1 (indice): GPIO36 / ADC1_CH0
//   Flexor F2 (pulgar): GPIO39 / ADC1_CH3
//   MPU6050 SDA: GPIO21
//   MPU6050 SCL: GPIO22
//   GPIO16: se conserva como OUTPUT HIGH, igual que el firmware anterior.
//
// CAMBIOS PRINCIPALES:
// 1) F1 y F2 tienen calibracion y umbrales INDEPENDIENTES.
// 2) La calibracion mide reposo y flexion real de cada dedo al arrancar.
// 3) Se usa mediana de 3 lecturas + filtro EMA para reducir picos ADC.
// 4) Se corrige el mapeo de inclinaciones segun las pruebas fisicas:
//      adelante/atras = eje que antes se clasificaba como derecha/izquierda
//      derecha/izquierda = eje que antes se clasificaba como atras/adelante
// 5) G8 detecta rotacion alrededor de la direccion de la gravedad (yaw relativo)
//    e invalida el intento si la inclinacion cambia demasiado. Esto evita que
//    una inclinacion lateral rapida se confunda facilmente con G8.
// 6) Confirmacion temporal, histéresis, bloqueo y rearme en posicion neutra.
//
// IMPORTANTE:
// - Al encender, seguir las instrucciones de calibracion del Monitor Serie.
// - Mantener la PCB quieta durante la calibracion del MPU6050.
// - Flexionar SOLO el dedo solicitado en cada etapa de calibracion.
// - Los umbrales se calculan automaticamente a partir de las lecturas reales.
// ============================================================================

#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <math.h>

// ---------------------------- Pines -----------------------------------------
const int FLEX1_PIN = 36;       // F1: indice
const int FLEX2_PIN = 39;       // F2: pulgar
const int I2C_SDA_PIN = 21;
const int I2C_SCL_PIN = 22;
const int OUTPUT_PIN_16 = 16;

Adafruit_MPU6050 mpu;

// ---------------------------- Muestreo --------------------------------------
const uint32_t SAMPLE_INTERVAL_MS = 20;  // 50 Hz
const float ACC_ALPHA = 0.22f;
const float GYRO_ALPHA = 0.30f;
const float FLEX_ALPHA = 0.30f;

float filtAx = 0, filtAy = 0, filtAz = 0;
float filtGx = 0, filtGy = 0, filtGz = 0;
float filtFlex1 = 0, filtFlex2 = 0;
bool mpuFilterReady = false;
bool flexFilterReady = false;

// ---------------------------- Calibracion MPU -------------------------------
const int MPU_CAL_SAMPLES = 100;  // aprox. 2 s
float gyroBiasX = 0, gyroBiasY = 0, gyroBiasZ = 0;
float neutralPitch = 0, neutralRoll = 0;
float neutralAx = 0, neutralAy = 0, neutralAz = 0;

// ---------------------------- Calibracion flexores --------------------------
// Cada flexor se calibra por separado. La direccion puede ser positiva o
// negativa, por lo que el codigo no presupone que ambos sensores respondan
// con la misma polaridad.
struct FlexCalibration {
  float neutralRaw;
  float bentRaw;
  float direction;
  float onDelta;
  float offDelta;
  bool valid;
  bool usedFallback;
};

FlexCalibration flex1Cal = {};
FlexCalibration flex2Cal = {};
bool indexBent = false;
bool thumbBent = false;

const int FLEX_CAL_SAMPLES = 80;          // 80 x 20 ms = 1.6 s por postura
const float FLEX_MIN_CAL_TRAVEL = 120.0f; // separacion minima entre reposo/flexion
const float FLEX_ON_FRACTION = 0.55f;     // activa al recorrer 55% del recorrido
const float FLEX_OFF_FRACTION = 0.32f;    // libera al volver por debajo del 32%

// Valores de respaldo basados en las mediciones comunicadas por el usuario:
// F1: minimo aprox. 600, maximo aprox. 1250 (picos 1340)
// F2: minimo aprox. 500, maximo aprox. 1550
// Solo se usan si la calibracion guiada no detecta suficiente recorrido.
const float F1_FALLBACK_NEUTRAL = 600.0f;
const float F1_FALLBACK_BENT = 1250.0f;
const float F2_FALLBACK_NEUTRAL = 500.0f;
const float F2_FALLBACK_BENT = 1550.0f;

// ---------------------------- Gestos MPU ------------------------------------
const float TILT_ON_DEG = 23.0f;
const float TILT_OFF_DEG = 11.0f;
const float GYRO_NEUTRAL_DPS = 28.0f;

// G8: rotacion alrededor del vector de gravedad.
// Debe cambiar la orientacion de yaw, pero no inclinar mucho la mano.
const float G8_MAX_GRAVITY_CHANGE_DEG = 12.0f;
const float G8_START_RATE_DPS = 55.0f;
const float G8_MIN_RATE_DPS = 15.0f;
const float G8_REQUIRED_ANGLE_DEG = 32.0f;
const float G8_MIN_PEAK_RATE_DPS = 55.0f;
const uint32_t G8_STOP_GAP_MS = 180;
const uint32_t G8_MAX_DURATION_MS = 1000;

const uint32_t FLEX_CONFIRM_MS = 160;
const uint32_t TILT_CONFIRM_MS = 140;
const uint32_t REARM_NEUTRAL_MS = 400;

// ---------------------------- Diagnostico -----------------------------------
const bool DEBUG_USB = true;
const uint32_t DEBUG_INTERVAL_MS = 250;

// ---------------------------- Identificadores -------------------------------
enum GestureId : uint8_t {
  NO_GESTURE = 0,
  GESTURE_1 = 1,
  GESTURE_2 = 2,
  GESTURE_3 = 3,
  GESTURE_4 = 4,
  GESTURE_5 = 5,
  GESTURE_6 = 6,
  GESTURE_7 = 7,
  GESTURE_8 = 8
};

bool gestureArmed = true;
uint8_t currentCandidate = NO_GESTURE;
uint32_t candidateSince = 0;
uint32_t neutralSince = 0;
uint32_t lastSample = 0;
uint32_t lastDebug = 0;

// Variables del detector de G8.
bool g8Tracking = false;
float g8AccumulatedAngle = 0.0f;
float g8PeakRate = 0.0f;
uint32_t g8StartedAt = 0;
uint32_t g8LastMotionAt = 0;

// ---------------------------- Funciones matematicas -------------------------
float radToDeg(float value) {
  return value * 180.0f / PI;
}

float wrapAngle(float angle) {
  while (angle > 180.0f) angle -= 360.0f;
  while (angle < -180.0f) angle += 360.0f;
  return angle;
}

float calculatePitch(float ax, float ay, float az) {
  return radToDeg(atan2f(ay, sqrtf(ax * ax + az * az)));
}

float calculateRoll(float ax, float az) {
  return radToDeg(atan2f(-ax, az));
}

float vectorMagnitude(float x, float y, float z) {
  return sqrtf(x * x + y * y + z * z);
}

float gravityChangeAngle(float ax, float ay, float az) {
  float currentNorm = vectorMagnitude(ax, ay, az);
  float neutralNorm = vectorMagnitude(neutralAx, neutralAy, neutralAz);
  if (currentNorm < 0.001f || neutralNorm < 0.001f) return 180.0f;

  float dot = (ax * neutralAx + ay * neutralAy + az * neutralAz) /
              (currentNorm * neutralNorm);
  dot = constrain(dot, -1.0f, 1.0f);
  return radToDeg(acosf(dot));
}

// ---------------------------- Lectura filtrada ADC -------------------------
int medianOfThree(int a, int b, int c) {
  if (a > b) { int t = a; a = b; b = t; }
  if (b > c) { int t = b; b = c; c = t; }
  if (a > b) { int t = a; a = b; b = t; }
  return b;
}

int readFlexMedian(int pin) {
  int a = analogRead(pin);
  int b = analogRead(pin);
  int c = analogRead(pin);
  return medianOfThree(a, b, c);
}

void captureFlexPairAverage(float &averageF1, float &averageF2) {
  double sumF1 = 0.0;
  double sumF2 = 0.0;
  for (int i = 0; i < FLEX_CAL_SAMPLES; i++) {
    sumF1 += readFlexMedian(FLEX1_PIN);
    sumF2 += readFlexMedian(FLEX2_PIN);
    delay(SAMPLE_INTERVAL_MS);
  }
  averageF1 = (float)(sumF1 / FLEX_CAL_SAMPLES);
  averageF2 = (float)(sumF2 / FLEX_CAL_SAMPLES);
}

FlexCalibration buildFlexCalibration(float neutralValue, float bentValue,
                                     float fallbackNeutral, float fallbackBent) {
  FlexCalibration result;
  result.neutralRaw = neutralValue;
  result.bentRaw = bentValue;
  result.direction = (bentValue >= neutralValue) ? 1.0f : -1.0f;
  result.valid = true;
  result.usedFallback = false;

  float travel = fabsf(bentValue - neutralValue);
  if (travel < FLEX_MIN_CAL_TRAVEL) {
    result.neutralRaw = fallbackNeutral;
    result.bentRaw = fallbackBent;
    result.direction = (fallbackBent >= fallbackNeutral) ? 1.0f : -1.0f;
    travel = fabsf(fallbackBent - fallbackNeutral);
    result.usedFallback = true;
  }

  result.onDelta = max(65.0f, travel * FLEX_ON_FRACTION);
  result.offDelta = max(35.0f, travel * FLEX_OFF_FRACTION);
  if (result.offDelta >= result.onDelta) {
    result.offDelta = result.onDelta * 0.60f;
  }
  return result;
}

bool updateFlexState(float filteredRaw, const FlexCalibration &cal,
                     bool previousState) {
  float flexTravel = (filteredRaw - cal.neutralRaw) * cal.direction;
  if (!previousState && flexTravel >= cal.onDelta) return true;
  if (previousState && flexTravel <= cal.offDelta) return false;
  return previousState;
}

float flexTravelValue(float filteredRaw, const FlexCalibration &cal) {
  return (filteredRaw - cal.neutralRaw) * cal.direction;
}

// ---------------------------- Inicializacion de sensores -------------------
void calibrateMPU6050() {
  Serial.println();
  Serial.println(F("CALIBRACION MPU6050"));
  Serial.println(F("Mantenga la mano en posicion neutra y la PCB completamente quieta."));

  double sumAx = 0, sumAy = 0, sumAz = 0;
  double sumGx = 0, sumGy = 0, sumGz = 0;

  for (int i = 0; i < MPU_CAL_SAMPLES; i++) {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    sumAx += a.acceleration.x;
    sumAy += a.acceleration.y;
    sumAz += a.acceleration.z;
    sumGx += radToDeg(g.gyro.x);
    sumGy += radToDeg(g.gyro.y);
    sumGz += radToDeg(g.gyro.z);
    delay(SAMPLE_INTERVAL_MS);
  }

  neutralAx = (float)(sumAx / MPU_CAL_SAMPLES);
  neutralAy = (float)(sumAy / MPU_CAL_SAMPLES);
  neutralAz = (float)(sumAz / MPU_CAL_SAMPLES);
  gyroBiasX = (float)(sumGx / MPU_CAL_SAMPLES);
  gyroBiasY = (float)(sumGy / MPU_CAL_SAMPLES);
  gyroBiasZ = (float)(sumGz / MPU_CAL_SAMPLES);

  neutralPitch = calculatePitch(neutralAx, neutralAy, neutralAz);
  neutralRoll = calculateRoll(neutralAx, neutralAz);

  filtAx = neutralAx;
  filtAy = neutralAy;
  filtAz = neutralAz;
  filtGx = filtGy = filtGz = 0.0f;
  mpuFilterReady = true;

  Serial.print(F("Pitch neutro: ")); Serial.println(neutralPitch, 1);
  Serial.print(F("Roll neutro:  ")); Serial.println(neutralRoll, 1);
  Serial.println(F("Calibracion MPU terminada."));
}

void calibrateFlexSensors() {
  Serial.println();
  Serial.println(F("CALIBRACION DE FLEXORES - seguir cada indicacion"));
  Serial.println(F("Paso 1/3: mantenga INDICE y PULGAR COMPLETAMENTE EXTENDIDOS."));
  Serial.println(F("No mueva la mano. Midiendo reposo en 2 segundos..."));
  delay(2000);
  float f1Neutral, f2Neutral;
  captureFlexPairAverage(f1Neutral, f2Neutral);

  Serial.println();
  Serial.println(F("Paso 2/3: FLEXIONE SOLO EL INDICE; mantenga el PULGAR extendido."));
  Serial.println(F("Mantenga la postura. Midiendo en 2 segundos..."));
  delay(2000);
  float f1Bent, f2DuringIndex;
  captureFlexPairAverage(f1Bent, f2DuringIndex);

  Serial.println();
  Serial.println(F("Paso 3/3: vuelva a extender el INDICE y FLEXIONE SOLO EL PULGAR."));
  Serial.println(F("Mantenga la postura. Midiendo en 2 segundos..."));
  delay(2000);
  float f1DuringThumb, f2Bent;
  captureFlexPairAverage(f1DuringThumb, f2Bent);

  flex1Cal = buildFlexCalibration(f1Neutral, f1Bent,
                                  F1_FALLBACK_NEUTRAL, F1_FALLBACK_BENT);
  flex2Cal = buildFlexCalibration(f2Neutral, f2Bent,
                                  F2_FALLBACK_NEUTRAL, F2_FALLBACK_BENT);

  filtFlex1 = f1Neutral;
  filtFlex2 = f2Neutral;
  flexFilterReady = true;
  indexBent = false;
  thumbBent = false;

  Serial.println();
  Serial.println(F("RESULTADO DE CALIBRACION FLEX"));
  Serial.print(F("F1 reposo=")); Serial.print(flex1Cal.neutralRaw, 1);
  Serial.print(F(" flexionado=")); Serial.print(flex1Cal.bentRaw, 1);
  Serial.print(F(" umbral ON delta=")); Serial.print(flex1Cal.onDelta, 1);
  Serial.print(F(" OFF delta=")); Serial.print(flex1Cal.offDelta, 1);
  Serial.print(F(" direccion=")); Serial.print(flex1Cal.direction > 0 ? "+" : "-");
  if (flex1Cal.usedFallback) Serial.print(F(" [RESPALDO]"));
  Serial.println();

  Serial.print(F("F2 reposo=")); Serial.print(flex2Cal.neutralRaw, 1);
  Serial.print(F(" flexionado=")); Serial.print(flex2Cal.bentRaw, 1);
  Serial.print(F(" umbral ON delta=")); Serial.print(flex2Cal.onDelta, 1);
  Serial.print(F(" OFF delta=")); Serial.print(flex2Cal.offDelta, 1);
  Serial.print(F(" direccion=")); Serial.print(flex2Cal.direction > 0 ? "+" : "-");
  if (flex2Cal.usedFallback) Serial.print(F(" [RESPALDO]"));
  Serial.println();

  Serial.print(F("F2 durante calibracion F1 (control de movimiento cruzado): "));
  Serial.println(f2DuringIndex, 1);
  Serial.print(F("F1 durante calibracion F2 (control de movimiento cruzado): "));
  Serial.println(f1DuringThumb, 1);

  if (flex1Cal.usedFallback || flex2Cal.usedFallback) {
    Serial.println(F("ADVERTENCIA: al menos un flexor uso umbrales de respaldo."));
    Serial.println(F("Si ese dedo no se detecta bien, revisar la postura durante calibracion."));
  }
  Serial.println(F("Calibracion de flexores terminada."));
  Serial.println(F("------------------------------------------------------------"));
}

void readAndFilterMPU(float &temperature) {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float ax = a.acceleration.x;
  float ay = a.acceleration.y;
  float az = a.acceleration.z;
  float gx = radToDeg(g.gyro.x) - gyroBiasX;
  float gy = radToDeg(g.gyro.y) - gyroBiasY;
  float gz = radToDeg(g.gyro.z) - gyroBiasZ;
  temperature = temp.temperature;

  if (!mpuFilterReady) {
    filtAx = ax; filtAy = ay; filtAz = az;
    filtGx = gx; filtGy = gy; filtGz = gz;
    mpuFilterReady = true;
  } else {
    filtAx += ACC_ALPHA * (ax - filtAx);
    filtAy += ACC_ALPHA * (ay - filtAy);
    filtAz += ACC_ALPHA * (az - filtAz);
    filtGx += GYRO_ALPHA * (gx - filtGx);
    filtGy += GYRO_ALPHA * (gy - filtGy);
    filtGz += GYRO_ALPHA * (gz - filtGz);
  }
}

void readAndFilterFlex() {
  float f1 = (float)readFlexMedian(FLEX1_PIN);
  float f2 = (float)readFlexMedian(FLEX2_PIN);

  if (!flexFilterReady) {
    filtFlex1 = f1;
    filtFlex2 = f2;
    flexFilterReady = true;
  } else {
    filtFlex1 += FLEX_ALPHA * (f1 - filtFlex1);
    filtFlex2 += FLEX_ALPHA * (f2 - filtFlex2);
  }

  indexBent = updateFlexState(filtFlex1, flex1Cal, indexBent);
  thumbBent = updateFlexState(filtFlex2, flex2Cal, thumbBent);
}

// ---------------------------- Reconocimiento de gestos ---------------------
uint8_t getFlexPattern() {
  // bit 0 = indice; bit 1 = pulgar
  return (indexBent ? 0x01 : 0x00) | (thumbBent ? 0x02 : 0x00);
}

const char* gestureName(uint8_t id) {
  switch (id) {
    case GESTURE_1: return "INDICE_FLEXIONADO";
    case GESTURE_2: return "PULGAR_FLEXIONADO";
    case GESTURE_3: return "INDICE_Y_PULGAR_FLEXIONADOS";
    case GESTURE_4: return "MUNECA_ADELANTE";
    case GESTURE_5: return "MUNECA_ATRAS";
    case GESTURE_6: return "MUNECA_DERECHA";
    case GESTURE_7: return "MUNECA_IZQUIERDA";
    case GESTURE_8: return "ROTACION_ALREDEDOR_DE_GRAVEDAD";
    default: return "NINGUNO";
  }
}

void emitGesture(uint8_t id) {
  Serial.print(F("GESTURE_ID="));
  Serial.print(id);
  Serial.print(F(" | "));
  Serial.println(gestureName(id));
}

uint8_t detectGestureCandidate(float pitchDelta, float rollDelta) {
  uint8_t pattern = getFlexPattern();

  // Los flexores tienen prioridad sobre los gestos de muñeca.
  if (pattern == 0x01) return GESTURE_1;
  if (pattern == 0x02) return GESTURE_2;
  if (pattern == 0x03) return GESTURE_3;

  // Los gestos de muñeca se reconocen unicamente con ambos dedos extendidos.
  // MAPEO CORREGIDO SEGUN LA PRUEBA FISICA DEL USUARIO:
  // - El eje rollDelta fue el que respondio al movimiento adelante/atras.
  // - El eje pitchDelta fue el que respondio al movimiento izquierda/derecha.
  // - El signo observado para derecha/izquierda estaba invertido respecto
  //   de la etiqueta anterior.
  float forwardBack = rollDelta;
  float rightLeft = -pitchDelta;

  float absForwardBack = fabsf(forwardBack);
  float absRightLeft = fabsf(rightLeft);

  if (absForwardBack < TILT_ON_DEG && absRightLeft < TILT_ON_DEG) {
    return NO_GESTURE;
  }

  // En movimientos diagonales se selecciona el eje dominante.
  if (absForwardBack >= absRightLeft) {
    if (forwardBack >= TILT_ON_DEG) return GESTURE_4;
    if (forwardBack <= -TILT_ON_DEG) return GESTURE_5;
  } else {
    if (rightLeft >= TILT_ON_DEG) return GESTURE_6;
    if (rightLeft <= -TILT_ON_DEG) return GESTURE_7;
  }

  return NO_GESTURE;
}

void resetG8Tracker() {
  g8Tracking = false;
  g8AccumulatedAngle = 0.0f;
  g8PeakRate = 0.0f;
  g8StartedAt = 0;
  g8LastMotionAt = 0;
}

float getGyroRateAroundGravity() {
  float norm = vectorMagnitude(filtAx, filtAy, filtAz);
  if (norm < 0.001f) return 0.0f;
  float ux = filtAx / norm;
  float uy = filtAy / norm;
  float uz = filtAz / norm;
  // Proyeccion del giroscopio sobre el vector de gravedad medido.
  // A diferencia de elegir Z fijo, esto se adapta a la orientacion de la PCB.
  return filtGx * ux + filtGy * uy + filtGz * uz;
}

bool updateG8Detector(uint32_t now, float dtSeconds, float gravityAngle) {
  bool fingersStraight = !indexBent && !thumbBent;
  bool gravityStable = gravityAngle <= G8_MAX_GRAVITY_CHANGE_DEG;

  // Si hay flexion o una inclinacion clara, no puede ser G8.
  if (!fingersStraight || !gravityStable) {
    resetG8Tracker();
    return false;
  }

  float yawRate = getGyroRateAroundGravity();
  float absRate = fabsf(yawRate);

  if (!g8Tracking) {
    if (absRate >= G8_START_RATE_DPS) {
      g8Tracking = true;
      g8StartedAt = now;
      g8LastMotionAt = now;
      g8AccumulatedAngle = yawRate * dtSeconds;
      g8PeakRate = absRate;
    }
    return false;
  }

  if (now - g8StartedAt > G8_MAX_DURATION_MS) {
    resetG8Tracker();
    return false;
  }

  if (absRate >= G8_MIN_RATE_DPS) {
    g8AccumulatedAngle += yawRate * dtSeconds;
    g8PeakRate = max(g8PeakRate, absRate);
    g8LastMotionAt = now;
  }

  // Se evalua al terminar el movimiento, no durante un pico aislado.
  if (now - g8LastMotionAt >= G8_STOP_GAP_MS) {
    bool completed = fabsf(g8AccumulatedAngle) >= G8_REQUIRED_ANGLE_DEG &&
                     g8PeakRate >= G8_MIN_PEAK_RATE_DPS;
    resetG8Tracker();
    return completed;
  }

  return false;
}

bool isNeutral(float pitchDelta, float rollDelta,
               float gx, float gy, float gz) {
  bool fingersStraight = !indexBent && !thumbBent;
  bool wristNeutral = fabsf(pitchDelta) < TILT_OFF_DEG &&
                      fabsf(rollDelta) < TILT_OFF_DEG;
  bool gyroStill = fabsf(gx) < GYRO_NEUTRAL_DPS &&
                   fabsf(gy) < GYRO_NEUTRAL_DPS &&
                   fabsf(gz) < GYRO_NEUTRAL_DPS;
  return fingersStraight && wristNeutral && gyroStill && !g8Tracking;
}

// ---------------------------- Setup -----------------------------------------
void setup() {
  Serial.begin(115200);
  delay(700);

  Serial.println();
  Serial.println(F("============================================================"));
  Serial.println(F(" NODEMCU-32S - RECONOCIMIENTO LOCAL DE 8 GESTOS"));
  Serial.println(F(" Bluetooth desactivado: no se transmiten datos por radio"));
  Serial.println(F("============================================================"));

  pinMode(OUTPUT_PIN_16, OUTPUT);
  digitalWrite(OUTPUT_PIN_16, HIGH);

  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);
  pinMode(FLEX1_PIN, INPUT);
  pinMode(FLEX2_PIN, INPUT);

  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);

  if (!mpu.begin(0x68)) {
    if (!mpu.begin(0x69)) {
      Serial.println(F("ERROR: no se encontro el MPU6050 en 0x68 ni 0x69."));
      while (true) delay(100);
    }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  calibrateMPU6050();
  calibrateFlexSensors();

  lastSample = millis();
  Serial.println();
  Serial.println(F("SISTEMA DE 8 GESTOS ACTIVADO."));
  Serial.println(F("G1 indice | G2 pulgar | G3 ambos"));
  Serial.println(F("G4 adelante | G5 atras | G6 derecha | G7 izquierda"));
  Serial.println(F("G8 rotacion alrededor de gravedad, sin inclinar la mano"));
  Serial.println(F("------------------------------------------------------------"));
}

// ---------------------------- Loop ------------------------------------------
void loop() {
  uint32_t now = millis();
  if (now - lastSample < SAMPLE_INTERVAL_MS) return;

  float dtSeconds = (now - lastSample) / 1000.0f;
  lastSample = now;
  if (dtSeconds <= 0.0f || dtSeconds > 0.1f) dtSeconds = SAMPLE_INTERVAL_MS / 1000.0f;

  float temperature = 0.0f;
  readAndFilterMPU(temperature);
  readAndFilterFlex();

  float currentPitch = calculatePitch(filtAx, filtAy, filtAz);
  float currentRoll = calculateRoll(filtAx, filtAz);
  float pitchDelta = wrapAngle(currentPitch - neutralPitch);
  float rollDelta = wrapAngle(currentRoll - neutralRoll);
  float gravityAngle = gravityChangeAngle(filtAx, filtAy, filtAz);

  uint8_t detected = detectGestureCandidate(pitchDelta, rollDelta);
  bool g8Completed = false;
  if (gestureArmed && detected == NO_GESTURE) {
    g8Completed = updateG8Detector(now, dtSeconds, gravityAngle);
  } else {
    resetG8Tracker();
  }

  if (gestureArmed) {
    if (g8Completed) {
      emitGesture(GESTURE_8);
      gestureArmed = false;
      currentCandidate = NO_GESTURE;
      candidateSince = 0;
      neutralSince = 0;
      resetG8Tracker();
    } else if (detected == NO_GESTURE) {
      currentCandidate = NO_GESTURE;
      candidateSince = 0;
    } else {
      if (detected != currentCandidate) {
        currentCandidate = detected;
        candidateSince = now;
      } else {
        uint32_t needed = (detected <= GESTURE_3) ? FLEX_CONFIRM_MS : TILT_CONFIRM_MS;
        if (now - candidateSince >= needed) {
          emitGesture(detected);
          gestureArmed = false;
          currentCandidate = NO_GESTURE;
          candidateSince = 0;
          neutralSince = 0;
          resetG8Tracker();
        }
      }
    }
  } else {
    if (isNeutral(pitchDelta, rollDelta, filtGx, filtGy, filtGz)) {
      if (neutralSince == 0) neutralSince = now;
      if (now - neutralSince >= REARM_NEUTRAL_MS) {
        gestureArmed = true;
        neutralSince = 0;
        currentCandidate = NO_GESTURE;
        candidateSince = 0;
        Serial.println(F("SISTEMA REARMADO: listo para otro gesto."));
      }
    } else {
      neutralSince = 0;
    }
  }

  if (DEBUG_USB && now - lastDebug >= DEBUG_INTERVAL_MS) {
    lastDebug = now;
    Serial.print(F("F1raw=")); Serial.print((int)filtFlex1);
    Serial.print(F(" F2raw=")); Serial.print((int)filtFlex2);
    Serial.print(F(" | F1delta=")); Serial.print(flexTravelValue(filtFlex1, flex1Cal), 0);
    Serial.print(F("/")); Serial.print(flex1Cal.onDelta, 0);
    Serial.print(F(" F2delta=")); Serial.print(flexTravelValue(filtFlex2, flex2Cal), 0);
    Serial.print(F("/")); Serial.print(flex2Cal.onDelta, 0);
    Serial.print(F(" | F1=")); Serial.print(indexBent ? F("FLEX") : F("EXT"));
    Serial.print(F(" F2=")); Serial.print(thumbBent ? F("FLEX") : F("EXT"));
    Serial.print(F(" | adelante/atras=")); Serial.print(rollDelta, 1);
    Serial.print(F(" derecha/izquierda=")); Serial.print(-pitchDelta, 1);
    Serial.print(F(" | gravedadDelta=")); Serial.print(gravityAngle, 1);
    Serial.print(F(" yawRate=")); Serial.print(getGyroRateAroundGravity(), 1);
    Serial.print(F(" yawAcum=")); Serial.print(g8AccumulatedAngle, 1);
    Serial.print(F(" | estado=")); Serial.print(gestureArmed ? F("ARMADO") : F("ESPERANDO NEUTRO"));
    Serial.print(F(" | temp=")); Serial.println(temperature, 1);
  }
}
