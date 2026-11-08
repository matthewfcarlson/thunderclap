// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0033e870 @ 0x0033e870
// luaB_coresume
#include "decls/data/lua.h"

extern "C" LuaVMState *__cdecl FUN_00213290(LuaVMState *L, int idx);
extern "C" int __cdecl FUN_00339c30(LuaVMState *L, int narg, const char *extramsg);
extern "C" int __cdecl FUN_00212d70(LuaVMState *L);
// equiv-conv: FUN_0033e7f0 eax esi edi
int FUN_0033e7f0(int narg, LuaVMState *co, LuaVMState *L);
extern "C" void __cdecl FUN_00213520(LuaVMState *L, int b);
extern "C" void __cdecl FUN_00212e20(LuaVMState *L, int idx);

extern "C" int __cdecl FUN_0033e870(LuaVMState *L)
{
    LuaVMState *co = FUN_00213290(L, 1);
    if (co == 0)
        FUN_00339c30(L, 1, "coroutine expected");
    int r = FUN_0033e7f0(FUN_00212d70(L) - 1, co, L);
    if (r < 0) {
        FUN_00213520(L, 0);
        FUN_00212e20(L, -2);
        return 2;
    }
    FUN_00213520(L, 1);
    FUN_00212e20(L, -(r + 1));
    return r + 1;
}
