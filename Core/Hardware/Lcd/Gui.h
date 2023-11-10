//
// Created by acer-zgy on 2023/11/10.
//

#ifndef STM32_LEARN01_GUI_H
#define STM32_LEARN01_GUI_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32f10x.h"
#include "Lcd.h"
#include "font.h"

void LCD_ShowChar(uint16_t x, uint16_t y, char chr);

void LCD_ShowString(uint16_t x, uint16_t y, uint16_t width, uint16_t height, char *p);

#ifdef __cplusplus
}
#endif


#endif //STM32_LEARN01_GUI_H
