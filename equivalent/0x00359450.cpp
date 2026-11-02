// STATUS: equivalent (tools/equiv.py level 3: 20016 inputs, branch coverage 0/0)
// FUN_00359450 @ 0x00359450
// Interval of a box (centre c, half extents ext, axes ax/ay/az) projected onto a direction.
#include "compat/ptr.h"
struct Vec3_359450 {
    float x, y, z;
};

union AbsFloat {
    float f;
    unsigned int bits;
};

extern "C" void __cdecl FUN_00359450(const void * dir_, const void *c, const void * ext_, const void *ax, const void *ay,
                          const void *az, float *outMin, float *outMax)
{
    const Vec3_359450 * dir = (const Vec3_359450 *)dir_;
    const Vec3_359450 * ext = (const Vec3_359450 *)ext_;
    hulk_freg centre = ((const Vec3_359450 *)c)->z * dir->z + ((const Vec3_359450 *)c)->y * dir->y + ((const Vec3_359450 *)c)->x * dir->x;

    AbsFloat px, py, pz;
    px.f = ((const Vec3_359450 *)ax)->z * dir->z + ((const Vec3_359450 *)ax)->y * dir->y + ((const Vec3_359450 *)ax)->x * dir->x;
    px.bits &= 0x7fffffff;
    py.f = ((const Vec3_359450 *)ay)->z * dir->z + ((const Vec3_359450 *)ay)->y * dir->y + ((const Vec3_359450 *)ay)->x * dir->x;
    py.bits &= 0x7fffffff;
    pz.f = ((const Vec3_359450 *)az)->z * dir->z + ((const Vec3_359450 *)az)->y * dir->y + ((const Vec3_359450 *)az)->x * dir->x;
    pz.bits &= 0x7fffffff;

    hulk_freg radius = pz.f * ext->z + py.f * ext->y + px.f * ext->x;
    *outMin = centre - radius;
    *outMax = centre + radius;
}
