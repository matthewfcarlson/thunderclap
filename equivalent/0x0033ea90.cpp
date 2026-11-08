// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0033ea90 @ 0x0033ea90
// luaopen_base's base_open: the state is passed in esi
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"
// data: base_funcs = DAT_00434d90 (luaL_reg[])

extern "C" void __cdecl FUN_00212ed0(LuaVMState *L, int idx);
extern "C" void __cdecl FUN_003390d0(LuaVMState *L, const char *libname, const LuaVMReg *l, int nup);
extern "C" void __cdecl FUN_00213380(LuaVMState *L, const char *s, unsigned int len);
extern "C" void __cdecl FUN_00213790(LuaVMState *L, int idx, const char *k);
extern "C" void __cdecl FUN_00213680(LuaVMState *L, int narray, int nrec);
extern "C" int __cdecl FUN_002138e0(LuaVMState *L, int objindex);
extern "C" void __cdecl FUN_002134a0(LuaVMState *L, LuaVMCFunction fn, int n);
extern "C" int __cdecl FUN_0033e3f0(LuaVMState *L);

// equiv-conv: FUN_0033ea90 esi
void FUN_0033ea90(LuaVMState *L)
{
    FUN_00212ed0(L, -10001);
    FUN_003390d0(L, 0, (const LuaVMReg *)&DAT_00434d90, 0);
    FUN_00213380(L, "Lua 5.1 (work)", 14);
    FUN_00213790(L, -2, "_VERSION");
    FUN_00213680(L, 0, 0);
    FUN_00212ed0(L, -1);
    FUN_002138e0(L, -2);
    FUN_00213380(L, "kv", 2);
    FUN_00213790(L, -2, "__mode");
    FUN_002134a0(L, FUN_0033e3f0, 1);
    FUN_00213790(L, -2, "newproxy");
    FUN_00213790(L, -1, "_G");
}
