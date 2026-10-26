#include "decls/data/game/global.h"

struct Pair_35d8f0 {
    int lo;
    int hi;
};

extern Pair_35d8f0 __cdecl Lookup(const char*);


void __cdecl FUN_0035d8f0() {
    Pair_35d8f0 p = Lookup("Header");
    (*(int*)&DAT_004de670) = p.lo;
    (*(int*)((char*)&DAT_004de670 + 4)) = p.hi;
}
