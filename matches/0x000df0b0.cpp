#include "compat/ptr.h"
float __cdecl FUN_000df0b0(float x, int n) {
    unsigned int p = n < 0 ? -n : n;
    hulk_freg r = 1.0f;
    do {
        if (p & 1)
            r *= x;
        p >>= 1;
        if (p)
            x *= x;
    } while (p);
    if (n < 0)
        return 1.0f / r;
    return r;
}