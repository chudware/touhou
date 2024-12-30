#include <gb/gb.h>
#include <stdint.h>
#include "setEnemy.h"

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
