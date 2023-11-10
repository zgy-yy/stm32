//
// Created by acer-zgy on 2023/11/10.
//

#include "Gui.h"

#include "stdio.h"


/**
 * @brief	显示asic 字符
 *
 * @param   x,y		起始坐标
 * @param   chr		显示的字符
 * @param   size	大小 16/24/32
 *
 * @return  void
 */

uint16_t POINT_COLOR = BLUE;    // 字体
uint16_t BACK_COLOR = WHITE;    // 背景

void LCD_ShowChar(uint16_t x, uint16_t y, char chr) {
    uint8_t size = 16;
    uint16_t c_ind = chr - ' ';
    if ((x > (X_MAX_PIXEL - size / 2)) || (y > (Y_MAX_PIXEL - size))) return;

    Lcd_SetRegion(x, y, x + size / 2 - 1, y + size - 1);//(x,y,x+8-1,y+16-1)

    if ((size == 16) || (size == 32))    //16
    {
        for (int i = 0; i < 16; ++i) {
            uint16_t ch = asc2_16x16[c_ind][i];
            for (int j = 0; j < 16 / 2; ++j) {
                uint16_t color = BACK_COLOR;
                if (ch & 0x80)
                    color = POINT_COLOR;
                LCD_WriteData_16Bit(color);
                ch <<= 1;

            }
        }
    }
}

/**

 *
 * @param   x,y		起点坐标
 * @param   width	字符显示宽度
 * @param   height	高度
 * @param   size	字体大小
 * @param   p		字符串首地址
 *
 * @return  void
 */
void LCD_ShowString(uint16_t x, uint16_t y, uint16_t width, uint16_t height, char *p) {
    uint8_t size = 16;
    uint8_t x0 = x;
    width += x;
    height += y;

    while ((*p <= '~') && (*p >= ' ')) //判断是否非法
    {
        if (x >= width) {
            x = x0;
            y += size;
        }

        if (y >= height)break; //退出

        LCD_ShowChar(x, y, *p);
        x += size / 2;
        p++;
    }
}