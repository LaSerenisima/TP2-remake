#include "stm32f103xb.h"

/*Diseñar una solución programable de manera tal que en el Puerto A se refleje el valor
del Puerto B con un desplazamiento lógico a la izquierda. Utilizar el operador <<.*/

int main(void){
    RCC-> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN;

    GPIOA-> CRL = 0x11111111;
    GPIOA-> CRH = 0x11111111;

    GPIOB-> CRL = 0x44444444;

    uint16_t in;
    uint32_t op;

    while(1){
        in = GPIOB-> IDR & 0x00FF;

        op = (in << 1); // este operador dice que in se va a desplazar 1 lugar a la izquierda, llenando el nuevo espacio con 0

        GPIOA-> ODR = (GPIOA-> ODR & 0xFE00) | (op & 0x01FF);
    }
    return 0;
}