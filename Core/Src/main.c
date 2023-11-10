#include <stdbool.h>
#include <malloc.h>
#include "stm32f10x.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "pwm.h"
#include "usart.h"
#include "Lcd.h"
#include "Gui.h"


int main() {

    Serial_init();

    Lcd_Init();
    Lcd_Clear(WHITE);

    LCD_ShowString(0, 0, 16*8, 16*10,"HELLO WORLD nihao");

    while (true) {
        Delay_ms(5);
    }
}


