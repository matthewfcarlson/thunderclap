// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0033e4d0 @ 0x0033e4d0
// lbaselib getpath: LUA_PATH or the default
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_002135a0(LuaVMState* L, int idx, const char* k);
extern "C" const char* __cdecl FUN_00213190(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
// equiv-conv: FUN_0033e4d0 esi
const char* FUN_0033e4d0(LuaVMState* L)
{
    FUN_002135a0(L, -10001, "LUA_PATH");
    const char* path = FUN_00213190(L, -1);
    FUN_00212d80(L, -2);
    return path ? path : "?;?.lua";
}
