// luaL_callmeta
#include "decls/data/lua.h"
extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
extern "C" int __cdecl FUN_00339010(LuaVMState* L, int obj, const char* event);
extern "C" void __cdecl FUN_00212ed0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_002139a0(LuaVMState* L, int nargs, int nresults);
extern "C" int FUN_00339070(LuaVMState* L, int obj, const char* event) {
    if (obj <= 0 && obj > -10000)
        obj = obj + 1 + FUN_00212d70(L);
    if (FUN_00339010(L, obj, event) == 0)
        return 0;
    FUN_00212ed0(L, obj);
    FUN_002139a0(L, 1, 1);
    return 1;
}
