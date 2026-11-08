#include "decls/data/lua.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s);
extern "C" void __cdecl FUN_00213600(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00213190(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
extern "C" void FUN_00267760(char* buffer, unsigned int size, const char* format, ...);
// state (include/gen/owners.h K_1d2c60 +0x08) is the lua_State, an int member there; a (the key string) and b
// (the output buffer) are hulk_intptr there: cast at the use.
bool owners::K_1d2c60::FUN_001d2c60(hulk_intptr a, hulk_intptr b, int c) {
    FUN_002133d0((LuaVMState*)(hulk_intptr)state, (const char*)a);
    FUN_00213600((LuaVMState*)(hulk_intptr)state, -2);
    const char* v = FUN_00213190((LuaVMState*)(hulk_intptr)state, -1);
    bool r = true;
    if (v == 0)
        r = false;
    else
        FUN_00267760((char*)b, c, "%s", v);
    FUN_00212d80((LuaVMState*)(hulk_intptr)state, -2);
    return r;
}
