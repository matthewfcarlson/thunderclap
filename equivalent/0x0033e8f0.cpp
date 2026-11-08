// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0033e8f0 @ 0x0033e8f0
// luaB_auxwrap (upvalue 1: the coroutine)
#include "decls/data/lua.h"

extern "C" LuaVMState* __cdecl FUN_00213290(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
// equiv-conv: FUN_0033e7f0 eax esi edi
int FUN_0033e7f0(int narg, LuaVMState* co, LuaVMState* L);
extern "C" int __cdecl FUN_00212fb0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00338d90(LuaVMState* L, int level);
extern "C" void __cdecl FUN_00212e20(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213c90(LuaVMState* L, int n);
extern "C" int __cdecl FUN_00213c40(LuaVMState* L);

extern "C" int __cdecl FUN_0033e8f0(LuaVMState* L) {
    LuaVMState* co = FUN_00213290(L, -10002);
    int r = FUN_0033e7f0(FUN_00212d70(L), co, L);
    if (r < 0) {
        if (FUN_00212fb0(L, -1)) {
            FUN_00338d90(L, 1);
            FUN_00212e20(L, -2);
            FUN_00213c90(L, 2);
        }
        FUN_00213c40(L);
    }
    return r;
}
