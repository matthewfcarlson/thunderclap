// luaB_gcinfo
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00213ba0(LuaVMState* L, int what, int data);
extern "C" void __cdecl FUN_00213360(LuaVMState* L, int n);

extern "C" int __cdecl FUN_0033dc80(LuaVMState* L) {
    int v = FUN_00213ba0(L, 3, 0);
    FUN_00213360(L, v);
    return 1;
}
