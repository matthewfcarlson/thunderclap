// luaL_ref
#include "decls/data/lua.h"
extern "C" {
int __cdecl FUN_00212d70(LuaVMState* L);
int __cdecl FUN_00212f00(LuaVMState* L, int i);
void __cdecl FUN_00212d80(LuaVMState* L, int i);
void __cdecl FUN_00213640(LuaVMState* L, int a, int b);
int __cdecl FUN_00213120(LuaVMState* L, int i);
void __cdecl FUN_00213870(LuaVMState* L, int a, int b);
int __cdecl FUN_003392c0(LuaVMState* L, int a);
void __cdecl FUN_00339270(LuaVMState* L, int a, int b);
}

extern "C" int __cdecl FUN_00339650(LuaVMState* L, int idx) {
    if (idx <= 0 && idx > -10000) {
        idx = idx + FUN_00212d70(L) + 1;
    }
    if (!FUN_00212f00(L, -1)) {
        FUN_00212d80(L, -2);
        return -1;
    }
    FUN_00213640(L, idx, 1);
    int r = FUN_00213120(L, -1);
    FUN_00212d80(L, -2);
    if (r) {
        FUN_00213640(L, idx, r);
        FUN_00213870(L, idx, 1);
    } else {
        r = FUN_003392c0(L, idx);
        if (r < 2)
            r = 2;
        r++;
        FUN_00339270(L, idx, r);
    }
    FUN_00213870(L, idx, r);
    return r;
}
