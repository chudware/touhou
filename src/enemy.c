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

void setEnemy(int16_t *enemyX, int16_t *enemyY) {
    set_sprite_tile(21, 9);
    move_sprite(21, *enemyX, *enemyY);
    set_sprite_tile(22, 10);
    move_sprite(22, *enemyX, *enemyY + 8 * 1);
    set_sprite_tile(23, 11);
    move_sprite(23, *enemyX + 8, *enemyY);
    set_sprite_tile(24, 12);
    move_sprite(24, *enemyX + 8, *enemyY + 8);
    set_sprite_tile(25, 13);
    move_sprite(25, *enemyX, *enemyY + 8 * 2);
    set_sprite_tile(26, 15);
    move_sprite(26, *enemyX + 8, *enemyY + 8 * 2);
    set_sprite_tile(27, 14);
    move_sprite(27, *enemyX, *enemyY + 8 * 3);
    set_sprite_tile(28, 16);
    move_sprite(28, *enemyX + 8, *enemyY + 8 * 3);
}
