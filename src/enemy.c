#include <gb/gb.h>
#include "assets.h"
#include "enemy.h"

int enemyshotIndex;
int enemyshot;
int enemyLS[ENEMY_MAX_PROJECTILES];
int enemyLX[ENEMY_MAX_PROJECTILES]; // projectile x's
int enemyLY[ENEMY_MAX_PROJECTILES]; // projectile y's

void enemyShoot(void)
{
    if (joypad() & J_B)
    {
        if (1)
        {
            for (enemyshotIndex = 0; enemyshotIndex < ENEMY_MAX_PROJECTILES; enemyshotIndex++)
            {
                if (!enemyLS[enemyshotIndex])
                {
                    enemyLS[enemyshotIndex] = TRUE;
                    enemyLX[enemyshotIndex] = enemyX + 4;
                    enemyLY[enemyshotIndex] = enemyY;
                    break;
                }
            }
            enemyshot = 1;
        }
    }
    else if (!(joypad() & J_B))
    {
        enemyshot = 0;
    }
}

void moveEnemyProjectiles(void)
{
    for (int enemyshotIndex = 0; enemyshotIndex < ENEMY_MAX_PROJECTILES; enemyshotIndex++)
    {
        if (enemyLS[enemyshotIndex])
        {
            enemyLY[enemyshotIndex] += 10;
            if (enemyLY[enemyshotIndex] <= 0)
            {
                enemyLY[enemyshotIndex] = FALSE;
            }
        }
    }
}

void updateEnemyProjectiles(void)
{
    // update player projectiles
    for (enemyshotIndex = 0; enemyshotIndex < ENEMY_MAX_PROJECTILES; enemyshotIndex++)
    {
        if (enemyLS[enemyshotIndex])
        {
            move_sprite(BASE_TILE_PROJECTILE + enemyshotIndex, enemyLX[enemyshotIndex], enemyLY[enemyshotIndex]);
        }
    }
}