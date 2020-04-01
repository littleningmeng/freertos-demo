#include "balance.h"
#include "kalman.h"
#include "config.h"
#include "cfassert.h"
#include "led.h"
#include "common.h"
#include "system.h"
#include "FreeRTOS.h"
#include "task.h"
#include <string.h>
#include <math.h>

static bool isInited = false;
static void balanceTask(void *param);


void balanceInit()
{
    if(isInited)
    {
        return;
    }

    ASSERT(xTaskCreate(balanceTask, (const signed char *)"balanceTask", configMINIMAL_STACK_SIZE,
        NULL, STABILIZER_TASK_PRIORITY, NULL) == pdPASS);

    isInited = true;
}

bool balanceTest()
{
    bool pass = isInited;
    return pass;
}


static void balanceTask(void *param)
{
    while(1)
    {
        ledSetRed(0);
        vTaskDelay(M2T(200));
        ledSetRed(1);
        vTaskDelay(M2T(200));
    }
}
