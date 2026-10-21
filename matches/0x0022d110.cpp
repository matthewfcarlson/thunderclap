#include "compat/ptr.h"
extern "C" double sqrt(double);
extern const float gSmall, gOne, gZero;
struct Vec_22d110 {
    float x, y, z;
    float Normalize();
};
// x87: the squared length, the root and its reciprocal stay in registers (MSVC also returns the length unrounded in
// st0; natively the float return rounds it); the sum is x*x + y*y, then + z*z (the listing order)
float Vec_22d110::Normalize() {
    hulk_freg n = (hulk_freg)x * x + (hulk_freg)y * y + (hulk_freg)z * z;
    if (n >= gSmall) {
        hulk_freg s = sqrt(n);
        s = gOne / s;
        x *= s;
        y *= s;
        z *= s;
        return gOne / s;
    }
    hulk_freg result = gZero;
    x = y = z = 0;
    return result;
}
