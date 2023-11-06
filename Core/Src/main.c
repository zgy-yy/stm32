#include <stdbool.h>
#include "stm32f10x.h"
#include "led.h"
#include "key.h"
#include "delay.h"

#include "pwm.h"

void main() {

    Pwm_init();

    Pwm_setCompare(1000);
    while (true) {

    }
}


