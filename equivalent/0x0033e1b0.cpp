// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0033e1b0 @ 0x0033e1b0
// luaB_pcall
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00339dc0(LuaVMState* L, int narg);
extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
extern "C" int __cdecl FUN_002139f0(LuaVMState* L, int nargs, int nresults, int errfunc);
extern "C" void __cdecl FUN_00213520(LuaVMState* L, int b);
extern "C" void __cdecl FUN_00212e20(LuaVMState* L, int idx);

extern "C" int __cdecl FUN_0033e1b0(LuaVMState* L) {
    FUN_00339dc0(L, 1);
    int status = FUN_002139f0(L, FUN_00212d70(L) - 1, -1, 0);
    FUN_00213520(L, status == 0);
    FUN_00212e20(L, 1);
    return FUN_00212d70(L);
}
