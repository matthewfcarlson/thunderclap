// Same code shape as 0x000238b0 (propagated; names are from that function)
#include "gen/owners.h"
typedef unsigned int U_1ab0e0;
typedef unsigned __int64 U64_1ab0e0;
extern U64_1ab0e0 __cdecl FUN_0027b020(U_1ab0e0);
hulk_intptr owners::Obj_1ab0e0::FUN_001ab0e0(hulk_uintptr param) {
    U64_1ab0e0 a = FUN_0027b020(((U_1ab0e0)param));
    return Second(a);
}