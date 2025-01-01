#ifndef UPDATESPRITES_H
#define UPDATESPRITES_H

#define BASE_TILE_PROJECTILE 10 // sets starter tile id (after 1 - 4 for player)
#define MAX_PROJECTILES 16

// player
extern int playerSpeed;
extern int playerX;
extern int playerY;
extern int playerIsFocus;
extern int playerSize;
extern int PROJECTILE_SIZE;
extern int i;
extern int playerHP;
extern int ls[MAX_PROJECTILES];
extern int lx[MAX_PROJECTILES]; // projectile x's
extern int ly[MAX_PROJECTILES]; // projectile y's

// enemy
extern int enemyHP;
extern int enemySize;
extern int enemyX;
extern int enemyY;

void updateSprites(void);

#endif
