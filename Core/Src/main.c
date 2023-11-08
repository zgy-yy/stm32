#include <stdbool.h>
#include <malloc.h>
#include "stm32f10x.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "pwm.h"
#include "usart.h"


int main() {

    Serial_init();
    Serial_sendByte(0x42);

    printf("hello，%0.2f",3.14);
    printf("你好、n");
    while (true) {

    }
}


