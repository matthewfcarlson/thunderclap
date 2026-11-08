// db_getupvalue
#include "decls/data/lua.h"
extern "C" int __cdecl FUN_00339f70(LuaVMState* L, int narg);
extern "C" void __cdecl FUN_00339d70(LuaVMState* L, int narg, int t);
extern "C" int __cdecl FUN_00212f40(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00213dd0(LuaVMState* L, int funcindex, int n);
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s);
extern "C" void __cdecl FUN_00212e20(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_0033a560(LuaVMState* p) {
    int v = FUN_00339f70(p, 2);
    FUN_00339d70(p, 1, 6);
    if (FUN_00212f40(p, 1) != 0)
        return 0;
    const char* r = FUN_00213dd0(p, 1, v);
    if (r == 0)
        return 0;
    FUN_002133d0(p, r);
    FUN_00212e20(p, -2);
    return 2;
}
