#include "stm32f103xb.h"

/*Diseñar una solución programable de manera tal que en el Puerto A se visualice el
complemento a 2 del Puerto B.*/

int main(void){
    RCC-> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN;

    GPIOA-> CRL = 0x11111111; // Salida push pull a 10MHz LOW
    GPIOB-> CRL = 0x44444444;

    uint16_t in;
    uint16_t comp2;

    while(1){

        in = GPIOB-> IDR & 0x00FF; //guardo lectura de B (solo los primeros 8 bits)

        comp2 = -in; //complemento a 2, el - hace el complemento a 1 y suma 1

        GPIOA-> ODR = (GPIOA->ODR & 0xFF00) | (comp2 & 0x00FF); // limpio bit 0 al 7 de A para no afectar los otros pines (0xFF00)
        //comp2 es la salida de datos, 0x00FF es para motrar datos del 15 al 8 donde F son los datos a reescribir
        //no combiene hacer esta parte en lineas separadas porque habra delay notorio entre limpiar bits y rescribirlos
    }
return 0;
}