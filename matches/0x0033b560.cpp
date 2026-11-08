// luaopen_table
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"
extern "C" void __cdecl FUN_003390d0(LuaVMState* L, const char* libname, const LuaVMReg* l, int nup);
extern "C" int __cdecl FUN_0033b560(LuaVMState* p) {
    FUN_003390d0(p, "table", (const LuaVMReg*)DAT_004348a0, 0);
    return 1;
}
