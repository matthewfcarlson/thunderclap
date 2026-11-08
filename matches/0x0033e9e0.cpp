// luaB_yield
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
extern "C" int __cdecl FUN_00215b60(LuaVMState* L, int nresults);

extern "C" int __cdecl FUN_0033e9e0(LuaVMState* L) {
    return FUN_00215b60(L, FUN_00212d70(L));
}
