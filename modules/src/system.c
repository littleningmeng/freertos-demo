#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "cfassert.h"
#include "system.h"
#include "led.h"
#include "balance.h"
#include "pm.h"
#include "balance.h"


static bool isInited = false;
/* System wide synchronisation */
static void systemTask(void *param);

void systemLaunch()
{
    ASSERT(xTaskCreate(systemTask, (const signed char *)"SYSTEM",
             configMINIMAL_STACK_SIZE, NULL, configMAX_PRIORITIES - 1,  NULL) == pdPASS);
}

void systemInit()
{
    if(isInited)
    {
        return;
    }
    pmInit();
    ledInit();
    balanceInit();
    isInited = true;
}

bool systemTest()
{
    bool pass = isInited;
    pass &= pmTest();
    pass &= ledTest();
    pass &= balanceTest();
    return pass;
}

void systemTask(void *param)
{
    systemInit();
    if(systemTest())
	{  
        while(1)
        {
            vTaskDelay(M2T(10000));
        }
    }
    else
    {

    }

    vTaskDelete(NULL);  /* NULL: delete myself */
}
