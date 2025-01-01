#include "_global.h"

#define ENEMY_MAX_PROJECTILES 10 // Define the maximum number of enemy projectiles

// player
int playerX;
int playerY;
int playerHitBoxX;
int playerHitBoxY;
int playerHP;
int playerSize = 24;
int playerHitBoxSize = 2;
// where to place the hitbox relative to the player sprite
// this seems fine
int playerHitBoxOffset = (24-8)/2;
// true if player is pressing focus
int playerIsFocus = 0;
int playershot;
int playerSpeed = 1;
int i;
int n;
int PROJECTILE_SIZE = 8;
int ls[MAX_PROJECTILES];
int lx[MAX_PROJECTILES]; // projectile x's
int ly[MAX_PROJECTILES]; // projectile y's

// enemy
int enemyX = 79;    // enemy sprite in not centered in assets.gbr thus the odd number
int enemyY = 20;
int enemyHP;
int enemySize = 24;
int enemyshot;
int enemyshotIndex;
int enemyLS[ENEMY_MAX_PROJECTILES];
int enemyLX[ENEMY_MAX_PROJECTILES]; // projectile x's
int enemyLY[ENEMY_MAX_PROJECTILES]; // projectile y's
