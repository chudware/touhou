#include <gb/gb.h>
#include "sound.h"

void playSound(void)
{
    NR10_REG = 0x06;
    NR11_REG = 0x50;
    NR12_REG = 0x22;
    NR13_REG = 0x10;
    NR14_REG = 0xB3;
}