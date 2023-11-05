#include <stdbool.h>
#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "key.h"

void main() {

    led_init();
    key_init();
    led_off();

    uint8_t key_num = 0;

    while (true) {
        if (key_getNum() == 1) {
            led_turn();
        }

    }
}
