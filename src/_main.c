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
#include "backgroundData.h"
#include "backgroundMap.h"

const UWORD backgroundpalette[] = {
    /* Gameboy Color palette 0 */
    backgroundDataCGBPal0c0,
    backgroundDataCGBPal0c1,
    backgroundDataCGBPal0c2,
    backgroundDataCGBPal0c3,

    /* Gameboy Color palette 1 */
    backgroundDataCGBPal1c0,
    backgroundDataCGBPal1c1,
    backgroundDataCGBPal1c2,
    backgroundDataCGBPal1c3,

    /* Gameboy Color palette 2 */
    backgroundDataCGBPal2c0,
    backgroundDataCGBPal2c1,
    backgroundDataCGBPal2c2,
    backgroundDataCGBPal2c3,

    /* Gameboy Color palette 3 */
    backgroundDataCGBPal3c0,
    backgroundDataCGBPal3c1,
    backgroundDataCGBPal3c2,
    backgroundDataCGBPal3c3,
};

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

    /* Gameboy Color palette 3 */
    spritesCGBPal3c0,
    spritesCGBPal3c1,
    spritesCGBPal3c2,
    spritesCGBPal3c3,

    /* Gameboy Color palette 4 */
    spritesCGBPal4c0,
    spritesCGBPal4c1,
    spritesCGBPal4c2,
    spritesCGBPal4c3,

    /* Gameboy Color palette 5 */
    spritesCGBPal5c0,
    spritesCGBPal5c1,
    spritesCGBPal5c2,
    spritesCGBPal5c3,

    /* Gameboy Color palette 6 */
    spritesCGBPal6c0,
    spritesCGBPal6c1,
    spritesCGBPal6c2,
    spritesCGBPal6c3,
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

  set_bkg_palette(0, 4, &backgroundpalette[0]);

  // set background data
  set_bkg_data(0, 2, backgroundData);

  // switch to 2nd video memory bank
  VBK_REG = 1;

  // set background color palette map, do this first
  set_bkg_tiles(0, 0, backgroundMapWidth, backgroundMapHeight, backgroundMapPLN1);

  // switch back to 1st video memory bank
  VBK_REG = 0;

  // set background map
  set_bkg_tiles(0, 0, backgroundMapWidth, backgroundMapHeight, backgroundMapPLN0);

  set_sprite_palette(0, 1, &spritepalette[0]);

  // set sprites 8x8 mode
  SPRITES_8x8;

  // player sprites
  set_sprite_palette(1, 7, &spritepalette[0]);
  set_sprite_data(1, 26, sprites);

  // top left
  set_sprite_prop(1, 2);
  set_sprite_tile(1, 16);
  // top center
  set_sprite_prop(2, 2);
  set_sprite_tile(2, 17);
  // top right
  set_sprite_prop(3, 2);
  set_sprite_tile(3, 18);

  // center left
  set_sprite_prop(4, 7);
  set_sprite_tile(4, 19);

  // center
  set_sprite_prop(5, 7);
  set_sprite_tile(5, 20);

  // center right
  set_sprite_prop(6, 7);
  set_sprite_tile(6, 21);

  // bottom left
  set_sprite_prop(7, 4);
  set_sprite_tile(7, 22);

  // bottom center
  set_sprite_prop(8, 4);
  set_sprite_tile(8, 23);

  // bottom right
  set_sprite_prop(9, 4);
  set_sprite_tile(9, 24);

  // set projectile sprites
  for (i = 10; i < MAX_PROJECTILES; i++) // moved i from 5 to 10
  {                                      // id 5 to MAX_PROJECTILES
    set_sprite_tile(i, 6);
    set_sprite_prop(i, 6); // set projectile color to cyan
  }

  // spawns boss/enemy
  setEnemy();

  SHOW_BKG;
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