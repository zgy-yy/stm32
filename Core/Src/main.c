#include <stdbool.h>
#include "stdio.h"
#include "delay.h"
#include "pwm.h"
#include "usart.h"
#include "Lcd.h"
#include "Gui.h"
#include "Ic.h"
#include "Adc.h"

int main() {

    Serial_init();
    Adc_init();


    Lcd_Init();
    Lcd_Clear(RED);


    uint16_t data = 0;
    while (true) {
        data = Adc_getValue();
        lcd_printf(0, 0, "adc=%d", data);

        Delay_ms(100);
    }
}


