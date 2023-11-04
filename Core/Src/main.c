#include "stm32f10x.h"

void main() {

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);//使能 gpioc 时钟

    GPIO_InitTypeDef gpio_initStructure = {
            .GPIO_Mode = GPIO_Mode_Out_PP,
            .GPIO_Pin=GPIO_Pin_13,
            .GPIO_Speed=GPIO_Speed_50MHz
    };
    GPIO_Init(GPIOC, &gpio_initStructure);
    GPIO_ResetBits(GPIOC, GPIO_Pin_13);
//    GPIO_SetBits(GPIOC, GPIO_Pin_13);
    while (1) {

    }
}