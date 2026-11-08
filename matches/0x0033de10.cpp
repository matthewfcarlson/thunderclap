// luaB_ipairs
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00213120(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00339d70(LuaVMState* L, int narg, int t);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_002135a0(LuaVMState* L, int idx, const char* k);
extern "C" void __cdecl FUN_00212ed0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213360(LuaVMState* L, int n);
extern "C" void __cdecl FUN_00213640(LuaVMState* L, int idx, int n);

extern "C" int __cdecl FUN_0033de10(LuaVMState* L) {
    int n = FUN_00213120(L, 2);
    FUN_00339d70(L, 1, LUAVM_TTABLE);
    if (n == 0 && FUN_00212f00(L, 2) == -1) {
        FUN_002135a0(L, -10001, "ipairs");
        FUN_00212ed0(L, 1);
        FUN_00213360(L, n);
        return 3;
    }
    n++;
    FUN_00213360(L, n);
    FUN_00213640(L, 1, n);
    return FUN_00212f00(L, -1) != 0 ? 2 : 0;
}
