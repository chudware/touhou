#include <stdint.h>
#include "limitPlayer.h"

void limitPlayer(int16_t *playerX, int16_t *playerY)
{
    if (*playerX < 8)
    {
        *playerX++;
    }
    if (*playerX > 152)
    {
        *playerX--;
    }
    if (*playerY < 16)
    {
        *playerY++;
    }
    if (*playerY > 144)
    {
        *playerY--;
    }
}