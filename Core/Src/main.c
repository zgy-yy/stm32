#include <stdbool.h>
#include "stm32f10x.h"
#include "led.h"
#include "key.h"
#include "delay.h"

#include "pwm.h"

void main() {

    Pwm_init();


    while (true) {
        for (uint8_t i = 0; i <100; ++i) {
            Pwm_setCompare(i);
            Delay_ms(10);
        }
        for (uint8_t i = 0; i <100; ++i) {
            Pwm_setCompare(100-i);
            Delay_ms(10);
        }
    }
}


