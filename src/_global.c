#include "_global.h"

#define ENEMY_MAX_PROJECTILES 10 // Define the maximum number of enemy projectiles

// player
int playerX;
int playerY;
int playerHP;
int playerSize = 16;
int playershot;
int playerSpeed = 1;
int i;
int n;
int PROJECTILE_SIZE = 8;
int ls[MAX_PROJECTILES];
int lx[MAX_PROJECTILES]; // projectile x's
int ly[MAX_PROJECTILES]; // projectile y's

// enemy
int enemyX = 80;
int enemyY = 20;
int enemyHP;
int enemySize = 16;
int enemyshot;
int enemyshotIndex;
int enemyLS[ENEMY_MAX_PROJECTILES];
int enemyLX[ENEMY_MAX_PROJECTILES]; // projectile x's
int enemyLY[ENEMY_MAX_PROJECTILES]; // projectile y's
