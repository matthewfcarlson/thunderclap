#include "decls/data/game/global.h"
// data: gFirst_35d5c0 = DAT_004ddf48, gSecond_35d5c0 = DAT_004ddf4c, hulk_at_0040048c = DAT_0040048c

#include "compat/ptr.h"
struct Pair_35d5c0 {
    int a;
    int b;
};
Pair_35d5c0 __cdecl FUN_0027b020(int*);
void FUN_0035d5c0() {
    Pair_35d5c0 p = FUN_0027b020((int*)((hulk_intptr)((char*)&DAT_0040048c)));
    (*(int*)&DAT_004ddf48) = p.a;
    (*(int*)&DAT_004ddf4c) = p.b;
}