// luaopen_debug
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"

extern "C" void __cdecl FUN_003390d0(LuaVMState* L, const char* libname, const LuaVMReg* l, int nup);
extern "C" void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n);
extern "C" void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);
extern "C" int __cdecl FUN_0033aa40(LuaVMState* L);
extern "C" int __cdecl FUN_0033ac90(LuaVMState* p) {
    FUN_003390d0(p, "debug", ((const LuaVMReg*)&DAT_00434710), 0);
    FUN_002134a0(p, FUN_0033aa40, 0);
    FUN_00213790(p, -10001, "_TRACEBACK");
    return 1;
}
