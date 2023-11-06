//
// Created by acer-zgy on 2023/11/6.
//

#ifndef STM32_LEARN01_PWM_H
#define STM32_LEARN01_PWM_H

#include "stm32f10x.h"

void Pwm_init();

void Pwm_setCompare(uint16_t);

void Servo_setAngle(float Angle);

#endif //STM32_LEARN01_PWM_H
