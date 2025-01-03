#include <gb/gb.h>
#include "displayHP.h"

void displayPlayerHP(void)
{
    set_sprite_prop(30, 2); // colors
    if (playerHP == 100)
    {
        set_sprite_tile(30, 2); // full
    }
    if (playerHP <= 99)
    {
        set_sprite_tile(30, 3); // mostly full
    }
    if (playerHP <= 50)
    {
        set_sprite_tile(30, 4); // half full
    }
    if (playerHP <= 25)
    {
        set_sprite_tile(30, 5); // mostly empty
    }
    move_sprite(30, 158, 18); // update hp
}

void displayEnemyHP(void)
{
    set_sprite_prop(31, 2); // colors
    if (enemyHP == 500)
    {
        set_sprite_tile(31, 2); // full
    }
    if (enemyHP <= 499)
    {
        set_sprite_tile(31, 3); // mostly full
    }
    if (enemyHP <= 250)
    {
        set_sprite_tile(31, 4); // half full
    }
    if (enemyHP <= 125)
    {
        set_sprite_tile(31, 5); // mostly empty
    }
    move_sprite(31, 10, 18); // update hp
}