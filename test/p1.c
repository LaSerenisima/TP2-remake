#include "stm32f103xb.h"

#define pinA 2
#define pinB 4

int main(void){
    RCC->APB2ENR|= RCC_APB2ENR_IOPAEN|RCC_APB2ENR_IOPBEN; // clock para GPIOA & B
    
    GPIOA-> CRL &= ~(15 << (pinA*4)); // limpio bits pero del pin A (15=1111)
    GPIOA-> CRL |= (3 << (pinA*4));  // configuro el pin A como salida push-pull a 50MHz (3=0011)

    GPIOB-> CRL &= ~(15 <<(pinB*4)); // limpio bits pero del pin B (15=1111)
    GPIOB-> CRL |= (4 <<(pinB*4)); // configuro el pin B como entrada, 01 para floating input y 00 porque es input (4=0100)

    while(1){ //loop infinito
        if((GPIOB-> IDR & (1 << pinB)) == 0){ // leo si pinB vale 0 (si la lectura no es iguala 1, IDR devuelve 0 y entonces se cumple el 0==0)
            GPIOA-> BSRR = (1 << (pinA+16)); // pongo pinA en 0 (bit 2 en zona alta (2 es bit 2 en baja, 16 es bit 2 en alta))
        }
        else{
            GPIOA-> BSRR = (1 << pinA); // pongo pinA en 1 (bit 2 en zona baja)
        }
    }
    return 0;
}