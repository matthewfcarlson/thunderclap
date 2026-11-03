#include "decls/data/game/global.h"
// data: one = DAT_003f32dc

#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" double sqrt(double);
// x87: the squared length (x*x + y*y, then + z*z), its root and the reciprocal stay in registers; MSVC drops the
// (float) cast of sqrt's result
void owners::Vec3_22d1c0::FUN_0022d1c0(const owners::Vec3_22d1c0* p) {
    hulk_freg s = (hulk_freg)p->x * p->x + (hulk_freg)p->y * p->y + (hulk_freg)p->z * p->z;
    hulk_freg f = DAT_003f32dc / (hulk_freg)sqrt((double)s);
    x = f * p->x;
    y = f * p->y;
    z = f * p->z;
}
