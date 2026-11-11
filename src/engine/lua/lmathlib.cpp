// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0033b610..0x0033bd00 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_fe2daf34 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fe2daf34 {} using namespace fn_fe2daf34;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_fe2daf34 {
extern "C" float __cdecl FUN_00339ec0(LuaVMState* L, int narg);
extern "C" void __cdecl FUN_00213340(LuaVMState* L, float n);
} // namespace fn_fe2daf34
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sin(double);
#endif
extern "C" double __cdecl __ceil_default(double);
extern "C" double __cdecl __floor_default(double);
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl log(double);
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl log10(double);
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl frexp(double, int*);
#endif
namespace fn_fe2daf34 {
extern "C" int __cdecl FUN_00339f70(LuaVMState* L, int narg);
} // namespace fn_fe2daf34
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl ldexp(double, int);
#endif
namespace fn_fe2daf34 {
extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
} // namespace fn_fe2daf34
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int rand(void);
#endif
namespace fn_fe2daf34 {
extern "C" int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);
extern "C" int __cdecl FUN_0034773f(int status);
extern "C" void __cdecl FUN_003390d0(LuaVMState* L, const char* libname, const LuaVMReg* l, int nup);
extern "C" void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);
extern "C" void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n);
extern "C" int __cdecl FUN_0033b880(LuaVMState* L);


// 0x0033b610 FUN_0033b610 (37 B): matches/0x0033b610.cpp
// sym: _FUN_0033b610
// lmathlib
extern "C" int __cdecl FUN_0033b610(LuaVMState* L) {
    FUN_00213340(L, (float)fabs(FUN_00339ec0(L, 1)));
    return 1;
}


// 0x0033b640 FUN_0033b640 (37 B): matches/0x0033b640.cpp
// sym: _FUN_0033b640
// lmathlib
extern "C" int __cdecl FUN_0033b640(LuaVMState* L) {
    FUN_00213340(L, (float)sin(FUN_00339ec0(L, 1)));
    return 1;
}


// 0x0033b670 FUN_0033b670 (37 B): matches/0x0033b670.cpp
// sym: _FUN_0033b670
// lmathlib
extern "C" int __cdecl FUN_0033b670(LuaVMState* L) {
    FUN_00213340(L, (float)cos(FUN_00339ec0(L, 1)));
    return 1;
}


// 0x0033b6a0 FUN_0033b6a0 (39 B): matches/0x0033b6a0.cpp
// sym: _FUN_0033b6a0
// lmathlib
extern "C" int __cdecl FUN_0033b6a0(LuaVMState* L) {
    FUN_00213340(L, (float)tan(FUN_00339ec0(L, 1)));
    return 1;
}


// 0x0033b6d0 FUN_0033b6d0 (47 B): matches/0x0033b6d0.cpp
// sym: _FUN_0033b6d0
// lmathlib
extern "C" int __cdecl FUN_0033b6d0(LuaVMState* L) {
    float x = FUN_00339ec0(L, 1);
    *(volatile float*)&x = x;
    FUN_00213340(L, (float)asin(x));
    return 1;
}


// 0x0033b700 FUN_0033b700 (47 B): matches/0x0033b700.cpp
// sym: _FUN_0033b700
// lmathlib
extern "C" int __cdecl FUN_0033b700(LuaVMState* L) {
    float a = FUN_00339ec0(L, 1);
    FUN_00213340(L, (float)acos(a));
    return 1;
}


// 0x0033b730 FUN_0033b730 (39 B): matches/0x0033b730.cpp
// sym: _FUN_0033b730
// lmathlib
extern "C" int __cdecl FUN_0033b730(LuaVMState* L) {
    FUN_00213340(L, (float)atan(FUN_00339ec0(L, 1)));
    return 1;
}


// 0x0033b760 FUN_0033b760 (55 B): matches/0x0033b760.cpp
// sym: _FUN_0033b760
// lmathlib
extern "C" int __cdecl FUN_0033b760(LuaVMState* L) {
    float a = FUN_00339ec0(L, 2);
    float b = FUN_00339ec0(L, 1);
    FUN_00213340(L, (float)atan2(b, a));
    return 1;
}


// 0x0033b7a0 FUN_0033b7a0 (44 B): matches/0x0033b7a0.cpp
// sym: _FUN_0033b7a0
// lmathlib
extern "C" int __cdecl FUN_0033b7a0(LuaVMState* L) {
    FUN_00213340(L, (float)__ceil_default(FUN_00339ec0(L, 1)));
    return 1;
}


// 0x0033b7d0 FUN_0033b7d0 (44 B): matches/0x0033b7d0.cpp
// sym: _FUN_0033b7d0
// lmathlib
extern "C" int __cdecl FUN_0033b7d0(LuaVMState* L) {
    FUN_00213340(L, (float)__floor_default(FUN_00339ec0(L, 1)));
    return 1;
}


// 0x0033b800 FUN_0033b800 (67 B): matches/0x0033b800.cpp
// sym: _FUN_0033b800
// lmathlib
extern "C" int __cdecl FUN_0033b800(LuaVMState* L) {
    float a = FUN_00339ec0(L, 2);
    float b = FUN_00339ec0(L, 1);
    FUN_00213340(L, (float)fmod(b, a));
    return 1;
}


// 0x0033b850 FUN_0033b850 (37 B): matches/0x0033b850.cpp
// sym: _FUN_0033b850
// lmathlib
extern "C" int __cdecl FUN_0033b850(LuaVMState* L) {
    FUN_00213340(L, (float)sqrt(FUN_00339ec0(L, 1)));
    return 1;
}


// 0x0033b880 FUN_0033b880 (67 B): matches/0x0033b880.cpp
// sym: _FUN_0033b880
// lmathlib
extern "C" int __cdecl FUN_0033b880(LuaVMState* L) {
    float x = FUN_00339ec0(L, 2);
    float y = FUN_00339ec0(L, 1);
    FUN_00213340(L, (float)pow(y, x));
    return 1;
}


// 0x0033b8d0 FUN_0033b8d0 (41 B): matches/0x0033b8d0.cpp
// sym: _FUN_0033b8d0
// lmathlib
extern "C" int __cdecl FUN_0033b8d0(LuaVMState* L) {
    FUN_00213340(L, (float)log(FUN_00339ec0(L, 1)));
    return 1;
}


// 0x0033b900 FUN_0033b900 (41 B): matches/0x0033b900.cpp
// sym: _FUN_0033b900
// lmathlib
extern "C" int __cdecl FUN_0033b900(LuaVMState* L) {
    FUN_00213340(L, (float)log10(FUN_00339ec0(L, 1)));
    return 1;
}


// 0x0033b930 FUN_0033b930 (57 B): matches/0x0033b930.cpp
// sym: _FUN_0033b930
// lmathlib
extern "C" int __cdecl FUN_0033b930(LuaVMState* L) {
    FUN_00213340(L, (float)exp(FUN_00339ec0(L, 1)));
    return 1;
}


// 0x0033b970 FUN_0033b970 (41 B): matches/0x0033b970.cpp
// sym: _FUN_0033b970
// lmathlib
// data: gScale_33b970 = DAT_00434ab4
extern "C" int __cdecl FUN_0033b970(LuaVMState* L) {
    FUN_00213340(L, FUN_00339ec0(L, 1) * DAT_00434ab4);
    return 1;
}


// 0x0033b9a0 FUN_0033b9a0 (41 B): matches/0x0033b9a0.cpp
// sym: _FUN_0033b9a0
// lmathlib
// data: gScale_33b9a0 = DAT_003f32b8
extern "C" int __cdecl FUN_0033b9a0(LuaVMState* L) {
    FUN_00213340(L, FUN_00339ec0(L, 1) * DAT_003f32b8);
    return 1;
}


// 0x0033b9d0 FUN_0033b9d0 (72 B): matches/0x0033b9d0.cpp
// sym: _FUN_0033b9d0
// lmathlib
extern "C" int __cdecl FUN_0033b9d0(LuaVMState* L) {
    int exponent;
    double x = FUN_00339ec0(L, 1);
    FUN_00213340(L, (float)frexp(x, &exponent));
    FUN_00213340(L, (float)exponent);
    return 2;
}


// 0x0033ba20 FUN_0033ba20 (62 B): matches/0x0033ba20.cpp
// sym: _FUN_0033ba20
// lmathlib
extern "C" int __cdecl FUN_0033ba20(LuaVMState* L) {
    int exponent = FUN_00339f70(L, 2);
    double d = FUN_00339ec0(L, 1);
    FUN_00213340(L, (float)ldexp(d, exponent));
    return 1;
}


// 0x0033ba60 FUN_0033ba60 (98 B): matches/0x0033ba60.cpp
// sym: _FUN_0033ba60
// math.min
extern "C" int __cdecl FUN_0033ba60(LuaVMState* L) {
    int n = FUN_00212d70(L);
    float dmin = FUN_00339ec0(L, 1);
    for (int i = 2; i <= n; ++i) {
        float d = FUN_00339ec0(L, i);
        if (d < dmin)
            dmin = d;
    }
    FUN_00213340(L, dmin);
    return 1;
}


// 0x0033bad0 FUN_0033bad0 (98 B): matches/0x0033bad0.cpp
// sym: _FUN_0033bad0
// math.max
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


// 0x0033bb40 FUN_0033bb40 (317 B): matches/0x0033bb40.cpp
// sym: _FUN_0033bb40
// FUN_0033bb40 @ 0x0033bb40
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


// 0x0033bc80 FUN_0033bc80 (24 B): matches/0x0033bc80.cpp
// sym: _FUN_0033bc80
// os.exit
extern "C" int __cdecl FUN_0033bc80(LuaVMState* L) {
    int v = FUN_00339f70(L, 1);
    FUN_0034773f(v);
    return 0;
}


// 0x0033bca0 FUN_0033bca0 (86 B): matches/0x0033bca0.cpp
// sym: _FUN_0033bca0
// luaopen_math
// data: s_math = DAT_00434af0, mathlib = DAT_00434970 (luaL_reg[]), s_pi = DAT_00434aec, s_pow = DAT_004269e4
extern "C" int __cdecl FUN_0033bca0(LuaVMState* L) {
    FUN_003390d0(L, DAT_00434af0, (const LuaVMReg*)&DAT_00434970, 0);
    FUN_00213340(L, 3.14159265358979323846f);
    FUN_00213790(L, -2, DAT_00434aec);
    FUN_002134a0(L, FUN_0033b880, 0);
    FUN_00213790(L, -10001, DAT_004269e4);
    return 1;
}

} // namespace fn_fe2daf34
