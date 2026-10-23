// STATUS: equivalent (tools/equiv.py level 3: 4020 inputs, branch coverage 69/78, incomplete)
// FUN_000396a0 @ 0x000396a0
// equiv-conv: FUN_00035e70 eax stack
#include "compat/ptr.h"
#include "decls/address.h"
extern "C" double sqrt(double);
extern "C" double atan2(double y, double x);

struct Obj13;

struct V3_396a0 {
    float x, y, z;
    float FUN_00018990();
    float FUN_000111f0();
    void FUN_0022d240(V3_396a0 *in, Obj13 *cam);
};

struct Obj13 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual Obj13 *v13();
};

struct Inner_396a0 {
    Obj13 *FUN_001c19a0();
};
struct Cam_396a0 {
    Inner_396a0 *inner;
    V3_396a0 *FUN_001c39d0();
};
Cam_396a0 *FUN_001c3d90();

struct HitObj_396a0 {
    char pad0[0x10];
    int f10;
};

struct Sub11c_396a0 {
    char pad0[0x1a0];
    float f1a0;
};
struct Sub8_396a0 {
    char pad0[0x40];
    int f40;
    char pad44[0x11c - 0x44];
    Sub11c_396a0 *p11c;
    HitObj_396a0 *FUN_001d75c0(int idx);
};
struct Thing_396a0 {
    char pad0[8];
    Sub8_396a0 *p8;
    int type;
};

struct Ray_396a0 {
    char FUN_00201e00(V3_396a0 *from, V3_396a0 *to, int one, V3_396a0 *outA, V3_396a0 *outB, int z1, HitObj_396a0 **hit);
};
struct List_396a0 {
    int **begin;
    int **end;
};
struct ListOwner_396a0 {
    List_396a0 *FUN_002ed700();
};
struct Mid_396a0 {
    char pad0[8];
    ListOwner_396a0 *p8;
};
struct World {
    char pad0[0x10];
    Mid_396a0 *p10;
    char pad14[0x24 - 0x14];
    Ray_396a0 *p24;
};

Thing_396a0 *FUN_000969d0(int a);
char FUN_00035e70(Thing_396a0 *t, float len);

static float HalfPi()
{
    return 1.5707964f;
}

class Picker {
public:
    char pad0[0x328];
    Thing_396a0 *p328;
    void FUN_000350c0(V3_396a0 *out);
    char FUN_00039440(Thing_396a0 *t, V3_396a0 *out, int *score, int flag);
    Thing_396a0 *F(float x, float z, int minScore);
};

Thing_396a0 *Picker::F(float x, float z, int minScore)
{
    struct Frame {
        char pad0c[3];
        char flag;
        float d;
        int best;
        V3_396a0 R;
        int score2;
        V3_396a0 Tp;
        V3_396a0 T;
        HitObj_396a0 *hit;
        float bestAngle;
        float dA;
        float dB;
        V3_396a0 D;
        V3_396a0 H;
        V3_396a0 P;
        float B;
        Thing_396a0 *result;
        float A;
        int idx;
        float inv;
        int thisSpill;
        int f24spill;
        Obj13 *cam;
        int count;
        V3_396a0 W;
        V3_396a0 outA;
        V3_396a0 X;
        V3_396a0 outB;
    } fr;

    float len = (float)sqrt(x * x + z * z);
    if (len <= 0.0f)
        return 0;
    float inv0 = 1.0f / len;
    x = x * inv0;
    z = z * inv0;
    fr.cam = FUN_001c3d90()->inner->FUN_001c19a0()->v13();
    fr.P.x = 0;
    fr.P.y = 0;
    fr.P.z = 0;
    FUN_000350c0(&fr.P);
    Thing_396a0 *cur = p328;
    fr.best = 0x80000000;
    fr.A = 0;
    fr.B = 0;
    if (cur) {
        fr.Tp.x = 0;
        fr.Tp.y = 0;
        fr.Tp.z = 0;
        FUN_00039440(cur, &fr.Tp, &fr.best, 0);
        fr.R.FUN_0022d240(&fr.Tp, fr.cam);
        fr.A = (float)atan2(fr.R.x, fr.R.z);
        fr.B = (float)atan2(fr.R.y, fr.R.z);
    }
    Ray_396a0 *ray = DAT_004dd700->p24;
    fr.result = 0;
    fr.bestAngle = 3.4028235e38f;
    fr.flag = 0;
    List_396a0 *list = DAT_004dd700->p10->p8->FUN_002ed700();
    if (!list)
        return fr.result;
    int count = (int)(list->end - list->begin);
    for (int i = 0; i < count; i++) {
        int *item = list->begin[i];
        if (!item)
            continue;
        Thing_396a0 *th = FUN_000969d0(item[6]);
        if (!th)
            continue;
        if (th == p328)
            continue;
        fr.T.x = 0;
        fr.T.y = 0;
        fr.T.z = 0;
        fr.score2 = 0x80000000;
        if (!FUN_00039440(th, &fr.T, &fr.score2, 0))
            continue;
        int score2 = fr.score2;
        if (score2 < minScore)
            continue;
        char bl;
        if (fr.best >= 50) {
            if (score2 < 50)
                continue;
            bl = 0;
        } else {
            bl = score2 >= 50;
        }
        fr.W.FUN_0022d240(&fr.T, fr.cam);
        fr.dA = (float)atan2(fr.W.x, fr.W.z) - fr.A;
        fr.dB = (float)atan2(fr.W.y, fr.W.z) - fr.B;
        fr.d = (float)sqrt(fr.dB * fr.dB + fr.dA * fr.dA);
        if (fr.d > 4.71238899f) {
            if (!bl)
                continue;
        }
        float u, v;
        if (fr.d > 0.0f) {
            fr.inv = 1.0f / fr.d;
            u = fr.inv * fr.dA;
            v = fr.inv * fr.dB;
        } else {
            u = 0.0f;
            v = 0.0f;
        }
        float dot = u * x + v * z;
        if (dot < 0.0f && !bl)
            continue;
        static float halfPi = HalfPi();
        fr.d = fr.d - dot * halfPi;
        if (!(fr.d < fr.bestAngle) && !fr.flag && !bl)
            continue;
        char ok = 1;
        if (th->type == 1) {
            fr.D.x = fr.T.x - fr.P.x;
            fr.D.y = fr.T.y - fr.P.y;
            fr.D.z = fr.T.z - fr.P.z;
            float dl = fr.D.FUN_00018990();
            ok = FUN_00035e70(th, dl);
        }
        bl = 0;
        if (ok) {
            V3_396a0 *cp = FUN_001c3d90()->FUN_001c39d0();
            fr.X.x = cp->x;
            fr.X.y = cp->y;
            fr.X.z = cp->z;
            fr.Tp.x = fr.T.x;
            fr.Tp.y = fr.T.y;
            fr.Tp.z = fr.T.z;
            fr.hit = 0;
            if (th->type == 1 && th->p8 && th->p8->p11c)
                fr.Tp.y = fr.Tp.y + th->p8->p11c->f1a0;
            bl = ray->FUN_00201e00(&fr.X, &fr.Tp, 1, &fr.outA, &fr.outB, 0, &fr.hit);
            if (bl) {
                fr.H.x = fr.outA.x - fr.Tp.x;
                fr.H.y = fr.outA.y - fr.Tp.y;
                fr.H.z = fr.outA.z - fr.Tp.z;
                if (fr.H.FUN_000111f0() < 100.0f) {
                    bl = 0;
                } else {
                    bool commit = false;
                    if (fr.hit && th->type == 5 && th->p8) {
                        HitObj_396a0 *ho = th->p8->FUN_001d75c0(th->p8->f40);
                        if (ho && ho->f10 == (hulk_intptr)fr.hit) {
                            bl = 0;
                            commit = true;
                        }
                    }
                    if (!commit) {
                        fr.D.x = fr.P.x - fr.T.x;
                        fr.D.y = fr.P.y - fr.T.y;
                        fr.D.z = fr.P.z - fr.T.z;
                        if (!(fr.D.FUN_000111f0() < 10000.0f))
                            continue;
                        if (score2 >= 100 && fr.best < 100) {
                            commit = true;
                        } else {
                            if (!fr.flag)
                                continue;
                            if (fr.d >= fr.bestAngle)
                                continue;
                            commit = true;
                        }
                    }
                }
            }
        }
        fr.result = th;
        fr.bestAngle = fr.d;
        fr.best = score2;
        fr.flag = bl;
    }
    return fr.result;
}
