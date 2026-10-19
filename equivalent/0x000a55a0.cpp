// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 36/38, incomplete)
// FUN_000a55a0 @ 0x000a55a0
#include "decls/data/game/global.h"

struct V3_a55a0 {
    float x, y, z;
};

struct Sub32c_a55a0 {
    char pad0[0x345 - 0x32c];
    char FUN_000a2370(int dt, float *a, float *b, float *c);
};

struct Inner18 {
    char pad0[0x18];
    int kind;
};

struct Inner11c {
    char pad0[0x11c];
    Inner18 *f11c;
};

struct Stats_a55a0 {
    char pad0[0x338];
    Inner11c *f338;
    char FUN_00035550(V3_a55a0 *out);
};

union Slot_a55a0 {
    int i;
    float f;
    unsigned int u;
};


struct ThisCall_000a0dc0 {
    void FUN_000a0dc0(int a, int b, int c);
};
void __cdecl FUN_000a04c0(V3_a55a0 *v, float *p1, float *p2, float *p3);
double __cdecl FUN_000a00e0(int a, int b, int c, int d, int e);
double __cdecl FUN_000186b0(float *v, float *lo, float *hi);
double __cdecl FUN_000a0450(V3_a55a0 *v);
double __cdecl FUN_000a02a0(float v);
double __cdecl FUN_000a03c0(int v, float lo, float hi);
double __cdecl FUN_000a05b0(int a, float b, int c, int d, int e);
V3_a55a0 *__cdecl FUN_0009f8c0(V3_a55a0 *out, int a, int b, int c);

class Camera {
public:
    char pad0[0x194];
    V3_a55a0 out194;
    char pad1a0[0x1c4 - 0x1a0];
    V3_a55a0 pos;
    char pad1d0[0x1e8 - 0x1d0];
    V3_a55a0 tgt;
    char pad1f4[0x26c - 0x1f4];
    V3_a55a0 v26c;
    char pad278[0x2e4 - 0x278];
    float f2e4;
    float f2e8;
    float f2ec;
    char pad2f0[0x2f4 - 0x2f0];
    float f2f4;
    char pad2f8[0x2fc - 0x2f8];
    float f2fc;
    char pad300[0x32c - 0x300];
    Sub32c_a55a0 sub32c;
    char b345;
    char pad346[0x350 - 0x346];
    Stats_a55a0 *f350;
    char pad354[0x444 - 0x354];
    float f444;
    int f448;
    char pad44c[0x46c - 0x44c];
    float f46c;
    float f470;
    char pad474[4];
    int f478;
    int f47c;
    int f480;
    int f484;
    int f488;
    void FUN_000a0940(int z);
    void FUN_000a0ac0(float a, float b);
    void FUN_000a55a0(int a1, Slot_a55a0 a2);
};

void Camera::FUN_000a55a0(int a1, Slot_a55a0 a2)
{
    struct Frame {
        float s0;
        float s4;
        float s8;
        float s12;
        float s16;
        float s20;
        float s24;
        float s28;
        float s32;
        V3_a55a0 d;
        V3_a55a0 v;
    } f;

    int dt = a2.i;
    ((ThisCall_000a0dc0*)(this))->FUN_000a0dc0(0, *(int *)&DAT_0049ec7c, dt);
    f.d.x = v26c.x - pos.x;
    f.d.y = v26c.y - pos.y;
    f.d.z = v26c.z - pos.z;
    FUN_000a04c0(&f.d, &f.s4, &f.s0, &f.s8);
    f.s12 = f2fc + f2e8;
    a2.f = 5.0f;
    *(int *)&f.s16 = *(int *)&f444;
    f.s20 = f2f4 + f2ec + f2e4;
    double m08 = f444 * 0.8f;
    f.s32 = f444 * 1.2f;
    if (f.s8 < m08) {
        f.s16 = (float)m08;
        a2.i = *(int *)&DAT_0049ec54;
    } else if (f.s8 > f.s32) {
        f.s16 = f.s32;
        a2.i = *(int *)&DAT_0049ec54;
    }
    f.s8 = (float)FUN_000a00e0(*(int *)&f.s8, *(int *)&f.s16, a2.i, dt, 0x3f800000);

    if (!(DAT_0049ec60 - 2.0f > f.s0) && !(DAT_0049ec5c + 2.0f < f.s0)) {
        if (sub32c.FUN_000a2370(dt, &f.s32, &f.s16, &a2.f)) {
            f.s4 = (float)((double)f.s32 + f.s4);
            f.s16 = (float)((double)f.s16 + f.s0);
            double clamp = FUN_000186b0(&f.s16, &DAT_0049ec60, &DAT_0049ec5c);
            char flag = *(char *)&a2.i;
            double delta = clamp - f.s0;
            f.s0 = (float)clamp;
            f.s12 = (float)((double)f.s32 + f.s12);
            f.s20 = (float)((double)f.s20 - delta);
            if (flag)
                f488 = *(int *)&(*(float*)&DAT_0049ec98);
        } else if (b345) {
            Stats_a55a0 *e = f350;
            Inner11c *i1 = e->f338;
            if (i1 != 0) {
                Inner18 *i2 = i1->f11c;
                if (i2 != 0 && (i2->kind == 3 || i2->kind == 2)) {
                    if (e->FUN_00035550(&f.v)) {
                        double r1 = FUN_000a0450(&f.v);
                        double r2 = FUN_000a02a0((float)(r1 + 180.0f));
                        double x = FUN_000a03c0(*(int *)&f.s4, (float)(r2 - 70.0f), (float)(70.0f + r2));
                        if (!(f.s4 == x)) {
                            double r5 = FUN_000a05b0(0, (float)(x - f.s4), *(int *)&(*(float*)&DAT_0049ec44), dt,
                                                     0x40a00000);
                            f.s4 = (float)((double)f.s4 + r5);
                            f.s12 = (float)(r5 + f.s12);
                        }
                    }
                }
            }
        }
    } else {
        if (f.s0 >= DAT_0049ec60 && f.s0 <= DAT_0049ec5c)
            a2.f = f.s0;
        else if (f.s0 > DAT_0049ec5c)
            a2.i = *(int *)&DAT_0049ec5c;
        else
            a2.i = *(int *)&DAT_0049ec60;
        f.s0 = (float)FUN_000a00e0(*(int *)&f.s0, a2.i, *(int *)&(*(float*)&DAT_0049ec48), dt, 0);
    }

    V3_a55a0 *p = FUN_0009f8c0(&f.v, *(int *)&f.s4, *(int *)&f.s0, *(int *)&f.s8);
    float nx = pos.x + p->x;
    float ny = pos.y + p->y;
    f.v.z = pos.z + p->z;
    out194.z = f.v.z;
    out194.x = nx;
    out194.y = ny;
    FUN_000a0940(0);
    f478 = *(int *)&f.s4;
    f47c = *(int *)&f.s0;
    f480 = *(int *)&f.s8;
    f484 = f448;
    f488 = 0;

    f.v.x = tgt.x - out194.x;
    f.v.y = tgt.y - out194.y;
    f.v.z = tgt.z - out194.z;
    FUN_000a04c0(&f.v, &f.s28, &f.s24, &a2.f);
    a2.f = (float)FUN_000a00e0(*(int *)&f.s20, *(int *)&f.s24, *(int *)&(*(float*)&DAT_0049eca8), dt, 0x41200000);
    f.s16 = (float)FUN_000a05b0(*(int *)&f.s12, f.s28, *(int *)&(*(float*)&DAT_0049eca8), dt, 0x41200000);
    double h = f470 * 0.5f;
    f.s20 = (float)(f.s24 + h);
    double low = f.s24 - h;
    if (!(a2.f >= low)) {
        if (!(a2.f <= f.s20))
            a2.f = f.s20;
        else
            a2.f = (float)low;
    } else if (!(a2.f <= f.s20)) {
        a2.f = f.s20;
    }
    double h2 = f46c * 0.5f;
    int vbits = a2.i;
    f.s16 = (float)FUN_000a03c0(*(int *)&f.s16, (float)(f.s28 - h2), (float)(f.s28 + h2));
    FUN_000a0ac0(f.s16, *(float *)&vbits);
}
