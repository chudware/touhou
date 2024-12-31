#ifndef DETECTCOLLISIONS_H
#define DETECTCOLLISIONS_H

extern int playerX;
extern int playerY;
extern int playerHitBoxX;
extern int playerHitBoxY;
extern int enemyX;
extern int enemyY;
extern int playerSize;
extern int playerHitBoxSize;
extern int enemySize;
extern int playerHP;
extern int enemyHP;
extern int playerSpeed;
extern int ls[16];
extern int lx[16];
extern int ly[16];
extern int i;
extern int n;
extern int PROJECTILE_SIZE;

int detectCollisions(int x1, int y1, int x2, int y2, int size1, int size2);
void checkCol(void);
#endif
