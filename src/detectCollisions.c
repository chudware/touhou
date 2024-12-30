#include "detectCollisions.h"

int detectCollisions(int x1, int y1, int x2, int y2, int size1, int size2) {
    int left1 = x1 - size1 / 2;
    int right1 = x1 + size1 / 2;
    int top1 = y1 - size1 / 2;
    int bottom1 = y1 + size1 / 2;

    int left2 = x2 - size2 / 2;
    int right2 = x2 + size2 / 2;
    int top2 = y2 - size2 / 2;
    int bottom2 = y2 + size2 / 2;

    return (left1 < right2 && right1 > left2 && top1 < bottom2 && bottom1 > top2);
}