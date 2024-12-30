#ifndef UPDATESPRITES_H
#define UPDATESPRITES_H

#define BASE_TILE_PROJECTILE 5 // sets starter tile id (after 1 - 4 for player)
#define MAX_PROJECTILES 16

#define ENEMY_MAX_PROJECTILES 10 // Define the maximum number of enemy projectiles
extern int PROJECTILE_SIZE;
extern int ls[MAX_PROJECTILES];
extern int lx[MAX_PROJECTILES]; // projectile x's
extern int ly[MAX_PROJECTILES]; // projectile y's
extern int enemyLS[ENEMY_MAX_PROJECTILES];
extern int enemyLX[ENEMY_MAX_PROJECTILES]; // projectile x's
extern int enemyLY[ENEMY_MAX_PROJECTILES]; // projectile y's
extern int i;
extern int playerHP;
extern int enemyHP;
extern int playerSpeed;
extern int playerX;
extern int playerY;
extern int playerSize;
extern int enemySize;
extern int enemyX;
extern int enemyY;

void updateSprites(void);

void checkCol(void);

#endif