#include "decls/data/game/DollyScript.h"
#include "decls/data/game/global.h"
// data: hulk_at_00400488 = DAT_00400488

#include "compat/ptr.h"
extern "C" unsigned long long FUN_0027b020(const void*);
void FUN_0035e0e0() {
    (*(unsigned long long*)&DAT_004e0a48) = FUN_0027b020((const void*)((hulk_intptr)((char*)&DAT_00400488)));
}
