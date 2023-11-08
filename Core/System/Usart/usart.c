//
// Created by acer-zgy on 2023/11/8.
//
#include "stm32f10x.h"
#include "usart.h"


void Serial_init() {
//    刷新缓冲区
    setvbuf(stdout, NULL, _IONBF, 0);

//    开启 usart1 和 gpioA 时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);

//    初始化GPIO
    GPIO_InitTypeDef gpio_tx_config = {
            .GPIO_Speed=GPIO_Speed_50MHz,
            .GPIO_Pin=GPIO_Pin_9,
            .GPIO_Mode=GPIO_Mode_AF_PP,
    };
    GPIO_InitTypeDef gpio_rx_config = {
            .GPIO_Speed=GPIO_Speed_50MHz,
            .GPIO_Pin=GPIO_Pin_10,
            .GPIO_Mode=GPIO_Mode_IPU,
    };
    GPIO_Init(GPIOA, &gpio_tx_config);
    GPIO_Init(GPIOA, &gpio_rx_config);

    USART_InitTypeDef usart_config = {
            .USART_BaudRate=9600,
            .USART_HardwareFlowControl=USART_HardwareFlowControl_None,
            .USART_Mode=USART_Mode_Rx | USART_Mode_Tx,
            .USART_Parity=USART_Parity_No,
            .USART_StopBits=USART_StopBits_1,
            .USART_WordLength=USART_WordLength_8b,
    };
    USART_Init(USART1, &usart_config);

    USART_Cmd(USART1, ENABLE);
}

void Serial_sendByte(uint8_t data) {
    USART_SendData(USART1, data);
//    等待数据 进入移位寄存器
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}


int __io_putchar(int ch) {
    Serial_sendByte(ch);
}