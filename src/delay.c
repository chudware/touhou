#include <stdint.h>
#include "delay.h"

void performantdelay(uint8_t numloops)
{
    uint8_t i;
    for (i = 0; i < numloops; i++)
    {
        wait_vbl_done();
    }
}