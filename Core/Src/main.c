#include "stm32f10x.h"

void main() {

    RCC->APB2ENR = 0x00000010;//使能时钟
    GPIOC->CRH = 0x00300000; // gpio模式
    GPIOC->ODR = 0x00200000;
    while (1) {

    }
}