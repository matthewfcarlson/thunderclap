// Same code shape as 0x001d1a50 (propagated; names are from that function)
#include "decls/data/lua.h"
#include "gen/owners.h"
typedef unsigned int u32_1d1ac0;
extern "C" void __cdecl FUN_00213340(LuaVMState*, float);
// member (include/gen/owners.h C_1d1ac0 +0x08) is the lua_State, an unsigned int member there; arg is the float's
// bits (an unsigned int parameter there): cast at the use.
bool owners::C_1d1ac0::FUN_001d1ac0(u32_1d1ac0 arg) {
    FUN_00213340((LuaVMState*)(hulk_uintptr)member, *(float*)&arg);
    return true;
}
