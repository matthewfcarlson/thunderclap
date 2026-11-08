// lmathlib
#include "decls/data/lua.h"
extern "C" float __cdecl FUN_00339ec0(LuaVMState* L, int narg);
extern "C" void __cdecl FUN_00213340(LuaVMState* L, float n);
#include "decls/data/game/unknown.h"
// data: gScale_33b9a0 = DAT_003f32b8
extern "C" int __cdecl FUN_0033b9a0(LuaVMState* L) {
    FUN_00213340(L, FUN_00339ec0(L, 1) * DAT_003f32b8);
    return 1;
}
