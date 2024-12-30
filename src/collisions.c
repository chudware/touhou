#include "collisions.h"
#include <gb/gb.h>

int detectCollisions(int x1, int y1, int x2, int y2, int size1, int size2) {
    int left1 = x1 - size1 / 2;
    int right1 = x1 + size1 / 2;
    int top1 = y1 - size1 / 2;
    int bottom1 = y1 + size1 / 2;

    int left2 = x2 - size2 / 2;
    int right2 = x2 + size2 / 2;
    int top2 = y2 - size2 / 2;
    int bottom2 = y2 + size2 / 2;

    return (left1 < right2 && right1 > left2 && top1 < bottom2 && bottom1 > top2);
}

void checkCol(void)
{
    // Check player-enemy collision
    if (detectCollisions(playerX, playerY, enemyX, enemyY, playerSize, enemySize))
    {
        playerHP -= playerSpeed;
    }

    // Check projectile-enemy collisions
    for (int i = 0; i < MAX_PROJECTILES; i++)
    {
        if (ls[i])
        {
            if (detectCollisions(lx[i], ly[i], enemyX, enemyY, PROJECTILE_SIZE, enemySize))
            {
                // check player enemy-collision
                ls[i] = FALSE; // disable projectile
                enemyHP -= 1;
            }
        }
    }

    // Check  collisions
    for (int enemyshotIndex = 0; enemyshotIndex < ENEMY_MAX_PROJECTILES; enemyshotIndex++)
    {
        if (enemyLS[enemyshotIndex])
        {
            if (detectCollisions(enemyLX[enemyshotIndex], enemyLY[enemyshotIndex], playerX, playerY, PROJECTILE_SIZE, playerSize))
            {
                // check -collision
                enemyLS[enemyshotIndex] = FALSE; // disable projectile
                playerHP -= 1;
            }
        }
    }
}