#include <gb/gb.h>
#include "_global.h"
#include "playerMovement.h"

void playerMovement(void)
{
  // focus
  if(joypad() & J_B)
    {
      playerSpeed = 1;
      playerIsFocus = 1;
    }
  else
    {
      playerSpeed = 2;
      playerIsFocus = 0;
    }
  
   // player movement
  if (joypad() & J_RIGHT)
  {
    playerX += playerSpeed;
    if (playerX >= 152)
      playerX -= playerSpeed;
  }

  if (joypad() & J_LEFT)
  {
    playerX -= playerSpeed;
    if (playerX <= 8)
      playerX += playerSpeed;
  }

  if (joypad() & J_DOWN)
  {
    playerY += playerSpeed;
    if (playerY >= 144)
      playerY -= playerSpeed;
  }

  if (joypad() & J_UP)
  {
    playerY -= playerSpeed;
    if (playerY <= 16)
      playerY += playerSpeed;
  }

  // move the hitbox
  playerHitBoxX = playerX + playerHitBoxOffset;
  playerHitBoxY = playerY + playerHitBoxOffset;
}
