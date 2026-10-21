#include "compat/ptr.h"
extern "C" int __cdecl FUN_00212f00(int, int);
extern "C" float __cdecl FUN_00339ec0(int, int);
hulk_freg __cdecl FUN_00339f40(int param_1, int param_2, float param_3) {
    int value = FUN_00212f00(param_1, param_2);
    if (value <= 0)
        goto fallback;
    return FUN_00339ec0(param_1, param_2);
fallback:
    return param_3;
}