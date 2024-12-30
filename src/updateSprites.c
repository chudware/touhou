#include <gb/gb.h>
#include "updateSprites.h"
#include "detectCollisions.h"


void updateSprites(void)
{
    // player
    move_sprite(1, playerX, playerY);
    move_sprite(2, playerX, playerY + 8);
    move_sprite(3, playerX + 8, playerY);
    move_sprite(4, playerX + 8, playerY + 8);

    // update player projectiles
    for (i = 0; i < MAX_PROJECTILES; i++)
    {
        if (ls[i])
        {
            move_sprite(BASE_TILE_PROJECTILE + i, lx[i], ly[i]);
        }
    }

    // update enemy
    move_sprite(21, enemyX, enemyY);
    move_sprite(22, enemyX, enemyY + 8 * 1);
    move_sprite(23, enemyX + 8, enemyY);
    move_sprite(24, enemyX + 8, enemyY + 8);
    move_sprite(25, enemyX, enemyY + 8 * 2);
    move_sprite(26, enemyX + 8, enemyY + 8 * 2);
    move_sprite(27, enemyX, enemyY + 8 * 3);
    move_sprite(28, enemyX + 8, enemyY + 8 * 3);
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