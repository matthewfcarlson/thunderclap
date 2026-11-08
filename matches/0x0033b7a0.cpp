// lmathlib
#include "decls/data/lua.h"
extern "C" float __cdecl FUN_00339ec0(LuaVMState* L, int narg);
extern "C" void __cdecl FUN_00213340(LuaVMState* L, float n);
extern "C" double __cdecl __ceil_default(double);
extern "C" int __cdecl FUN_0033b7a0(LuaVMState* L) {
    FUN_00213340(L, (float)__ceil_default(FUN_00339ec0(L, 1)));
    return 1;
}
