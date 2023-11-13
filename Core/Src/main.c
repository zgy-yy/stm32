#include <stdbool.h>
#include "stdio.h"
#include "delay.h"
#include "pwm.h"
#include "usart.h"
#include "Lcd.h"
#include "Gui.h"
#include "Ic.h"
#include "Adc.h"

#include "Dma.h"
#include "Infrared.h"

int main() {
    Serial_init();


    Lcd_Init();
    Lcd_Clear(RED);


    while (true) {
    // printf("%d\n", DAC_GetDataOutputValue(DAC_Channel_1));
        Delay_ms(100);
    }
}
