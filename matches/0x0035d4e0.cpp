#include "decls/data/game/global.h"
// data: hashA = DAT_004ddee0, hashB = DAT_004ddee4, hulk_at_00400488 = DAT_00400488

#include "compat/ptr.h"
extern "C" unsigned long long __cdecl FUN_0027b020(const void*);

void FUN_0035d4e0() {
    unsigned long long result = FUN_0027b020((const void*)((hulk_intptr)((char*)&DAT_00400488)));
    (*(unsigned int*)&DAT_004ddee0) = (unsigned int)result;
    (*(unsigned int*)&DAT_004ddee4) = (unsigned int)(result >> 32);
}
