#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
// data: hulk_at_00400488 = DAT_00400488

#include "compat/ptr.h"
#include "decls/address.h"
typedef unsigned int uint32;
typedef unsigned long long uint64;
void __cdecl FUN_0035d160() {
    uint64 r = FUN_0027b020((const char*)((hulk_intptr)((char*)&DAT_00400488)));
    (*(uint32*)&DAT_004dd8f8) = (uint32)r;
    (*(uint32*)&DAT_004dd8fc) = (uint32)(r >> 32);
}
