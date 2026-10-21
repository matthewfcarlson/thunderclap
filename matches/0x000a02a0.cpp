#include "compat/ptr.h"
extern "C" int __isnan(double);

float FUN_000a02a0(float a) {
    if (!__isnan((double)a)) {
        hulk_freg b = a;
        *(unsigned*)&b &= 0x7fffffff;
        if (!(b > 3600.0f)) {
            while (a < -180.0f)
                a += 360.0f;
            while (a >= 180.0f)
                a -= 360.0f;
            return a;
        }
    }
    return 0.0f;
}
