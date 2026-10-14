// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00359450 @ 0x00359450
// Interval of a box (centre c, half extents ext, axes ax/ay/az) projected onto a direction.
struct Vec3 {
    float x, y, z;
};

union AbsFloat {
    float f;
    unsigned int bits;
};

void __cdecl FUN_00359450(const Vec3 *dir, const Vec3 *c, const Vec3 *ext, const Vec3 *ax, const Vec3 *ay,
                          const Vec3 *az, float *outMin, float *outMax)
{
    float centre = c->z * dir->z + c->y * dir->y + c->x * dir->x;

    AbsFloat px, py, pz;
    px.f = ax->z * dir->z + ax->y * dir->y + ax->x * dir->x;
    px.bits &= 0x7fffffff;
    py.f = ay->z * dir->z + ay->y * dir->y + ay->x * dir->x;
    py.bits &= 0x7fffffff;
    pz.f = az->z * dir->z + az->y * dir->y + az->x * dir->x;
    pz.bits &= 0x7fffffff;

    float radius = pz.f * ext->z + py.f * ext->y + px.f * ext->x;
    *outMin = centre - radius;
    *outMax = centre + radius;
}
