// math.max
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
extern "C" float __cdecl FUN_00339ec0(LuaVMState* L, int narg);
extern "C" void __cdecl FUN_00213340(LuaVMState* L, float n);

extern "C" int __cdecl FUN_0033bad0(LuaVMState* L) {
    int n = FUN_00212d70(L);
    float dmax = FUN_00339ec0(L, 1);
    for (int i = 2; i <= n; i++) {
        float d = FUN_00339ec0(L, i);
        if (d > dmax)
            dmax = d;
    }
    FUN_00213340(L, dmax);
    return 1;
}
