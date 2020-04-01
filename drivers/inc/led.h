#ifndef __LED_H__
#define __LED_H__

#include <stdbool.h>
#include "config.h"
#include "stm32f10x_conf.h"
#include "FreeRTOS.h"

// RED  -- LED4
// BLUE -- LED3
#define LED_GPIO_RED_PERIF     RCC_APB2Periph_GPIOB
#define LED_GPIO_BLUE_PERIF    RCC_APB2Periph_GPIOB
#define LED_GPIO_RED_PORT      GPIOB
#define LED_GPIO_BLUE_PORT     GPIOB
#define LED_GPIO_RED           GPIO_Pin_5
#define LED_GPIO_BLUE          GPIO_Pin_4

#define LED_NUM 2

typedef enum {LED_RED = 0, LED_BLUE} led_t;

void ledInit(void);
bool ledTest(void);

// Procedures to set the status of the LEDs
void ledSet(led_t led, bool value);

void ledTask(void *param);

#define ledSetRed(VALUE)   ledSet(LED_RED, VALUE)
#define ledSetBlue(VALUE)  ledSet(LED_BLUE, VALUE);


#endif
