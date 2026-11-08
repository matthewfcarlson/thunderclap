// generic_reader (luaB_load's lua_Reader): call the reader function, keep the piece it returns in the registry
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00339710(LuaVMState* L, int t, int ref);
extern "C" void __cdecl FUN_00213640(LuaVMState* L, int idx, int n);
extern "C" void __cdecl FUN_002139a0(LuaVMState* L, int nargs, int nresults);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00212fb0(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00213190(LuaVMState* L, int idx);
extern "C" unsigned int __cdecl FUN_002131f0(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00339650(LuaVMState* L, int t);
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);

// the original passes (res, LUA_REGISTRYINDEX) to luaL_unref in this order
extern "C" const char* __cdecl FUN_0033df70(LuaVMState* L, void* ud, unsigned int* size) {
    LuaVMLoadRefs* d = (LuaVMLoadRefs*)ud;
    FUN_00339710(L, d->res, -10000);
    FUN_00213640(L, -10000, d->func);
    FUN_002139a0(L, 0, 1);
    int t = FUN_00212f00(L, -1);
    if (!t) {
        *size = t;
        return 0;
    }
    if (FUN_00212fb0(L, -1)) {
        const char* s = FUN_00213190(L, -1);
        *size = FUN_002131f0(L, -1);
        d->res = FUN_00339650(L, -10000);
        return s;
    }
    FUN_00338e20(L, "reader function must return a string");
    return 0;
}
