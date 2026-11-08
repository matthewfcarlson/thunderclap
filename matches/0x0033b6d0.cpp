// lmathlib
#include "decls/data/lua.h"
extern "C" float __cdecl FUN_00339ec0(LuaVMState* L, int narg);
extern "C" void __cdecl FUN_00213340(LuaVMState* L, float n);
extern "C" double asin(double);
extern "C" int __cdecl FUN_0033b6d0(LuaVMState* L) {
    float x = FUN_00339ec0(L, 1);
    *(volatile float*)&x = x;
    FUN_00213340(L, (float)asin(x));
    return 1;
}
