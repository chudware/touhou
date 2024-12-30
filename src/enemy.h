#ifndef ENEMY_H
#define ENEMY_H

#define ENEMY_MAX_PROJECTILES 10 // Define the maximum number of enemy projectiles

// enemy
extern int enemyX;
extern int enemyY;
extern int enemyLS[ENEMY_MAX_PROJECTILES];
extern int enemyLX[ENEMY_MAX_PROJECTILES]; // projectile x's
extern int enemyLY[ENEMY_MAX_PROJECTILES]; // projectile y's

void enemyShoot(void);
void moveEnemyProjectiles(void);
void updateEnemyProjectiles(void);
void setEnemy(void);

extern int quit;

#endif
