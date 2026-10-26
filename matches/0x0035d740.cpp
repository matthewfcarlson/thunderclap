#include "decls/data/game/global.h"
// data: gValue = DAT_004ddfb8, hulk_at_0040048c = DAT_0040048c

#include "compat/ptr.h"
extern "C" __int64 __cdecl FUN_0027b020(hulk_intptr);
void __cdecl FUN_0035d740() {
    (*(__int64*)&DAT_004ddfb8) = FUN_0027b020(((hulk_intptr)((char*)&DAT_0040048c)));
}