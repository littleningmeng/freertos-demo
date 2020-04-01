#include "pm.h"
#include "config.h"
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include <stm32f10x_adc.h>
#include <stm32f10x_rcc.h>
#include <string.h>

static bool isInited = false;
static bool pmAdcInit(void);
static void pmPowerInit(void);


void pmInit()
{
    if(isInited)
    {
        return;
    }
    
    pmPowerInit();
    pmAdcInit();
    
    isInited = true;
}

static void pmPowerInit()
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(PM_POWER_RCC_PERIPH, ENABLE);
    GPIO_InitStructure.GPIO_Pin = PM_POWER_GPIO_PIN;
    GPIO_InitStructure.GPIO_Speed = PM_POWER_GPIO_SPEED;
    GPIO_InitStructure.GPIO_Mode = PM_POWER_GPIO_MODE;
    GPIO_Init(PM_POWER_GPIO, &GPIO_InitStructure);
    GPIO_SetBits(PM_POWER_GPIO, PM_POWER_GPIO_PIN);
}


static bool pmAdcInit()
{   
    return true;
}

bool pmTest()
{
    return isInited;
}

void pmPowerOff()
{
    GPIO_ResetBits(PM_POWER_GPIO, PM_POWER_GPIO_PIN);
}
