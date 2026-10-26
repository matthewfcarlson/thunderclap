#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
// data: gZero_a0450 = DAT_003f32e0

#include "compat/ptr.h"
extern "C" double atan2(double y, double x);
float __cdecl Wrap(float v);
union Bits_a0450 {
    float f;
    unsigned long u;
};
hulk_freg __cdecl Fn(float* p) {
    Bits_a0450 a;
    a.f = p[0];
    a.u &= 0x7fffffffUL;
    if (a.f <= DAT_00405564) {
        Bits_a0450 b;
        b.f = p[2];
        b.u &= 0x7fffffffUL;
        if (b.f <= DAT_00405564)
            return DAT_003f32e0;
    }
    return Wrap((float)(atan2(p[0], p[2]) * DAT_003f3ef4));
}
