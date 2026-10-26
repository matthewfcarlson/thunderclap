#include "decls/data/game/global.h"

struct Pair_35c6e0 {
    int lo;
    int hi;
};
extern "C" Pair_35c6e0 FUN_0027b020(const char*);
void FUN_0035c6e0() {
    Pair_35c6e0 x = FUN_0027b020("golfBall_golfBall");
    (*(int*)&DAT_004dc030) = x.lo;
    (*(int*)((char*)&DAT_004dc030 + 4)) = x.hi;
}
