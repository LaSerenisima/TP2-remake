#include "stm32f103xb.h"

/*Diseñar una solución programable de manera tal que en el Puerto A se obtenga el
resultado de la operación resta entre el Puerto B y el literal 0x23.*/

int main(void){
RCC-> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN;

GPIOA-> CRL = 0x11111111;
GPIOA-> CRH = 0x11111111;

GPIOB-> CRL = 0x44444444;

uint16_t in;
uint32_t res;

while(1){
    in = GPIOB-> IDR & 0x00FF;

    res = in - 0x23;

    GPIOA-> ODR = res; //se borraron las mascarasa de proteccion (lo que habia para limitar que se muestra en la salida) porque se usan los 16 bits
}
return 0;
}