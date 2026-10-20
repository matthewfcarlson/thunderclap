// STATUS: equivalent (tools/equiv.py level 3: 3081 inputs, branch coverage 61/62, incomplete)
// FUN_001d86d0 @ 0x001d86d0
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" double sqrt(double);

struct V3_1d86d0 {
    float x, y, z;
    float FUN_0022d110();
    float FUN_000111f0();
    float FUN_00018990();
};

struct SymMatrix {
    char data[0x1c];
    void FUN_002fca90();
    void FUN_002fcaa0();
};

struct Mat4_1d86d0 {
    float m[16];
    void FUN_0022cdb0();
    void FUN_0022c3b0(V3_1d86d0 *in, V3_1d86d0 *out);
};

struct Obj70_1d86d0;

struct ObjC_1d86d0 {
    char pad0[0x5c];
    V3_1d86d0 v5c;
    char pad68[0x84 - 0x68];
    char b84;
};

struct Obj70_1d86d0 {
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17(void *a, V3_1d86d0 *v, int i, int j, int k);
    virtual void v18(void *a, V3_1d86d0 *v, SymMatrix *g, int i, int j, int k);
    virtual void v19(int i, int j, int k);
    virtual void v20(void *a, SymMatrix *g, int i, int j, int k);
    char pad04[0x10 - 4];
    ObjC_1d86d0 *p10;
    char pad14[0x98 - 0x14];
    float f98, f9c, fa0;
    void FUN_0016fc60(V3_1d86d0 *out);
};

struct ObjB_1d86d0 {
    char pad0[0x50];
    V3_1d86d0 v50;
    V3_1d86d0 v5c;
    char pad68[0x70 - 0x68];
    Obj70_1d86d0 *p70;
};

struct ObjA_1d86d0 {
    char pad0[0x10];
    ObjB_1d86d0 *p10;
};

struct Link_1d86d0 {
    unsigned __int64 FUN_001d4f70();
    char FUN_001d4e40();
};

struct Req_1d86d0 {
    void FUN_00083320(V3_1d86d0 *a, V3_1d86d0 *b, int c, int d, V3_1d86d0 *e, int f);
};
struct Hub4c_1d86d0 {
    Req_1d86d0 *FUN_0007ad00(void *p);
};
struct World {
    char pad0[0x4c];
    Hub4c_1d86d0 *p4c;
};


float FUN_00083d90(float *p);

class Thing_1d86d0 {
public:
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
    virtual void v13();
    virtual void v14();
    virtual Mat4_1d86d0 *v15();
    char pad04[4];
    char sub8[1];
    char pad9[0xa0 - 9];
    ObjA_1d86d0 *pA0;
    char pada4[0xec - 0xa4];
    Link_1d86d0 *link;
    char padf0[0x14d - 0xf0];
    char b14d;
    char pad14e[0x188 - 0x14e];
    V3_1d86d0 v188;
    char pad194[0x25c - 0x194];
    V3_1d86d0 v25c;
    float f268;
    void FUN_001d7510();
    V3_1d86d0 *FUN_001d6b40();
    void F(V3_1d86d0 *v, void *arg2);
};

void Thing_1d86d0::F(V3_1d86d0 *vin, void *arg2)
{
    struct Frame {
        float N;
        V3_1d86d0 V;
        V3_1d86d0 R;
        V3_1d86d0 P1;
        V3_1d86d0 SV1;
        V3_1d86d0 SV2;
        V3_1d86d0 S48;
        SymMatrix G2;
        SymMatrix G1;
        Mat4_1d86d0 M;
    } fr;
    SymMatrix &G1 = fr.G1;
    V3_1d86d0 &V = fr.V;
    v25c.x = vin->x;
    v25c.y = vin->y;
    v25c.z = vin->z;
    f268 = 0;
    if (b14d) {
        Req_1d86d0 *r = DAT_004dd700->p4c->FUN_0007ad00(sub8);
        if (r) {
            fr.R.x = 0; fr.R.y = 0; fr.R.z = 0;
            r->FUN_00083320(&fr.R, &fr.R, 0, 1, &fr.R, 0);
        }
    }
    if (!pA0 || !pA0->p10 || !pA0->p10->p70)
        return;
    V.x = vin->x;
    V.y = vin->y;
    V.z = vin->z;
    float &N = fr.N;
    N = V.FUN_0022d110();
    if (N < 0.01f)
        return;
    FUN_001d7510();
    V3_1d86d0 *pos = FUN_001d6b40();
    v188.x = pos->x;
    v188.y = pos->y;
    v188.z = pos->z;
    unsigned __int64 id = link->FUN_001d4f70();
    *(volatile unsigned int *)&fr.P1.y = (unsigned int)(id >> 32);
    bool match = id == (*(unsigned __int64*)&DAT_004dc0c0) || id == (*(unsigned __int64*)&DAT_004dc098) || id == (*(unsigned __int64*)&DAT_004dc078);
    if (match) {
        if (V.y > 0.4f && V.y < 0.97f) {
            V.y = 0;
            float l = V.FUN_000111f0();
            V.y = 0.4f;
            double k = sqrt((double)0.84f / (double)l);
            V.x = V.x * k;
            V.z = V.z * k;
            V.FUN_0022d110();
            N = N * 1.5f;
        } else if (!(V.y >= 0.97f)) {
            N = N + N;
        } else {
            N = N * 0.7f;
        }
    }
    ObjB_1d86d0 *B = pA0->p10;
    Obj70_1d86d0 *o70 = B->p70;
    void *a2 = arg2;
    V3_1d86d0 &SV1 = fr.SV1;
    V3_1d86d0 &SV2 = fr.SV2;
    SV1 = B->v50;
    SV2 = B->v5c;
    o70->v17(a2, &V, 0, -1, -1);
    G1.FUN_002fca90();
    o70->v20(a2, &G1, 0, -1, -1);
    V.x = V.x * N;
    V.y = V.y * N;
    V.z = V.z * N;
    o70->v18(a2, &V, &G1, 0, -1, -1);
    o70->v19(1, -1, -1);
    v25c.x = V.x;
    v25c.y = V.y;
    v25c.z = V.z;
    V3_1d86d0 &TV = fr.R;
    TV = o70->p10->v5c;
    if (!o70->p10->b84) {
        V3_1d86d0 &S48 = fr.S48;
        o70->FUN_0016fc60(&S48);
        ObjB_1d86d0 *b2 = pA0->p10;
        b2->v50.x = SV1.x;
        b2->v50.z = SV1.z;
        b2->v50.y = SV1.y;
        ObjB_1d86d0 *b3 = pA0->p10;
        b3->v5c.x = SV2.x;
        b3->v5c.z = SV2.z;
        b3->v5c.y = SV2.y;
        o70->v17(&S48, &V, 0, -1, -1);
        SymMatrix &G2 = fr.G2;
        G2.FUN_002fca90();
        o70->v20(&S48, &G2, 0, -1, -1);
        o70->v18(&S48, &V, &G2, 0, -1, -1);
        o70->v19(1, -1, -1);
        match = id == (*(unsigned __int64*)&DAT_004dc0c0) || id == (*(unsigned __int64*)&DAT_004dc098) || id == (*(unsigned __int64*)&DAT_004dc078);
        if (match && TV.FUN_000111f0() > 0.1f) {
            Mat4_1d86d0 &M = fr.M;
            M = *v15();
            M.FUN_0022cdb0();
            V3_1d86d0 &P1 = fr.P1;
            M.FUN_0022c3b0(&TV, &P1);
            union { float f; unsigned int u; } t;
            t.f = P1.x;
            t.u &= 0x7fffffff;
            if (t.f >= 0.1f) {
                float sgn = FUN_00083d90(&P1.x);
                TV.x = 0.1f;
                if (!(sgn > 0.0f))
                    TV.x = -0.1f;
            }
            t.f = P1.z;
            t.u &= 0x7fffffff;
            if (t.f >= 0.1f) {
                float sgn = FUN_00083d90(&P1.z);
                TV.z = 0.1f;
                if (!(sgn > 0.0f))
                    TV.z = -0.1f;
            }
            P1.y = P1.y * 3.0f;
            v15()->FUN_0022c3b0(&P1, &TV);
        }
        ObjB_1d86d0 *b4 = pA0->p10;
        b4->v5c.x = TV.x;
        b4->v5c.y = TV.y;
        b4->v5c.z = TV.z;
        G2.FUN_002fcaa0();
    }
    if (link->FUN_001d4e40()) {
        unsigned __int64 id2 = link->FUN_001d4f70();
        if (id2 != (*(unsigned __int64*)&DAT_004e2548)) {
            V3_1d86d0 *bv = &pA0->p10->v50;
            if (bv->FUN_00018990() > 50.0f) {
                bv->FUN_0022d110();
                bv->x = bv->x * 50.0f;
                bv->y = bv->y * 50.0f;
                bv->z = bv->z * 50.0f;
            }
        }
    }
    G1.FUN_002fcaa0();
}
