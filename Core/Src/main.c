#include <stdbool.h>
#include "stm32f10x.h"
#include "led.h"
#include "key.h"
#include "exti.h"

void main() {

    led_init();
    key_init();
    exti_init();


    led_off();

    while (true) {


    }
}
