# Especificación de Requerimientos: App Android Puente (Guante ESP32 $\rightarrow$ Home Assistant)

## 1. Objetivo del Proyecto

Desarrollar una aplicación nativa para Android (teléfono y tablet) que actúe como puente de baja latencia entre un dispositivo *wearable* basado en **ESP32** (guante detector de gestos) y un servidor local de **Home Assistant**. La app debe recibir identificadores numéricos de gestos (`1` al `8`) vía Bluetooth y ejecutar acciones domóticas configuradas por el usuario mediante la API REST de Home Assistant a través de Wi-Fi local.

---

## 2. Flujo de Datos y Arquitectura

1. **Entrada (Bluetooth):** El ESP32 clasifica localmente el movimiento de la mano y envía únicamente el ID del gesto detectado (`1` a `8`).
2. **Procesamiento (Android):** Un servicio en segundo plano recibe el ID, consulta la tabla de asignación configurada por el usuario y construye la petición HTTP correspondiente.
3. **Salida (Wi-Fi / REST API):** La app envía una petición `POST` autenticada con un *Long-Lived Access Token* al servidor local de Home Assistant para ejecutar la acción sobre la entidad asignada.

---

## 3. Requerimientos Funcionales por Pantalla

### Pantalla 1: Configuración de Home Assistant

* **Campos de entrada:**
* URL base del servidor local (ej. `[http://192.168.1.50:8123](http://192.168.1.50:8123)`).
* Campo seguro para pegar el **Long-Lived Access Token**.


* **Validación de conexión:** Botón *"Probar conexión"* que ejecute `GET /api/` y muestre confirmación visual si recibe código `200 OK`.
* **Sincronización de entidades:** Botón *"Actualizar dispositivos"* que consulte `GET /api/states` y almacene en caché local las entidades controlables (filtrando dominios como `light`, `switch`, `cover`, `scene`, `script`, `fan`, `media_player`) junto con su `friendly_name`.
* **Persistencia:** Guardar credenciales y lista de entidades de forma segura en el dispositivo (`EncryptedSharedPreferences` o `DataStore`).

### Pantalla 2: Vinculación Bluetooth (ESP32)

* **Selector de dispositivo:** Listar dispositivos Bluetooth emparejados y permitir seleccionar el ESP32.
* **Control de conexión:** Botón Conectar / Desconectar con indicador de estado (*Conectado*, *Reconectando*, *Desconectado*) y reconexión automática ante pérdida temporal de señal.
* **Monitor en vivo:** Indicador visual que muestre el último gesto recibido en tiempo real (ej. `Último recibido: G1 - Pulgar arriba`) para facilitar pruebas físicas del guante.

### Pantalla 3: Mapa de Asignación de Gestos (G1 – G8)

Listado fijo con los 8 gestos soportados por el firmware del ESP32. Al seleccionar cada fila, el usuario debe poder elegir un **Dispositivo/Entidad** de Home Assistant y una **Acción** (*Encender*, *Apagar*, *Alternar / Toggle*, *Ejecutar escena*, o *Sin asignar*):

| ID Recibido | Nombre del Gesto en UI | Ejemplo de Acción Configurable |
| --- | --- | --- |
| **1** | Pulgar arriba | Encender luz principal (`light.turn_on`) |
| **2** | Señalando | Alternar lámpara de escritorio (`homeassistant.toggle`) |
| **3** | Desplazamiento derecha | Siguiente escena / Subir persiana |
| **4** | Desplazamiento izquierda | Escena anterior / Bajar persiana |
| **5** | Cerrar la mano | Apagar todo (`homeassistant.turn_off`) |
| **6** | Señal de alto | Pausar multimedia / Detener persiana |
| **7** | Inclinar abajo | Atenuar luces / Activar modo noche |
| **8** | Girar muñeca | Activar ventilador o enchufe inteligente |

---

## 4. Especificaciones Técnicas e Interfaces

### Contrato de Comunicación Bluetooth (ESP32 $\rightarrow$ App)

* **Protocolo:** Bluetooth Classic (SPP / RFCOMM) o BLE GATT (característica con propiedad `NOTIFY`), a definir en conjunto con el firmware final.
* **Formato del mensaje:** Cadena ASCII terminada en salto de línea (`"1\n"` a `"8\n"`) o byte único (`0x01` a `0x08`). La app debe descartar cualquier trama inválida o fuera de rango.

### Contrato API REST (App $\rightarrow$ Home Assistant)

* **Endpoint de ejecución:** `POST <URL_BASE>/api/services/<dominio>/<servicio>` (por ejemplo, `/api/services/homeassistant/toggle` o `/api/services/scene/turn_on`).
* **Cabeceras obligatorias:**
* `Authorization: Bearer <LONG_LIVED_ACCESS_TOKEN>`
* `Content-Type: application/json`


* **Cuerpo (JSON):**
```json
{
  "entity_id": "light.sala"
}

```



### Requisitos de Sistema Android

* **Stack sugerido:** Kotlin, Android SDK 26+ (Android 8.0 o superior), OkHttp / Retrofit para red, Coroutines para asincronía.
* **Ejecución en segundo plano:** Implementar un **Foreground Service** con notificación persistente mientras el guante esté conectado, evitando que el sistema operativo cierre el socket Bluetooth al apagar la pantalla.
* **Permisos y red local:**
* Solicitar en tiempo de ejecución `BLUETOOTH_CONNECT` y `BLUETOOTH_SCAN` (Android 12+).
* Habilitar `android:usesCleartextTraffic="true"` en el `AndroidManifest.xml` para permitir tráfico HTTP en la red local (`192.168.x.x`) sin exigir certificados SSL externos.



---

## 5. Criterios de Aceptación

* **Latencia:** El tiempo total desde que el ESP32 envía el ID por Bluetooth hasta que se despacha la petición HTTP a Home Assistant debe ser inferior a **300 ms**.
* **Manejo de errores:** Si el servidor de Home Assistant no responde o el token es inválido, la app debe registrar el error en pantalla sin cerrar el servicio Bluetooth.
* **Entregables:** Código fuente completo en repositorio Git, archivo `.apk` firmado para instalación directa en tablet/teléfono y guía breve de configuración inicial.

---
