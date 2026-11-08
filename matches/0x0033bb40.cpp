// FUN_0033bb40 @ 0x0033bb40
#include "decls/data/lua.h"

extern "C" int rand(void);
extern "C" double floor(double);

extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
extern "C" int __cdecl FUN_00339f70(LuaVMState* L, int narg);
extern "C" int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
extern "C" void __cdecl FUN_00213340(LuaVMState* L, float n);
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);

// math.random
extern "C" int __cdecl FUN_0033bb40(LuaVMState* L)
{
    float r = (float)(rand() % 0x7fff) * 3.0518509e-05f;
    switch (FUN_00212d70(L)) {
    case 0:
        FUN_00213340(L, r);
        return 1;
    case 1: {
        int u = FUN_00339f70(L, 1);
        if (u < 1)
            FUN_00339c30(L, 1, "interval is empty");
        FUN_00213340(L, (float)((int)floor(u * r) + 1));
        return 1;
    }
    case 2: {
        int lo = FUN_00339f70(L, 1);
        int hi = FUN_00339f70(L, 2);
        if (lo > hi)
            FUN_00339c30(L, 2, "interval is empty");
        FUN_00213340(L, (float)((int)floor((hi - lo + 1) * r) + lo));
        return 1;
    }
    default:
        return FUN_00338e20(L, "wrong number of arguments");
    }
}
