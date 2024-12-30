#include <gb/gb.h>
#include "_global.h"
#include "playerMovement.h"

void playerMovement(void)
{
  // player movement
  if (joypad() & J_RIGHT)
  {
    playerX += 1;
    if (playerX >= 152)
      playerX -= 1;
  }

  if (joypad() & J_LEFT)
  {
    playerX -= 1;
    if (playerX <= 8)
      playerX += 1;
  }

  if (joypad() & J_DOWN)
  {
    playerY += 1;
    if (playerY >= 144)
      playerY -= 1;
  }

  if (joypad() & J_UP)
  {
    playerY -= 1;
    if (playerY <= 16)
      playerY += 1;
  }
}