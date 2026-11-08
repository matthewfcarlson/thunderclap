// FUN_0033acd0 @ 0x0033acd0
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00212d80(LuaVMState *L, int idx);
extern "C" void __cdecl FUN_00212ed0(LuaVMState *L, int idx);
extern "C" int __cdecl FUN_00212f00(LuaVMState *L, int idx);
extern "C" void __cdecl FUN_00213360(LuaVMState *L, int n);
extern "C" void __cdecl FUN_00213640(LuaVMState *L, int idx, int n);
extern "C" void __cdecl FUN_002139a0(LuaVMState *L, int nargs, int nresults);
extern "C" int __cdecl FUN_003392c0(LuaVMState *L, int idx);
extern "C" void __cdecl FUN_00339d70(LuaVMState *L, int idx, int type);

// Calls the function in argument 2 on each element (index, value) of the table in argument 1
// and returns 1 as soon as it answers true, otherwise 0.
extern "C" int __cdecl FUN_0033acd0(LuaVMState *L)
{
    FUN_00339d70(L, 1, 5);
    int n = FUN_003392c0(L, 1);
    FUN_00339d70(L, 2, 6);
    for (int i = 1; i <= n; i++) {
        FUN_00212ed0(L, 2);
        FUN_00213360(L, i);
        FUN_00213640(L, 1, i);
        FUN_002139a0(L, 2, 1);
        if (FUN_00212f00(L, -1))
            return 1;
        FUN_00212d80(L, -2);
    }
    return 0;
}
