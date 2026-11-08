// luaB_next
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00339d70(LuaVMState* L, int narg, int t);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00213c50(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213320(LuaVMState* L);

extern "C" int __cdecl FUN_0033dd90(LuaVMState* L) {
    FUN_00339d70(L, 1, LUAVM_TTABLE);
    FUN_00212d80(L, 2);
    if (FUN_00213c50(L, 1))
        return 2;
    FUN_00213320(L);
    return 1;
}
