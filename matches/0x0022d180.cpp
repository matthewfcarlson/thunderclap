#include "decls/data/game/global.h"
// data: one = DAT_003f32dc

#include "compat/ptr.h"
extern "C" double sqrt(double);
// x87: the squared length (x*x + y*y, then + z*z), its root and the reciprocal stay in registers; MSVC drops the
// (float) cast of sqrt's result
void __fastcall Normalize(float* p, void*) {
    hulk_freg s = (hulk_freg)p[0] * p[0] + (hulk_freg)p[1] * p[1] + (hulk_freg)p[2] * p[2];
    hulk_freg f = DAT_003f32dc / (hulk_freg)sqrt((double)s);
    p[0] = f * p[0];
    p[1] = f * p[1];
    p[2] = f * p[2];
}
