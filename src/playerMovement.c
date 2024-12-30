#include <gb/gb.h>
#include "playerMovement.h"

void playerMovement(int16_t *playerX, int16_t *playerY) {
    // player movement
    if (joypad() & J_RIGHT) {
        *playerX += 1;
    }
    if (joypad() & J_LEFT) {
        *playerX -= 1;
    }
    if (joypad() & J_DOWN) {
        *playerY += 1;
    }
    if (joypad() & J_UP) {
        *playerY -= 1;
    }
}
