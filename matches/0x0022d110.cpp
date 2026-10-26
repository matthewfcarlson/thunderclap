#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
// data: gSmall = DAT_004275c4, gZero = DAT_003f32e0

#include "compat/ptr.h"
extern "C" double sqrt(double);
struct Vec_22d110 {
    float x, y, z;
    hulk_freg Normalize();
};
// x87: the squared length, the root and its reciprocal stay in registers, and the length comes back unrounded in st0
// (hulk_freg return: double natively, bound to the callers' float declarations by tools/native_link.py, which on x87
// read it from st0 the same way); the sum is x*x + y*y, then + z*z (the listing order)
hulk_freg Vec_22d110::Normalize() {
    hulk_freg n = (hulk_freg)x * x + (hulk_freg)y * y + (hulk_freg)z * z;
    if (n >= DAT_004275c4) {
        hulk_freg s = sqrt(n);
        s = DAT_003f32dc / s;
        x *= s;
        y *= s;
        z *= s;
        return DAT_003f32dc / s;
    }
    hulk_freg result = DAT_003f32e0;
    x = y = z = 0;
    return result;
}
