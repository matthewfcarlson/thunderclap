// lmathlib
#include "decls/data/lua.h"
extern "C" float __cdecl FUN_00339ec0(LuaVMState* L, int narg);
extern "C" void __cdecl FUN_00213340(LuaVMState* L, float n);
extern "C" int __cdecl FUN_00339f70(LuaVMState* L, int narg);
extern "C" double __cdecl ldexp(double, int);
extern "C" int __cdecl FUN_0033ba20(LuaVMState* L) {
    int exponent = FUN_00339f70(L, 2);
    double d = FUN_00339ec0(L, 1);
    FUN_00213340(L, (float)ldexp(d, exponent));
    return 1;
}
