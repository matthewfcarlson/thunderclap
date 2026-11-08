// luaB_pairs
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00339d70(LuaVMState* L, int narg, int t);
extern "C" void __cdecl FUN_002135a0(LuaVMState* L, int idx, const char* k);
extern "C" void __cdecl FUN_00212ed0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213320(LuaVMState* L);

extern "C" int __cdecl FUN_0033ddd0(LuaVMState* L) {
    FUN_00339d70(L, 1, LUAVM_TTABLE);
    FUN_002135a0(L, -10001, "next");
    FUN_00212ed0(L, 1);
    FUN_00213320(L);
    return 3;
}
