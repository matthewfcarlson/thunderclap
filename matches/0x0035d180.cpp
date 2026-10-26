#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
// data: hulk_at_0040048c = DAT_0040048c

#include "compat/ptr.h"
struct Pair_35d180 {
    unsigned int lo;
    unsigned int hi;
};
extern Pair_35d180 __cdecl FUN_0027b020(void*);

void __cdecl FUN_0035d180() {
    Pair_35d180 p = FUN_0027b020((void*)((hulk_intptr)((char*)&DAT_0040048c)));
    (*(unsigned int*)&DAT_004dd900) = p.lo;
    (*(unsigned int*)&DAT_004dd904) = p.hi;
}
