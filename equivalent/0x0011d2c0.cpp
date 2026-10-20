// STATUS: equivalent (tools/equiv.py level 3: 3087 inputs, branch coverage 62/62)
// hulkfight::ai::PathFormationAction::vfunc_5 @ 0x0011d2c0
#include "decls/address.h"
#include "decls/data/game/hulkfight/ai.h"
struct V3_11d2c0 {
    float x, y, z;
    float FUN_0022d110();
};

struct Body_11d2c0 {
    struct Info_11d2c0 *FUN_00059a30();
    void FUN_00059a50(V3_11d2c0 *out);
};
struct Info_11d2c0 {
    char pad[0x140];
    int f140;
};

struct Sub11c_11d2c0 {
    char pad[0x380];
    int f380;
};

struct Source_11d2c0 {
    char pad0[0x1a60];
    V3_11d2c0 v1a60;
};

struct Thing_11d2c0 {
    char pad0[8];
    Source_11d2c0 *p8;
    int mode;
    char pad10[0x40 - 0x10];
    V3_11d2c0 v40;
};

struct Owner_11d2c0 {
    char pad0[0x10];
    Body_11d2c0 *p10;
    char pad14[0x11c - 0x14];
    Sub11c_11d2c0 *p11c;
    char pad120[0x328 - 0x120];
    Thing_11d2c0 *f328;
    char pad32c[0x1a60 - 0x32c];
    V3_11d2c0 v1a60;
    char pad1a6c[0x1b38 - 0x1a6c];
    float f1b38;
    char pad1b3c[0x2064 - 0x1b3c];
    V3_11d2c0 dir;
    float speed;
    V3_11d2c0 aim;
    void FUN_00035550(V3_11d2c0 *out);
};

struct Target7c {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    char pad04[0x28 - 4];
    int f28;
    char pad2c[4];
    float f30;
};

struct Global_11d2c0 {
    char pad0[0x150];
    int f150;
    char pad154[0x2c8 - 0x154];
    int f2c8;
    void FUN_000671b0(V3_11d2c0 *p);
};
Global_11d2c0 *FUN_000678d0();

struct Hub1c_11d2c0 {
    char FUN_001ae2c0(V3_11d2c0 *a, V3_11d2c0 *b, V3_11d2c0 *c, float f1, float f2, float f3, int i1, int i2, int i3, int i4, int i5,
                      float t, int i6);
};
struct World {
    char pad0[0x1c];
    Hub1c_11d2c0 *f1c;
};

void FUN_00018810(Thing_11d2c0 **slot, Thing_11d2c0 *t);
char FUN_00018960(float a, float b, float eps);

class PathFormationAction {
public:
    char pad0[0x1c];
    char b1c;
    char b1d;
    char pad1e[2];
    V3_11d2c0 v20;
    V3_11d2c0 v2c;
    char pad38[0x64 - 0x38];
    V3_11d2c0 v64;
    char pad70[4];
    int mode;
    char pad78[4];
    Target7c *p7c;
    void *p80;
    Thing_11d2c0 *p84;
    char pad88[0xb8 - 0x88];
    Owner_11d2c0 *owner;
    char padbc[4];
    int idLo;
    int idHi;
    char bC8;
    char padc9[3];
    float fCC;
    char F(int a, float dt);
};

char PathFormationAction::F(int a, float dt)
{
    Owner_11d2c0 *own = owner;
    int var4 = 1;
    if (own)
        var4 = own->p11c->f380;
    fCC = dt + fCC;
    if (a != 0)
        return 1;
    if (!p80 || !own)
        return 0;
    V3_11d2c0 U;
    V3_11d2c0 W;
    U.x = 0; U.y = 0; U.z = 0;
    W.x = 0; W.y = 0; W.z = 0;
    float T = 0.0f;
    Thing_11d2c0 *th = own->f328;
    if (!th) {
        th = p84;
        if (!th)
            return 1;
    }
    V3_11d2c0 P = th->v40;
    int c28 = p7c->f28;
    FUN_000678d0()->f2c8 = c28;
    if (FUN_000678d0()->f150 < p7c->f28)
        return 1;
    FUN_000678d0()->FUN_000671b0(&P);
    owner->FUN_00035550(&U);
    V3_11d2c0 X;
    X.x = U.x; X.y = U.y; X.z = U.z;
    own = owner;
    v20 = own->v1a60;
    float f1b = owner->f1b38;
    if (!(f1b == 0.0f))
        T = f1b;
    FUN_00018810(&p84, th);

    bool skipTo2d4 = false;
    if (bC8) {
        if (!(idLo == DAT_004e0d18 && idHi == DAT_004e0d1c)) {
            if (fCC > 5.0f) {
                bC8 = 0;
                fCC = 0;
            }
        }
        if (bC8) {
            float r = p7c->v7();
            if (!(r < 0.0f))
                skipTo2d4 = true;
        }
    }
    if (!skipTo2d4) {
        V3_11d2c0 Y;
        if (th->mode == 1) {
            Y = th->p8->v1a60;
        } else {
            Y = th->v40;
        }
        if (owner->p10->FUN_00059a30()->f140 != 1)
            return 1;
        V3_11d2c0 Z;
        owner->p10->FUN_00059a50(&Z);
        V3_11d2c0 Q = v2c;
        char ok = DAT_004dd700->f1c->FUN_001ae2c0(&v2c, &Z, &Y, 6.0f, 200.0f, 360.0f, 1, 0, 3, var4, 1, T, 0);
        if (ok)
            bC8 = 1;
        else
            v2c = Q;
        b1c = 1;
    }
    W.x = v2c.x - v20.x;
    W.y = 0;
    W.z = v2c.z - v20.z;
    float lenW = W.FUN_0022d110();
    T = lenW;

    float A, B;
    if (!bC8 || !b1d) {
        A = 0.0f;
        B = X.y;
    } else if (mode != 2) {
        V3_11d2c0 Y;
        Y.x = v64.x - v20.x;
        Y.y = 0;
        Y.z = v64.z - v20.z;
        float L = Y.FUN_0022d110();
        int lo = idLo;
        int d28 = DAT_004e0d28;
        int hi = idHi;
        bool toW;
        if ((lo == d28 && hi == DAT_004e0d2c) || (lo == DAT_004e0d18 && hi == DAT_004e0d1c)) {
            toW = false;
        } else if (FUN_00018960(L, 0.0f, 1.0e-5f)) {
            toW = true;
        } else {
            toW = !(T > p7c->f30);
        }
        if (toW) {
            U.x = W.x; U.y = W.y; U.z = W.z;
            X.x = W.x;
            X.z = W.z;
            A = 0.0f;
            B = W.y;
        } else {
            U.x = Y.x; U.y = Y.y; U.z = Y.z;
            if (lo == d28 && hi == DAT_004e0d2c) {
                U.x = Y.x * -1.0f;
                U.y = Y.y * -1.0f;
                U.z = Y.z * -1.0f;
            }
            X.x = Y.x;
            X.z = Y.z;
            A = 1.0f;
            B = Y.y;
        }
    } else {
        V3_11d2c0 Y;
        Y.x = v2c.x - v20.x;
        Y.y = v2c.y;
        Y.z = v2c.z - v20.z;
        if (T > p7c->f30) {
            U.x = Y.x;
            U.y = 0;
            U.z = Y.z;
            if (idLo == DAT_004e0d28 && idHi == DAT_004e0d2c) {
                *(unsigned int *)&U.y = 0x80000000;
                U.x = Y.x * -1.0f;
                U.z = Y.z * -1.0f;
            }
            X.x = Y.x;
            X.z = Y.z;
            A = 1.0f;
            B = 0.0f;
        } else {
            U.x = W.x; U.y = W.y; U.z = W.z;
            X.x = W.x;
            X.z = W.z;
            A = 0.0f;
            B = W.y;
        }
    }
    Owner_11d2c0 *o = owner;
    o->speed = A;
    o->dir.x = X.x;
    o->dir.y = B;
    o->dir.z = X.z;
    o->aim.x = U.x;
    o->aim.y = U.y;
    o->aim.z = U.z;
    return 1;
}
