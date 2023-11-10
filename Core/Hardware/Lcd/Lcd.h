//
// Created by acer-zgy on 2023/11/8.
//

#ifndef STM32_LEARN01_DRIVER_H
#define STM32_LEARN01_DRIVER_H

#include "stm32f10x.h"


#define X_MAX_PIXEL            128
#define Y_MAX_PIXEL            160

#define RED    0xf800
#define GREEN    0x07e0
#define BLUE    0x001f
#define WHITE    0xffff
#define BLACK    0x0000
#define YELLOW  0xFFE0
#define GRAY0   0xEF7D    //»ÒÉ«0 3165 00110 001011 00101
#define GRAY1   0x8410        //»ÒÉ«1      00000 000000 00000
#define GRAY2   0x4208        //»ÒÉ«2  1111111111011111



void LCD_GPIO_Init(void);

void Lcd_WriteIndex(uint8_t Index);

void Lcd_WriteData(uint8_t Data);

void Lcd_WriteReg(uint8_t Index, uint8_t Data);

u16 Lcd_ReadReg(uint8_t LCD_Reg);

void Lcd_Reset(void);

void Lcd_Init(void);

void Lcd_Clear(uint16_t Color);

void Lcd_SetXY(uint16_t x, uint16_t y);

void Lcd_DrawPoint(uint16_t x, uint16_t y, uint16_t Data);

unsigned int Lcd_ReadPoint(uint16_t x, uint16_t y);

void Lcd_SetRegion(uint16_t x_start, uint16_t y_start, uint16_t x_end, uint16_t y_end);

void LCD_WriteData_16Bit(uint16_t Data);


#endif //STM32_LEARN01_DRIVER_H
