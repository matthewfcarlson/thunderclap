// luaB_rawget
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00339d70(LuaVMState* L, int narg, int t);
extern "C" void __cdecl FUN_00339dc0(LuaVMState* L, int narg);
extern "C" void __cdecl FUN_00213600(LuaVMState* L, int idx);

extern "C" int __cdecl FUN_0033dc10(LuaVMState* L) {
    FUN_00339d70(L, 1, LUAVM_TTABLE);
    FUN_00339dc0(L, 2);
    FUN_00213600(L, 1);
    return 1;
}
