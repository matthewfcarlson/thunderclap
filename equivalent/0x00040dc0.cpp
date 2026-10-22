// STATUS: equivalent (tools/equiv.py level 3: 20049 inputs, branch coverage 78/78)
// FUN_00040dc0 @ 0x00040dc0
#include "compat/ptr.h"
// the value a float slot holds after a store: the original reloads it (rounded) where MSVC 7.1 would reuse the
// unrounded register
static inline float Stored_40dc0(const float &v)
{
    return *(const volatile float *)&v;
}

struct V3_40dc0 {
    float x, y, z;
    float FUN_0022d110();
    char FUN_0022d2b0(const V3_40dc0 *other, float eps);
};

struct Mat4_40dc0 {
    float m[12];
    V3_40dc0 trans;
    float w;
    void FUN_0022c120();
    void FUN_0022ca90(const Mat4_40dc0 *a, const Mat4_40dc0 *b);
    void FUN_0022c2b0(const V3_40dc0 *in, V3_40dc0 *out);
    void FUN_0022c3b0(const V3_40dc0 *in, V3_40dc0 *out);
};

struct Xform_40dc0 {
    Mat4_40dc0 mat;
    float q[4];
    int type;
    void FUN_00221b70(const Mat4_40dc0 *m);
    void FUN_00221be0(const Xform_40dc0 *other);
    void FUN_00221e60(const Mat4_40dc0 *m);
    void FUN_00221c60(const Mat4_40dc0 *m);
    Mat4_40dc0 *FUN_00221c40();
    void FUN_00222120(V3_40dc0 *out);
    float FUN_002220d0();
};

struct Bones_40dc0 {
    char pad0[0x1c];
    char *mats;
};

struct Scene_40dc0 {
    char pad0[0x10];
    Xform_40dc0 xf;
    Bones_40dc0 *bones;
    void FUN_00224260(unsigned int lo, unsigned int hi, Xform_40dc0 *x);
    void FUN_00222f40(float dt);
    void FUN_00223fa0();
    void FUN_00223060();
    void FUN_002226e0(const Mat4_40dc0 *m);
    void FUN_002226f0(const V3_40dc0 *v);
    void FUN_00222710(const V3_40dc0 *v);
    float FUN_00222da0(void *key);
};

struct Holder10_40dc0 {
    Scene_40dc0 *FUN_00059a40();
};

struct Prop_40dc0 {
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
    virtual Mat4_40dc0 *v15();
};

struct Releasable_40dc0 {
    virtual void v0();
    virtual void v1();
};

struct Cfg_40dc0 {
    char pad0[0x30];
    float f30;
    float f34;
};

struct Obj338 {
    char pad0[0x10];
    Holder10_40dc0 *holder;
};

struct Obj388 {
    char pad0[0x18];
    Xform_40dc0 xf;
};

struct CCharacter_40dc0;
struct Sink_40dc0 {
    void FUN_00099d00(struct Args_40dc0 *a, CCharacter_40dc0 *f, int z);
};
struct Args_40dc0 {
    char pad0[8];
    Sink_40dc0 *f8;
};

extern float __cdecl FUN_00224fc0(float a, float b);

struct Frame_40dc0 {
    float ang0;     // 0x00
    float inv;      // 0x04
    V3_40dc0 vA;          // 0x08
    V3_40dc0 vB;          // 0x14
    V3_40dc0 vC;          // 0x20
    V3_40dc0 vD;          // 0x2c
    V3_40dc0 P0;          // 0x38
    float S0;       // 0x44
    Mat4_40dc0 M58;       // 0x48
    Mat4_40dc0 M98;       // 0x88
    V3_40dc0 od8, oe4, of0, ofc;
    Xform_40dc0 x;        // 0xf8
    Mat4_40dc0 M15c;      // 0x14c
    Mat4_40dc0 M19c;      // 0x18c
};

class CCharacter_40dc0 {
public:
    char pad0[0x10];
    Holder10_40dc0 *holder;
    Xform_40dc0 x14;
    V3_40dc0 v68;
    V3_40dc0 v74;
    V3_40dc0 v80;
    float f8c;
    char pad90[0x110 - 0x90];
    float f110;
    int i114;
    char pad118;
    char b119;
    char pad11a[2];
    Cfg_40dc0 *cfg;
    char pad120[0x128 - 0x120];
    Prop_40dc0 *p128;
    char pad12c[0x13c - 0x12c];
    int i13c;
    int mode;
    char pad144[0x14c - 0x144];
    char *p14c;
    Mat4_40dc0 m150;
    V3_40dc0 v190;
    V3_40dc0 v19c;
    V3_40dc0 v1a8;
    V3_40dc0 v1b4;
    V3_40dc0 v1c0;
    char pad1cc[0x1e4 - 0x1cc];
    float f1e4;
    V3_40dc0 v1e8;
    float f1f4;
    float f1f8;
    int i1fc;
    char pad200[0x338 - 0x200];
    Obj338 *p338;
    unsigned int u33c;
    unsigned int lo340;
    unsigned int hi344;
    Mat4_40dc0 m348;
    Obj388 *p388;
    char pad38c[4];
    int i390;
    char pad394[0x3a4 - 0x394];
    Releasable_40dc0 *p3a4;
    char pad3a8[0x1b20 - 0x3a8];
    int i1b20;
    char pad1b24[0x22e0 - 0x1b24];
    char b22e0;
    char FUN_00035550(V3_40dc0 *out);
    void FUN_00036480(Args_40dc0 *a, float dt);
    void FUN_000365f0(Args_40dc0 *a, float dt);
    void FUN_00038c40();
    void FUN_0003ba60(Args_40dc0 *a, float dt);
    void FUN_0003be00();
    void FUN_00040dc0(Args_40dc0 *a1, float a2);
};

void CCharacter_40dc0::FUN_00040dc0(Args_40dc0 *a1, float a2)
{
    Scene_40dc0 *scene = holder->FUN_00059a40();
    Frame_40dc0 f;
    f.P0 = x14.mat.trans;
    f.S0 = scene->xf.mat.trans.y;
    float absA2 = a2;
    if (absA2 < 0.0f)
        absA2 = -absA2;
    if (b119)
        return;

    if (p338 != 0 && p388 != 0) {
        Scene_40dc0 *s2 = p338->holder->FUN_00059a40();
        if (s2 != 0) {
            Mat4_40dc0 *src;
            if (u33c != 0xffff)
                src = (Mat4_40dc0 *)(s2->bones->mats + (u33c << 6));
            else
                src = s2->xf.FUN_00221c40();
            f.M98 = *src;
            if ((lo340 | hi344) != 0) {
                f.M15c = f.M98;
                f.M15c.FUN_0022c120();
                f.x.FUN_00221b70(p388->xf.FUN_00221c40());
                f.x.FUN_00221e60(&f.M15c);
                s2->FUN_00224260(lo340, hi344, &f.x);
                f.M58.FUN_0022ca90(&m348, f.x.FUN_00221c40());
            } else {
                f.M58 = m348;
            }
            f.M19c.FUN_0022ca90(&f.M58, &f.M98);
            p388->xf.FUN_00221c60(&f.M19c);
        }
    }

    x14.FUN_00221be0(&scene->xf);
    v68 = x14.mat.trans;
    if (mode == 1 || mode == 2) {
        v68.y = cfg->f30 * 0.5f + v68.y;
    } else if (mode == 4) {
        V3_40dc0 &t = f.vA;
        t.x = 0.0f;
        t.y = 0.0f;
        t.z = 0.0f;
        FUN_00035550(&t);
        float k = -cfg->f34;
        v68.x = t.x * k + v68.x;
        v68.y = t.y * k + v68.y;
        v68.z = t.z * k + v68.z;
    }

    scene->FUN_00222f40(a2);
    scene->FUN_00223fa0();
    if (!b22e0 && p128 != 0)
        scene->FUN_002226e0(p128->v15());
    FUN_0003be00();
    scene->FUN_00223060();

    if (p338 != 0 && p388 != 0) {
        Scene_40dc0 *s2 = p338->holder->FUN_00059a40();
        if (s2 != 0) {
            if (scene->FUN_00222da0(p388) >= 1.0f) {
                Mat4_40dc0 *src;
                if (u33c != 0xffff)
                    src = (Mat4_40dc0 *)(s2->bones->mats + (u33c << 6));
                else
                    src = s2->xf.FUN_00221c40();
                f.M58 = *src;
                f.M19c = *scene->xf.FUN_00221c40();
                f.M98 = f.M58;
                f.M98.FUN_0022c120();
                f.M15c.FUN_0022ca90(&f.M19c, &f.M98);
                if ((lo340 | hi344) != 0) {
                    f.x.FUN_00221b70(p388->xf.FUN_00221c40());
                    f.x.FUN_00221e60(&f.M98);
                    s2->FUN_00224260(lo340, hi344, &f.x);
                    f.M58 = *f.x.FUN_00221c40();
                    f.M58.FUN_0022c120();
                    m348.FUN_0022ca90(&f.M15c, &f.M58);
                } else {
                    m348 = f.M15c;
                }
            }
        }
    }

    V3_40dc0 *sp = &scene->xf.mat.trans;
    V3_40dc0 cp = *sp;
    V3_40dc0 &w = f.vB;
    hulk_freg wx = (hulk_freg)cp.x + v19c.x;   // x and y stay in registers, z goes through w.z (rounded)
    hulk_freg wy = (hulk_freg)cp.y + v19c.y;
    w.z = cp.z + v19c.z;
    v1a8.x = a2 * v1a8.x;
    v1a8.y = a2 * v1a8.y;
    v1a8.z = a2 * v1a8.z;
    w.x = wx + Stored_40dc0(v1a8.x);
    w.y = wy + Stored_40dc0(v1a8.y);
    w.z = Stored_40dc0(w.z) + Stored_40dc0(v1a8.z);
    scene->FUN_002226f0(&w);
    v19c.z = 0.0f;
    v19c.y = 0.0f;
    v19c.x = 0.0f;
    v1a8.z = 0.0f;
    v1a8.y = 0.0f;
    v1a8.x = 0.0f;
    if (!(absA2 <= 1e-05f)) {
        v80 = *sp;
        v80.x = v80.x - x14.mat.trans.x;
        v80.y = v80.y - x14.mat.trans.y;
        v80.z = v80.z - x14.mat.trans.z;
        hulk_freg inv = 1.0f / a2;
        v80.x = inv * Stored_40dc0(v80.x);
        v80.y = inv * Stored_40dc0(v80.y);
        v80.z = inv * Stored_40dc0(v80.z);
    }

    V3_40dc0 &w2 = f.vC;
    w2 = *sp;
    w2.x = w2.x + v1b4.x;
    w2.y = w2.y + v1b4.y;
    w2.z = w2.z + v1b4.z;
    if (f1e4 > 0.0f) {
        if (!(i1fc > 0) && !(f110 > 0.0f) && !(i114 > 0) && !(i1b20 > 0)) {
            V3_40dc0 &d = f.vB;
            d.x = w2.x - x14.mat.trans.x;
            d.y = w2.y - x14.mat.trans.y;
            d.z = w2.z - x14.mat.trans.z;
            d.FUN_0022d110();
            double dot = d.z * v1e8.z;        // dot, t and s stay in registers (double: MSVC spills dot)
            dot += d.y * v1e8.y;
            dot += d.x * v1e8.x;
            double t = 1.0f;
            if (dot > 0.0f)
                t = 1.0f - dot;
            double s = t * f1f4 * a2;
            V3_40dc0 &p = f.vA;
            p.x = v1e8.x;
            p.y = v1e8.y;
            p.z = v1e8.z;
            w2.x = p.x * s + w2.x;
            p.y = p.y * s;
            p.z = p.z * s;
            w2.y = Stored_40dc0(p.y) + w2.y;
            w2.z = Stored_40dc0(p.z) + w2.z;
            if (f1f4 >= 1.0f)
                a1->f8->FUN_00099d00(a1, this, 0);
        }
        f1f4 = a2 * f1f8 + f1f4;
        f1e4 = f1e4 - a2;
    }
    scene->FUN_002226f0(&w2);
    v1b4.z = 0.0f;
    v1b4.y = 0.0f;
    v1b4.x = 0.0f;

    V3_40dc0 &w3 = f.vA;
    w3 = *sp;
    w3.x = w3.x + v1c0.x;
    w3.y = w3.y + v1c0.y;
    w3.z = w3.z + v1c0.z;
    scene->FUN_002226f0(&w3);
    v1c0.z = 0.0f;
    v1c0.y = 0.0f;
    v1c0.x = 0.0f;

    int m13c = i13c;
    float s44 = scene->xf.mat.trans.y;
    if (m13c != 0) {
        mode = m13c;
        i13c = 0;
    } else if (p128 == 0) {
        float dd = f.S0 - s44;
        if (dd < 0.0f)
            dd = -dd;
        if (dd <= 0.01f)
            mode = 1;
        else
            mode = 3;
    } else {
        mode = 3;
    }
    if (mode == 1 || mode == 2 || mode == 4)
        i390 = 0;

    if (p14c != 0) {
        f.M98 = m150;
        f.M98.FUN_0022c120();
        f.M58 = *(Mat4_40dc0 *)(p14c + 0x10);
        V3_40dc0 &w4 = f.vB;
        w4 = *sp;
        V3_40dc0 &od8 = f.od8;
        f.M98.FUN_0022c2b0(&w4, &od8);
        V3_40dc0 &o18 = f.vA;
        f.M58.FUN_0022c2b0(&od8, &o18);
        if (!(absA2 <= 1e-05f)) {
            v190 = *sp;
            v190.x = v190.x - o18.x;
            V3_40dc0 &z3 = f.vC;
            z3.x = 0.0f;
            v190.y = v190.y - o18.y;
            z3.y = 0.0f;
            z3.z = 0.0f;
            v190.z = v190.z - o18.z;
            hulk_freg ninv = -1.0f / a2;
            v190.x = ninv * Stored_40dc0(v190.x);
            v190.y = ninv * Stored_40dc0(v190.y);
            v190.z = ninv * Stored_40dc0(v190.z);
            if (!v190.FUN_0022d2b0(&z3, 1e-05f))
                FUN_00038c40();
        }
        scene->FUN_002226f0(&o18);
        V3_40dc0 &oe4 = f.oe4;
        scene->xf.FUN_00222120(&oe4);
        V3_40dc0 &ofc = f.ofc;
        f.M98.FUN_0022c3b0(&oe4, &ofc);
        V3_40dc0 &of0 = f.of0;
        f.M58.FUN_0022c3b0(&ofc, &of0);
        scene->FUN_00222710(&of0);
    } else {
        v190.z = 0.0f;
        v190.y = 0.0f;
        v190.x = 0.0f;
    }

    FUN_00036480(a1, a2);
    V3_40dc0 &w5 = f.vD;
    w5 = *sp;
    if (!w5.FUN_0022d2b0(&f.P0, 1e-05f)) {
        if (p3a4 != 0)
            p3a4->v1();
        p3a4 = 0;
        FUN_0003ba60(a1, a2);
        FUN_000365f0(a1, a2);
    }
    if (!(absA2 <= 1e-05f)) {
        float &inv = f.inv;
        inv = 1.0f / a2;
        v74 = w5;
        v74.x = v74.x - f.P0.x;
        v74.y = v74.y - f.P0.y;
        v74.z = v74.z - f.P0.z;
        v74.x = Stored_40dc0(inv) * Stored_40dc0(v74.x);
        v74.y = Stored_40dc0(inv) * Stored_40dc0(v74.y);
        v74.z = Stored_40dc0(inv) * Stored_40dc0(v74.z);
        Scene_40dc0 *s3 = holder->FUN_00059a40();
        float &ang0 = f.ang0;
        if (s3 == 0)
            ang0 = 0.0f;
        else
            ang0 = s3->xf.FUN_002220d0();
        f8c = FUN_00224fc0(x14.FUN_002220d0(), ang0) * inv;
    }
}
