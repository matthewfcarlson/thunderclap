// luaB_unpack
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00339d70(LuaVMState* L, int narg, int t);
extern "C" int __cdecl FUN_003392c0(LuaVMState* L, int t);
extern "C" void __cdecl FUN_00338fe0(LuaVMState* L, int space, const char* mes);
extern "C" void __cdecl FUN_00213640(LuaVMState* L, int idx, int n);

extern "C" int __cdecl FUN_0033e160(LuaVMState* L) {
    FUN_00339d70(L, 1, LUAVM_TTABLE);
    int n = FUN_003392c0(L, 1);
    FUN_00338fe0(L, n, "table too big to unpack");
    for (int i = 1; i <= n; ++i)
        FUN_00213640(L, 1, i);
    return n;
}
