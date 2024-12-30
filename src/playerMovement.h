#ifndef PLAYERMOVEMENT_H
#define PLAYERMOVEMENT_H

#include <stdint.h>

void playerMovement(int16_t *playerX, int16_t *playerY);
void limitPlayer(int16_t *playerX, int16_t *playerY);
#endif 