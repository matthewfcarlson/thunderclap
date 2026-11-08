#include "decls/data/lua.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s);
extern "C" void __cdecl FUN_00213520(LuaVMState* L, int b);
extern "C" void __cdecl FUN_00213800(LuaVMState* L, int idx);
// member (include/gen/owners.h Obj_1d1e10 +0x08) is the lua_State, a void* there, and a (the key string) a
// hulk_intptr there: cast at the use.
bool owners::Obj_1d1e10::FUN_001d1e10(hulk_intptr a, unsigned char b) {
    FUN_002133d0((LuaVMState*)member, (const char*)a);
    FUN_00213520((LuaVMState*)member, b);
    FUN_00213800((LuaVMState*)member, -3);
    return true;
}
