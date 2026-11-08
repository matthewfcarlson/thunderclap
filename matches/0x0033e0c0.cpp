// luaB_dofile
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00339e60(LuaVMState* L, int narg, const char* def, unsigned int* len);
extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
extern "C" int __cdecl FUN_00339800(LuaVMState* L, const char* filename);
extern "C" int __cdecl FUN_00213c40(LuaVMState* L);
extern "C" void __cdecl FUN_002139a0(LuaVMState* L, int nargs, int nresults);

extern "C" int __cdecl FUN_0033e0c0(LuaVMState* L) {
    const char* fname = FUN_00339e60(L, 1, 0, 0);
    int n = FUN_00212d70(L);
    if (FUN_00339800(L, fname))
        FUN_00213c40(L);
    FUN_002139a0(L, 0, -1);
    return FUN_00212d70(L) - n;
}
