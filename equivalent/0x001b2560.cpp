// STATUS: equivalent (tools/equiv.py level 3: 3191 inputs, branch coverage 113/118, incomplete)
// AICollisionSolverAgent::vfunc_5 @ 0x001b2560
#include "compat/ptr.h"
#include "gen/global.h"
#include "decls/address.h"
#include "decls/data/game/global.h"

struct V3_1b2560 {
    float x, y, z;
};

struct Body_1b2560;
struct Sub_1b2560 {
    char pad0[0x104];
    int f104;
    char FUN_001d6980();
    void FUN_001d8350(void *shape);
    void FUN_001d7590();
    void FUN_0003aaf0(Body_1b2560 *b);
};

struct F74 {
    char pad0[0x72];
    char b72;
};

struct Body_1b2560 {
    char pad0[8];
    Sub_1b2560 *f8;
    int fc;
    char pad10[0x74 - 0x10];
    F74 *f74;
};

struct Ref_1b2560 {
    char pad0[8];
    unsigned int f8;
    unsigned int fc;
    char pad10[8];
    Body_1b2560 *f18;
};

struct Hold_1b2560 {
    char pad0[0x34];
    float f34;
};

struct Contact_1b2560 {
    Hold_1b2560 *f0;
    Hold_1b2560 *f4;
    Ref_1b2560 *f8;
    Ref_1b2560 *fc;
    char pad10[8];
    V3_1b2560 v18;
    float f24;
    char pad28[4];
    V3_1b2560 v2c;
    V3_1b2560 v38;
};

struct Pool_1b2560 {
    char FUN_000242d0(void *shape);
};
struct World {
    char pad0[0x20];
    Pool_1b2560 *f20;
};

class Listener_1b2560 {
public:
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual void notify(Contact_1b2560 *c, int a1);
};

union FU_1b2560 {
    float f;
    unsigned int u;
};

struct AICollisionSolverAgent_nv_1b2560 {
    int FUN_001afb80(Body_1b2560 *b, Body_1b2560 *a);
    int FUN_001afba0(Body_1b2560 *a, Body_1b2560 *b, V3_1b2560 *p, V3_1b2560 *q, float f);
    int FUN_001afdc0(Body_1b2560 *a, Body_1b2560 *b, V3_1b2560 *p, V3_1b2560 *q, float f);
    int FUN_001afe70(Body_1b2560 *a, Hold_1b2560 *h, Body_1b2560 *b, V3_1b2560 *p, V3_1b2560 *q, float f);
    void FUN_001b0090(Sub_1b2560 *s, Body_1b2560 *a, Body_1b2560 *b);
    int FUN_001b05a0(Sub_1b2560 *s, Body_1b2560 *b, Contact_1b2560 *c);
    int FUN_001b0e30(Body_1b2560 *a, Body_1b2560 *b, V3_1b2560 *p, V3_1b2560 *q, unsigned int fabsBits);
    int FUN_001afea0(Contact_1b2560 *c, Body_1b2560 *b0, Body_1b2560 *b1, Body_1b2560 *b2, V3_1b2560 *p, V3_1b2560 *q, float f);
    int FUN_001b1e90(Body_1b2560 *a, Body_1b2560 *b, V3_1b2560 *p, V3_1b2560 *q, V3_1b2560 *r, float f);
    int FUN_001b1710(Body_1b2560 *x, Body_1b2560 *b, Body_1b2560 *a, V3_1b2560 *p, V3_1b2560 *q, float f);
    int FUN_001aff50(Body_1b2560 *a0, Body_1b2560 *a, Body_1b2560 *b0, Body_1b2560 *b, V3_1b2560 *p, V3_1b2560 *q, V3_1b2560 *r, float f);
};

int AICollisionSolverAgent::vfunc_5(void* __p0, void* __p1) { Contact_1b2560 * C = (Contact_1b2560 *)__p0; hulk_intptr a1 = (hulk_intptr)__p1;

    Body_1b2560 *A = C->f8->f18;
    Body_1b2560 *B = C->fc->f18;
    int typeA;
    int typeB;
    int res;
    V3_1b2560 neg;
    Ref_1b2560 *s8;
    Ref_1b2560 *sc;
    Sub_1b2560 *sub;
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
        return ((AICollisionSolverAgent_nv_1b2560*)this)->FUN_001afb80(B, A);
    if (typeA == 3) {
        if (typeB == 5) {
            neg.x = C->v18.x * -1.0f;
            neg.y = C->v18.y * -1.0f;
            neg.z = C->v18.z * -1.0f;
            return ((AICollisionSolverAgent_nv_1b2560*)this)->FUN_001afba0(A, B, &C->v38, &neg, C->f24);
        }
    } else if (typeB == 3 && typeA == 5) {
        return ((AICollisionSolverAgent_nv_1b2560*)this)->FUN_001afba0(B, A, &C->v2c, &C->v18, C->f24);
    }
    if (typeA == 4) {
        if (typeB == 5) {
            neg.x = C->v18.x * -1.0f;
            neg.y = C->v18.y * -1.0f;
            neg.z = C->v18.z * -1.0f;
            return ((AICollisionSolverAgent_nv_1b2560*)this)->FUN_001afdc0(A, B, &C->v38, &neg, C->f24);
        }
    } else if (typeB == 4 && typeA == 5) {
        return ((AICollisionSolverAgent_nv_1b2560*)this)->FUN_001afdc0(B, A, &C->v2c, &C->v18, C->f24);
    }
    if (typeA == 6) {
        neg.x = C->v18.x * -1.0f;
        neg.y = C->v18.y * -1.0f;
        neg.z = C->v18.z * -1.0f;
        return ((AICollisionSolverAgent_nv_1b2560*)this)->FUN_001afe70(A, C->f4, B, &C->v38, &neg, C->f24);
    }
    if (typeB == 6)
        return ((AICollisionSolverAgent_nv_1b2560*)this)->FUN_001afe70(B, C->f0, A, &C->v2c, &C->v18, C->f24);

    if ((*(Listener_1b2560 * *)&this->f_08) != 0)
        (*(Listener_1b2560 * *)&this->f_08)->notify(C, a1);
    res = 0;
    if (A->fc == 5) {
        sub = A->f8;
        if (sub->FUN_001d6980()) {
            v34 = C->f0->f34;
            flag = 1;
            if (B->fc == 1) {
                Sub_1b2560 *bs = B->f8;
                if (!DAT_004dd700->f20->FUN_000242d0(bs))
                    return 1;
                A->f74->b72 = 0;
                sub->FUN_001d8350(bs);
                return 1;
            }
            Ref_1b2560 *r = C->fc;
            if (r->f8 != DAT_004e2198)
                return 1;
            if (r->fc != (*(unsigned int*)&DAT_004e219c))
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
        ((AICollisionSolverAgent_nv_1b2560*)this)->FUN_001b0090(sub, A, B);
        Ref_1b2560 *r2 = C->fc;
        if (r2->f8 == DAT_004e2198 && r2->fc == (*(unsigned int*)&DAT_004e219c)) {
            res = ((AICollisionSolverAgent_nv_1b2560*)this)->FUN_001b05a0(sub, B, C);
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
                Sub_1b2560 *as = A->f8;
                if (!DAT_004dd700->f20->FUN_000242d0(as))
                    return 1;
                B->f74->b72 = 0;
                sub->FUN_001d8350(as);
                return 1;
            }
            Ref_1b2560 *r = C->f8;
            if (r->f8 != DAT_004e2198)
                return 1;
            if (r->fc != (*(unsigned int*)&DAT_004e219c))
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
        ((AICollisionSolverAgent_nv_1b2560*)this)->FUN_001b0090(sub, B, A);
        Ref_1b2560 *r2 = C->f8;
        if (r2->f8 == DAT_004e2198 && r2->fc == (*(unsigned int*)&DAT_004e219c)) {
            res = ((AICollisionSolverAgent_nv_1b2560*)this)->FUN_001b05a0(sub, A, C);
            if (res == 1)
                return 1;
        }
    }

    if (A->fc == 7) {
        FU_1b2560 u;
        u.f = C->f24;
        u.u &= 0x7fffffff;
        return ((AICollisionSolverAgent_nv_1b2560*)this)->FUN_001b0e30(A, B, &C->v38, &C->v18, u.u);
    }
    typeB = B->fc;
    if (typeB == 7) {
        neg.x = C->v18.x * -1.0f;
        neg.y = C->v18.y * -1.0f;
        neg.z = C->v18.z * -1.0f;
        FU_1b2560 u;
        u.f = C->f24;
        u.u &= 0x7fffffff;
        return ((AICollisionSolverAgent_nv_1b2560*)this)->FUN_001b0e30(B, A, &C->v2c, &neg, u.u);
    }
    s8 = C->f8;
    if (s8->f8 == DAT_004e2198 && s8->fc == (*(unsigned int*)&DAT_004e219c) && typeB == 1) {
        neg.x = C->v18.x * -1.0f;
        neg.y = C->v18.y * -1.0f;
        neg.z = C->v18.z * -1.0f;
        return ((AICollisionSolverAgent_nv_1b2560*)this)->FUN_001afea0(C, C->fc->f18, B, A, &C->v2c, &neg, C->f24);
    }
    sc = C->fc;
    if (sc->f8 == DAT_004e2198 && sc->fc == (*(unsigned int*)&DAT_004e219c) && A->fc == 1)
        return ((AICollisionSolverAgent_nv_1b2560*)this)->FUN_001afea0(C, s8->f18, A, B, &C->v38, &C->v18, C->f24);
    if (A->fc == 5) {
        if (B->fc == 5)
            return ((AICollisionSolverAgent_nv_1b2560*)this)->FUN_001b1e90(A, B, &C->v2c, &C->v38, &C->v18, C->f24);
        if (B->fc == 1) {
            neg.x = C->v18.x * -1.0f;
            neg.y = C->v18.y * -1.0f;
            neg.z = C->v18.z * -1.0f;
            return ((AICollisionSolverAgent_nv_1b2560*)this)->FUN_001b1710(sc->f18, B, A, &C->v2c, &neg, C->f24);
        }
    }
    {
        int ta = A->fc;
        if (B->fc == 5) {
            if (ta == 1)
                return ((AICollisionSolverAgent_nv_1b2560*)this)->FUN_001b1710(s8->f18, A, B, &C->v38, &C->v18, C->f24);
            return res;
        }
        if (ta == 1 && B->fc == 1)
            return ((AICollisionSolverAgent_nv_1b2560*)this)->FUN_001aff50(s8->f18, A, sc->f18, B, &C->v2c, &C->v38, &C->v18, C->f24);
    }
    return res;
}
