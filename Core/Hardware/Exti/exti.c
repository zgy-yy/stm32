

#include "exti.h"
#include "stm32f10x.h"
#include "led.h"

void exti_init() {

//    1. gpio 初始化
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
    GPIO_InitTypeDef gpioA_config = {
            .GPIO_Mode = GPIO_Mode_IPU, //上拉输入,浮空时默认读出的是 高电平
            .GPIO_Pin = GPIO_Pin_0,
            .GPIO_Speed = GPIO_Speed_50MHz
    };
    GPIO_Init(GPIOA, &gpioA_config);

//    2.AFIO 重映射到 exti边沿检测
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_Pin_0);

//    3.配置exti
    EXTI_InitTypeDef exti_config = {
            .EXTI_Line=EXTI_Line0,//触发中断的线 对应GPIO口
            .EXTI_LineCmd=ENABLE,
            .EXTI_Mode=EXTI_Mode_Interrupt,//中断模式，而非事件
            .EXTI_Trigger=EXTI_Trigger_Falling,//上升沿触发
    };
    EXTI_Init(&exti_config);
//    4. 配置nvic

// 每个程序只需要配置一次，在全局设置更合适****
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);//设置响应优先级

    NVIC_InitTypeDef nvic_config = {
            .NVIC_IRQChannel=EXTI0_IRQn,//配置通道
            .NVIC_IRQChannelCmd=ENABLE,
            .NVIC_IRQChannelPreemptionPriority=1,
            .NVIC_IRQChannelSubPriority=1,
    };
    NVIC_Init(&nvic_config);

}

// 中断服务函数
void EXTI0_IRQHandler() {
//    判断中断标志位
    if (EXTI_GetITStatus(EXTI_Line0) == SET) {
        led_turn();
    }
    EXTI_ClearITPendingBit(EXTI_Line0);
}