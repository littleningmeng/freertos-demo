#include "led.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdbool.h>
#include <stm32f10x_conf.h>

static bool isInit = false;

static GPIO_TypeDef* ledPorts[] = {
    LED_GPIO_RED_PORT,
    LED_GPIO_BLUE_PORT
};

static uint16_t ledPins[] = {
    LED_GPIO_RED,
    LED_GPIO_BLUE
};

//Initialize the green led pin as output
void ledInit(void)
{
    int i;
    GPIO_InitTypeDef GPIO_InitStructure;
    
    if(isInit)
    {
        return;
    }

    RCC_APB2PeriphClockCmd(LED_GPIO_RED_PERIF, ENABLE);
    RCC_APB2PeriphClockCmd(LED_GPIO_BLUE_PERIF | RCC_APB2Periph_AFIO, ENABLE);
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    for (i = 0; i < LED_NUM; i++)
    {
        GPIO_InitStructure.GPIO_Pin = ledPins[i];
        GPIO_Init(ledPorts[i], &GPIO_InitStructure);
        ledSet((led_t)i, true);
    }
    
    xTaskCreate(ledTask, (const signed char *)"workBlinkTask", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    isInit = true;
}

bool ledTest(void)
{
    return isInit;
}

void ledSet(led_t led, bool value)
{
    if ((int)led > LED_NUM)
    {
        return;
    }

    if(value)
    {
        GPIO_SetBits(ledPorts[led], ledPins[led]);
    }
    else
    {
        GPIO_ResetBits(ledPorts[led], ledPins[led]);
    }
}


void ledTask(void *param)
{
    while(1)
    {
        ledSetBlue(0);
        vTaskDelay(M2T(100));
        ledSetBlue(1);
        vTaskDelay(M2T(100));
    }
}

