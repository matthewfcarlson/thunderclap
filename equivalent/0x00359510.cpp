// STATUS: equivalent (tools/equiv.py level 3: 20022 inputs, branch coverage 17/18, incomplete)
// FUN_00359510 @ 0x00359510
#include "compat/ptr.h"
struct Vec3 {
    float x, y, z;
};
extern void __cdecl FUN_003579f0(const Vec3* axis, const Vec3* const* tri, float* mn, float* mx);
extern void __cdecl FUN_00359450(const Vec3* axis, const Vec3* center, const float* half, const Vec3* a0,
                                 const Vec3* a1, const Vec3* a2, float* lo, float* hi);

// Triangle (t0,t1,t2) against an oriented box (center, half extents, three axes): separating-axis test.
bool __cdecl FUN_00359510(const Vec3* center, const float* half, const Vec3* ax0, const Vec3* ax1,
                          const Vec3* ax2, const Vec3* t0, const Vec3* t1, const Vec3* t2) {
    struct Frame {
        float mn, lo, hi, mx;
        int j;
        int diff;
        Vec3 v;
        Vec3 e2;
        Vec3 e1;
        const Vec3* axes[3];
        const Vec3* tri[3];
        Vec3 edge[3];
    } f;
    f.axes[0] = ax0;
    f.axes[1] = ax1;
    f.axes[2] = ax2;
    f.tri[0] = t0;
    f.tri[1] = t1;
    f.tri[2] = t2;
    const float* h = half;
    // the first loop walks half[] and axes[] together (the original keeps their byte distance in a stack slot)
    f.diff = (int)((const char*)f.axes - (const char*)half);
    for (f.j = 0; f.j < 3; f.j++, h++) {
        f.v = **(const Vec3* const*)((const char*)h + f.diff);
        FUN_003579f0(&f.v, f.tri, &f.mn, &f.mx);
        double d = (double)f.v.x * center->x;
        d = d + (double)f.v.y * center->y;
        d = d + (double)f.v.z * center->z;
        f.lo = (float)(d - *h);
        double hi = d + *h;
        f.hi = (float)hi;
        if (hi < f.mn)
            return false;
        if (f.mx < f.lo)
            return false;
    }
    f.e1.x = t1->x - t0->x;
    f.e1.y = t1->y - t0->y;
    f.e1.z = t1->z - t0->z;
    f.edge[0] = f.e1;
    f.e2.x = t2->x - t0->x;
    f.e2.y = t2->y - t0->y;
    f.e2.z = t2->z - t0->z;
    f.edge[1] = f.e2;
    f.edge[2].x = f.e2.x - f.e1.x;
    f.edge[2].y = f.e2.y - f.e1.y;
    f.edge[2].z = f.e2.z - f.e1.z;
    f.v.x = f.e2.z * f.e1.y - f.e2.y * f.e1.z;
    f.v.y = f.e1.z * f.e2.x - f.e2.z * f.e1.x;
    hulk_freg vz = f.e2.y * f.e1.x - f.e1.y * f.e2.x;   // stored rounded, used unrounded
    f.v.z = vz;
    hulk_freg dd = vz * t0->z;     // one term per statement, in the listing's order
    dd += f.v.y * t0->y;
    dd += f.v.x * t0->x;
    f.mn = dd;
    f.mx = dd;
    FUN_00359450(&f.v, center, half, ax0, ax1, ax2, &f.lo, &f.hi);
    if (f.hi < f.mn)
        return false;
    if (f.mn < f.lo)
        return false;
    for (f.j = 0; f.j < 3; f.j++) {
        for (int i = 0; i < 3; i++) {
            const Vec3* a = f.axes[i];
            const Vec3& e = f.edge[f.j];
            f.v.x = e.y * a->z - e.z * a->y;
            f.v.y = a->x * e.z - a->z * e.x;
            f.v.z = a->y * e.x - a->x * e.y;
            FUN_003579f0(&f.v, f.tri, &f.mn, &f.mx);
            FUN_00359450(&f.v, center, half, ax0, ax1, ax2, &f.lo, &f.hi);
            if (f.hi < f.mn)
                return false;
            if (f.mx < f.lo)
                return false;
        }
    }
    return true;
}
