#include "decls/data/game/Render.h"

struct Pair_35e800 {
    unsigned int lo;
    unsigned int hi;
};
extern "C" Pair_35e800 __cdecl FUN_0027b020(const char*);
void FUN_0035e800() {
    struct Pair_35e800 r = FUN_0027b020("hulk");
    (*(unsigned int*)&DAT_004e2330) = r.lo;
    (*(unsigned int*)&DAT_004e2334) = r.hi;
}
