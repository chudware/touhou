#include <gb/gb.h>
#include "playerMovement.h"

void playerMovement(int16_t *playerX, int16_t *playerY)
{
    // player movement
    if (joypad() & J_RIGHT)
    {
        *playerX += 1;
    }
    if (joypad() & J_LEFT)
    {
        *playerX -= 1;
    }
    if (joypad() & J_DOWN)
    {
        *playerY += 1;
    }
    if (joypad() & J_UP)
    {
        *playerY -= 1;
    }
}

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