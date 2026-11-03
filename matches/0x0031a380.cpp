#include "gen/owners.h"
void owners::Thing_31a380::FUN_0031a380(int p1, int p2, int p3, int p4, int p5) {
    mCopy = mVptr;
    a = p1;
    b = p3;
    c = p2;
    d = p4;
    e = p5;
    x[0] = 0;
    x[1] = 0;
    x[2] = 0;
    x[3] = 0;
    x[4] = 0;
    x[5] = 0;
    x[6] = 0;
    if ((p5 & 6) == 0)
        return;
    if (!(p5 & 4)) {
        u = 0x3f800000;
        v = 0;
        return;
    }
    if (p5 & 2)
        return;
    u = 0;
    v = 0x3f800000;
}