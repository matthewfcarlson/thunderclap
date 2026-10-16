// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 56/56)
// FUN_000cc7e0 @ 0x000cc7e0
// FUN_000cc7e0: debug/HUD gauge drawer (builds quads through the vertex-handle API)
#include "decls/address.h"
struct Vec3_cc7e0 {
    float x, y, z;
};

struct Node {
    char pad0[0x10];
    float x;
    float y;
    float z;
};

struct Handle_cc7e0 {
    char pad0[8];
    Vec3_cc7e0 *pos;      // 0x08
    char pad1[4];
    unsigned int *col;  // 0x10
    void FUN_0008ef00();
    void FUN_0008ef90(const Vec3_cc7e0 *p, unsigned int color);
};

struct Gfx {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29();
    virtual Handle_cc7e0 *v30(int a, int b, int c, int d, int e);
    virtual void v31(Handle_cc7e0 *h);
};

struct Pass_cc7e0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};

struct PassHolder_cc7e0 {
    Pass_cc7e0 *pass;
    void FUN_00293d00(const Vec3_cc7e0 *color);
    void FUN_00293bf0(float a);
    void FUN_00293da0(float a, float b, float c);
};

struct Widget_cc7e0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(int a, int b);
};

struct Sub_cc7e0 {
    char pad0[0x144];
    float f144;
    float f148;
    float f14c;
};

struct Owner_cc7e0 {
    char pad0[0x11c];
    Sub_cc7e0 *sub;
    float FUN_00036090();
    float FUN_000360b0();
};

struct Tex_cc7e0 {
    char pad0[0x10];
    int id;
};

union Word_cc7e0 {
    float f;
    unsigned int u;
};

extern float FUN_000186b0(const float &v, const float &lo, const float &hi);
extern float FUN_000186f0(const float &a, const float &b);
extern float FUN_00018710(const float &a, const float &b);

extern PassHolder_cc7e0 *DAT_0052c2ac;
extern Vec3_cc7e0 DAT_004ddf0c;

static __forceinline float Lerp(float a, float b, float t)
{
    return (1.0f - t) * a + b * t;
}

// inlined body of Handle::FUN_0008ef90 at the call sites that don't call it
static __forceinline void EmitV(Handle_cc7e0 *h, float x, float z, unsigned int color)
{
    Vec3_cc7e0 *p = h->pos;
    p->x = x;
    p->y = 0.0f;
    p->z = z;
    *h->col = color;
    h->FUN_0008ef00();
}

// vertex built in a stack Vec3 and passed to Handle::FUN_0008ef90
static __forceinline void EmitP(Handle_cc7e0 *h, Vec3_cc7e0 &v, float x, float z, unsigned int color)
{
    v.x = x;
    v.y = 0.0f;
    v.z = z;
    h->FUN_0008ef90(&v, color);
}

static __forceinline float Clamp01(float v)
{
    float r;
    if (v >= 0.0f && v <= 1.0f)
        r = v;
    else if (v > 1.0f)
        r = 1.0f;
    else
        r = 0.0f;
    return r;
}

// The original keeps these in fixed stack words and hands pointers to them to callees; the
// callees see (and the checker compares) their neighbours, so the slot order is kept.
struct Frame_cc7e0 {
    Word_cc7e0 s0;        // A (clamped progress 1)
    Word_cc7e0 s1;        // B (clamped progress 2)
    Word_cc7e0 s2;        // N1 (x extent of 1ac - 1a4); scratch in mode 1
    Word_cc7e0 s3;
    Word_cc7e0 s4;        // colC
    Word_cc7e0 s5;
    Word_cc7e0 s6;
    Word_cc7e0 s7;
    Word_cc7e0 s8;
    Word_cc7e0 s9;        // N2
    Vec3_cc7e0 v;         // vertex passed to FUN_0008ef90 / f144, f148, f14c in mode 1
    Word_cc7e0 s13;
    Word_cc7e0 s14;
    Word_cc7e0 s15;
    Word_cc7e0 s16;
    Word_cc7e0 s17;
    Word_cc7e0 s18;
};

class ProgressGauge {
public:
    char pad0[0x14];
    Owner_cc7e0 *owner;           // 0x14
    char pad18[0x90 - 0x18];
    Tex_cc7e0 *tex;               // 0x90
    char pad94[0xb8 - 0x94];
    unsigned char flags;    // 0xb8
    char padb9[0x154 - 0xb9];
    float f154;
    float f158;
    char pad15c[4];
    int alpha;              // 0x160
    Widget_cc7e0 *w164;
    char pad168[0x174 - 0x168];
    float f174;
    float f178;
    float f17c;
    char pad180[0x18c - 0x180];
    float f18c;
    float f190;
    char pad194[4];
    Widget_cc7e0 *w198;
    char pad19c[4];
    int mode;               // 0x1a0
    Node *p1a4;
    Node *p1a8;
    Node *p1ac;
    Node *p1b0;
    Node *p1b4;
    Node *p1b8;
    Node *p0[3];            // 0x1bc
    Node *p1[3];            // 0x1c8
    char pad1d4[0x1e0 - 0x1d4];
    Node *p1e0;
    Node *p1e4;
    Node *p1e8;
    float w[3];             // 0x1ec

    void FUN_000cc7e0();
};

void ProgressGauge::FUN_000cc7e0()
{
    if (!(flags & 1))
        return;

    Frame_cc7e0 F;

    DAT_0052c2ac->pass->v15(0);
    DAT_0052c2ac->FUN_00293d00(&DAT_004ddf0c);
    DAT_0052c2ac->FUN_00293bf0(-1.5707964f);
    DAT_0052c2ac->FUN_00293da0(1.2f, 1.2f, 1.2f);
    w164->v8(0, 0);
    w198->v8(0, 0);

    F.s2.f = p1ac->x - p1a4->x;
    F.s9.f = p1b8->x - p1b0->x;

    float T0 = owner->FUN_000360b0();
    double D = owner->FUN_00036090() - T0;
    F.s0.f = Clamp01((f154 - T0) / D);
    F.s1.f = Clamp01((f158 - T0) / D);

    unsigned int a24 = (unsigned int)alpha << 24;
    unsigned int colA = a24 | 0xff00;
    unsigned int colB = a24 | (f154 < f158 ? 0xff0000 : 0x79fe4);
    F.s4.u = a24 | (f174 < f178 ? 0xff0000 : 0x79fe4);

    if (mode == 0) {
        float xa = p1a4->x;
        float zA = p1a4->z;
        float zB = p1a8->z;
        float mn = F.s0.f < F.s1.f ? F.s0.f : F.s1.f;
        float X1 = mn * F.s2.f + p1a4->x;
        Handle_cc7e0 *h = DAT_0052c2a8->v30(tex->id, 1, 0x2020, 4, 0);
        EmitV(h, xa, zA, colA);
        EmitV(h, X1, zA, colA);
        EmitV(h, xa, zB, colA);
        EmitV(h, X1, zB, colA);
        DAT_0052c2a8->v31(h);

        float mn2 = F.s0.f < F.s1.f ? F.s0.f : F.s1.f;
        float X1b = mn2 * F.s2.f + p1a4->x;
        float mx = F.s0.f < F.s1.f ? F.s1.f : F.s0.f;
        float X2 = mx * F.s2.f + p1a4->x;
        Handle_cc7e0 *h2 = DAT_0052c2a8->v30(tex->id, 1, 0x2020, 4, 0);
        EmitV(h2, X1b, zA, colB);
        EmitV(h2, X2, zA, colB);
        EmitV(h2, X1b, zB, colB);
        EmitV(h2, X2, zB, colB);
        DAT_0052c2a8->v31(h2);
    } else if (mode == 1) {
        Sub_cc7e0 *s = owner->sub;
        F.v.x = s->f144;        // a
        F.v.y = s->f148;        // b
        F.v.z = s->f14c;        // c
        float cx[3];
        float cy[3];
        F.s8.f = 1.0f;
        F.s6.f = 0.0f;
        F.s7.f = 1.0f / F.v.x;
        F.s5.f = F.s7.f * f174;
        cx[0] = FUN_000186b0(F.s5.f, F.s6.f, F.s8.f);

        F.s8.f = f174 - F.v.x;
        F.s5.f = 1.0f;
        F.s3.f = 0.0f;
        F.s6.f = 1.0f / F.v.y;
        F.s2.f = F.s6.f * F.s8.f;
        cx[1] = FUN_000186b0(F.s2.f, F.s3.f, F.s5.f);

        F.s3.f = 1.0f;
        F.s2.f = 0.0f;
        F.s5.f = 1.0f / F.v.z;
        F.s8.f = (F.s8.f - F.v.y) * F.s5.f;
        cx[2] = FUN_000186b0(F.s8.f, F.s2.f, F.s3.f);

        F.s7.f = F.s7.f * f178;
        F.s8.f = 1.0f;
        F.s3.f = 0.0f;
        cy[0] = FUN_000186b0(F.s7.f, F.s3.f, F.s8.f);

        F.s7.f = 1.0f;
        F.s3.f = 0.0f;
        F.s8.f = f178 - F.v.x;
        F.s6.f = F.s8.f * F.s6.f;
        cy[1] = FUN_000186b0(F.s6.f, F.s3.f, F.s7.f);

        F.s8.f = (F.s8.f - F.v.y) * F.s5.f;
        F.s6.f = 0.0f;
        F.s7.f = 1.0f;
        cy[2] = FUN_000186b0(F.s8.f, F.s6.f, F.s7.f);

        for (int i = 0; i < 3; i++) {
            if (!(w[i] <= 0.0f)) {
                float x0 = p0[i]->x;
                float z0 = p0[i]->z;
                float z1 = p1[i]->z;
                float mn = cx[i] < cy[i] ? cx[i] : cy[i];
                float q1 = mn * w[i] + p0[i]->x;
                Handle_cc7e0 *h = DAT_0052c2a8->v30(tex->id, 1, 0x2020, 4, 0);
                EmitV(h, x0, z0, colA);
                EmitV(h, q1, z0, colA);
                EmitV(h, x0, z1, colA);
                EmitV(h, q1, z1, colA);
                DAT_0052c2a8->v31(h);

                Word_cc7e0 dd;
                dd.f = cx[i] - cy[i];
                dd.u &= 0x7fffffff;
                if (!(dd.f <= 1e-05f)) {
                    float qx = w[i] * cx[i] + p0[i]->x;
                    float z0b = p0[i]->z;
                    float z1b = p1[i]->z;
                    float qy = w[i] * cy[i] + p0[i]->x;
                    float lo = qx;
                    float hi = qy;
                    if (qy < qx) {
                        lo = qy;
                        hi = qx;
                    }
                    Handle_cc7e0 *h2 = DAT_0052c2a8->v30(tex->id, 1, 0x2020, 4, 0);
                    EmitV(h2, lo, z0b, F.s4.u);
                    EmitV(h2, hi, z0b, F.s4.u);
                    EmitV(h2, lo, z1b, F.s4.u);
                    EmitV(h2, hi, z1b, F.s4.u);
                    DAT_0052c2a8->v31(h2);
                }
            }
        }

        Handle_cc7e0 *h3 = DAT_0052c2a8->v30(tex->id, 1, 0x2020, 4, 0);
        EmitV(h3, p1b0->x, p1b0->z, 0x8000ff00);
        float t = F.s0.f * F.s9.f;
        EmitV(h3, t + p1b0->x, p1b0->z, 0x8000ff00);
        EmitV(h3, p1b4->x, p1b4->z, 0x8000ff00);
        EmitV(h3, t + p1b4->x, p1b4->z, 0x8000ff00);
        DAT_0052c2a8->v31(h3);
    } else if (mode == 2) {
        float N3 = p1e8->x - p1e0->x;
        float u = f18c / owner->FUN_000360b0();
        if (!(u < 1.0f))
            u = 1.0f;
        float v = f190 / owner->FUN_000360b0();
        if (!(v < 1.0f))
            v = 1.0f;
        float x0 = p1e0->x;
        float z0 = p1e0->z;
        float z1 = p1e4->z;
        float mn = u < v ? u : v;
        float q = mn * N3 + p1e0->x;
        Handle_cc7e0 *h = DAT_0052c2a8->v30(tex->id, 1, 0x2020, 4, 0);
        EmitP(h, F.v, x0, z0, colA);
        EmitP(h, F.v, q, z0, colA);
        EmitP(h, F.v, x0, z1, colA);
        EmitP(h, F.v, q, z1, colA);
        DAT_0052c2a8->v31(h);

        float mn2 = u < v ? u : v;
        float X1 = mn2 * N3 + p1e0->x;
        float mx = u < v ? v : u;
        float X2 = mx * N3 + p1e0->x;
        Handle_cc7e0 *h2 = DAT_0052c2a8->v30(tex->id, 1, 0x2020, 4, 0);
        EmitP(h2, F.v, X1, z0, F.s4.u);
        EmitP(h2, F.v, X2, z0, F.s4.u);
        EmitP(h2, F.v, X1, z1, F.s4.u);
        EmitP(h2, F.v, X2, z1, F.s4.u);
        DAT_0052c2a8->v31(h2);
    } else if (mode == 3 || mode == 4 || mode == 5) {
        F.s7.f = Lerp(p1b0->z, p1a4->z, f17c);          // zA
        F.s6.f = Lerp(p1b4->z, p1a8->z, f17c);          // zB
        F.s5.f = Lerp(p1b0->x, p1a4->x, f17c);          // xA
        float mn = FUN_000186f0(F.s0.f, F.s1.f);
        float xB1 = (mn * F.s2.f + p1b0->x) * (1.0f - f17c);
        float mn2 = FUN_000186f0(F.s0.f, F.s1.f);
        F.s4.f = (mn2 * F.s2.f + p1a4->x) * f17c + xB1;  // xB
        Handle_cc7e0 *h = DAT_0052c2a8->v30(tex->id, 1, 0x2020, 4, 0);
        EmitP(h, F.v, F.s5.f, F.s7.f, colA);
        EmitP(h, F.v, F.s4.f, F.s7.f, colA);
        EmitP(h, F.v, F.s5.f, F.s6.f, colA);
        EmitP(h, F.v, F.s4.f, F.s6.f, colA);
        DAT_0052c2a8->v31(h);

        F.s3.f = 1.0f - f17c;
        Node *b0c = p1b0;
        float mnA = FUN_000186f0(F.s0.f, F.s1.f);
        F.s9.f = (mnA * F.s2.f + b0c->x) * F.s3.f;      // xC
        float mnB = FUN_000186f0(F.s0.f, F.s1.f);
        F.s5.f = (mnB * F.s2.f + p1a4->x) * f17c + F.s9.f;      // xD
        float mxA = FUN_00018710(F.s0.f, F.s1.f);
        F.s9.f = (mxA * F.s2.f + b0c->x) * F.s3.f;      // xE
        float mxB = FUN_00018710(F.s0.f, F.s1.f);
        F.s4.f = (mxB * F.s2.f + p1a4->x) * f17c + F.s9.f;      // xF
        Handle_cc7e0 *h2 = DAT_0052c2a8->v30(tex->id, 1, 0x2020, 4, 0);
        EmitP(h2, F.v, F.s5.f, F.s7.f, colB);
        EmitP(h2, F.v, F.s4.f, F.s7.f, colB);
        EmitP(h2, F.v, F.s5.f, F.s6.f, colB);
        EmitP(h2, F.v, F.s4.f, F.s6.f, colB);
        DAT_0052c2a8->v31(h2);
    }

    DAT_0052c2ac->pass->v16(0);
}
