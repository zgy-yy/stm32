#include "stm32f10x.h"

// 外部时钟源
void SourceClock_init() {
    //    启动 tim2的时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

//    配置时钟源使用的gpio
    GPIO_InitTypeDef gpioA_config = {
            .GPIO_Speed=GPIO_Speed_50MHz,
            .GPIO_Pin=GPIO_Pin_0,
            .GPIO_Mode=GPIO_Mode_IPU,
    };

    GPIO_Init(GPIOA, &gpioA_config);

    //**选择外部时钟源**
    TIM_ETRClockMode2Config(TIM2, TIM_ExtTRGPSC_OFF, TIM_ExtTRGPolarity_NonInverted, 0x00);


//    3. 配置时基单元
    TIM_TimeBaseInitTypeDef tim2_base_config = {
            .TIM_ClockDivision=TIM_CKD_DIV1, //时钟信号滤波采样频率 分频系数
            .TIM_CounterMode=TIM_CounterMode_Up, //向上计数
            .TIM_Period=10 - 1,//arr 自动重装载寄存器
            .TIM_Prescaler=1 - 1,//psc 预分频
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


