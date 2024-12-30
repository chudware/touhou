#include <stdbool.h>
#include <gb/gb.h>
#include "moveProjectiles.h"
#include "updateSprites.h"

void move_PROJECTILES(void)
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