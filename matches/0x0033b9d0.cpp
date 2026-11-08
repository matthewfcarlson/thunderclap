// lmathlib
#include "decls/data/lua.h"
extern "C" float __cdecl FUN_00339ec0(LuaVMState* L, int narg);
extern "C" void __cdecl FUN_00213340(LuaVMState* L, float n);
extern "C" double __cdecl frexp(double, int*);
extern "C" int __cdecl FUN_0033b9d0(LuaVMState* L) {
    int exponent;
    double x = FUN_00339ec0(L, 1);
    FUN_00213340(L, (float)frexp(x, &exponent));
    FUN_00213340(L, (float)exponent);
    return 2;
}
