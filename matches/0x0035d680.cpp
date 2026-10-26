#include "decls/data/game/global.h"
// data: hulk_at_00400488 = DAT_00400488, result = DAT_004ddf80

#include "compat/ptr.h"
extern "C" __int64 __cdecl FUN_0027b020(hulk_intptr);
void FUN_0035d680() {
    (*(__int64*)&DAT_004ddf80) = FUN_0027b020(((hulk_intptr)((char*)&DAT_00400488)));
}