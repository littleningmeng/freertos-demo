#ifndef __COMMON_H__
#define __COMMON_H__

#include <stm32f10x.h>
#include <stdbool.h>

#define CONSTRAINT(v, min, max) do { \
        if((v) > (max)) { \
            v = max; \
        } else if ((v) < (min)) { \
            v = min; \
        } \
    }while(0)

void delay_us(uint32_t us);
void delay_ms(uint32_t ms);

#endif
