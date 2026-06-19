#include "stm32f103xb.h"

/*Diseñar una solución programable de manera tal que las salidas A0, A1, A2 y A3 se
activen si B0 está inactivo; y las salidas A4, A5, A6 y A7 se activen si B0 está activo.*/

#define B0 0

int main(void){
    RCC-> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN;

    GPIOA-> CRL = 0x11111111;

    GPIOB-> CRL &= ~(15 << (B0*4));
    GPIOB-> CRL |= (8 << (B0*4));

    GPIOB-> ODR |= (1 << B0); // pull up

    uint16_t in1;

    while(1){
        in1 = GPIOB-> IDR & (1 << B0);
        //par
        if(in1){
            GPIOA-> BSRR = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) |//prende
                            (1 << 20) | (1 << 21) | (1 << 22) | (1 << 23);//apaga 4-7
        }
        else{
            GPIOA-> BSRR = (1 << 16) | (1 << 17) | (1 << 18) | (1 << 19) |//apaga
                            (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7); //prende 4-7
        }        
    }
    return 0;
}