#include "cfassert.h"
#include "led.h"

void assertFail(char *exp, char *file, int line)
{
    ledSetRed(true);
    ledSetBlue(true);
    while (1)
    {
    }
}
