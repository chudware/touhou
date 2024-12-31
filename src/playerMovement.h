#ifndef PLAYERMOVEMENT_H
#define PLAYERMOVEMENT_H

extern int playerX;
extern int playerY;
extern int playerSpeed;
extern int playerHitBoxSize;
extern int playerHitBoxOffset;
extern int playerHitBoxX;
extern int playerHitBoxY;
extern int playerIsFocus;

void playerMovement();
void limitPlayer();

#endif 
