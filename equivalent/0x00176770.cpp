// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 52/52)
// hulkfight::motion::SurfAction::vfunc_5 @ 0x00176770
#include "decls/address.h"
extern "C" double cos(double);
extern "C" double fabs(double);

struct V3_176770 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_000111b0(const V3_176770 *a, const V3_176770 *b);
    char FUN_0022d2b0(const V3_176770 *z, float eps);
};

struct Mat_176770 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(const V3_176770 *axis, float angle);
    void FUN_0022c3b0(const V3_176770 *in, V3_176770 *out);
    void FUN_0022ba70(float angle);
    void FUN_0022ca90(Mat_176770 *a, Mat_176770 *b);
};

struct YObj_176770 {
    char pad0[0x1a39];
    char b1a39;
    char pad1a3a[0x1a6c - 0x1a3a];
    V3_176770 v1a6c;
    char pad1a78[0x2064 - 0x1a78];
    V3_176770 v2064;
    void FUN_00035550(V3_176770 *out);
};

struct XObj_176770 {
    YObj_176770 *FUN_00059a30();
    void FUN_00059a50(V3_176770 *out);
};

struct F20_176770 {
    XObj_176770 *FUN_000592a0();
};

struct Sub18_176770 {
    void FUN_00221c60(Mat_176770 *m);
};

struct F24 {
    char pad0[0x18];
    Sub18_176770 sub18;
};

struct P1c_176770 {
    char pad0[0x18];
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
    float f38;
};

struct Lim {
    char pad0[0x18];
    float f18;
};
struct World {
    char pad0[0x24];
    Lim *p24;
};

extern float DAT_004b7d18;
extern float DAT_004b7d1c;
extern float DAT_004b7d20;
extern float DAT_004e13f8;
extern unsigned int DAT_004e13fc;

float __cdecl FUN_00224f10(V3_176770 *v);
float __cdecl FUN_00224fc0(float a, float b);
float __cdecl FUN_00083d90(float *v);
void __cdecl FUN_00224d70(float angle, V3_176770 *v);
void __cdecl FUN_00224db0(Mat_176770 *m, V3_176770 *a, V3_176770 *b);

struct Frame_176770 {
    float t0;           // 0x00
    char pad4[3];
    char b7;            // 0x07
    float s8;           // 0x08
    float sc;           // 0x0c
    float s10;          // 0x10
    V3_176770 q;               // 0x14
    V3_176770 u;               // 0x20
    float ang;          // 0x2c
    float lim;          // 0x30
    V3_176770 z;               // 0x34
    V3_176770 g;               // 0x40
    V3_176770 h;               // 0x4c
    V3_176770 k;               // 0x58
    union {
        XObj_176770 *X;
        float dd;
    } u64;              // 0x64
    V3_176770 w;               // 0x68
    V3_176770 n;               // 0x74
    Mat_176770 M1;             // 0x80
    Mat_176770 M2;             // 0xc0
    Mat_176770 M3;             // 0x100
    Mat_176770 M4;             // 0x140
    Mat_176770 M5;             // 0x180
};

class SurfAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool v5(int a0, float dt);
    char pad04[0x1c - 4];
    P1c_176770 *p1c;
    F20_176770 *p20;
    F24 *p24;
    float f28;
    float f2c;
    float f30;
    float f34;
    V3_176770 v38;
    float f44_unused;
};

bool SurfAction::v5(int a0, float dt)
{
    Frame_176770 f;

    if (a0)
        return true;
    if (p24 == 0)
        return false;

    f.u64.X = p20->FUN_000592a0();
    YObj_176770 *Y = f.u64.X->FUN_00059a30();
    f.g.x = DAT_004b7d18;
    f.g.y = DAT_004b7d1c;
    f.g.z = DAT_004b7d20;
    Y->FUN_00035550(&f.g);
    f.u.x = Y->v2064.x;
    f.u.y = Y->v2064.y;
    f.u.z = Y->v2064.z;
    f.b7 = 1;
    f.z.x = 0.0f;
    f.z.y = 0.0f;
    f.z.z = 0.0f;
    if (f.u.FUN_0022d2b0(&f.z, 1e-5f)) {
        f.b7 = 0;
        f.u.x = f.g.x;
        f.u.y = f.g.y;
        f.u.z = f.g.z;
    }
    f.u.FUN_0022d110();
    f.lim = 0.0f;
    double dot = f.g.z * f.u.z + f.g.y * f.u.y + f.g.x * f.u.x;
    if (dot < -0.7071067690849304f) {
        f.u.x = f.g.x;
        f.u.y = f.g.y;
        f.u.z = f.g.z;
        f.lim = (-0.7071067690849304f - dot) * 3.4142134189605713f;
    }

    f.sc = FUN_00224f10(&f.u);
    float ang0 = f.sc;
    float f28s = f28;
    f.ang = f28s;
    double sd = FUN_00224fc0(f28s, ang0) * 0.31830987334251404f;
    P1c_176770 *p = p1c;
    f.t0 = p->f24;
    f.sc = p->f28;
    sd = sd * f.sc;
    f.s10 = (float)sd;
    double adj;
    if (f.t0 > 0.0f) {
        float a = (float)fabs(f2c);
        f.s8 = (a < f.t0) ? a : f.t0;
        adj = f.s10 - FUN_00083d90(&f2c) * f.s8 / f.t0 * f.sc;
    } else {
        adj = sd;
    }
    double n2c = adj * dt + f2c;
    f2c = (float)n2c;
    f.ang = (float)(n2c * dt + f.ang);
    f.w.x = DAT_004b7d18;
    f.w.y = DAT_004b7d1c;
    f.w.z = DAT_004b7d20;
    FUN_00224d70(f.ang, &f.w);
    f.t0 = (float)(f.w.z * f.u.z + f.w.y * f.u.y + f.w.x * f.u.x);
    f.t0 = (float)fabs(f.t0);
    f.sc = 1.0f - f.t0;
    float r = FUN_00224fc0(ang0, f.ang);
    p = p1c;
    f.s10 = p->f2c;
    float sgn;
    if (r < 0.0f)
        sgn = -1.0f;
    else if (r > 0.0f)
        sgn = 1.0f;
    else
        sgn = 0.0f;
    double t = -(sgn * f.s10 * f.sc);
    f.s8 = f30;
    f.t0 = (float)(f.s8 - t);
    f.t0 = (float)fabs(f.t0);
    double newf30 = t;
    if (!(f.t0 <= 1e-5f)) {
        double e = f.b7 ? p->f30 : p->f34;
        if (!(e <= 0.0f)) {
            float diff = (float)(t - f.s8);
            f.t0 = diff;
            f.s10 = (float)fabs(diff);
            f.sc = (float)(e * dt);
            if (!(f.s10 < f.sc))
                newf30 = FUN_00083d90(&f.t0) * f.sc + f.s8;
        }
    }
    f30 = (float)newf30;

    double v1 = f34 - dt * p->f1c;
    f34 = (float)v1;
    double v2 = v1 - f.lim * p->f20 * dt;
    f34 = (float)v2;
    if (v2 < 0.0f)
        f34 = 0.0f;
    if (p->f18 > f34)
        f34 = p->f18;

    f.n.x = 0.0f;
    f.n.y = 0.0f;
    f.n.z = 0.0f;
    f.u64.X->FUN_00059a50(&f.n);
    f.k.x = DAT_004b7d18;
    f.k.y = DAT_004b7d1c;
    f.k.z = DAT_004b7d20;
    FUN_00224d70(f.ang, &f.k);
    double s = dt * f34;
    f.h.x = f.n.x;
    f.h.y = f.n.y;
    f.h.z = f.n.z;
    f.k.x = f.k.x * s;
    f.k.y = f.k.y * s;
    f.k.z = f.k.z * s;
    f.lim = DAT_004dd700->p24->f18;
    f.h.x = f.h.x + f.k.x;
    double hy = f.k.y + f.h.y;
    f.h.y = (float)hy;
    f.h.z = f.h.z + f.k.z;
    if (hy <= f.lim)
        f.h.y = f.lim + 1e-5f;

    f.M4.FUN_0022b980();
    f.q.x = 0.0f;
    f.q.y = 1.0f;
    f.q.z = 0.0f;
    if (Y->b1a39) {
        f.q.y = Y->v1a6c.y;
        f.q.x = Y->v1a6c.x;
        f.q.z = Y->v1a6c.z;
        if (f.q.y <= 0.1f) {
            f.q.x = 0.0f;
            f.q.y = 1.0f;
            f.q.z = 0.0f;
        }
    }
    f.t0 = dt * p1c->f38;
    double cc;
    if (f.t0 < 0.0f || f.t0 > 3.1415927410125732f)
        cc = -1.0f;
    else
        cc = cos(f.t0);
    double dd2 = f.q.z * v38.z + f.q.y * v38.y + f.q.x * v38.x;
    f.u64.dd = (float)dd2;
    if (!(DAT_004e13fc & 1)) {
        double c1 = cos(0.017453293005625408);
        DAT_004e13fc |= 1;
        DAT_004e13f8 = (float)(1.0f - c1);
    }
    if (dd2 >= cc - DAT_004e13f8) {
        v38.x = f.q.x;
        v38.y = f.q.y;
        v38.z = f.q.z;
    } else if (!(DAT_004e13f8 - 1.0f >= f.u64.dd)) {
        f.z.FUN_000111b0(&f.q, &v38);
        if (f.z.z * f.z.z + f.z.y * f.z.y + f.z.x * f.z.x > 0.0f) {
            f.M2.FUN_0022b980();
            f.M2.FUN_0022baf0(&f.z, f.t0);
            f.q.x = v38.x;
            f.q.y = v38.y;
            f.q.z = v38.z;
            f.M2.FUN_0022c3b0(&f.q, &v38);
        }
    }
    if (v38.y > 0.0f && v38.y < 0.9999899864196777f) {
        f.z.x = 0.0f;
        f.z.y = 1.0f;
        f.z.z = 0.0f;
        FUN_00224db0(&f.M4, &f.z, &v38);
    }
    f.M3.FUN_0022b980();
    f.M3.FUN_0022ba70(f.ang);
    f28 = f.ang;
    f.M5.FUN_0022b980();
    f.M5.FUN_0022baf0(&f.w, f30);
    f.M1 = f.M3;
    f.M2.FUN_0022ca90(&f.M1, &f.M4);
    f.M1 = f.M2;
    f.M2.FUN_0022ca90(&f.M1, &f.M5);
    f.M1 = f.M2;
    f.M1.m[12] = f.h.x;
    f.M1.m[14] = f.h.z;
    f.M1.m[13] = f.h.y;
    p24->sub18.FUN_00221c60(&f.M1);
    return f34 > 0.0f;
}
