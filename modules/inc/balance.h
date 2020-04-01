#ifndef __BALANCE_H__
#define __BALANCE_H__

#include <stdbool.h>
#include <stm32f10x.h>

void balanceInit(void);
bool balanceTest(void);
void balanceStop(void);
void balanceRestart(void);


#endif
