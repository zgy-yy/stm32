//
// Created by acer-zgy on 2023/11/12.
//

#include "Infrared.h"

#include "stm32f10x_rcc.h"

void Infrare_init() {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitTypeDef vcc_config = {
        .GPIO_Pin = GPIO_Pin_0,
        .GPIO_Speed = GPIO_Speed_50MHz,
        .GPIO_Mode = GPIO_Mode_Out_PP
    };

    GPIO_InitTypeDef gnd_config = {
        .GPIO_Pin = GPIO_Pin_7,
        .GPIO_Speed = GPIO_Speed_50MHz,
        .GPIO_Mode = GPIO_Mode_Out_PP
    };

    GPIO_Init(GPIOB, &vcc_config);
    GPIO_Init(GPIOA, &gnd_config);
    GPIO_SetBits(GPIOB,GPIO_Pin_0);
    GPIO_ResetBits(GPIOA,GPIO_Pin_7);
}
