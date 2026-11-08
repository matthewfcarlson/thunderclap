// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0033eb30 @ 0x0033eb30
// luaopen_base
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
// data: s_coroutine = DAT_0042257c, co_funcs = DAT_00434e68 (luaL_reg[]), s_LOADED = DAT_00435210

// equiv-conv: FUN_0033ea90 esi
void FUN_0033ea90(LuaVMState* L);
extern "C" void __cdecl FUN_003390d0(LuaVMState* L, const char* libname, const LuaVMReg* l, int nup);
extern "C" void __cdecl FUN_00213680(LuaVMState* L, int narray, int nrec);
extern "C" void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);

extern "C" int __cdecl FUN_0033eb30(LuaVMState* L) {
    FUN_0033ea90(L);
    FUN_003390d0(L, DAT_0042257c, (const LuaVMReg*)DAT_00434e68, 0);
    FUN_00213680(L, 0, 0);
    FUN_00213790(L, -10001, DAT_00435210);
    return 2;
}
