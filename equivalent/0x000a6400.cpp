// STATUS: equivalent (tools/equiv.py level 3: 2706 inputs, branch coverage 142/148, incomplete)
// FUN_000a6400 @ 0x000a6400
#include "decls/data/game/global.h"

extern "C" double sqrt(double);

struct V3 {
    float x, y, z;
    float FUN_0022d110();
};


struct V3v {
    volatile float x, y, z;
};

union Bits {
    float f;
    unsigned int u;
};

struct Radius {
    char pad0[0x30];
    float f30;
};

struct Sub338 {
    char FUN_00035a90();
};

class Ent {
public:
    char pad0[0x11c];
    Radius *f11c;
    char pad120[0x338 - 0x120];
    Sub338 *f338;
    void FUN_000382c0(V3 *out);
    void FUN_00035550(V3 *out);
    int FUN_00035910();
};

class Actor {
public:
    char pad0[0x148];
    Ent *f148;
    void FUN_001d69f0(V3 *out);
};

struct Mode {
    char pad0[8];
    void *obj;
    int kind;
    char pad10[0x40 - 0x10];
    V3 v40;
};

float __cdecl FUN_000189c0(float v);
void __cdecl FUN_000a04c0(V3 *delta, float *a, float *b, float *c);
float __cdecl FUN_000a00e0(float a, float b, float c, float d, float e);
float __cdecl FUN_000a02a0(float v);
float __cdecl FUN_000a03c0(float v, float lo, float hi);
float __cdecl FUN_000a0450(V3 *v);
char __cdecl FUN_0009ffc0(float a, float b, float c, float *out);
float __cdecl FUN_000a05b0(float a, float b, float c, float d, float e);
V3 *__cdecl FUN_0009f8c0(V3 *out, float a, float b, float c);

#define CLAMP(v, lo, hi) \
    do { \
        if ((v) >= (lo) && (v) <= (hi)) { \
        } else if ((v) > (hi)) \
            (v) = (hi); \
        else \
            (v) = (lo); \
    } while (0)

struct Frame {
    union { float hlen; float u; float k3; float k4; float mm; float r2; unsigned int abits; float afl; };
    float q;
    char pad8[3];
    char b17;
    union { float ang2; float k2; float scratch; float k5; float hh; float k6; float tmp; };
    union { float inv; float lo; float limLo; float oa3; float b3f; unsigned int b3u; };
    union { float q20; float hd; float len3; float lo2; };
    float v;
    union { float p1c; float ey1; };
    union { float k1; float s2; };
    union { float limHi; float b2f; unsigned int b2u; };
    union { V3 o; V3 dd; V3 d2; V3 d3; };
    float dist;
    float angC;
    union { float o48; float hi3; };
    float angA;
    float angB;
    V3 e;
    float f60;
    float p2;
    float oa2;
    V3 t2;
    union { V3 w; V3 w2; };
    union { V3 d; V3 nv; };
    float oa1;
    float p3;
    float p1;
    V3 t1;
};

class Camera {
public:
    char pad0[0x170];
    V3 v170;
    char pad17c[0x194 - 0x17c];
    V3 v194;
    V3v v1a0;
    V3v v1ac;
    char pad1b8[0x1c4 - 0x1b8];
    V3 pos;
    V3 v1d0;
    char pad1dc[0x1e8 - 0x1dc];
    V3 tgt;
    char pad1f4[0x20c - 0x1f4];
    float f20c;
    float f210;
    float f214;
    char pad218[4];
    float f21c;
    char pad220[4];
    float f224;
    char pad228[0x238 - 0x228];
    float f238;
    float f23c;
    char pad240[0x248 - 0x240];
    V3 v248;
    char pad254[0x278 - 0x254];
    V3 v278;
    char pad284[0x2e4 - 0x284];
    float f2e4;
    float f2e8;
    float f2ec;
    char pad2f0[4];
    float f2f4;
    char pad2f8[4];
    float f2fc;
    char pad300[0x346 - 0x300];
    char f346;
    char f347;
    char pad348[0x350 - 0x348];
    Ent *f350;
    char pad354[0x414 - 0x354];
    Mode *f414;
    V3 v418;
    char pad424[0x444 - 0x424];
    float f444;
    float f448;
    float f44c;
    char pad450[0x46c - 0x450];
    float f46c;
    float f470;
    float f474;
    float f478;
    float f47c;
    float f480;
    char pad484[4];
    int f488;
    char pad48c[0x498 - 0x48c];
    float f498;
    float f49c;

    void FUN_000a0dc0(float a, float b, float c);
    void FUN_000a0940(float a);
    void FUN_000a0ac0(float a, float b);
    char FUN_000a5a90(float a, float b, float c, float d, float e, int f, float g);
    void FUN_000a6400(float a1, float a2);
};

void Camera::FUN_000a6400(float a1, float a2)
{
    Frame f;
    f.b17 = 0;
    if (f347 && f350 && f350->f338 && !f350->f338->FUN_00035a90())
        f.b17 = 1;

    Mode *m = f414;
    f.f60 = 3.0f;
    V3 *cp = &v418;
    if (m->kind == 5) {
        Actor *a = (Actor *)m->obj;
        Ent *e = a->f148;
        if (e) {
            e->FUN_000382c0(cp);
            f.f60 = e->f11c->f30;
        } else {
            a->FUN_001d69f0(cp);
        }
    } else if (m->kind == 1) {
        Ent *e = (Ent *)m->obj;
        e->FUN_000382c0(cp);
        f.f60 = e->f11c->f30;
    } else if (m->kind == 7) {
        v418 = *(V3 *)((char *)m->obj + 0x64);
        f.f60 = 0.8f;
    } else {
        v418 = m->v40;
    }

    FUN_000a0dc0(DAT_0049ec74 * 0.6f, DAT_0049ec7c * 0.5f, a2);

    V3 *dp = &v1d0;
    f.w = *dp;
    f.hlen = (float)sqrt(f.w.z * f.w.z + f.w.x * f.w.x);
    f.d.x = v248.x - pos.x;
    f.d.y = v248.y - pos.y;
    f.d.z = v248.z - pos.z;
    FUN_000a04c0(&f.d, &f.p1, &f.p2, &f.p3);
    f.p1c = f.p1;

    f.dist = FUN_000a00e0(f.p3, f444, 10.0f, a2, 0.5f);
    float hi = f444 * 1.1f;
    f.lo = (float)(f444 * 0.9f);
    CLAMP(f.dist, f.lo, hi);
    f.inv = 1.0f / f.dist;

    f.v = (f49c - pos.y) * f.inv;
    CLAMP(f.v, -1.0f, 1.0f);
    f.angA = FUN_000189c0(f.v) * 57.2957763671875f;
    f.v = (f498 - pos.y) * f.inv;
    CLAMP(f.v, -0.94f, 1.0f);
    f.angB = FUN_000189c0(f.v) * 57.2957763671875f;
    f.v = ((f23c + 0.3f) - pos.y) * f.inv;
    CLAMP(f.v, -1.0f, 1.0f);
    f.angC = FUN_000189c0(f.v) * 57.2957763671875f;

    f.q = f.p2;
    if (f.b17) {
        f47c = f.q;
    } else if (f.hlen >= DAT_0049ed38 || f.q < f.angC || f.q < f.angA || f.q > f.angB) {
        f.tmp = DAT_0049ed34 * f.hlen;
        f.s2 = FUN_000a00e0(f.q, f44c, f.tmp, a2, 2.0f);
        f.q20 = f.q;
        if (f.q < f.angC)
            f.q20 = f.angC;
        if (f.q20 > f.angB) {
            f.q20 = f.angB;
            f346 = 1;
        } else if (f.q20 < f.angA) {
            f.q20 = f.angA;
            f346 = 1;
        }
        if (f.q == f.q20) {
            f.q = f.s2;
        } else {
            float s3 = FUN_000a00e0(f.q, f.q20, (*(float*)&DAT_0049ec48), a2, 2.0f);
            float e3 = s3 - f.q;
            float e2 = f.s2 - f.q;
            f.b3f = e3;
            f.b2f = e2;
            f.b3u &= 0x7fffffff;
            f.b2u &= 0x7fffffff;
            if (f.b3f > f.b2f)
                f.q = s3;
            else if (e3 * e2 < 0.0f)
                f.q = s3;
            else
                f.q = f.s2;
        }
    }

    if (f350->FUN_00035910() == 2 || f350->FUN_00035910() == 3) {
        float R = FUN_000a02a0(f238 + 180.0f);
        f.p1c = FUN_000a03c0(f.p1c, (float)(R - 70.0f), (float)(70.0f + R));
    }

    FUN_000a02a0(f.p1c + 180.0f);
    f.t1.x = cp->x - v248.x;
    f.t1.y = cp->y - v248.y;
    f.t1.z = cp->z - v248.z;
    FUN_000a0450(&f.t1);

    f.t2.x = cp->x - pos.x;
    f.t2.y = cp->y - pos.y;
    f.t2.z = cp->z - pos.z;
    f.hd = (float)sqrt(f.t2.z * f.t2.z + f.t2.x * f.t2.x);
    f.ang2 = FUN_000a0450(&f.t2);
    f.limLo = -180.0f;
    f.limHi = 135.0f;
    if (f.hlen >= 5.0f) {
        float X = FUN_000a0450(dp) + 180.0f;
        f.limLo = (float)(X - 90.0f);
        f.limHi = (float)(X + 90.0f);
    }

    if (FUN_0009ffc0(f.hd, f46c, f.dist, &f.o48)) {
        bool pass = true;
        if (f350->FUN_00035910() == 2 || f350->FUN_00035910() == 3) {
            f350->FUN_00035550(&f.nv);
            f.nv.FUN_0022d110();
            f350->FUN_000382c0(&f.o);
            f.w2.x = cp->x - f.o.x;
            f.w2.y = cp->y - f.o.y;
            f.w2.z = cp->z - f.o.z;
            f.w2.FUN_0022d110();
            float dot = f.nv.z * f.w2.z + f.nv.y * f.w2.y + f.nv.x * f.w2.x;
            pass = !(dot < 0.2f);
        }
        if (pass) {
            f.u = f.o48 + f46c;
            float R2 = FUN_000a02a0(f.ang2 + 180.0f);
            f.limLo = (float)(R2 - f.u);
            f.limHi = (float)(R2 + f.u);
            f.p1c = FUN_000a03c0(f.p1c, f.limLo, f.limHi);
        }
    }

    f.k1 = -10.0f;
    f.k2 = 30.0f;
    f.len3 = (float)sqrt(f.t2.y * f.t2.y + f.t2.z * f.t2.z + f.t2.x * f.t2.x);
    f.v = f.t2.y / f.len3;
    CLAMP(f.v, -1.0f, 1.0f);
    if (FUN_0009ffc0(f.len3, f470, f.dist, &f.o48)) {
        f.u = f.o48 + f470;
        float deg = FUN_000189c0(f.v) * 57.2957763671875f;
        f.lo2 = (float)(-deg - f.u);
        float hi2 = -deg + f.u;
        CLAMP(f.q, f.lo2, hi2);
    }
    CLAMP(f.q, -60.0f, 60.0f);

    if (f.q < f.angC) {
        f.q = f.angC;
        if (f.k1 < f.angC)
            f.k1 = f.angC;
    }
    if (f.q > f.angB) {
        f.q = f.angB;
        if (!(f.k2 < f.angB))
            f.k2 = f.angB;
        f346 = 1;
    } else if (f.q < f.angA) {
        f.q = f.angA;
        if (f.k1 < f.angA)
            f.k1 = f.angA;
        f346 = 1;
    }

    f478 = FUN_000a05b0(f478, f.p1c, (*(float*)&DAT_0049ec4c), a2, 10.0f);
    f47c = FUN_000a00e0(f47c, f.q, (*(float*)&DAT_0049ec50), a2, 10.0f);
    f.r2 = FUN_000a00e0(f480, f.dist, 20.0f, a2, 0.5f);
    f480 = f.r2;
    V3 *pp = FUN_0009f8c0(&f.dd, f478, f47c, f.r2);
    float nx = pos.x + pp->x;
    float ny = pos.y + pp->y;
    float nz = pos.z + pp->z;
    v194.z = nz;
    v194.x = nx;
    v194.y = ny;
    FUN_000a0940((*(float*)&DAT_0049ec80));

    f.afl = a2;
    f.abits &= 0x7fffffff;
    f488 = 0;
    if (!(f.afl <= 1e-05f)) {
        float ia = 1.0f / a2;
        float x0 = v170.x - v248.x;
        float y0 = v170.y - v248.y;
        float z0 = v170.z - v248.z;
        v1a0.z = z0;
        v1a0.x = x0;
        v1a0.y = y0;
        v1a0.x = ia * v1a0.x;
        v1a0.y = ia * v1a0.y;
        v1a0.z = ia * v1a0.z;
        float x1 = v1a0.x - v278.x;
        float y1 = v1a0.y - v278.y;
        float z1 = v1a0.z - v278.z;
        v1ac.z = z1;
        v1ac.x = x1;
        v1ac.y = y1;
        v1ac.x = ia * v1ac.x;
        v1ac.y = ia * v1ac.y;
        v1ac.z = ia * v1ac.z;
    }

    f.k3 = -200.0f;
    {
        float S = dp->x * dp->x + dp->z * dp->z;
        if (dp->y * dp->y < S && S >= 25.0f)
            f.k3 = FUN_000a02a0(FUN_000a0450(dp) + 180.0f);
    }

    if (FUN_000a5a90(f.limLo, f.limHi, f.k3, f.k1, f.k2, 1, a2)) {
        f.dd.x = v194.x - pos.x;
        f.dd.y = v194.y - pos.y;
        f.dd.z = v194.z - pos.z;
        FUN_000a04c0(&f.dd, &f478, &f47c, &f480);
    }

    if (f.b17) {
        FUN_000a0ac0(f2fc + f2e8, f2f4 + f2ec + f2e4);
    } else {
        f.dd.x = tgt.x - v194.x;
        f.dd.y = tgt.y - v194.y;
        f.dd.z = tgt.z - v194.z;
        FUN_000a04c0(&f.dd, &f210, &f20c, &f.scratch);
    }

    f.d2.x = cp->x - v194.x;
    f.d2.y = cp->y - v194.y;
    f.d2.z = cp->z - v194.z;
    f.k4 = FUN_000a02a0(FUN_000a0450(&f.d2) - f210) * 0.5f + f210;
    if (f.b17)
        f.k4 = FUN_000a00e0(f2fc + f2e8, f.k4, (*(float*)&DAT_0049eca8), a2, 10.0f);

    f.k5 = f46c;
    if (f350->FUN_00035910() == 2 || f350->FUN_00035910() == 3)
        f.k5 = f474;

    f.d3.x = pos.x - v194.x;
    f.d3.y = pos.y - v194.y;
    f.d3.z = pos.z - v194.z;
    FUN_000a04c0(&f.d3, &f.oa1, &f.oa2, &f.oa3);
    float hh2 = f.k5 * 0.5f;
    f224 = FUN_000a02a0(FUN_000a03c0(f.k4, (float)(f.oa1 - hh2), (float)(f.oa1 + hh2)) - f210);

    f.e.x = pos.x - v194.x;
    f.e.y = (pos.y - v194.y) - 2.7f;
    f.e.z = pos.z - v194.z;
    f.e.FUN_0022d110();
    f.ey1 = f.e.y;
    f.e.x = cp->x - v194.x;
    f.e.y = cp->y - v194.y;
    f.e.z = cp->z - v194.z;
    f.hh = f.f60 * 0.5f;
    f.e.y = f.e.y - f.hh;
    f.e.FUN_0022d110();
    f.mm = (f.ey1 < f.e.y) ? f.ey1 : f.e.y;
    CLAMP(f.mm, -1.0f, 1.0f);
    f.f60 = FUN_000189c0(f.mm);

    f.e.x = pos.x - v194.x;
    f.e.y = (pos.y - v194.y) + 0.3f;
    f.e.z = pos.z - v194.z;
    f.e.FUN_0022d110();
    f.ey1 = f.e.y;
    f.e.x = cp->x - v194.x;
    f.e.y = cp->y - v194.y;
    f.e.z = cp->z - v194.z;
    f.e.y = f.e.y + f.hh;
    f.e.FUN_0022d110();
    f.mm = (f.ey1 < f.e.y) ? f.e.y : f.ey1;
    CLAMP(f.mm, -1.0f, 1.0f);
    f.k6 = (FUN_000189c0(f.mm) + f.f60) * 28.64788818359375f + f448;
    float X6 = f.k6;
    if (f.b17)
        X6 = FUN_000a00e0(f2f4 + f2ec + f2e4, f.k6, (*(float*)&DAT_0049eca8), a2, 10.0f);

    float h2 = f470 * 0.5f;
    f.hi3 = (float)(f.oa2 + h2);
    f.oa2 = (float)(f.oa2 - h2);
    CLAMP(X6, f.oa2, f.hi3);
    f214 = (float)(X6 - f20c - f21c);
}
