#include <gb/gb.h>
#include <stdlib.h>
#include "_global.h"
#include "enemy.h"
#include "sprites.h"

// projectile speed
int enemyLDX[ENEMY_MAX_PROJECTILES];
int enemyLDY[ENEMY_MAX_PROJECTILES];

// needs function for removing dead projectiles
void enemyShoot(void)
{
    // shoot every n frames
    if (!quit)
    {
        if (1)
        {
            for (int enemyshotIndex = 0; enemyshotIndex < ENEMY_MAX_PROJECTILES; enemyshotIndex++)
            {
                if (!enemyLS[enemyshotIndex])
                {
                    enemyLS[enemyshotIndex] = TRUE;
                    enemyLX[enemyshotIndex] = enemyX + 4;
                    enemyLY[enemyshotIndex] = enemyY + 20;
                    enemyLDY[enemyshotIndex] = 5 + rand() % 5;
                    enemyLDX[enemyshotIndex] = enemyshotIndex - 4;
                    break;
                }
            }
            enemyshot = 1;
        }
    }
    else if (quit)
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
            // move the projectile
            enemyLY[enemyshotIndex] += enemyLDY[enemyshotIndex];
            enemyLX[enemyshotIndex] += enemyLDX[enemyshotIndex];
            // disable if out of screen
            if (enemyLY[enemyshotIndex] < 0 || enemyLY[enemyshotIndex] > 170 || enemyLX[enemyshotIndex] < 0 || enemyLX[enemyshotIndex] > 170)
            {
                enemyLS[enemyshotIndex] = FALSE;
                // enemyLY[enemyshotIndex] = FALSE;
            }
        }
    }
}

void updateEnemyProjectiles(void)
{
    // update player projectiles
    for (int enemyshotIndex = 0; enemyshotIndex < ENEMY_MAX_PROJECTILES; enemyshotIndex++)
    {
        if (enemyLS[enemyshotIndex])
        {
            move_sprite(BASE_TILE_PROJECTILE + enemyshotIndex, enemyLX[enemyshotIndex], enemyLY[enemyshotIndex]);
        }
    }
}

void setEnemy(void)
{
    set_sprite_tile(21, 7);     // top left
    set_sprite_tile(22, 8);     // top
    set_sprite_tile(24, 10);    // top right

    set_sprite_tile(25, 11);
    set_sprite_tile(26, 12);

    set_sprite_tile(27, 13);
    set_sprite_tile(28, 14);
}
