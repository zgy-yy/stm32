
#include "stm32f10x.h"
#include "delay.h"

void key_init() {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef gpioA_config = {
            .GPIO_Mode = GPIO_Mode_IPU, //上拉输入,浮空时默认读出的是 高电平
            .GPIO_Pin = GPIO_Pin_0,
            .GPIO_Speed = GPIO_Speed_50MHz
    };
    GPIO_Init(GPIOA, &gpioA_config);
}

uint8_t key_getNum() {
    uint8_t key_num = 0;
//    读取输入数据  防抖
    if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0) {
        Delay_ms(20);
        while (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0);
        Delay_ms(20);
        key_num = 1;
    }
    return key_num;
}