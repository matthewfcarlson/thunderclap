#include "decls/data/game/global.h"
// data: hulk_at_00400488 = DAT_00400488

#include "compat/ptr.h"
typedef unsigned int u32;
typedef unsigned long long u64_35da10;
extern "C" u64_35da10 __cdecl FUN_0027b020(const void*);
void FUN_0035da10() {
    u64_35da10 r = FUN_0027b020((const void*)((hulk_intptr)((char*)&DAT_00400488)));
    (*(u32*)&DAT_004de6f0) = (u32)r;
    (*(u32*)&DAT_004de6f4) = (u32)(r >> 32);
}
