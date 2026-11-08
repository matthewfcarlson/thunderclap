// lmathlib
#include "decls/data/lua.h"
extern "C" float __cdecl FUN_00339ec0(LuaVMState* L, int narg);
extern "C" void __cdecl FUN_00213340(LuaVMState* L, float n);
extern "C" double __cdecl pow(double, double);
extern "C" int __cdecl FUN_0033b880(LuaVMState* L) {
    float x = FUN_00339ec0(L, 2);
    float y = FUN_00339ec0(L, 1);
    FUN_00213340(L, (float)pow(y, x));
    return 1;
}
