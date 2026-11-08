#include "decls/data/lua.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* a);
extern "C" void __cdecl FUN_00213600(LuaVMState* L, int a);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int a);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int a);
extern "C" int __cdecl FUN_00339650(LuaVMState*, int);
// L (include/gen/owners.h C_1d2e10 +0x08) is the lua_State, an int member there: cast at the use.
bool owners::C_1d2e10::FUN_001d2e10(hulk_intptr a, int* out) {
    FUN_002133d0((LuaVMState*)(hulk_intptr)L, (const char*)a);
    FUN_00213600((LuaVMState*)(hulk_intptr)L, -2);
    bool r = true;
    if (FUN_00212f00((LuaVMState*)(hulk_intptr)L, -1) != 6) {
        r = false;
        FUN_00212d80((LuaVMState*)(hulk_intptr)L, -2);
    } else {
        *out = FUN_00339650((LuaVMState*)(hulk_intptr)L, -10000);
    }
    return r;
}
