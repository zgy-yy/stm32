//
// Created by acer-zgy on 2023/11/6.
//

#include "pwm.h"
#include "stm32f10x.h"

void Pwm_init() {
//    启动 tim2的时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
//  默认使用系统时钟
    TIM_InternalClockConfig(TIM2);

//    3. 配置时基单元
    TIM_TimeBaseInitTypeDef tim2_base_config = {
            .TIM_ClockDivision=TIM_CKD_DIV1, //时钟信号滤波采样频率 分频系数
            .TIM_CounterMode=TIM_CounterMode_Up, //向上计数
            .TIM_Period=100 - 1,//arr 自动重装载寄存器
            .TIM_Prescaler=720 - 1,//psc 预分频
            .TIM_RepetitionCounter=0 //重复计数器参数 普通定时器没有 设置0

    };
    TIM_TimeBaseInit(TIM2, &tim2_base_config);


//    TIM_OCStructInit(&tim_oc_config);                            //结构体初始化，若结构体没有完整赋值
//    pwm 比较初始化
    TIM_OCInitTypeDef tim_oc_config = {
            .TIM_OCMode = TIM_OCMode_PWM1,//输出比较模式，选择PWM模式1
            .TIM_OCPolarity=TIM_OCPolarity_High,//输出极性，选择为高，若选择极性为低，则输出高低电平取反
            .TIM_OutputState=TIM_OutputState_Enable,//输出使能
            .TIM_Pulse=0,//初始的CCR值
    };


    TIM_OC1Init(TIM2, &tim_oc_config);

// 对应的GPIO 配置
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef gpio_config = {
            .GPIO_Mode = GPIO_Mode_AF_PP,
            .GPIO_Pin=GPIO_Pin_0,
            .GPIO_Speed=GPIO_Speed_50MHz
    };
    GPIO_Init(GPIOA, &gpio_config);


    TIM_Cmd(TIM2, ENABLE);
}

void Pwm_setCompare(uint16_t compare) {
//    更改 ccr的值
    TIM_SetCompare1(TIM2, compare);
}