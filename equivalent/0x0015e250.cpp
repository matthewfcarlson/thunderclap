// STATUS: equivalent (tools/equiv.py level 3: 19963 inputs, branch coverage 28/28)
// hulkfight::motion::LocomotionSprintAction::vfunc_5 @ 0x0015e250
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

extern "C" double sqrt(double);

struct V3_15e250 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(V3_15e250 *other, float limit);
};

struct Stats_15e250 {
    char pad0[0x2064];
    V3_15e250 v2064;
    char pad2070[4];
    V3_15e250 v2074;
    float FUN_000354c0();
    char FUN_00035550(V3_15e250 *out);
};

struct Target_15e250 {
    char pad0[0x8a0];
    float f8a0;
    float f8a4;
    float f8a8;
    float f8ac;
    float f8b0;
};

struct Cfg_15e250 {
    char pad0[0x18];
    float f18;
    float f1c;
    float f20;
    float f24;
};

void *__fastcall FUN_000592a0(void *owner);
Stats_15e250 *__fastcall FUN_00059a30(void *x);
double __cdecl FUN_00224ea0(float x, float z);
double __cdecl FUN_00224fc0(int a, int b);
double __cdecl FUN_00224f10(V3_15e250 *v);
double __cdecl FUN_00083d90(float *v);
void __cdecl FUN_00224d70(int angle, V3_15e250 *v);

union Slot_15e250 {
    int i;
    float f;
    unsigned int u;
};

union Bits_15e250 {
    float f;
    unsigned int u;
    int i;
};

class LocomotionSprintAction {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual bool vfunc_5(Slot_15e250 a1, Slot_15e250 a2);
    char pad04[0x1c - 4];
    Cfg_15e250 *cfg;
    void *owner;
    Target_15e250 *target;
    char pad28[4];
    float f2c;
    float FUN_0015c4f0(float v);
};

bool LocomotionSprintAction::vfunc_5(Slot_15e250 a1, Slot_15e250 a2)
{
    struct Frame {
        float s0;
        float s4;
        float s8;
        float sC;
        float s10;
        float s14;
        V3_15e250 w;
        V3_15e250 v2;
        V3_15e250 z;
        V3_15e250 v;
        V3_15e250 v0;
        V3_15e250 v1;
    } f;

    if (a1.i != 0)
        return true;
    if (target == 0)
        return false;

    Stats_15e250 *st = FUN_00059a30(FUN_000592a0(owner));
    f.v = st->v2064;
    f.z.x = 0.0f;
    f.z.y = 0.0f;
    f.z.z = 0.0f;
    if (f.v.FUN_0022d2b0(&f.z, 1e-5f)) {
        f.v = st->v2074;
        f.z.x = 0.0f;
        f.z.y = 0.0f;
        f.z.z = 0.0f;
        if (f.v.FUN_0022d2b0(&f.z, 1e-5f))
            st->FUN_00035550(&f.v);
    }

    a1.f = (float)FUN_00224ea0(f.v.x, f.v.z);
    int h0 = a1.i;
    f.s14 = FUN_0015c4f0(1.0f);
    *(int *)&f.s0 = *(int *)&target->f8ac;
    float cur = st->FUN_000354c0();
    target->f8a8 = cur;
    double dd = FUN_00224fc0(*(int *)&f.s0, h0);
    dd = dd * 0.31830987f;
    Cfg_15e250 *c = cfg;
    *(int *)&f.s4 = *(int *)&c->f1c;
    *(int *)&a1.i = *(int *)&c->f18;
    dd = dd * f.s4;
    f.s10 = (float)dd;

    double rr = dd;
    if (a1.f > 0.0f) {
        Bits_15e250 fc;
        fc.f = f2c;
        Bits_15e250 ab;
        ab.u = fc.u & 0x7fffffff;
        *(int *)&f.sC = fc.i;
        if (ab.f < a1.f)
            f.s8 = ab.f;
        else
            f.s8 = a1.f;
        rr = (double)f.s10 - FUN_00083d90(&f2c) * f.s8 / a1.f * f.s4;
    }
    Target_15e250 *t1 = target;
    double sum = rr * a2.f + f2c;
    f2c = (float)sum;
    double ang = sum * a2.f + f.s0;
    t1->f8a8 = (float)ang;
    float na = (float)ang;
    f.s0 = na;
    target->f8ac = na;
    target->f8b0 = f.s14;
    f.s0 = (float)FUN_00224fc0(h0, *(int *)&na);

    f.v0 = (*(V3_15e250*)&DAT_004b4d60);
    FUN_00224d70(*(int *)&na, &f.v0);
    f.v1 = (*(V3_15e250*)&DAT_004b4d60);
    FUN_00224d70(h0, &f.v1);
    Cfg_15e250 *c2 = cfg;
    Slot_15e250 s20;
    s20.f = c2->f20;
    a1.f = s20.f;
    double dot = f.v0.z * f.v1.z + f.v0.y * f.v1.y + f.v0.x * f.v1.x;
    double t;
    if (dot < a1.f)
        t = 0.0;
    else if (dot < 0.0)
        t = 0.0;
    else if (dot > 1.0)
        t = 1.0;
    else if (!(a1.f > 0.0f))
        t = dot;
    else
        t = (dot - a1.f) / a1.f;
    double u = 1.0 - t;
    f.sC = target->f8a0;
    f.s4 = target->f8a4;
    a1.f = (float)u;
    f.s8 = f.sC - f.s0;
    Bits_15e250 b1;
    b1.f = f.s8;
    b1.u &= 0x7fffffff;
    double outA;
    double outB;
    bool direct = false;
    if (b1.f <= 1e-5f) {
        f.s8 = f.s4 - a1.f;
        b1.f = f.s8;
        b1.u &= 0x7fffffff;
        if (b1.f <= 1e-5f)
            direct = true;
    }
    if (!direct) {
        f.s14 = c2->f24;
        if (f.s14 <= 0.0f)
            direct = true;
    }
    if (direct) {
        outA = f.s0;
        outB = a1.f;
    } else {
        f.v2 = (*(V3_15e250*)&DAT_004b4d60);
        FUN_00224d70(*(int *)&f.sC, &f.v2);
        f.v2.x = f.v2.x * f.s4;
        f.z = (*(V3_15e250*)&DAT_004b4d60);
        f.v2.y = f.v2.y * f.s4;
        f.v2.z = f.v2.z * f.s4;
        FUN_00224d70(*(int *)&f.s0, &f.z);
        f.z.x = f.z.x * a1.f;
        f.w.x = f.z.x;
        f.z.y = f.z.y * a1.f;
        f.w.y = f.z.y;
        f.z.z = f.z.z * a1.f;
        f.w.z = f.z.z;
        f.w.x = f.w.x - f.v2.x;
        f.w.y = f.w.y - f.v2.y;
        f.w.z = f.w.z - f.v2.z;
        a2.f = f.s14 * a2.f;
        double len = f.w.FUN_0022d110();
        if (len <= a2.f) {
            outA = f.s0;
            outB = a1.f;
        } else {
            struct { hulk_freg x, y; float z; } t;   // w * a2: z is stored (rounded), x and y stay in registers
            t.x = f.w.x * a2.f;
            t.y = f.w.y * a2.f;
            t.z = f.w.z * a2.f;
            f.w.x = t.x + f.v2.x;
            f.w.y = t.y + f.v2.y;
            f.w.z = t.z + f.v2.z;
            outA = FUN_00224f10(&f.w);
            outB = sqrt(f.w.z * f.w.z + f.w.y * f.w.y + f.w.x * f.w.x);
        }
    }
    target->f8a0 = (float)outA;
    target->f8a4 = (float)outB;
    return true;
}
