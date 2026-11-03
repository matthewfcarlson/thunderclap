// Same code shape as 0x0033b970 (propagated; names are from that function)
#include "decls/data/game/unknown.h"
// data: gScale_33b9a0 = DAT_003f32b8

extern "C" float __cdecl FUN_00339ec0(void*, int);
extern "C" void __cdecl FUN_00213340(void*, float);
extern "C" int __cdecl FUN_0033b9a0(void* L) {
    FUN_00213340(L, FUN_00339ec0(L, 1) * DAT_003f32b8);
    return 1;
}