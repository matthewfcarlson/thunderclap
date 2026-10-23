#include "compat/ptr.h"
extern "C" double atan2(double, double);
extern const float kEps;
extern const float kZero_224ea0;
extern const float kTwoPi;
union FU_224ea0 {
    float f;
    unsigned u;
};
__forceinline float Abs(float x) {
    FU_224ea0 t;
    t.f = x;
    t.u &= 0x7fffffff;
    return t.f;
}
hulk_freg Angle(float a, float b) {
    if (Abs(a) <= kEps && Abs(b) <= kEps)
        return kZero_224ea0;
    hulk_freg r = (hulk_freg)atan2(-a, -b);
    if (r < kZero_224ea0)
        r += kTwoPi;
    return r;
}
