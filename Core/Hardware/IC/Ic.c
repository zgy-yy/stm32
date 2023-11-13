//
// Created by acer-zgy on 2023/11/11.
//

#include "Ic.h"
#include "stdio.h"

void Ic_init() {
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

    RCC_APB1PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    //    配置TIM3-CH1 的引脚 PA6

    GPIO_InitTypeDef tim3_pin_config = {
        .GPIO_Mode = GPIO_Mode_IPU,
        .GPIO_Pin = GPIO_Pin_6,
        .GPIO_Speed = GPIO_Speed_50MHz
    };
    GPIO_Init(GPIOA, &tim3_pin_config);

    TIM_InternalClockConfig(TIM3); //选择TIM3为内部时钟，若不调用此函数，TIM默认也为内部时钟

    TIM_TimeBaseInitTypeDef time_config = {
        .TIM_CounterMode = TIM_CounterMode_Up,
        .TIM_Period = 65536 - 1,
        .TIM_Prescaler = 1 - 1, //1Mhz
        .TIM_ClockDivision = TIM_CKD_DIV1,
        .TIM_RepetitionCounter = 0,
    };
    TIM_TimeBaseInit(TIM3, &time_config);

    TIM_ICInitTypeDef ic_config = {
        .TIM_Channel = TIM_Channel_1,
        .TIM_ICPolarity = TIM_ICPolarity_Rising,
        .TIM_ICSelection = TIM_ICSelection_DirectTI,
        .TIM_ICPrescaler = TIM_ICPSC_DIV1,
        .TIM_ICFilter = 0xF
    };
    TIM_ICInit(TIM3, &ic_config);

    //    4.使能中断
    TIM_ITConfig(TIM3, TIM_IT_CC1, ENABLE);
    //    5.nvic 配置
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); //设置响应优先级

    NVIC_InitTypeDef nvic_config = {
        .NVIC_IRQChannel = TIM3_IRQn, //配置通道
        .NVIC_IRQChannelCmd = ENABLE,
        .NVIC_IRQChannelPreemptionPriority = 1,
        .NVIC_IRQChannelSubPriority = 1,
    };
    NVIC_Init(&nvic_config);


    TIM_SelectInputTrigger(TIM3, TIM_TS_TI1FP1); //设置触发源头
    TIM_SelectSlaveMode(TIM3, TIM_SlaveMode_Reset); //从模式  CNT 清零
    TIM_Cmd(TIM3, ENABLE);
}


uint32_t IC_GetFreq() {
    return TIM_GetCapture1(TIM3); //测周法得到频率fx = fc / N，这里不执行+1的操作也可
}
