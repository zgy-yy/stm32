

#include "stm32f10x.h"


//tim2 初始化
void Timer_Init() {
//    启动 tim2的时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
//  默认使用系统时钟
    TIM_InternalClockConfig(TIM2);

//    3. 配置时基单元
    TIM_TimeBaseInitTypeDef tim2_base_config = {
            .TIM_ClockDivision=TIM_CKD_DIV1, //时钟信号滤波采样频率 分频系数
            .TIM_CounterMode=TIM_CounterMode_Up, //向上计数
            .TIM_Period=10000 - 1,//arr 自动重装载寄存器
            .TIM_Prescaler=7200 - 1,//psc 预分频
            .TIM_RepetitionCounter=0 //重复计数器参数 普通定时器没有 设置0

    };
    TIM_TimeBaseInit(TIM2, &tim2_base_config);

//    避免初始化完就进中断
/*  手动清除一下标志位，防止设置预分频和重载载计数器 触发中断 （因为它们都有缓冲寄存器 只有触发了中断才会更新）  */
    TIM_ClearFlag(TIM2, TIM_FLAG_Update);
//    4.使能中断
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

//    5.nvic 配置
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);//设置响应优先级

    NVIC_InitTypeDef nvic_config = {
            .NVIC_IRQChannel=TIM2_IRQn,//配置通道
            .NVIC_IRQChannelCmd=ENABLE,
            .NVIC_IRQChannelPreemptionPriority=1,
            .NVIC_IRQChannelSubPriority=1,
    };
    NVIC_Init(&nvic_config);

    TIM_Cmd(TIM2, ENABLE);
}


/*
void TIM2_IRQHandler() {
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET) {

        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}*/
