#include "decls/data/game/global.h"
// data: gResult_35dc30 = DAT_004de7f0, hulk_at_00400488 = DAT_00400488

#include "compat/ptr.h"
extern "C" unsigned __int64 __cdecl FUN_0027b020(const void*);
void __cdecl FUN_0035dc30() {
    (*(unsigned __int64*)&DAT_004de7f0) = FUN_0027b020((const void*)((hulk_intptr)((char*)&DAT_00400488)));
}
