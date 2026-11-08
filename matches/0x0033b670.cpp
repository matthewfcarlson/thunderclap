// lmathlib
#include "decls/data/lua.h"
extern "C" float __cdecl FUN_00339ec0(LuaVMState* L, int narg);
extern "C" void __cdecl FUN_00213340(LuaVMState* L, float n);
extern "C" double __cdecl cos(double);
extern "C" int __cdecl FUN_0033b670(LuaVMState* L) {
    FUN_00213340(L, (float)cos(FUN_00339ec0(L, 1)));
    return 1;
}
