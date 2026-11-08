// luaL_newmetatable: registry[tname] = a new table (and registry[table] = tname); 0 when it exists.
#include "decls/data/lua.h"
extern "C" void __cdecl FUN_002135a0(LuaVMState* L, int idx, const char* k);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213680(LuaVMState* L, int narray, int nrec);
extern "C" void __cdecl FUN_00212ed0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s);
extern "C" void __cdecl FUN_00213800(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00338eb0(LuaVMState* L, const char* tname) {
    FUN_002135a0(L, -10000, tname);
    if (FUN_00212f00(L, -1))
        return 0;
    FUN_00212d80(L, -2);
    FUN_00213680(L, 0, 0);
    FUN_00212ed0(L, -1);
    FUN_00213790(L, -10000, tname);
    FUN_00212ed0(L, -1);
    FUN_002133d0(L, tname);
    FUN_00213800(L, -10000);
    return 1;
}
