#include "common.h"
#include <math.h>

void delay_us(uint32_t us)
{
    volatile int32_t i;

    for(; us > 0; us--)
    {
        for(i = 9; i > 0; i--);
    }
}

void delay_ms(uint32_t ms)
{
    for(; ms > 0; ms--) 
    {
        delay_us(1000);
    }
}
