#ifndef ENEMY_H
#define ENEMY_H


#define ENEMY_MAX_PROJECTILES 10 // Define the maximum number of enemy projectiles

extern int enemyX;
extern int enemyY;
extern int enemyLS[ENEMY_MAX_PROJECTILES];
extern int enemyLX[ENEMY_MAX_PROJECTILES]; // projectile x's
extern int enemyLY[ENEMY_MAX_PROJECTILES]; // projectile y's

// enemy projectiles
#define BASE_TILE_PROJECTILE 5

void enemyShoot(void);
void moveEnemyProjectiles(void);
void updateEnemyProjectiles(void);
void setEnemy(int16_t *enemyX, int16_t *enemyY);
#endif