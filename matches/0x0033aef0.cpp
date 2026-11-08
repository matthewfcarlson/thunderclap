// FUN_0033aef0 @ 0x0033aef0
#include "decls/data/lua.h"
extern "C" void __cdecl FUN_00339d70(LuaVMState* L, int idx, int type);
extern "C" int __cdecl FUN_003392c0(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00339fe0(LuaVMState* L, int idx, int def);
extern "C" void __cdecl FUN_00339270(LuaVMState* L, int idx, int n);
extern "C" void __cdecl FUN_00213640(LuaVMState* L, int idx, int n);
extern "C" void __cdecl FUN_00213870(LuaVMState* L, int idx, int n);
extern "C" void __cdecl FUN_00213320(LuaVMState* L);
// tremove
extern "C" int __cdecl FUN_0033aef0(LuaVMState* L) {
    FUN_00339d70(L, 1, 5);
    int n = FUN_003392c0(L, 1);
    int pos = FUN_00339fe0(L, 2, n);
    if (n <= 0) return 0;
    FUN_00339270(L, 1, n - 1);
    FUN_00213640(L, 1, pos);
    for (; pos < n; pos++) {
        FUN_00213640(L, 1, pos + 1);
        FUN_00213870(L, 1, pos);
    }
    FUN_00213320(L);
    FUN_00213870(L, 1, n);
    return 1;
}
