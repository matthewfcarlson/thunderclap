// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 14/14)
// FUN_00358700 @ 0x00358700
extern "C" double __cdecl sqrt(double);

struct Vec3_358700 {
    float x, y, z;
};

union FS_358700 {
    float f;
    unsigned int u;
};

// stack-argument slots that the callees also use as float out-parameters
union VecSlot {
    Vec3_358700 *v;
    float f;
};

bool FUN_00358630(Vec3_358700 *a, Vec3_358700 *dir, float radius, float len, int zero, float planeD, Vec3_358700 *n, VecSlot *out);
bool FUN_003577c0(Vec3_358700 *p, Vec3_358700 *a, Vec3_358700 *b, void *c, Vec3_358700 *n);
bool FUN_00357960(Vec3_358700 *a, Vec3_358700 *dir, float reach, Vec3_358700 *p5, Vec3_358700 *p6, void *p7, Vec3_358700 *n, float *dist, Vec3_358700 *hit, Vec3_358700 *outN);
bool FUN_00358030(Vec3_358700 *a, Vec3_358700 *dir, int f1, Vec3_358700 *p5, Vec3_358700 *p6, void *p7, float *s, Vec3_358700 *pt, Vec3_358700 *q, float *w, float *t, int f2, int f3, int f4);

// Swept sphere (segment start a, direction dir, half length len, radius) against a triangle plane.
bool FUN_00358700(Vec3_358700 *a, Vec3_358700 *dir, float radius, float len, VecSlot p5, Vec3_358700 *p6, void *p7, VecSlot n8,
                  float *dist, Vec3_358700 *hit, Vec3_358700 *outN)
{
    struct Frame {
        FS_358700 ad;          // 0x00
        float w;        // 0x04
        Vec3_358700 lo;        // 0x08
        Vec3_358700 hi;        // 0x14
        Vec3_358700 v;         // 0x20
        Vec3_358700 pt;        // 0x2c
        float spare[3]; // 0x38
    } f;
    Vec3_358700 *n = n8.v;
    if (!FUN_00358630(a, dir, radius, len, 0, -(p5.v->z * n->z + p5.v->y * n->y + n->x * p5.v->x), n, &n8))
        return false;

    f.pt.x = len * dir->x;
    f.ad.f = len * dir->z;
    f.lo.x = a->x - f.pt.x;
    f.lo.y = a->y - len * dir->y;
    f.lo.z = a->z - len * dir->z;
    f.hi.x = f.pt.x + a->x;
    f.hi.y = len * dir->y + a->y;
    f.hi.z = f.ad.f + a->z;

    float d = ((f.lo.z - p6->z) * n->z + (f.lo.y - p6->y) * n->y) + (f.lo.x - p6->x) * n->x;
    *dist = d;
    f.ad.f = d;
    f.ad.u &= 0x7fffffff;
    if (f.ad.f < radius) {
        f.v.x = d * n->x;
        f.v.y = d * n->y;
        f.pt.z = f.lo.z - d * n->z;
        hit->z = f.pt.z;
        hit->x = f.lo.x - f.v.x;
        hit->y = f.lo.y - f.v.y;
        if (FUN_003577c0(hit, p5.v, p6, p7, n)) {
            *dist = n8.f;
            *outN = *n;
            return true;
        }
    }

    d = ((f.hi.z - p6->z) * n->z + (f.hi.y - p6->y) * n->y) + (f.hi.x - p6->x) * n->x;
    *dist = d;
    f.ad.f = d;
    f.ad.u &= 0x7fffffff;
    if (f.ad.f < radius) {
        f.v.x = d * n->x;
        f.v.y = d * n->y;
        f.pt.z = f.hi.z - d * n->z;
        hit->z = f.pt.z;
        hit->x = f.hi.x - f.v.x;
        hit->y = f.hi.y - f.v.y;
        if (FUN_003577c0(hit, p5.v, p6, p7, n)) {
            *dist = n8.f;
            *outN = *n;
            return true;
        }
    }

    if (FUN_00357960(&f.lo, dir, len + len + radius, p5.v, p6, p7, n, dist, hit, outN)) {
        *dist = n8.f;
        return true;
    }

    f.v.x = f.hi.x - f.lo.x;
    f.v.y = f.hi.y - f.lo.y;
    f.v.z = f.hi.z - f.lo.z;
    FUN_00358030(&f.lo, &f.v, 1, p5.v, p6, p7, &p5.f, &f.pt, &f.hi, &f.w, &f.ad.f, 1, 1, 1);
    // `x`, `z` and the sums below are stored to float temporaries by the original where noted; the rest stays on the FPU stack
    double pdx = p5.f * dir->x;
    double pdy = p5.f * dir->y;
    volatile float sz = p5.f * dir->z;
    volatile float x1 = pdx + f.lo.x;
    volatile float qz = f.hi.z * f.ad.f;
    volatile float px = f.pt.x + f.hi.x * f.ad.f;
    hit->x = px;
    volatile float pz = f.pt.z + qz;
    hit->y = f.pt.y + f.hi.y * f.ad.f;
    hit->z = pz;
    volatile float dx = x1 - px;
    volatile float dy = (pdy + f.lo.y) - (*(volatile float *)&f.pt.y + *(volatile float *)&f.hi.y * *(volatile float *)&f.ad.f);
    double dz = ((double)sz + (double)f.lo.z) - (double)pz;
    double ddy = dy;
    double ddx = dx;
    double r = sqrt((dz * dz + ddy * ddy) + ddx * ddx) - radius;
    *dist = (float)r;
    if (!(r < 0.0))
        return false;
    *dist = n8.f;
    *outN = *n;
    return true;
}
