#include "decls/data/lua.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s);
extern "C" void __cdecl FUN_00213340(LuaVMState* L, float n);
extern "C" void __cdecl FUN_00213800(LuaVMState* L, int idx);
// member (include/gen/owners.h Obj_1d1d90 +0x08) is the lua_State, an int member there; a (the key string) is a
// hulk_intptr and b (the number, a float) an int there: cast at the use.
bool owners::Obj_1d1d90::FUN_001d1d90(hulk_intptr a, int b) {
    FUN_002133d0((LuaVMState*)(hulk_intptr)member, (const char*)a);
    FUN_00213340((LuaVMState*)(hulk_intptr)member, *(float*)&b);
    FUN_00213800((LuaVMState*)(hulk_intptr)member, -3);
    return true;
}
