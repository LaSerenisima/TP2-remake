#include "stm32f103xb.h"

int main(void){
    RCC-> APB2ENR |= RCC_APB2ENR_IOPAEN |RCC_APB2ENR_IOPBEN; // clock para GPIOA & B

    GPIOA-> CRL = 0x11111111; // Salida push pull a 10MHz LOW
    GPIOA-> CRH = 0x11111111; // Salida push pull a 10MHz HIGH

    GPIOB-> CRL = 0x44444444; // Entrada flotante LOW
    GPIOB-> CRH = 0x44444444; // Entrada flotante HIGH

    // 0x activa la mascara o macros
    // 0x00000000 el numero representa el modo (00 push pull, 00 reset, el resultado de 0000 = 0, por eso hay 8 ceros (1 por cada pin))
    // ↑ ↑↑↑↑↑↑↑↑
    // M 01234567 (en CRL) 8 9 10 11 12 13 14 15 (en CRH)

    uint32_t datain; // lectura de B
    uint32_t dataout; // salida de A

    while(1){
        datain = GPIOB-> IDR; //guardo lectura de B

        dataout = ~datain; //complemento a1, la ~ invierte 1 a 0 y asi

        GPIOA-> ODR = dataout; //salida de complemento
    }
    return 0;
} /* aclaraciones:

- No andaria bien porque hay pines que no se pueden usar como A13, A14, A15, B3 y B4

- Si no se enchufa algo a alguno de los pines CRH (8 al 15) se genera ruido y da lecturas random

*/

/* ejemplo de codigo usando 8 pines 

#include "stm32f103xb.h"

int main(void){
    // 1. Habilitar relojes para Puerto A y B
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN; 
    
    // 2. Configurar pines del 0 al 7 en ambos puertos de golpe
    GPIOA->CRL = 0x33333333; // PA0-PA7: Salidas Push-Pull 50MHz
    GPIOB->CRL = 0x44444444; // PB0-PB7: Entradas Flotantes

    uint16_t datos_ingreso;
    uint16_t datos_salida;

    while(1){
        // 3. Leer TODO el puerto B y aislamos solo los primeros 8 bits (0xFF = 11111111)
        // Si entra 11101101 (237), datos_ingreso guardará exactamente eso.
        datos_ingreso = GPIOB->IDR & 0x00FF; 

        // 4. Aplicar el Complemento a 1 usando el operador '~'
        // El ~ transforma el 11101101 en 00010010 (que es 18 en decimal)
        datos_salida = ~datos_ingreso;

        // 5. Escribir el resultado en el Puerto A
        // Usamos una máscara para no modificar los pines del PA8 al PA15 por si acaso
        GPIOA->ODR = (GPIOA->ODR & 0xFF00) | (datos_salida & 0x00FF);
    }
}

*/