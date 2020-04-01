#include "config.h"
#include "FreeRTOS.h"
#include "task.h"
#include "cfassert.h"
#include "system.h"

int main()
{
    systemLaunch();
    vTaskStartScheduler();
    ASSERT(0);
}

