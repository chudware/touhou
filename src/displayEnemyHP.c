#include <gb/gb.h>
#include "displayEnemyHP.h"

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