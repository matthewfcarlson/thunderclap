#include "decls/data/lua.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s);
extern "C" void __cdecl FUN_00213680(LuaVMState* L, int narray, int nrec);
extern "C" void __cdecl FUN_00213800(LuaVMState* L, int idx);
// member (include/gen/owners.h Obj_1d1980 +0x08) is the lua_State, an int member there, and arg (the table's
// name) is a hulk_uintptr there: cast at the use.
bool owners::Obj_1d1980::FUN_001d1980(hulk_uintptr arg, unsigned char flag) {
    int v = -3;
    if (flag)
        v = -10001;
    FUN_002133d0((LuaVMState*)(hulk_intptr)member, (const char*)arg);
    FUN_00213680((LuaVMState*)(hulk_intptr)member, 0, 0);
    FUN_00213800((LuaVMState*)(hulk_intptr)member, v);
    return true;
}
