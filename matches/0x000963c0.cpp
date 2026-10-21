#include "compat/ptr.h"
extern const float zero_963c0;
hulk_freg FUN_000963c0(float a, float b, float c, float d, float e) {
    if (!(e <= a)) {
        if (e >= c)
            return d;
        if (c - a > zero_963c0)
            return (d - b) * ((e - a) / (c - a)) + b;
    }
    return b;
}
