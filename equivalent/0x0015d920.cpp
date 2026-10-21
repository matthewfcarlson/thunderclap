// STATUS: equivalent (tools/equiv.py level 3: 20024 inputs, branch coverage 69/70, incomplete)
// hulkfight::motion::LocomotionStrafeAction::vfunc_5 @ 0x0015d920
#include "compat/ptr.h"
extern "C" double fabs(double);

struct V3 {
    float x, y, z;
    char FUN_0022d2b0(const V3 *z, float eps);
    float FUN_0022d110();
    float FUN_00018990();
};

struct Obj10 {
    void FUN_00059a50(V3 *out);
};

struct Part8 {
    char pad0[0x10];
    Obj10 *f10;
    void FUN_001d69f0(V3 *out);
};

struct Obj328 {
    char pad0[8];
    Part8 *f8;
    int fc;
    char pad10[0x40 - 0x10];
    float f40, f44, f48;
};

struct Obj1ca0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int v9();
};

struct YObj {
    char pad0[0x10];
    Obj10 *f10;
    char pad14[0x144 - 0x14];
    unsigned int f144;
    char pad148[0x328 - 0x148];
    Obj328 *f328;
    char pad32c[0x1ca0 - 0x32c];
    Obj1ca0 *f1ca0;
    char pad1ca4[0x2064 - 0x1ca4];
    V3 v2064;
    float f2070;
    V3 v2074;
    char pad2080[0x20a8 - 0x2080];
    int f20a8;
    float FUN_000354c0();
    void FUN_00035550(V3 *out);
};

struct XObj {
    YObj *FUN_00059a30();
};
struct F1c {
    XObj *FUN_000592a0();
};

struct State {
    char pad0[0x12e0];
    float f12e0;
    float f12e4;
    float f12e8;
};

extern float DAT_004b4d60;
extern float DAT_004b4d64;
extern float DAT_004b4d68;

float __cdecl FUN_00224ea0(float a, float b);
float __cdecl FUN_00224fc0(float a, float b);
float __cdecl FUN_00224f10(V3 *v);
char __cdecl FUN_00018960(float a, float b, float c);
void __cdecl FUN_00224d70(float angle, V3 *v);

struct Frame {
    char pad0[3];
    char b3;            // 0x03
    float s10;          // 0x04
    float s14;          // 0x08
    float s18;          // 0x0c
    float s1c;          // 0x10
    float s20;          // 0x14
    float s24;          // 0x18
    float s28;          // 0x1c
    V3 H;               // 0x20
    V3 D;               // 0x2c
    V3 Vv;              // 0x38
    V3 G;               // 0x44
    V3 P;               // 0x50
    V3 Z1;              // 0x5c
    V3 Z2;              // 0x68
};

class LocomotionStrafeAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool v5(int a0, float dt);
    virtual void v6();
    virtual void v7();
    virtual void v8(float *a, float *b, char *c);
    char pad04[0x1c - 4];
    F1c *f1c;
    State *f20;
    float FUN_0015d4f0(float a, float b, float c);
};

bool LocomotionStrafeAction::v5(int a0, float dt)
{
    Frame f;

    if (f20 == 0)
        return false;
    YObj *Y = f1c->FUN_000592a0()->FUN_00059a30();
    f.s1c = -1.0f;
    f.s18 = -1.0f;
    f.b3 = 0;
    v8(&f.s1c, &f.s18, &f.b3);
    if (a0)
        return true;
    f20->f12e0 = Y->FUN_000354c0();
    Y->f10->FUN_00059a50(&f.P);
    if (Y->f328 != 0) {
        Obj328 *o = Y->f328;
        int kind = o->fc;
        if (kind == 1) {
            f.Vv.z = 0.0f;
            f.Vv.y = 0.0f;
            f.Vv.x = 0.0f;
            o->f8->f10->FUN_00059a50(&f.Vv);
        } else if (kind == 5) {
            o->f8->FUN_001d69f0(&f.Vv);
        } else {
            f.Vv.x = o->f40;
            f.Vv.y = o->f44;
            f.Vv.z = o->f48;
        }
        f.D.x = f.Vv.x - f.P.x;
        f.D.y = f.Vv.y - f.P.y;
        f.D.z = f.Vv.z - f.P.z;
        Obj1ca0 *o1 = Y->f1ca0;
        if (o1 != 0) {
            if (o1->v9() == 4) {
                f.D.x = f.D.x * -1.0f;
                f.D.y = f.D.y * -1.0f;
                f.D.z = f.D.z * -1.0f;
            }
        }
    } else {
        f.D.x = Y->v2074.x;
        f.D.y = Y->v2074.y;
        f.D.z = Y->v2074.z;
        f.Z1.x = 0.0f;
        f.Z1.y = 0.0f;
        f.Z1.z = 0.0f;
        if (f.D.FUN_0022d2b0(&f.Z1, 1e-5f)) {
            f.D.x = Y->v2064.x;
            f.D.y = Y->v2064.y;
            f.D.z = Y->v2064.z;
            f.Z2.x = 0.0f;
            f.Z2.y = 0.0f;
            f.Z2.z = 0.0f;
            if (f.D.FUN_0022d2b0(&f.Z2, 1e-5f))
                Y->FUN_00035550(&f.D);
        }
    }

    if (f.b3) {
        f.s20 = FUN_00224ea0(f.D.x, f.D.z);
        f.s10 = f20->f12e0;
        f.s28 = f.s18;
        double nv;
        if (f.s18 <= 0.0f) {
            nv = f.s20;
        } else {
            float diff = FUN_00224fc0(f.s10, f.s20);
            f.s14 = f.s28 * dt;
            f.s24 = diff;
            f.s24 = (float)fabs(f.s24);
            if (f.s24 <= f.s14) {
                nv = f.s20;
            } else if (diff < 0.0f) {
                nv = f.s10 - f.s14;
            } else {
                nv = f.s14 + f.s10;
            }
        }
        f.s10 = (float)nv;
        f20->f12e0 = (float)nv;
        f20->f12e4 = (float)nv;
        f.s24 = f20->f12e8;
        f.s14 = Y->f2070;
        if (!(Y->f20a8 < 0)) {
            if (f.s14 <= 0.0f) {
                f.s14 = 0.0f;
            } else {
                float old = f.s14;
                f.s14 = 0.5f;
                if (!(old <= 0.5f))
                    f.s14 = 1.0f;
            }
        }
        float n10 = f.s10;
        f.s14 = FUN_0015d4f0(f.s14, n10, n10);
        if (Y->f144 & 2) {
            float r2 = FUN_0015d4f0(0.5f, n10, n10);
            if (f.s14 > r2)
                f.s14 = r2;
        }
        if (!(f.s1c <= 0.0f)) {
            f.s20 = f.s1c * dt;
            double d = f.s14 - f.s24;
            if (d > 0.0) {
                if (!(f.s20 > d))
                    f20->f12e8 = (float)(f.s20 + f.s24);
                else
                    f20->f12e8 = f.s14;
            } else if (-f.s20 < d) {
                f20->f12e8 = f.s14;
            } else {
                f20->f12e8 = f.s24 - f.s20;
            }
            return true;
        }
        f20->f12e8 = f.s14;
        return true;
    }

    f.G.x = Y->v2064.x;
    f.G.y = Y->v2064.y;
    f.G.z = Y->v2064.z;
    f.s10 = Y->f2070;
    if (!(Y->f20a8 < 0)) {
        if (f.s10 <= 0.0f) {
            f.s10 = 0.0f;
        } else {
            float old = f.s10;
            f.s10 = 0.5f;
            if (!(old <= 0.5f))
                f.s10 = 1.0f;
        }
    }
    f.s24 = f.s10;
    f.s24 = (float)fabs(f.s24);
    if (f.s24 <= 1e-5f) {
        f.G.x = f.D.x;
        f.G.y = f.D.y;
        f.G.z = f.D.z;
    }
    {
        float c0 = f20->f12e0;
        float c4 = f20->f12e4;
        f.s28 = c0;
        f.s24 = c4;
        f.s10 = FUN_0015d4f0(f.s10, c4, c0);
    }
    if (Y->f144 & 2) {
        float d0 = f20->f12e0;
        float d4 = f20->f12e4;
        f.s28 = d0;
        f.s24 = d4;
        float r2 = FUN_0015d4f0(0.5f, d4, d0);
        if (f.s10 > r2)
            f.s10 = r2;
    }
    f.s28 = f20->f12e0;
    f.s20 = FUN_00224f10(&f.D);
    f.s24 = f.s18;
    double nvB;
    if (f.s18 <= 0.0f) {
        nvB = f.s20;
    } else {
        float diff = FUN_00224fc0(f.s28, f.s20);
        f.s14 = f.s24 * dt;
        f.s24 = diff;
        f.s24 = (float)fabs(f.s24);
        if (f.s24 <= f.s14)
            nvB = f.s20;
        else if (diff < 0.0f)
            nvB = f.s28 - f.s14;
        else
            nvB = f.s14 + f.s28;
    }
    f20->f12e0 = (float)nvB;
    float cur2 = f20->f12e4;
    float f8s = f20->f12e8;
    f.s14 = cur2;
    f.s24 = f8s;
    f.s20 = FUN_00224f10(&f.G);
    f.s28 = cur2 - f.s20;
    f.s28 = (float)fabs(f.s28);
    float p4;
    double p8;
    bool early = false;
    if (f.s28 <= 1e-5f) {
        if (FUN_00018960(f8s, f.s10, 1e-5f)) {
            p4 = f.s20;
            p8 = f.s10;
            early = true;
        }
    }
    if (!early) {
        f.s28 = f.s1c;
        if (f.s1c <= 0.0f) {
            p4 = f.s20;
            p8 = f.s10;
        } else {
            f.Vv.x = DAT_004b4d60;
            f.Vv.y = DAT_004b4d64;
            f.Vv.z = DAT_004b4d68;
            f.Vv.x = f.Vv.x * f8s;
            f.Vv.y = f.Vv.y * f8s;
            f.Vv.z = f.Vv.z * f8s;
            FUN_00224d70(cur2, &f.Vv);
            f.H.x = DAT_004b4d60;
            f.H.y = DAT_004b4d64;
            f.H.z = DAT_004b4d68;
            f.H.x = f.H.x * f.s10;
            f.H.y = f.H.y * f.s10;
            f.H.z = f.H.z * f.s10;
            FUN_00224d70(f.s20, &f.H);
            f.H.x = f.H.x - f.Vv.x;
            f.H.y = f.H.y - f.Vv.y;
            f.H.z = f.H.z - f.Vv.z;
            f.s24 = f.s28 * dt;
            if (f.H.FUN_0022d110() <= f.s24) {
                p4 = f.s20;
                p8 = f.s10;
            } else {
                struct { hulk_freg x, y; float z; } hs;   // H * s24: z is stored (rounded), x and y stay in registers
                hs.x = f.H.x * f.s24;
                hs.y = f.H.y * f.s24;
                hs.z = f.H.z * f.s24;
                f.H.x = hs.x + f.Vv.x;
                f.H.y = hs.y + f.Vv.y;
                f.H.z = hs.z + f.Vv.z;
                p4 = FUN_00224f10(&f.H);
                p8 = f.H.FUN_00018990();
            }
        }
    }
    f20->f12e4 = p4;
    f20->f12e8 = (float)p8;
    return true;
}
