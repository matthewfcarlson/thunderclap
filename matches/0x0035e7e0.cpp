#include "decls/address.h"
#include "decls/data/game/Render.h"
// data: gHigh_35e7e0 = DAT_004e233c
void FUN_0035e7e0() {
    unsigned long long r = FUN_0027b020("golfBall_golfBall");
    (*(unsigned int*)&DAT_004e2338) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e233c) = (unsigned int)(r >> 32);
}
