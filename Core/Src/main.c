#include "stm32f10x.h"
#include "led.h"

void main() {

    led_init();
    led_on();

    while (1) {

    }
}
