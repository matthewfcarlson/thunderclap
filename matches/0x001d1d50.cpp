#include "decls/data/lua.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s);
extern "C" void __cdecl FUN_00213800(LuaVMState* L, int idx);
// m (include/gen/owners.h Thing_1d1d50 +0x08) is the lua_State, a void* there, and a, b (key and value strings)
// are hulk_uintptr there: cast at the use.
bool owners::Thing_1d1d50::FUN_001d1d50(hulk_uintptr a, hulk_uintptr b) {
    FUN_002133d0((LuaVMState*)m, (const char*)a);
    FUN_002133d0((LuaVMState*)m, (const char*)b);
    FUN_00213800((LuaVMState*)m, -3);
    return true;
}
