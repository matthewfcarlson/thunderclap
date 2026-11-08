// luaopen_math
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"
// data: s_math = DAT_00434af0, mathlib = DAT_00434970 (luaL_reg[]), s_pi = DAT_00434aec, s_pow = DAT_004269e4

extern "C" void __cdecl FUN_003390d0(LuaVMState* L, const char* libname, const LuaVMReg* l, int nup);
extern "C" void __cdecl FUN_00213340(LuaVMState* L, float n);
extern "C" void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);
extern "C" void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n);
extern "C" int __cdecl FUN_0033b880(LuaVMState* L);

extern "C" int __cdecl FUN_0033bca0(LuaVMState* L) {
    FUN_003390d0(L, DAT_00434af0, (const LuaVMReg*)&DAT_00434970, 0);
    FUN_00213340(L, 3.14159265358979323846f);
    FUN_00213790(L, -2, DAT_00434aec);
    FUN_002134a0(L, FUN_0033b880, 0);
    FUN_00213790(L, -10001, DAT_004269e4);
    return 1;
}
