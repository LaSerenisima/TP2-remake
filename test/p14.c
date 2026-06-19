#include "stm32f103xb.h"

/*Diseñar una solución programable de manera tal que en el Puerto A se refleje el valor
del Puerto B con un desplazamiento lógico a la derecha. Utilizar el operador >>.*/

int main(void){
    RCC-> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN;

    GPIOA-> CRL = 0x11111111;

    GPIOB-> CRL = 0x44444444;

    uint16_t in;
    uint16_t op;

    while(1){
        in = GPIOB-> IDR & 0x00FF;

        op = (in >> 1); // este operador solo desplaza bits, el bit desplazado a la nada se pierde

        GPIOA-> ODR = (GPIOA-> ODR & 0xFF00) | (op & 0x00FF);
    }
    return 0;
}