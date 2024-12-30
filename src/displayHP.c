#include <gb/gb.h>
#include "displayHP.h"

void displayPlayerHP(void)
{

    if (playerHP >= 100)
    {
        set_sprite_tile(30, 21); // full
    }
    if (playerHP <= 99)
    {
        set_sprite_tile(30, 20); // mostly full
    }
    if (playerHP <= 50)
    {
        set_sprite_tile(30, 19); // mostly full
    }
    if (playerHP <= 25)
    {
        set_sprite_tile(30, 18); // mostly full
    }
    if (playerHP <= 0)
    {
        set_sprite_tile(30, 17); // mostly full
    }

    move_sprite(30, 156, 20); // update hp
}

void displayEnemyHP(void)
{

    if (enemyHP == 500)
    {
        set_sprite_tile(29, 21); // full
    }
    if (enemyHP <= 375)
    {
        set_sprite_tile(29, 20); // mostly full
    }
    if (enemyHP <= 250)
    {
        set_sprite_tile(29, 19); // half full
    }
    if (enemyHP <= 125)
    {
        set_sprite_tile(29, 18); // mostly empty
    }
    if (enemyHP == 0)
    {
        set_sprite_tile(29, 17); // empty
    }

    move_sprite(29, 12, 20); // update hp
}