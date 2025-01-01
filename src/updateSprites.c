#include <gb/gb.h>
#include "updateSprites.h"
#include "collisions.h"

void updateSprites(void)
{
    // player
    move_sprite(1, playerX, playerY);
    move_sprite(2, playerX + 8 * 1, playerY);
    move_sprite(3, playerX + 8 * 2, playerY);

    move_sprite(4, playerX, playerY + 8 * 1);
    move_sprite(5, playerX + 8 * 1, playerY + 8 * 1);
    move_sprite(6, playerX + 8 * 2, playerY + 8 * 1);

    move_sprite(7, playerX, playerY + 8 * 2);
    move_sprite(8, playerX + 8 * 1, playerY + 8 * 2);
    move_sprite(9, playerX + 8 * 2, playerY + 8 * 2);

    // show hit-box
    if(playerIsFocus)
      move_sprite(10, playerHitBoxX, playerHitBoxY);
    else
      //how to un-show sprite?
      move_sprite(10, -1, -1);
    
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
    move_sprite(22, enemyX + 8 * 1, enemyY);
    move_sprite(23, enemyX + 8 * 2, enemyY);

    move_sprite(24, enemyX, enemyY + 8 * 1);
    move_sprite(25, enemyX + 8 * 1, enemyY + 8 * 1);
    move_sprite(26, enemyX + 8 * 2, enemyY + 8 * 1);

    move_sprite(27, enemyX, enemyY + 8 * 2);
    move_sprite(28, enemyX + 8 * 1, enemyY + 8 * 2);
    //move_sprite(29, enemyX + 8 * 3, enemyY + 8 * 2);
}
