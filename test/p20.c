#include "stm32f103xb.h"
// p20 Diseñar una solución programable de manera tal que las salidas A0 y A1 se activen si B0 está activo, 
// las salidas A2 y A3 se activen si B1 está activo, las salidas A4 y A5 se activen
// si B2 está activo, las salidas A6 y A7 se activen si B3 está activo.

int main(void){
  RCC-> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN; 
  
  GPIOA-> CRL = 0x11111111; //  a0 a a7 10mhz salida push pull

  GPIOB-> CRL = 0x88888888; // b0 a b3 pull up/down
  GPIOB->ODR &= 0xFF00; // pull down (cada letra es 4 bits, F pone los bits B15 a B12 en 1, osea no los toca, la otra F lo mismo del 11 al 8. y el 00 pone pull down del 7 al 0)

  while(1){
    //leo puerto B y lo guardo
    uint16_t con1 = (GPIOB-> IDR & (1 << 0));
    uint16_t con2 = (GPIOB-> IDR & (1 << 1));
    uint16_t con3 = (GPIOB-> IDR & (1 << 2));
    uint16_t con4 = (GPIOB-> IDR & (1 << 3));

    //A0 y A1
    if(con1){
        GPIOA-> BSRR = (1 << 0) | (1 << 1);
    }
    else{
        GPIOA-> BSRR = (1 << 16) | (1 << 17);
    }

    //A2 y A3
    if(con2){
        GPIOA-> BSRR = (1 << 2) | (1 << 3);
    }
    else{
        GPIOA-> BSRR = (1 << 18) | (1 << 19);
    }

    //A4 y A5
    if(con3){
        GPIOA-> BSRR = (1 << 4) | (1 << 5);
    }
    else{
        GPIOA-> BSRR = (1 << 20) | (1 << 21);
    }

    //A6 y A7
        if(con4){
        GPIOA-> BSRR = (1 << 6) | (1 << 7);
    }
    else{
        GPIOA-> BSRR = (1 << 22) | (1 << 23);
    }
  }

  return 0;
}