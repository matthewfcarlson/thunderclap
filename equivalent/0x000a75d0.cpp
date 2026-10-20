// STATUS: equivalent (tools/equiv.py level 3: 3091 inputs, branch coverage 130/130)
// CChaseCamera::vfunc_35 @ 0x000a75d0
// cl-flags: /GS
#include "decls/data/game/global.h"

extern "C" double __cdecl sqrt(double);


static float AbsF(float v)
{
    union { float f; unsigned int u; } c;
    c.f = v;
    c.u &= 0x7fffffff;
    return c.f;
}

struct V3_a75d0 {
    float x, y, z;
    void FUN_0022d210(struct Mat_a75d0 *m);
    void FUN_000a06d0(V3_a75d0 *src);
    void FUN_00078710(V3_a75d0 *a, V3_a75d0 *b, float c);
};

struct Mat_a75d0 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022b9f0();
    void FUN_0022bda0(float a, float b, float c);
    void FUN_0022be40(V3_a75d0 *pos);
    void FUN_0022bec0(V3_a75d0 *a, V3_a75d0 *b);
};

float __cdecl FUN_0009faa0(float cur, float target, float dt, float rate);
float __cdecl FUN_0009fb20(float a, float b, float c, float d, float e);
float __cdecl FUN_000a00e0(float a, float b, float c, float d, float e);
float __cdecl FUN_000a02a0(float v);
float __cdecl FUN_000a0450(V3_a75d0 *v);
void __cdecl FUN_000a04c0(V3_a75d0 *dir, float *yaw, float *pitch, float *len);

struct Target_a75d0 {
    char pad0[0x140];
    int f140;
    char pad144[0x328 - 0x144];
    int f328;
    char pad32c[0x1a60 - 0x32c];
    V3_a75d0 f1a60;
    void FUN_000382c0(V3_a75d0 *out);
    char FUN_00038e30(V3_a75d0 *a, V3_a75d0 *b, float c, int d, V3_a75d0 *e, V3_a75d0 *f);
    char FUN_00035550(V3_a75d0 *out);
    char FUN_00035d80();
};

struct Input32c_a75d0 {
    int state;
    void FUN_000a2100(float a1, float a3, float dt, float f14, float f10);
};

class CGameCamera {
public:
    void vfunc_35(float a1, float dt, float a3, float a4);
};

class CChaseCamera {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual Mat_a75d0 *v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void v21(Mat_a75d0 *m);
    char padf4[0xf1 - 4];
    char bf1;
    char padf2[0x170 - 0xf2];
    V3_a75d0 p170;
    char pad17c[0x194 - 0x17c];
    V3_a75d0 p194;
    V3_a75d0 p1a0;
    V3_a75d0 p1ac;
    V3_a75d0 p1b8;
    V3_a75d0 p1c4;
    V3_a75d0 p1d0;
    char pad1dc[0x20c - 0x1dc];
    float f20c;
    float f210;
    float f214;
    float f218;
    float f21c;
    float f220;
    float f224;
    float f228;
    float f22c;
    float f230;
    char pad234[0x238 - 0x234];
    float f238;
    char pad23c[0x240 - 0x23c];
    float f240;
    char b244;
    char pad245[3];
    V3_a75d0 p248;
    char pad254[0x278 - 0x254];
    V3_a75d0 p278;
    char pad284[0x290 - 0x284];
    V3_a75d0 p290;
    char pad29c[0x2ec - 0x29c];
    float f2ec, f2f0, f2f4, f2f8, f2fc, f300, f304, f308;
    char pad30c[0x318 - 0x30c];
    float f318;
    char pad31c[4];
    int state;
    char pad324[0x32c - 0x324];
    Input32c_a75d0 in32c;
    char pad330[0x334 - 0x330];
    float f334;
    char pad338[0x344 - 0x338];
    char b344;
    char pad345;
    char b346;
    char b347;
    char b348;
    char b349;
    char pad34a[2];
    float f34c;
    Target_a75d0 *f350;
    char pad354[0x3b4 - 0x354];
    int f3b4;
    char pad3b8[0x410 - 0x3b8];
    unsigned int f410;
    int f414;
    char pad418[0x444 - 0x418];
    float f444;
    char pad448[4];
    float f44c;
    char pad450[0x478 - 0x450];
    float f478, f47c, f480, f484;
    int f488;
    char pad48c[4];
    char b490;
    char pad491[0x4ac - 0x491];
    float f4ac, f4b0, f4b4;
    char b4b8, b4b9, b4ba;

    void FUN_000a74c0(float a, int b);
    void FUN_000a1ca0(float a, float dt);
    void FUN_000a0c40(int v);
    void FUN_000a2cc0(float a, float b, float c, float d, int e);
    void FUN_000a2f30(int v);
    void FUN_000a3040(float a, float dt);
    void FUN_000a38c0(float a, float dt);
    void FUN_000a4450(float a, float dt);
    void FUN_000a4b90(float a, float dt);
    void FUN_000a5400(float a, float dt);
    void FUN_000a55a0(float a, float dt);
    void FUN_000a6400(float a, float dt);
    void FUN_000a1760(float a, float dt);
    char FUN_000a5a90(float a, float b, float c, float d, float e, int f, float g);
    void vfunc_35(float a1, float dt, float a3, float a4);
};

struct Frame_a75d0 {
    float F10;
    float F14;
    V3_a75d0 v1;
    V3_a75d0 v2;
    V3_a75d0 vA;
    V3_a75d0 vB;
    V3_a75d0 vC;
    V3_a75d0 vD;
    union {
        Mat_a75d0 M;
        struct { char p[0x40]; V3_a75d0 vE; } x;
        struct { char p[0x38]; Mat_a75d0 M3; } m3;
    } u;
    char pad[0x14];
    Mat_a75d0 mat2;
};

void CChaseCamera::vfunc_35(float a1, float dt, float a3, float a4)
{
    Frame_a75d0 f;
    if (!bf1) {
        p248.FUN_000a06d0(&p170);
        b346 = 0;
        b349 = 0;
        if (f350 == 0)
            FUN_000a74c0(a1, 0);
        FUN_000a1ca0(a1, dt);
        if (f4ac <= dt)
            f4ac = 0.0f;
        else
            f4ac = f4ac - dt;
        if (f4b0 <= dt)
            f4b0 = 0.0f;
        else
            f4b0 = f4b0 - dt;
        if (f4b4 <= dt)
            f4b4 = 0.0f;
        else
            f4b4 = f4b4 - dt;
        if (b4b8) {
            if (AbsF(f4ac) <= 1e-005f && AbsF(f4b0) <= 1e-005f)
                b4b8 = 0;
        }
        float dx = p1b8.x - p290.x;
        float dy = p1b8.y - p290.y;
        float dz = p1b8.z - p290.z;
        f.F14 = 0.0f;
        if (state == 0) {
            float dot = dx * dx + dy * dy + dz * dz;
            if (!(AbsF(dot) <= 0.01f)) {
                f.u.M = *v14();
                f.vB.x = f.u.M.m[12];
                f.vB.y = f.u.M.m[13];
                f.vB.z = f.u.M.m[14];
                f.u.M.FUN_0022b9f0();
                f350->FUN_000382c0(&f.vA);
                f.v1.x = DAT_0049ecbc;
                f.v1.y = 0.0f;
                f.v1.z = (*(float*)&DAT_0049ecc4);
                f.v1.FUN_0022d210(&f.u.M);
                f.v1.x = f.vB.x + f.v1.x;
                f.v1.y = f.vB.y + f.v1.y;
                f.v1.z = f.vB.z + f.v1.z;
                f.v2.x = DAT_0049ecb8;
                f.v2.y = 0.0f;
                f.v2.z = -0.5f;
                f.v2.FUN_0022d210(&f.u.M);
                f.v2.x = f.v2.x + f.vA.x;
                f.v2.y = f.vA.y + f.v2.y;
                f.v2.z = f.vA.z + f.v2.z;
                if (f350->FUN_00038e30(&f.v2, &f.v1, (*(float*)&DAT_0049ecc0), 1, &f.vC, &f.vD)) {
                    f.F14 = 1.0f;
                    f4ac = (*(float*)&DAT_0049ecc8);
                }
                f.v1.x = -DAT_0049ecbc;
                f.v1.y = 0.0f;
                f.v1.z = (*(float*)&DAT_0049ecc4);
                f.v1.FUN_0022d210(&f.u.M);
                f.v1.x = f.vB.x + f.v1.x;
                f.v1.y = f.vB.y + f.v1.y;
                f.v1.z = f.vB.z + f.v1.z;
                f.v2.x = -DAT_0049ecb8;
                f.v2.y = 0.0f;
                f.v2.z = -0.5f;
                f.v2.FUN_0022d210(&f.u.M);
                f.v2.x = f.v2.x + f.vA.x;
                f.v2.y = f.vA.y + f.v2.y;
                f.v2.z = f.vA.z + f.v2.z;
                if (f350->FUN_00038e30(&f.v2, &f.v1, (*(float*)&DAT_0049ecc0), 1, &f.vC, &f.vD)) {
                    f.F14 = f.F14 - 1.0f;
                    f4b0 = (*(float*)&DAT_0049ecc8);
                }
            }
        }
        if (b4ba || (f4ac > 0.0f && f4b0 > 0.0f)) {
            f.F14 = 0.0f;
            b4ba = 1;
        } else {
            if (f.F14 != 0.0f) {
                f.F14 = FUN_0009faa0(f334, f.F14, dt, (*(float*)&DAT_0049eccc));
                b4b8 = 1;
            }
        }
        if (b4ba) {
            if (AbsF(f4ac) <= 1e-005f && AbsF(f4b0) <= 1e-005f)
                b4ba = 0;
        }
        b4b9 = 0;
        f.F10 = 0.0f;
        if (f350->f140 == 3) {
            float ex = p1b8.x - f350->f1a60.x;
            float ey = p1b8.y - f350->f1a60.y;
            float ez = p1b8.z - f350->f1a60.z;
            if (ex * ex + ey * ey + ez * ez >= DAT_0049ecd0 * DAT_0049ecd0) {
                if (f350->FUN_00035550(&f.vC)) {
                    f.u.M = *v14();
                    f.vA.x = f.u.M.m[12];
                    f.vA.y = f.u.M.m[13];
                    f.vA.z = f.u.M.m[14];
                    f.u.M.FUN_0022b9f0();
                    f350->FUN_000382c0(&f.vB);
                    f.v2.x = 0.0f;
                    f.v2.y = 0.0f;
                    f.v2.z = 0.0f;
                    f.v2.FUN_0022d210(&f.u.M);
                    f.v2.x = f.v2.x + f.vA.x;
                    f.v2.y = f.vA.y + f.v2.y;
                    f.v2.z = f.vA.z + f.v2.z;
                    f.mat2.FUN_0022b9f0();
                    f.vA.x = 0.0f;
                    f.vA.y = 1.0f;
                    f.vA.z = 0.0f;
                    f.mat2.FUN_0022bec0(&f.vC, &f.vA);
                    f.v1.x = 0.0f;
                    f.v1.y = (*(float*)&DAT_0049ecd4);
                    f.v1.z = (*(float*)&DAT_004dd9e0);
                    f.v1.FUN_0022d210(&f.mat2);
                    f.v1.x = f.vB.x + f.v1.x;
                    f.v1.y = f.vB.y + f.v1.y;
                    f.v1.z = f.vB.z + f.v1.z;
                    if (f350->FUN_00038e30(&f.v1, &f.v2, (*(float*)&DAT_0049ecc0), 1, &f.u.x.vE, &f.vD)) {
                        f.F10 = 1.0f;
                        b4b9 = 1;
                        if (b348)
                            f4b4 = 1.5f;
                        else
                            f4b4 = 0.5f;
                    }
                }
            }
        }
        in32c.FUN_000a2100(a1, a3, dt, f.F14, f.F10);
        if (in32c.state == 1) {
            int s = state;
            if (s != 1 && s != 3 && s != 6 && s != 7) {
                float t;
                if (s == 2)
                    t = 0.0f;
                else
                    t = f44c;
                FUN_000a2cc0(f238 + 180.0f, t, f444, (*(float*)&DAT_0049ec64), s);
                f488 = 0;
            }
        }
        if (state == 4 && !(f410 & 0x21))
            FUN_000a0c40(0);
        int ecx = state;
        if (ecx == 1 && f3b4 == 0 && !(f410 & 0x86))
            f3b4 = 2;
        int ea = f350->f140;
        if (ea > 0 && ea <= 2 && (ecx == 1 || (ecx > 1 && ecx <= 3)))
            FUN_000a0c40(0);
        f414 = 0;
        if (f350->FUN_00035d80())
            f414 = f350->f328;
        if (f414 != 0) {
            if (state != 6) {
                FUN_000a0c40(6);
                f.v1.x = p248.x - p1c4.x;
                f.v1.y = p248.y - p1c4.y;
                f.v1.z = p248.z - p1c4.z;
                FUN_000a04c0(&f.v1, &f478, &f47c, &f480);
                f484 = f2f4 + f2ec;
            }
        } else if (state == 6) {
            FUN_000a0c40(0);
        }
        if ((f410 >> 8) & 1)
            b347 = 1;
        if (b347) {
            if (state != 6 && state != 5)
                FUN_000a0c40(5);
        } else if (state == 5) {
            FUN_000a0c40(0);
        }
        if (!b344) {
            FUN_000a2f30(0);
        } else {
            switch (state) {
            case 0: FUN_000a3040(a1, dt); break;
            case 1: FUN_000a38c0(a1, dt); break;
            case 2: FUN_000a4450(a1, dt); break;
            case 3: FUN_000a4b90(a1, dt); break;
            case 4: FUN_000a5400(a1, dt); break;
            case 5: FUN_000a55a0(a1, dt); break;
            case 6: FUN_000a6400(a1, dt); break;
            case 7: FUN_000a1760(a1, dt); break;
            }
        }
        if (b346)
            f34c = DAT_0049ecac;
        if (state != 6) {
            if (!(AbsF(dt) <= 1e-005f)) {
                float inv = 1.0f / dt;
                volatile float *u = &p1a0.x;
                u[0] = p170.x - p248.x;
                u[1] = p170.y - p248.y;
                u[2] = p170.z - p248.z;
                u[0] = inv * u[0];
                u[1] = inv * u[1];
                u[2] = inv * u[2];
                volatile float *u2 = &p1ac.x;
                u2[0] = u[0] - p278.x;
                u2[1] = u[1] - p278.y;
                u2[2] = u[2] - p278.z;
                u2[0] = inv * u2[0];
                u2[1] = inv * u2[1];
                u2[2] = inv * u2[2];
            }
            f.F10 = -200.0f;
            if (p1d0.x * p1d0.x + p1d0.z * p1d0.z >= 25.0f)
                f.F10 = FUN_000a02a0(FUN_000a0450(&p1d0) + 180.0f);
            FUN_000a5a90(0.0f, 360.0f, f.F10, -10.0f, 60.0f, 0, dt);
        }
        float ddx = p194.x - p1c4.x;
        float ddy = p194.y - p1c4.y;
        float ddz = p194.z - p1c4.z;
        f.F10 = (float)sqrt(ddx * ddx + (ddy * ddy + ddz * ddz));
        float cur = f.F10;
        float diff = cur - f318;
        if (b244) {
            if (!b490) {
                b490 = 1;
            } else if (diff > 0.02f) {
                float r = FUN_000a00e0(f318, f.F10, 15.0f, dt, 0.5f);
                p194.FUN_00078710(&p1c4, &p194, r / f.F10);
                cur = r;
            }
        } else {
            if (b490 && diff > 0.02f) {
                float r = FUN_000a00e0(f318, f.F10, 15.0f, dt, 0.5f);
                p194.FUN_00078710(&p1c4, &p194, r / f.F10);
                cur = r;
            } else if (diff <= 0.02f) {
                b490 = 0;
            }
        }
        f240 = cur;
        f.F10 = f214;
        f220 = f21c;
        f218 = f214;
        f228 = f224;
        f230 = f22c;
        f214 = FUN_0009fb20(f2ec, f2f0, f.F10, dt, (*(float*)&DAT_0049ec84));
        f21c = FUN_0009fb20(f2f4, f2f8, f220, dt, (*(float*)&DAT_0049ec84));
        f224 = FUN_0009fb20(f2fc, f300, f228, dt, (*(float*)&DAT_0049ec84));
        f22c = FUN_0009fb20(f304, f308, f230, dt, (*(float*)&DAT_0049ec88));
        f.u.m3.M3.FUN_0022b980();
        f.u.m3.M3.FUN_0022bda0((f20c + f21c + f214) * -0.01745329238474369f,
                               (f210 + f224) * 0.01745329238474369f, f22c * 0.01745329238474369f);
        f.u.m3.M3.FUN_0022be40(&p194);
        v21(&f.u.m3.M3);
        b344 = 1;
        ((CGameCamera *)this)->vfunc_35(a1, dt, a3, a4);
        f410 = 0;
    }
}
