#include <stdbool.h>
#include <gb/gb.h>
#include <time.h>
#include "_global.h"
#include "updateSprites.h"

int shootPlayerTicks = 0;
void shootPlayerProjectiles(void)
{
    if (joypad() & J_A)
    {
        if (shootPlayerTicks % 10 == 0)
        {
            for (i = 0; i < MAX_PROJECTILES; i++)
            {
                if (!ls[i])
                {
                    ls[i] = TRUE;
                    lx[i] = playerX + 4;
                    ly[i] = playerY;
                    break;
                }
            }
            playershot = 1;
        }
    }
    else if (!(joypad() & J_A))
    {
        playershot = 0;
    }
    shootPlayerTicks += 1;
}

void movePlayerProjectiles(void)
{
    for (int i = 0; i < MAX_PROJECTILES; i++)
    {
        if (ls[i])
        {
            ly[i] -= 10;
            if (ly[i] <= 0)
            {
                ls[i] = FALSE;
            }
        }
    }
}
