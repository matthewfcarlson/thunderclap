#include "decls/data/game/global.h"
// data: hulk_at_0040048c = DAT_0040048c, result = DAT_004de9a0

#include "compat/ptr.h"
extern "C" __int64 __cdecl FUN_0027b020(hulk_intptr);
void FUN_0035de80() {
    (*(__int64*)&DAT_004de9a0) = FUN_0027b020(((hulk_intptr)((char*)&DAT_0040048c)));
}