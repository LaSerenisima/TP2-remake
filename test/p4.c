#include "stm32f103xb.h"
/*Diseñar una solución programable de manera tal que en el Puerto A se obtenga el
resultado de la operación suma entre el Puerto B y el literal 0x23.*/

int main(void){

    RCC-> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN;

    GPIOA-> CRL = 0x11111111;
    GPIOA-> CRH &= ~(15 <<((8%8)*4));
    GPIOA-> CRH |= (1 <<((8%8)*4));    

    GPIOB-> CRL = 0x44444444;

    uint16_t in;
    uint32_t sum;

    while(1){
        in = GPIOB-> IDR & 0x00FF;

        sum = in + 0x23; // suma literal 0x23 -o- 35

        GPIOA-> ODR = (GPIOA-> ODR & 0xFE00) | (sum & 0x01FF); //mascara 0xEF00 para no afectar bits 15 al 9, mascara 0x01FF para motrar del 8 al 0
    }
    return 0;
}