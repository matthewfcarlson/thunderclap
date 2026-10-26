#include "decls/data/engine/choreo2.h"
#include "decls/data/game/global.h"
// data: kZero_224ea0 = DAT_003f32e0

#include "compat/ptr.h"
extern "C" double atan2(double, double);
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
    if (Abs(a) <= DAT_00427334 && Abs(b) <= DAT_00427334)
        return DAT_003f32e0;
    hulk_freg r = (hulk_freg)atan2(-a, -b);
    if (r < DAT_003f32e0)
        r += DAT_0042732c;
    return r;
}
