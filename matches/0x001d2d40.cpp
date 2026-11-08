#include "decls/data/lua.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s);
extern "C" void __cdecl FUN_00213600(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" float __cdecl FUN_002130e0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
// field (include/gen/owners.h Obj_1d2d40 +0x08) is the lua_State, an int member there, and arg (the key string)
// a hulk_intptr there: cast at the use.
bool owners::Obj_1d2d40::FUN_001d2d40(hulk_intptr arg, float* out) {
    FUN_002133d0((LuaVMState*)(hulk_intptr)field, (const char*)arg);
    FUN_00213600((LuaVMState*)(hulk_intptr)field, -2);
    bool result = true;
    if (FUN_00212f00((LuaVMState*)(hulk_intptr)field, -1) != 3)
        result = false;
    if (result)
        *out = FUN_002130e0((LuaVMState*)(hulk_intptr)field, -1);
    FUN_00212d80((LuaVMState*)(hulk_intptr)field, -2);
    return result;
}
