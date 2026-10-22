// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 22/22)
// FUN_00107760 @ 0x00107760
#include "compat/ptr.h"
extern "C" double sqrt(double);

struct V3_107760 {
    union {
        float x;
        int ix;
    };
    union {
        float y;
        int iy;
    };
    union {
        float z;
        int iz;
    };
    float FUN_0022d110();
    bool FUN_0022d2b0(const V3_107760 *other, float eps);
};

struct Pool_107760 {
    void FUN_00059a50(V3_107760 *out);
};

struct Other_107760 {
    char pad0[0x40];
    float x;
    char pad44[4];
    float z;
};

struct Body_107760 {
    char pad0[0x60];
    Other_107760 *other;       // 0x60
    char pad64[0xa8 - 0x64];
    int pa[3];          // 0xa8
    int pdir[3];        // 0xb4
    int gain;           // 0xc0
    int limit;          // 0xc4
};

struct Ctx_107760 {
    char pad0[0x10];
    Pool_107760 *pool;
};

extern "C" float __cdecl FUN_0010ae50(void *w, void *a, int b, V3_107760 *dir, V3_107760 *sum, int mark, void **hit);

struct Frame_107760 {
    char pad0[2];
    char ret;
    char flagB;
    float f;        // S4
    float lim;      // S8
    V3_107760 P;           // S12
    float d;        // S24
    V3_107760 m1;          // S28
    V3_107760 z;           // S40
    V3_107760 m2;          // S52
    V3_107760 n3;          // S64
    V3_107760 q;           // S76
    float ox;       // S88
    float pad92;
    float oz;       // S96
    V3_107760 dir;         // S100
    V3_107760 n2;          // S112
    V3_107760 n1;          // S124
    V3_107760 m3;          // S136
};

class Brain_107760 {
public:
    char pad0[0x58];
    Body_107760 *body;
    char FUN_00107760(void *a0, Ctx_107760 *a1, V3_107760 *outB, V3_107760 *outA);
};

char Brain_107760::FUN_00107760(void *a0, Ctx_107760 *a1, V3_107760 *outB, V3_107760 *outA)
{
    Frame_107760 f;
    outA->iz = 0;
    outA->iy = 0;
    outA->ix = 0;
    outB->iz = 0;
    outB->iy = 0;
    outB->ix = 0;
    Body_107760 *b = body;
    Other_107760 *o = b->other;
    f.P.ix = b->pa[0];
    f.P.iy = b->pa[1];
    f.P.iz = b->pa[2];
    f.dir.ix = b->pdir[0];
    f.dir.iy = b->pdir[1];
    f.dir.iz = b->pdir[2];
    f.f = *(float *)&b->gain;
    f.lim = *(float *)&b->limit;
    f.ret = 1;
    f.q.ix = 0;
    f.q.iy = 0;
    f.q.iz = 0;
    a1->pool->FUN_00059a50(&f.q);
    f.ox = o->x;
    f.oz = o->z;
    f.n1.x = f.ox - f.q.x;
    f.n1.iy = 0;
    f.n1.z = f.oz - f.q.z;
    f.n1.FUN_0022d110();
    f.n2.iy = 0;
    f.n2.x = f.P.x - f.q.x;
    f.n2.z = f.P.z - f.q.z;
    f.n3.iy = 0;
    f.n3.x = f.P.x - f.ox;
    f.n3.z = f.P.z - f.oz;
    f.d = sqrt(f.n3.x * f.n3.x + f.n3.z * f.n3.z);
    f.n3.FUN_0022d110();
    f.n2.FUN_0022d110();

    f.flagB = 0;
    if (f.f + 5.0f > f.d) {
        hulk_freg t = f.d - 2.0f;
        if (1.5f < t)
            f.f = t;
        else
            f.f = 1.5f;
        f.flagB = 1;
    }

    if (f.d > f.lim) {
        f.ret = 1;
        volatile float *vz = &f.z.x;
        hulk_freg A = f.dir.x * f.f;
        vz[1] = f.dir.y * f.f;
        vz[2] = f.dir.z * f.f;
        outA->z = vz[2] + f.P.z;
        outA->x = A + f.P.x;
        outA->y = vz[1] + f.P.y;
    } else {
        volatile float *vz = &f.z.x;
        hulk_freg A = f.n3.x * f.f;
        vz[1] = f.n3.y * f.f;
        vz[2] = f.n3.z * f.f;
        outA->z = f.P.z - vz[2];
        outA->x = f.P.x - A;
        outA->y = f.P.y - vz[1];
    }

    volatile float *va = &outA->x;
    f.m1.x = va[0] - f.q.x;
    f.m1.iy = 0;
    f.m1.z = va[2] - f.q.z;
    f.d = sqrt(f.m1.x * f.m1.x + f.m1.z * f.m1.z);
    f.m1.FUN_0022d110();
    f.m2.x = va[0] - f.P.x;
    f.m2.iy = 0;
    f.m2.z = va[2] - f.P.z;
    f.m2.FUN_0022d110();
    f.P.x = f.m2.z;
    f.P.z = -f.m2.x;
    f.m3.iy = 0;
    f.m3.x = va[0] - f.ox;
    f.m3.z = va[2] - f.oz;
    f.m3.FUN_0022d110();

    hulk_freg dotp = f.P.x * f.m1.x + f.P.z * f.m1.z + f.m1.y * 0.0f;
    f.lim = dotp;
    {
        union { float fl; unsigned int u; } ab;
        ab.fl = dotp;
        ab.u &= 0x7fffffff;
        f.lim = ab.fl;
    }
    bool pathX = false;
    if (f.lim < 0.97) {
        if (f.d > 1.5f)
            pathX = true;
    }
    if (pathX) {
        outB->x = f.m1.x;
        outB->iy = f.m1.iy;
        outB->iz = f.m1.iz;
        f.ret = 1;
        FUN_0010ae50(a0, a1, 0x3ff00000, outB, &f.dir, 0, 0);
        if (f.d > 5.0f) {
            outB->x = f.m1.x;
            outB->iy = f.m1.iy;
            outB->iz = f.m1.iz;
        }
        f.z.ix = 0;
        f.z.iy = 0;
        f.z.iz = 0;
        if (outB->FUN_0022d2b0(&f.z, 1e-5f)) {
            hulk_freg dq = f.m1.z * f.m2.z + f.m1.x * f.m2.x + f.m2.y * f.m1.y;
            if (dq > 0.0f) {
                outB->iy = f.m2.iy;
                outB->ix = f.m2.ix;
                outB->iz = f.m2.iz;
            } else {
                float nz = -f.m2.z;
                hulk_freg ny = -f.m2.y;
                hulk_freg nx = -f.m2.x;
                outB->x = nx;
                outB->iz = *(int *)&nz;
                outB->y = ny;
            }
            FUN_0010ae50(a0, a1, 0x3ff00000, outB, &f.dir, 0, 0);
        }
    } else {
        hulk_freg dr = f.n2.z * f.m2.z + f.n2.x * f.m2.x + f.n2.y * f.m2.y;
        {
            union { float fl; unsigned int u; } ab;
            ab.fl = dr;
            ab.u &= 0x7fffffff;
            f.lim = ab.fl;
        }
        if (f.lim < 0.97f) {
            outB->iy = 0;
            if (dotp > 0.0f) {
                outB->ix = f.P.ix;
                outB->iz = f.P.iz;
            } else {
                outB->x = -f.P.x;
                outB->z = -f.P.z;
            }
        }
        FUN_0010ae50(a0, a1, 0x3ff00000, outB, &f.z, 0, 0);
    }

    if (f.flagB) {
        f.ret = 0;
        outB->iz = 0;
        outB->iy = 0;
        outB->ix = 0;
    }
    outB->iy = 0;
    outB->FUN_0022d110();
    return f.ret;
}
