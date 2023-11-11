//
// Created by acer-zgy on 2023/11/11.
//

#include "Adc.h"

void Adc_init() {

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef gpio_config = {
            .GPIO_Pin=GPIO_Pin_0,
            .GPIO_Mode=GPIO_Mode_AIN,
            .GPIO_Speed=GPIO_Speed_50MHz
    };
    GPIO_Init(GPIOA, &gpio_config);

/*开启时钟*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);    //开启ADC1的时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

    /*设置ADC时钟*/
    RCC_ADCCLKConfig(RCC_PCLK2_Div6);                        //选择时钟6分频，ADCCLK = 72MHz / 6 = 12MHz
    /*规则组通道配置*/
    ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);        //规则组序列1的位置，配置为通道0

    ADC_InitTypeDef adc_config = {
            .ADC_Mode = ADC_Mode_Independent,        //模式，选择独立模式，即单独使用ADC1
            .ADC_DataAlign = ADC_DataAlign_Right,    //数据对齐，选择右对齐
            .ADC_ExternalTrigConv = ADC_ExternalTrigConv_None,    //外部触发，使用软件触发，不需要外部触发
            .ADC_ContinuousConvMode = DISABLE,        //连续转换，失能，每转换一次规则组序列后停止
            .ADC_ScanConvMode = DISABLE,            //扫描模式，失能，只转换规则组的序列1这一个位置
            .ADC_NbrOfChannel = 1                   //通道数，为1，仅在扫描模式下，才需要指定大于1的数，在非扫描模式下，只能是1
    };
    ADC_Init(ADC1, &adc_config);                        //将结构体变量交给ADC_Init，配置ADC1
    ADC_Cmd(ADC1, ENABLE);

    /*ADC校准*/
    ADC_ResetCalibration(ADC1);								//固定流程，内部有电路会自动执行校准
    while (ADC_GetResetCalibrationStatus(ADC1) == SET);
    ADC_StartCalibration(ADC1);
    while (ADC_GetCalibrationStatus(ADC1) == SET);
}
/**
  * 函    数：获取AD转换的值
  * 参    数：无
  * 返 回 值：AD转换的值，范围：0~4095
  */
uint16_t Adc_getValue()
{
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);					//软件触发AD转换一次
    while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);	//等待EOC标志位，即等待AD转换结束
    return ADC_GetConversionValue(ADC1);					//读数据寄存器，得到AD转换的结果
}
