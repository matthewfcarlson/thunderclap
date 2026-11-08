// luaB_error
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00339fe0(LuaVMState* L, int narg, int def);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00212fb0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00338d90(LuaVMState* L, int level);
extern "C" void __cdecl FUN_00212ed0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213c90(LuaVMState* L, int n);
extern "C" int __cdecl FUN_00213c40(LuaVMState* L);

extern "C" int __cdecl FUN_0033d8b0(LuaVMState* L) {
    int level = FUN_00339fe0(L, 2, 1);
    FUN_00212d80(L, 1);
    if (FUN_00212fb0(L, 1) && level > 0) {
        FUN_00338d90(L, level);
        FUN_00212ed0(L, 1);
        FUN_00213c90(L, 2);
    }
    return FUN_00213c40(L);
}
