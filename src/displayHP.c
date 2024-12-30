#include <gb/gb.h>
#include "displayHP.h"

void displayPlayerHP(int *playerHP)
{

    if (*playerHP >= 100)
    {
        set_sprite_tile(30, 21); // full
    }
    if (*playerHP <= 99)
    {
        set_sprite_tile(30, 20); // mostly full
    }
    if (*playerHP <= 50)
    {
        set_sprite_tile(30, 19); // mostly full
    }
    if (*playerHP <= 25)
    {
        set_sprite_tile(30, 18); // mostly full
    }
    if (*playerHP <= 0)
    {
        set_sprite_tile(30, 17); // mostly full
    }

    move_sprite(30, 156, 20); // update hp
}

void displayEnemyHP(int *enemyHP)
{

    if (*enemyHP == 100)
    {
        set_sprite_tile(29, 21); // full
    }
    if (*enemyHP <= 99)
    {
        set_sprite_tile(29, 20); // mostly full
    }
    if (*enemyHP <= 50)
    {
        set_sprite_tile(29, 19); // mostly full
    }
    if (*enemyHP <= 25)
    {
        set_sprite_tile(29, 18); // mostly full
    }
    if (*enemyHP <= 0)
    {
        set_sprite_tile(29, 17); // mostly full
    }

    move_sprite(29, 12, 20); // update hp
}