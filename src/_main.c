#include <gb/gb.h>
#include <gb/cgb.h>
#include <stdio.h>
#include <time.h>
#include "_global.h"
#include "playerMovement.h"
#include "playerProjectiles.h"
#include "enemy.h"
#include "displayHP.h"
#include "collisions.h"
#include "updateSprites.h"
#include "sprites.h"

const UWORD backgroundpalette[] = {
    RGB_SKYBLUE, RGB_LIGHTGRAY, RGB_LIGHTGRAY, RGB_LIGHTGRAY};

const UWORD spritepalette[] = {
    /* Gameboy Color palette 0 */
    spritesCGBPal0c0,
    spritesCGBPal0c1,
    spritesCGBPal0c2,
    spritesCGBPal0c3,

    /* Gameboy Color palette 1 */
    spritesCGBPal1c0,
    spritesCGBPal1c1,
    spritesCGBPal1c2,
    spritesCGBPal1c3,

    /* Gameboy Color palette 2 */
    spritesCGBPal2c0,
    spritesCGBPal2c1,
    spritesCGBPal2c2,
    spritesCGBPal2c3,
};

int quit = 0;
int resetTicks = 0;

void resetGame()
{
  resetTicks = 0;

  // reset health
  playerHP = 100;
  enemyHP = 500;

  // reset player position
  playerX = 76;
  playerY = 128;

  set_bkg_palette(0, 1, &backgroundpalette[0]);

  // set_sprite_prop(0, 0); // solors

  // sets bg
  set_sprite_palette(0, 1, &spritepalette[0]);
  set_bkg_data(0, 20, sprites);

  // set_bkg_tiles(0, 0, 20, 18, bgTilemap);
  SHOW_BKG;

  // set sprites 8x8 mode
  SPRITES_8x8;

  // player sprites
  set_sprite_palette(1, 3, &spritepalette[0]);
  set_sprite_data(1, 24, sprites);

  set_sprite_tile(1, 16);
  set_sprite_tile(2, 17);
  set_sprite_tile(3, 18);

  set_sprite_tile(4, 19);
  set_sprite_tile(5, 20);
  set_sprite_tile(6, 21);

  set_sprite_tile(7, 22);
  set_sprite_tile(8, 23);
  set_sprite_tile(9, 24);

  // set projectile sprites
  for (i = 10; i < MAX_PROJECTILES; i++) // moved i from 5 to 10
  {                                      // id 5 to MAX_PROJECTILES
    set_sprite_tile(i, 6);
    set_sprite_prop(i, 2);
  }

  // spawns boss/enemy
  setEnemy();
  SHOW_SPRITES;
  DISPLAY_ON;
}

void main(void)
{
  resetGame();
  while (!quit)
  {
    if (playerHP != 0 && enemyHP != 0)
    {
      scroll_bkg(0, -1);

      // player
      displayPlayerHP();
      shootPlayerProjectiles();
      movePlayerProjectiles();
      playerMovement();

      // enemy
      displayEnemyHP();
      enemyShoot();
      moveEnemyProjectiles();
      updateEnemyProjectiles();

      // check for collision and update sprites
      checkCol();
      updateSprites();
      delay(10); // vsync();
    }
    else
    {
      if (playerHP == 0)
      {
        printf("YOU DIED");
      }
      if (enemyHP == 0)
      {
        printf("THE ENEMY DIED");
      }
      resetTicks++;
      if (resetTicks > 120)
      {
        delay(10);
        resetGame();
      }
    }
  }
}