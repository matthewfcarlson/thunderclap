#include "decls/data/game/DollyScript.h"
#include "decls/data/game/global.h"
// data: hulk_at_0040048c = DAT_0040048c

#include "compat/ptr.h"
struct Pair_35e100 {
    int a, b;
};
extern "C" Pair_35e100 __cdecl FUN_0027b020(hulk_intptr);
void __cdecl FUN_0035e100() {
    Pair_35e100 r = FUN_0027b020(((hulk_intptr)((char*)&DAT_0040048c)));
    (*(int*)&DAT_004e0a50) = r.a;
    (*(int*)&DAT_004e0a54) = r.b;
}
