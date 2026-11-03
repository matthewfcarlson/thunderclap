#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
void owners::Vec4_22b170::FUN_0022b170(float angle, float* v) {
    hulk_freg a = angle * 0.5f;
    hulk_freg s = (hulk_freg)sin((double)a);
    w = (hulk_freg)cos((double)a);
    x = s * v[0];
    y = s * v[1];
    z = s * v[2];
}
