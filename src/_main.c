#include <gb/gb.h>
#include <stdio.h>
#include <time.h>
#include "_global.h"
#include "bg.h"
#include "assets.h"
#include "playerMovement.h"
#include "playerProjectiles.h"
#include "enemy.h"
#include "displayHP.h"
#include "collisions.h"
#include "updateSprites.h"

int quit = 0;
int resetTicks = 0;

void resetGame(void)
{
  resetTicks = 0;
    
  //reset health
  playerHP = 100;
  enemyHP = 100;
  
  // sets bg
  set_bkg_data(0, 23, assetsTileLabel);
  set_bkg_tiles(0, 0, bgTilemapWidth, bgTilemapHeight, bgTilemap);
  SHOW_BKG;

  // set sprites 8x8 mode
  SPRITES_8x8;

  // player sprites
  set_sprite_data(1, 23, assetsTileLabel);

  set_sprite_tile(1, 1);
  set_sprite_tile(2, 2);
  set_sprite_tile(3, 3);
  set_sprite_tile(4, 4);

  // set projectile sprites
  for (i = 5; i < MAX_PROJECTILES; i++)
    { // id 5 to MAX_PROJECTILES
      set_sprite_tile(i, 5);
    }
  // spawns boss/enemy
  setEnemy(&enemyX, &enemyY);
  SHOW_SPRITES;
  DISPLAY_ON;
}

void main(void)
{
  resetGame();
  while (!quit)
    {
      if(playerHP != 0 && enemyHP != 0) {
	scroll_bkg(0, -1);

	// player
	displayPlayerHP(&playerHP);
	shootPlayerProjectiles();
	movePlayerProjectiles();
	playerMovement(&playerX, &playerY);
	limitPlayer(&playerX, &playerY);

	// enemy
	displayEnemyHP(&enemyHP);
	enemyShoot();
	moveEnemyProjectiles();
	updateEnemyProjectiles();

	// check for collision and update sprites
	checkCol();
	updateSprites();
	delay(10); // vsync();
      } else {
	if (playerHP == 0)
	  {
	    printf("you died");
	  }
	if (enemyHP == 0)
	  {
	    printf("enemy died");
	  }
	resetTicks++;
	if(resetTicks > 120) {
	  delay(10);
	  resetGame();
	}
      }
    }
}
