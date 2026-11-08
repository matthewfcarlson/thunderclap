// lmathlib
#include "decls/data/lua.h"
extern "C" float __cdecl FUN_00339ec0(LuaVMState* L, int narg);
extern "C" void __cdecl FUN_00213340(LuaVMState* L, float n);
extern "C" double atan2(double, double);
extern "C" int __cdecl FUN_0033b760(LuaVMState* L) {
    float a = FUN_00339ec0(L, 2);
    float b = FUN_00339ec0(L, 1);
    FUN_00213340(L, (float)atan2(b, a));
    return 1;
}
