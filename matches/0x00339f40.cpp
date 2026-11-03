#include "compat/ptr.h"
extern "C" int __cdecl FUN_00212f00(int, int);
extern "C" float __cdecl FUN_00339ec0(int, int);
hulk_freg __cdecl FUN_00339f40(int L, int index, float fallback) {
    int value = FUN_00212f00(L, index);
    if (value <= 0)
        return fallback;
    return FUN_00339ec0(L, index);
}