// STATUS: equivalent (tools/equiv.py level 3: 3191 inputs, branch coverage 113/118, incomplete)
// AICollisionSolverAgent::vfunc_5 @ 0x001b2560
struct V3 {
    float x, y, z;
};

struct Body;
struct Sub {
    char pad0[0x104];
    int f104;
    char FUN_001d6980();
    void FUN_001d8350(void *shape);
    void FUN_001d7590();
    void FUN_0003aaf0(Body *b);
};

struct F74 {
    char pad0[0x72];
    char b72;
};

struct Body {
    char pad0[8];
    Sub *f8;
    int fc;
    char pad10[0x74 - 0x10];
    F74 *f74;
};

struct Ref {
    char pad0[8];
    unsigned int f8;
    unsigned int fc;
    char pad10[8];
    Body *f18;
};

struct Hold {
    char pad0[0x34];
    float f34;
};

struct Contact {
    Hold *f0;
    Hold *f4;
    Ref *f8;
    Ref *fc;
    char pad10[8];
    V3 v18;
    float f24;
    char pad28[4];
    V3 v2c;
    V3 v38;
};

struct Pool {
    char FUN_000242d0(void *shape);
};
struct Hub {
    char pad0[0x20];
    Pool *f20;
};
extern Hub *DAT_004dd700;
extern unsigned int DAT_004e2198;
extern unsigned int DAT_004e219c;
extern float DAT_004c3738;
extern int DAT_004c373c;

class Listener {
public:
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual void notify(Contact *c, int a1);
};

union FU {
    float f;
    unsigned int u;
};

class AICollisionSolverAgent {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5(Contact *c, int a1);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    char pad04[4];
    Listener *f8;

    int FUN_001afb80(Body *b, Body *a);
    int FUN_001afba0(Body *a, Body *b, V3 *p, V3 *q, float f);
    int FUN_001afdc0(Body *a, Body *b, V3 *p, V3 *q, float f);
    int FUN_001afe70(Body *a, Hold *h, Body *b, V3 *p, V3 *q, float f);
    void FUN_001b0090(Sub *s, Body *a, Body *b);
    int FUN_001b05a0(Sub *s, Body *b, Contact *c);
    int FUN_001b0e30(Body *a, Body *b, V3 *p, V3 *q, unsigned int fabsBits);
    int FUN_001afea0(Contact *c, Body *b0, Body *b1, Body *b2, V3 *p, V3 *q, float f);
    int FUN_001b1e90(Body *a, Body *b, V3 *p, V3 *q, V3 *r, float f);
    int FUN_001b1710(Body *x, Body *b, Body *a, V3 *p, V3 *q, float f);
    int FUN_001aff50(Body *a0, Body *a, Body *b0, Body *b, V3 *p, V3 *q, V3 *r, float f);
};

int AICollisionSolverAgent::v5(Contact *C, int a1)
{
    Body *A = C->f8->f18;
    Body *B = C->fc->f18;
    int typeA;
    int typeB;
    int res;
    V3 neg;
    Ref *s8;
    Ref *sc;
    Sub *sub;
    float v34;
    char flag;
    int lim;

    if (a1 > 1) {
        if (A->fc == 1)
            return 1;
        if (B->fc == 1)
            return 1;
        return 0;
    }
    typeA = A->fc;
    if (typeA == 2) {
        if (B->fc == 5)
            A->f8->FUN_0003aaf0(B);
        return 1;
    }
    typeB = B->fc;
    if (typeB == 2)
        return FUN_001afb80(B, A);
    if (typeA == 3) {
        if (typeB == 5) {
            neg.x = C->v18.x * -1.0f;
            neg.y = C->v18.y * -1.0f;
            neg.z = C->v18.z * -1.0f;
            return FUN_001afba0(A, B, &C->v38, &neg, C->f24);
        }
    } else if (typeB == 3 && typeA == 5) {
        return FUN_001afba0(B, A, &C->v2c, &C->v18, C->f24);
    }
    if (typeA == 4) {
        if (typeB == 5) {
            neg.x = C->v18.x * -1.0f;
            neg.y = C->v18.y * -1.0f;
            neg.z = C->v18.z * -1.0f;
            return FUN_001afdc0(A, B, &C->v38, &neg, C->f24);
        }
    } else if (typeB == 4 && typeA == 5) {
        return FUN_001afdc0(B, A, &C->v2c, &C->v18, C->f24);
    }
    if (typeA == 6) {
        neg.x = C->v18.x * -1.0f;
        neg.y = C->v18.y * -1.0f;
        neg.z = C->v18.z * -1.0f;
        return FUN_001afe70(A, C->f4, B, &C->v38, &neg, C->f24);
    }
    if (typeB == 6)
        return FUN_001afe70(B, C->f0, A, &C->v2c, &C->v18, C->f24);

    if (f8 != 0)
        f8->notify(C, a1);
    res = 0;
    if (A->fc == 5) {
        sub = A->f8;
        if (sub->FUN_001d6980()) {
            v34 = C->f0->f34;
            flag = 1;
            if (B->fc == 1) {
                Sub *bs = B->f8;
                if (!DAT_004dd700->f20->FUN_000242d0(bs))
                    return 1;
                A->f74->b72 = 0;
                sub->FUN_001d8350(bs);
                return 1;
            }
            Ref *r = C->fc;
            if (r->f8 != DAT_004e2198)
                return 1;
            if (r->fc != DAT_004e219c)
                return 1;
            if (v34 > DAT_004c3738)
                return 1;
            lim = DAT_004c373c;
            if (sub->f104 < lim) {
                sub->f104 = sub->f104 + 1;
                flag = 0;
            }
            if (sub->f104 >= lim)
                sub->FUN_001d7590();
            if (flag)
                return 1;
        }
        FUN_001b0090(sub, A, B);
        Ref *r2 = C->fc;
        if (r2->f8 == DAT_004e2198 && r2->fc == DAT_004e219c) {
            res = FUN_001b05a0(sub, B, C);
            if (res == 1)
                return 1;
        }
    }
    if (B->fc == 5) {
        sub = B->f8;
        if (sub->FUN_001d6980()) {
            v34 = C->f4->f34;
            flag = 1;
            if (A->fc == 1) {
                Sub *as = A->f8;
                if (!DAT_004dd700->f20->FUN_000242d0(as))
                    return 1;
                B->f74->b72 = 0;
                sub->FUN_001d8350(as);
                return 1;
            }
            Ref *r = C->f8;
            if (r->f8 != DAT_004e2198)
                return 1;
            if (r->fc != DAT_004e219c)
                return 1;
            if (v34 > DAT_004c3738)
                return 1;
            lim = DAT_004c373c;
            if (sub->f104 < lim) {
                sub->f104 = sub->f104 + 1;
                flag = 0;
            }
            if (sub->f104 >= lim)
                sub->FUN_001d7590();
            if (flag)
                return 1;
        }
        FUN_001b0090(sub, B, A);
        Ref *r2 = C->f8;
        if (r2->f8 == DAT_004e2198 && r2->fc == DAT_004e219c) {
            res = FUN_001b05a0(sub, A, C);
            if (res == 1)
                return 1;
        }
    }

    if (A->fc == 7) {
        FU u;
        u.f = C->f24;
        u.u &= 0x7fffffff;
        return FUN_001b0e30(A, B, &C->v38, &C->v18, u.u);
    }
    typeB = B->fc;
    if (typeB == 7) {
        neg.x = C->v18.x * -1.0f;
        neg.y = C->v18.y * -1.0f;
        neg.z = C->v18.z * -1.0f;
        FU u;
        u.f = C->f24;
        u.u &= 0x7fffffff;
        return FUN_001b0e30(B, A, &C->v2c, &neg, u.u);
    }
    s8 = C->f8;
    if (s8->f8 == DAT_004e2198 && s8->fc == DAT_004e219c && typeB == 1) {
        neg.x = C->v18.x * -1.0f;
        neg.y = C->v18.y * -1.0f;
        neg.z = C->v18.z * -1.0f;
        return FUN_001afea0(C, C->fc->f18, B, A, &C->v2c, &neg, C->f24);
    }
    sc = C->fc;
    if (sc->f8 == DAT_004e2198 && sc->fc == DAT_004e219c && A->fc == 1)
        return FUN_001afea0(C, s8->f18, A, B, &C->v38, &C->v18, C->f24);
    if (A->fc == 5) {
        if (B->fc == 5)
            return FUN_001b1e90(A, B, &C->v2c, &C->v38, &C->v18, C->f24);
        if (B->fc == 1) {
            neg.x = C->v18.x * -1.0f;
            neg.y = C->v18.y * -1.0f;
            neg.z = C->v18.z * -1.0f;
            return FUN_001b1710(sc->f18, B, A, &C->v2c, &neg, C->f24);
        }
    }
    {
        int ta = A->fc;
        if (B->fc == 5) {
            if (ta == 1)
                return FUN_001b1710(s8->f18, A, B, &C->v38, &C->v18, C->f24);
            return res;
        }
        if (ta == 1 && B->fc == 1)
            return FUN_001aff50(s8->f18, A, sc->f18, B, &C->v2c, &C->v38, &C->v18, C->f24);
    }
    return res;
}
