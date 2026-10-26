#include "decls/address.h"
#include "decls/data/game/unknown.h"
// data: gHash2 = DAT_004dd93c, gHash_35d1e0 = DAT_004dd938
void FUN_0035d1e0() {
    unsigned long long h = FUN_0027b020("golfBall_golfBall");
    (*(unsigned int*)&DAT_004dd938) = (unsigned int)h;
    (*(unsigned int*)&DAT_004dd93c) = (unsigned int)(h >> 32);
}