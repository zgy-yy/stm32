//
// Created by acer-zgy on 2023/11/11.
//

#include "Dma.h"


uint16_t AD_Value[4] = {0}; //定义用于存放AD转换结果的全局数组

void Dma_init() {
    /*开启时钟*/
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE); //开启DMA的时钟
    /*DMA初始化*/
    DMA_InitTypeDef dma_config = {
        .DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR, //外设基地址， ADC 外设
        .DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord, //外设数据宽度，选择字节
        .DMA_PeripheralInc = DMA_PeripheralInc_Disable, //外设地址自增，选择使能
        .DMA_MemoryBaseAddr = (uint32_t)AD_Value, //存储器基地址，给定形参AddrB
        .DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord, //存储器数据宽度，选择字节
        .DMA_MemoryInc = DMA_MemoryInc_Enable, //存储器地址自增，选择使能
        .DMA_DIR = DMA_DIR_PeripheralSRC, //数据传输方向，选择由外设到存储器
        .DMA_BufferSize = 4, //转运的数据大小（转运次数）
        .DMA_Mode = DMA_Mode_Circular, //模式，选择正常模式
        .DMA_M2M = DMA_M2M_Disable, //硬件触发，触发源 ADC1
        .DMA_Priority = DMA_Priority_Medium //优先级，选择中等
    };

    DMA_Init(DMA1_Channel1, &dma_config); //将结构体变量交给DMA_Init，配置DMA1的通道1

    /*DMA使能*/
    DMA_Cmd(DMA1_Channel1, ENABLE); //这里先不给使能，初始化后不会立刻工作，等后续调用Transfer后，再开始
}

void Dma_trans() {
    DMA_Cmd(DMA1_Channel1, DISABLE); //DMA失能，在写入传输计数器之前，需要DMA暂停工作
    DMA_SetCurrDataCounter(DMA1_Channel1, 4); //写入传输计数器，指定将要转运的次数
    DMA_Cmd(DMA1_Channel1, ENABLE); //DMA使能，开始工作
}
