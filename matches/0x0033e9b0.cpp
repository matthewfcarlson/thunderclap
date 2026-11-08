// luaB_cowrap
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0033e8f0(LuaVMState* L);
extern "C" int __cdecl FUN_0033e950(LuaVMState* L);
extern "C" void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n);

extern "C" int __cdecl FUN_0033e9b0(LuaVMState* L) {
    FUN_0033e950(L);
    FUN_002134a0(L, FUN_0033e8f0, 1);
    return 1;
}
