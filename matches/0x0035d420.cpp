#include "decls/data/game/global.h"
// data: hulk_at_00400488 = DAT_00400488

#include "compat/ptr.h"
extern "C" unsigned __int64 FUN_0027b020(hulk_uintptr);
void FUN_0035d420() {
    unsigned __int64 v = FUN_0027b020(((hulk_intptr)((char*)&DAT_00400488)));
    (*(unsigned int*)&DAT_004dde50) = (unsigned int)v;
    (*(unsigned int*)&DAT_004dde54) = (unsigned int)(v >> 32);
}
