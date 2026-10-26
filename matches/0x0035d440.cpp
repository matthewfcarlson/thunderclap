#include "decls/data/game/global.h"
// data: hulk_at_0040048c = DAT_0040048c

#include "compat/ptr.h"
extern "C" unsigned long long __cdecl __fastload(hulk_intptr);
void FUN_0035d440() {
    (*(unsigned long long*)&DAT_004dde58) = __fastload(((hulk_intptr)((char*)&DAT_0040048c)));
}
