#include "decls/data/game/global.h"

struct Pair_35d8f0 {
    int lo;
    int hi;
};

extern Pair_35d8f0 __cdecl FUN_0027b020(const char*);


void __cdecl FUN_0035d8f0() {
    Pair_35d8f0 p = FUN_0027b020("Header");
    (*(int*)&DAT_004de670) = p.lo;
    (*(int*)((char*)&DAT_004de670 + 4)) = p.hi;
}
