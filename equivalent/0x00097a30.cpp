// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 54/54)
// FUN_00097a30 @ 0x00097a30
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"

extern "C" double cos(double);

struct V3_97a30 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_000111b0(const V3_97a30 *a, const V3_97a30 *b);
    float FUN_000111f0();
};

struct Mat_97a30 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(const V3_97a30 *axis, float angle);
    void FUN_0022c3b0(const V3_97a30 *in, V3_97a30 *out);
};

struct Rng_97a30 {
    int FUN_00011380(int a, int b);
    float FUN_000787e0(float lo, float hi);
};


bool __cdecl FUN_00096b50(void *ev, V3_97a30 *out, int *err);
void __cdecl FUN_00096b00(void *ev, V3_97a30 *out);
float __cdecl FUN_000189c0(float v);
float __cdecl FUN_00018710(float *k, float *len);
void __cdecl FUN_00224d70(float angle, V3_97a30 *v);

union FU_97a30 {
    float f;
    unsigned int u;
};

struct Frame_97a30 {
    float s;            // 0x00
    V3_97a30 v;               // 0x04
    float len;          // 0x10
    V3_97a30 r;               // 0x14
    V3_97a30 p;               // 0x20
    V3_97a30 w;               // 0x2c
    union {
        int err;
        float k;
    } u38;              // 0x38
    V3_97a30 axis;            // 0x3c
    V3_97a30 cross;           // 0x48
    Mat_97a30 m;              // 0x54
};

int __cdecl FUN_00097a30(float a0, float a1, float a2, void *a3, float a4, V3_97a30 *a5, float a6, V3_97a30 *a7,
                         float a8, float a9, float a10, int a11)
{
    Frame_97a30 f;
    int mode;

    f.v.x = 0.0f;
    f.v.y = 0.0f;
    f.v.z = 0.0f;
    if (!FUN_00096b50(a3, &f.v, &f.u38.err))
        return a11;
    f.v.y = f.v.y + a4;

    mode = a11;
    if (a9 != 0.0f && a10 != 0.0f) {
        Rng_97a30 *rng = (*(Rng_97a30**)&DAT_004e5acc);
        if (mode == 1)
            mode = rng->FUN_00011380(2, 0xb);
        switch (mode) {
        case 2:
            f.v.x = rng->FUN_000787e0(a9, a10) + f.v.x;
            f.v.x = f.v.x - rng->FUN_000787e0(a9, a10);
            break;
        case 3:
            f.v.z = rng->FUN_000787e0(a9, a10) + f.v.z;
            break;
        case 4:
            f.v.z = f.v.z - rng->FUN_000787e0(a9, a10);
            break;
        case 5:
            f.v.z = rng->FUN_000787e0(a9, a10) + f.v.z;
            f.v.z = f.v.z - rng->FUN_000787e0(a9, a10);
            break;
        case 6:
            f.v.z = rng->FUN_000787e0(a9, a10) + f.v.z;
            f.v.x = f.v.x - rng->FUN_000787e0(a9, a10);
            break;
        case 7:
            f.v.z = f.v.z - rng->FUN_000787e0(a9, a10);
            f.v.x = rng->FUN_000787e0(a9, a10) + f.v.x;
            break;
        case 8:
            f.v.x = rng->FUN_000787e0(a9, a10) + f.v.x;
            f.v.z = rng->FUN_000787e0(a9, a10) + f.v.z;
            break;
        case 9:
            f.v.x = f.v.x - rng->FUN_000787e0(a9, a10);
            f.v.z = f.v.z - rng->FUN_000787e0(a9, a10);
            break;
        case 10:
            f.v.x = rng->FUN_000787e0(a9, a10) + f.v.x;
            break;
        case 11:
            f.v.x = f.v.x - rng->FUN_000787e0(a9, a10);
            break;
        default:
            break;
        }
    }

    f.w.x = f.v.x - a5->x;
    f.w.y = f.v.y - a5->y;
    f.w.z = f.v.z - a5->z;
    f.len = f.w.FUN_0022d110();
    if (a8 != 0.0f)
        FUN_00224d70(a8, &f.w);

    if (f.w.x * a7->x + f.w.y * a7->y + f.w.z * a7->z < a2)
        return 0;
    *a7 = f.w;
    if (a0 <= 0.0f)
        return mode;
    if (a1 <= 0.0f)
        return mode;

    f.s = f.len / a0;
    f.r.x = 0.0f;
    f.r.y = 0.0f;
    f.r.z = 0.0f;
    FUN_00096b00(a3, &f.r);
    f.r.y = 0.0f;
    double c = f.r.FUN_0022d110();
    if (c > a0)
        c = a0;
    f.r.x = f.r.x * c;
    f.r.y = f.r.y * c;
    double zz = f.r.z * c;
    f.r.z = (float)zz;
    if (f.len > 50.0f) {
        f.u38.k = 1.0f - (f.len - 50.0f) * 0.02f;
        f.len = 0.0f;
        double fac = FUN_00018710(&f.u38.k, &f.len);
        f.r.x = f.r.x * fac;
        f.r.y = f.r.y * fac;
        zz = fac * f.r.z;
    }
    f.r.x = f.r.x * f.s;
    f.r.y = f.r.y * f.s;
    f.r.z = (float)(zz * f.s);

    f.v.x = f.r.x + f.v.x;
    f.p.x = f.v.x;
    f.v.y = f.r.y + f.v.y;
    f.p.y = f.v.y;
    f.v.z = f.r.z + f.v.z;
    f.p.z = f.v.z;
    f.p.x = f.p.x - a5->x;
    f.p.y = f.p.y - a5->y;
    f.p.z = f.p.z - a5->z;
    f.p.FUN_0022d110();
    double dot = f.p.x * a7->x + f.p.z * a7->z + f.p.y * a7->y;

    double sd = f.s * a1;
    f.s = (float)sd;
    if (sd < 0.0f || f.s > 3.14159274f)
        f.s = 3.14159274f;

    if (dot < cos(f.s) - DAT_004dd940) {
        if (dot > DAT_004dd940 - 1.0f) {
            f.axis.FUN_000111b0(&f.p, a7);
            if (f.axis.FUN_000111f0() > 0.0f) {
                f.m.FUN_0022b980();
                f.m.FUN_0022baf0(&f.axis, f.s);
                f.m.FUN_0022c3b0(a7, &f.p);
            }
        }
    }
    if (a8 == 0.0f) {
        a7->x = f.p.x;
        a7->y = f.p.y;
        a7->z = f.p.z;
    } else {
        a7->y = f.p.y;
    }

    if (a6 <= 0.0f)
        return mode;
    double F = FUN_000189c0(f.p.y);
    f.u38.k = (float)F;
    FU_97a30 q;
    q.f = f.u38.k;
    q.u &= 0x7fffffff;
    f.len = q.f;
    if (!(f.len < a6))
        return mode;
    double sd2 = ((a6 - f.len) / a6) * (f.s * 0.5f);
    f.s = (float)sd2;
    if (sd2 > a6)
        f.s = a6;
    if (f.s > 0.785398185f)
        f.s = 0.785398185f;
    if (f.s + F < 1.57079637f) {
        f.axis.x = 0.0f;
        f.axis.y = 1.0f;
        f.axis.z = 0.0f;
        f.cross.FUN_000111b0(&f.axis, a7);
        f.m.FUN_0022b980();
        f.m.FUN_0022baf0(&f.cross, f.s);
        f.m.FUN_0022c3b0(a7, &f.p);
        a7->y = f.p.y;
        a7->x = f.p.x;
        a7->z = f.p.z;
        return mode;
    }
    a7->x = 0.0f;
    a7->y = 1.0f;
    a7->z = 0.0f;
    return mode;
}
