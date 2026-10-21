#include "compat/ptr.h"
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
struct Vec4_22b170 {
    float x, y, z, w;
    void Set(float angle, float* v);
};
void Vec4_22b170::Set(float angle, float* v) {
    hulk_freg a = angle * 0.5f;
    hulk_freg s = (hulk_freg)sin((double)a);
    w = (hulk_freg)cos((double)a);
    x = s * v[0];
    y = s * v[1];
    z = s * v[2];
}
