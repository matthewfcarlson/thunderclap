// STATUS: equivalent (tools/equiv.py level 3: 3039 inputs, branch coverage 66/66)
// CHypnoticCamera::vfunc_35 @ 0x000abb90
// cl-flags: /GS
#include "decls/address.h"

struct V3_abb90 { float x, y, z; };

struct Mat4_abb90 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bda0(float a, float b, float c);
    void FUN_0022be40(const V3_abb90 *t);
    void FUN_0022ca90(const Mat4_abb90 *a, const Mat4_abb90 *b);
};

struct Hub_abb90 {
    void FUN_000afe80();
};

struct Reg_abb90 {
    Hub_abb90 *FUN_00086330();
};

struct Clock_abb90 {
    float FUN_00085f80();
};

struct Sys_abb90;
struct Ev_abb90 {
    char pad0[8];
    Sys_abb90 *f8;
    char pad0c[0x54 - 0xc];
    Reg_abb90 *f54;
    Clock_abb90 *f58;
};

struct Sys_abb90 {
    void FUN_00099050(Ev_abb90 *e);
};

struct World {
    char pad0[0x54];
    Reg_abb90 *f54;
};

struct Snd_abb90 {
    void FUN_001eb560(const char *s);
    void FUN_001eb8d0(const char *s);
    void FUN_001eb6a0();
    void FUN_001eb6b0();
    void FUN_001ec480(const char *a, const char *b);
};
Snd_abb90 *FUN_001eb200();
char FUN_0009fa00();
float FUN_000a02a0(float v);
void FUN_000a04c0(V3_abb90 *delta, float *a, float *b, float *out);

struct Anim_abb90 {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5();
    virtual void v6(float ms, int flag);
    virtual void v7(); virtual void v8();
    virtual void v9();
};

struct AnimM {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13();
    virtual Mat4_abb90 *v14();
    char pad4[0x10 - 0x4];
    float f10;
};

struct Curve_abb90 {
    char pad0[0x80];
    void FUN_0022e500(int n, const V3_abb90 *p0, const V3_abb90 *t0, const V3_abb90 *p1, const V3_abb90 *t1);
    void FUN_0022e890(V3_abb90 *out, float s);
};

struct Key_abb90 {
    float time;                    // 0x00
    V3_abb90 pos;                        // 0x04
    V3_abb90 tang;                       // 0x10
    float roll;                    // 0x1c
    float pitch;                   // 0x20
    unsigned char flagA;           // 0x24
    char pad25[3];
};

struct R10 { char pad0[0xa8]; unsigned char ba8; };
struct R124 { char pad0[0x10]; R10 *f10; };
struct Q124 { char pad0[0x124]; R124 *f124; };

class CGameCamera {
public:
    virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4(); virtual void c5(); virtual void c6(); virtual void c7(); virtual void c8(); virtual void c9(); virtual void c10(); virtual void c11(); virtual void c12(); virtual void c13(); virtual void c14(); virtual void c15(); virtual void c16(); virtual void c17(); virtual void c18(); virtual void c19(); virtual void c20();
    virtual void v21(Mat4_abb90 *m);
    virtual void c22(); virtual void c23(); virtual void c24(); virtual void c25(); virtual void c26(); virtual void c27(); virtual void c28(); virtual void c29(); virtual void c30(); virtual void c31(); virtual void c32(); virtual void c33(); virtual void c34();
    virtual void vfunc_35(Ev_abb90 *e, float dt, int c, int d);
};

class CHypnoticCamera : public CGameCamera {
public:
    char pad4[0xf1 - 0x4];
    unsigned char bf1;
    char padf2[0x170 - 0xf2];
    Q124 *f170;
    char pad174[0x1c4 - 0x174];
    Key_abb90 keys[11];                  // 0x1c4
    Curve_abb90 curve;                   // 0x37c
    int count;                     // 0x3fc
    int cur;                       // 0x400
    char pad404[4];
    float f408;
    float f40c;
    float f410;
    float f414;
    float f418;
    float f41c;
    float f420;
    Anim_abb90 *f424;
    AnimM *f428;
    Mat4_abb90 m42c;                     // 0x42c (translation at 0x45c)
    float t;                       // 0x46c
    float f470;
    unsigned char b474;
    char pad475[3];
    Anim_abb90 *f478;
    unsigned char b47c;
    unsigned char b47d;
    unsigned char b47e;

    void FUN_000aa680();
    void FUN_000a9090(float v);
    virtual void vfunc_35(Ev_abb90 *e, float dt, int c, int d);
};

struct Frame_abb90 {
    float a;                       // E-0xc0
    float b;                       // E-0xbc
    float s;                       // E-0xb8
    float ac;                      // E-0xb4
    float bc;                      // E-0xb0
    V3_abb90 tmp0;                       // E-0xac
    V3_abb90 out;                        // E-0xa0
    V3_abb90 tmp1;                       // E-0x94
    float f88;                     // E-0x88
    Mat4_abb90 M;                        // E-0x84
    Mat4_abb90 R;                        // E-0x44
};

void CHypnoticCamera::vfunc_35(Ev_abb90 *e, float dt, int c, int d)
{
    Frame_abb90 f;
    char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
    if (bf1 != 0) {
        return;
    }
    if (b47d == 0) {
        FUN_000aa680();
        Snd_abb90 *sn = FUN_001eb200();
        sn->FUN_001eb560("hypnotic_on");
        sn->FUN_001eb8d0("hypnotic_on");
    }
    float clk = e->f58->FUN_00085f80();
    if (clk < 0.1f)
        dt = clk;
    else
        dt = 0.1f;
    DAT_004dd700->f54->FUN_00086330()->FUN_000afe80();

    bool phaseA = true;
    if (t >= 1.5f || b474 != 0) {
        if (FUN_0009fa00())
            b47e = 1;
        if (b474 != 0) {
            phaseA = false;
            if (b47e != 0)
                t = t - (dt + dt);
            else
                t = t - dt;
            if (t < 0.0f) {
                e->f8->FUN_00099050(e);
                Snd_abb90 *sn = FUN_001eb200();
                sn->FUN_001eb560("hypnotic_off");
                sn->FUN_001eb8d0("hypnotic_off");
                sn->FUN_001eb6b0();
                return;
            }
        }
    }
    if (phaseA) {
        float t2 = dt + t;
        t = t2;
        if (t2 >= f410) {
            f170->f124->f10->ba8 = 0;
            f410 = 1.0e12f;
            e->f54->FUN_00086330()->FUN_000afe80();
        }
        if (t >= f41c) {
            FUN_001eb200()->FUN_001eb6a0();
            f41c = 1.0e12f;
        }
        if (b47c != 0)
            f478->v6(dt * 1000.0f, 0);
        if (t >= f414) {
            FUN_001eb200()->FUN_001ec480("hypnotic_cam", "whoosh_in");
            b47c = 1;
            if (f478 != 0)
                f478->v6((t - f414) * 1000.0f, 0);
            f414 = 1.0e12f;
        } else if (t >= f418) {
            FUN_001eb200()->FUN_001ec480("hypnotic_cam", "whoosh_out");
            if (f478 != 0) {
                f478->v9();
                f478->v6((t - f418) * 1000.0f, 0);
            }
            f418 = 1.0e12f;
        }
        if (t >= f40c || b47e != 0) {
            float restart = f420;
            b474 = 1;
            b47c = 0;
            t = restart;
            f170->f124->f10->ba8 = 1;
        }
    }

    if (!(t < f408)) {
        float tmp = t - dt;
        float u;
        if (tmp < f408)
            u = t - f408;
        else
            u = dt;
        f424->v6(u * 1000.0f, 1);
        f.M = *f428->v14();
        f.R.FUN_0022ca90(&f.M, &m42c);
        f.M = f.R;
        v21(&f.M);
        FUN_000a9090(f428->f10 * 57.2957764f);
    } else {
        int ci = cur;
        int si = ci;
        if (si < 0) {
            si = 0;
        } else if (si > 0) {
            do {
                if (!(t <= keys[si].time))
                    break;
                si--;
            } while (si > 0);
        }
        if (si < count) {
            do {
                if (!(t > keys[si + 1].time))
                    break;
                si++;
            } while (si < count);
        }
        double D = keys[si + 1].time - keys[si].time;
        f.s = (float)((t - keys[si].time) / D);
        if (si != ci) {
            f.tmp0.x = (float)(D * keys[si].tang.x);
            f.tmp0.y = (float)(D * keys[si].tang.y);
            f.tmp0.z = (float)(D * keys[si].tang.z);
            f.tmp1.x = (float)(D * keys[si + 1].tang.x);
            f.tmp1.y = (float)(D * keys[si + 1].tang.y);
            f.tmp1.z = (float)(D * keys[si + 1].tang.z);
            curve.FUN_0022e500(2, &keys[si].pos, &f.tmp0, &keys[si + 1].pos, &f.tmp1);
            cur = si;
        }
        curve.FUN_0022e890(&f.out, f.s);
        Key_abb90 *k0 = &keys[si];
        Key_abb90 *k1 = &keys[si + 1];
        f.a = FUN_000a02a0(k1->roll - k0->roll) * f.s + k0->roll;
        f.b = (k1->pitch - k0->pitch) * f.s + k0->pitch;
        f.ac = f.a;
        f.bc = f.b;
        if (k0->flagA != 0 || k1->flagA != 0) {
            f.tmp0.x = m42c.m[12] - f.out.x;
            f.tmp0.y = m42c.m[13] - f.out.y;
            f.tmp0.z = m42c.m[14] - f.out.z;
            FUN_000a04c0(&f.tmp0, &f.ac, &f.bc, &f.f88);
        }
        if (k0->flagA != 0) {
            if (k1->flagA != 0) {
                f.a = f.ac;
                f.b = f.bc;
            } else {
                f.a = FUN_000a02a0(f.a - f.ac) * f.s + f.ac;
                f.b = (f.b - f.bc) * f.s + f.bc;
            }
        } else if (k1->flagA != 0) {
            f.a = FUN_000a02a0(f.ac - f.a) * f.s + f.a;
            f.b = (f.bc - f.b) * f.s + f.b;
        }
        f.M.FUN_0022b980();
        f.M.FUN_0022bda0(f.b * -0.017453292f, f.a * 0.017453292f, 0.0f);
        f.M.FUN_0022be40(&f.out);
        v21(&f.M);
        FUN_000a9090(f470);
    }
    CGameCamera::vfunc_35(e, dt, c, d);
}
