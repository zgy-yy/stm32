
#include "led.h"
#include "stm32f10x.h"

void led_init() {

//    开启 GPIOC 所在的APB2总线时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_InitTypeDef gpioc_init_config = {
            .GPIO_Speed = GPIO_Speed_50MHz,
            .GPIO_Pin=GPIO_Pin_13,
            .GPIO_Mode=GPIO_Mode_Out_PP
    };
    GPIO_Init(GPIOC, &gpioc_init_config);
}

void led_on() {
    GPIO_WriteBit(GPIOC, GPIO_Pin_13, 0);
}

void led_off() {
    GPIO_WriteBit(GPIOC, GPIO_Pin_13, 1);
}