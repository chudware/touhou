#include <gb/gb.h>
#include "displayPlayerHP.h"

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