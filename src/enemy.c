#include <gb/gb.h>
#include <stdlib.h>
#include "_global.h"
#include "assets.h"
#include "enemy.h"

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
    set_sprite_tile(21, 9);
    move_sprite(21, enemyX, enemyY);
    set_sprite_tile(22, 10);
    move_sprite(22, enemyX, enemyY + 8 * 1);
    set_sprite_tile(23, 11);
    move_sprite(23, enemyX + 8, enemyY);
    set_sprite_tile(24, 12);
    move_sprite(24, enemyX + 8, enemyY + 8);
    set_sprite_tile(25, 13);
    move_sprite(25, enemyX, enemyY + 8 * 2);
    set_sprite_tile(26, 15);
    move_sprite(26, enemyX + 8, enemyY + 8 * 2);
    set_sprite_tile(27, 14);
    move_sprite(27, enemyX, enemyY + 8 * 3);
    set_sprite_tile(28, 16);
    move_sprite(28, enemyX + 8, enemyY + 8 * 3);
}
