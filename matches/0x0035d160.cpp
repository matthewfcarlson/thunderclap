#include "compat/ptr.h"
#include "decls/address.h"
extern "C" char hulk_at_00400488[];
typedef unsigned int uint32;
typedef unsigned long long uint64;
extern uint32 gA_35d160;
extern uint32 gB_35d160;
void __cdecl FUN_0035d160() {
    uint64 r = FUN_0027b020((const char*)((hulk_intptr)hulk_at_00400488));
    gA_35d160 = (uint32)r;
    gB_35d160 = (uint32)(r >> 32);
}
