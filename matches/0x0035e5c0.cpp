#include "decls/data/game/global.h"

extern "C" struct Pair_35e5c0 {
    int lo;
    int hi;
};
extern "C" Pair_35e5c0 __cdecl FUN_0027b020(const char* s);
void FUN_0035e5c0() {
    Pair_35e5c0 r = FUN_0027b020("electric");
    (*(int*)&DAT_004e1808) = r.lo;
    (*(int*)&DAT_004e180c) = r.hi;
}
