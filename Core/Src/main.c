#include <stdbool.h>
#include "stm32f10x.h"
#include "led.h"
#include "key.h"
#include "exti.h"
#include "timmer.h"

void main() {

    led_init();
    key_init();
    exti_init();

    Timer_Init();
    led_off();

    while (true) {


    }
}


void TIM2_IRQHandler() {

    if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET) {

        led_turn();
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}