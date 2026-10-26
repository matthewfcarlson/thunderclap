#include "decls/address.h"
#include "decls/data/game/global.h"
void FUN_0035d260() {
    unsigned long long r = FUN_0027b020("golfBall_golfBall");
    (*(int*)&DAT_004dda00) = (int)r;
    (*(int*)&DAT_004dda04) = (int)(r >> 32);
}
