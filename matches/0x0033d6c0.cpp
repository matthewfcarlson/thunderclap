#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
// data: libname = DAT_003fd600, the luaL_reg list = DAT_00434af8

extern "C" void __cdecl FUN_003390d0(LuaVMState* L, const char* libname, const LuaVMReg* l, int nup);

extern "C" int __cdecl FUN_0033d6c0(LuaVMState* L) {
    FUN_003390d0(L, DAT_003fd600, (const LuaVMReg*)&DAT_00434af8, 0);
    return 1;
}
