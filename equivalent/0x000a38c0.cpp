// STATUS: equivalent (tools/equiv.py level 3: 20097 inputs, branch coverage 96/100, incomplete)
// FUN_000a38c0 @ 0x000a38c0
#include "decls/data/game/global.h"
#include "compat/ptr.h"

extern "C" double __cdecl sqrt(double);

static float AbsF(float v)
{
    union { float f; unsigned int u; } c;
    c.f = v;
    c.u &= 0x7fffffff;
    return c.f;
}

struct V3_a38c0 {
    float x, y, z;
    float FUN_000259c0();
    float FUN_0022d110();
    void FUN_00011160(float s, V3_a38c0 *d);
    void FUN_00011250(V3_a38c0 *out, V3_a38c0 *other);
};

V3_a38c0 *__cdecl FUN_0009f8c0(V3_a38c0 *out, float yaw, float pitch, float scale);
float __cdecl FUN_0009faa0(float cur, float target, float dt, float rate);
void __cdecl FUN_000a04c0(V3_a38c0 *dir, float *yaw, float *pitch, float *len);
float __cdecl FUN_000a0450(V3_a38c0 *v);
float __cdecl FUN_000a03c0(float v, float lo, float hi);
float __cdecl FUN_000189c0(float v);
float __cdecl FUN_000186b0(float *v, float *lo, float *hi);
char __cdecl FUN_00018960(float a, float b, float eps);
float __cdecl FUN_000a00e0(float a, float b, float c, float d, float e);
float __cdecl FUN_000a05b0(float a, float b, float c, float d, float e);

struct Input32c_a38c0 {
    char pad00[0x14];
    char FUN_000a2370(float dt, float *outA, float *outB, char *outC);
};

struct Frame_a38c0 {
    float pitch;   // E-0x50
    float outB;    // E-0x4c
    float yaw;     // E-0x48
    float len;     // E-0x44
    float angC;    // E-0x40 (also inv)
    float angB;    // E-0x3c
    float angA;    // E-0x38
    float outA;    // E-0x34
    V3_a38c0 dv;         // E-0x30
    V3_a38c0 w;          // E-0x24
    V3_a38c0 u;          // E-0x18
    V3_a38c0 o;          // E-0x0c
};

class Cam_a38c0 {
public:
    char pad000[0x194];
    V3_a38c0 p194;
    char pad1a0[0x1b8 - 0x1a0];
    V3_a38c0 p1b8;
    V3_a38c0 p1c4;
    char pad1d0[0x1e8 - 0x1d0];
    V3_a38c0 p1e8;
    char pad1f4[0x204 - 0x1f4];
    float f204;
    char pad208[0x20c - 0x208];
    float f20c;
    float f210;
    char pad214[0x23c - 0x214];
    float f23c;
    char pad240[0x248 - 0x240];
    V3_a38c0 p248;
    char pad254[0x29c - 0x254];
    V3_a38c0 p29c;
    char pad2a8[0x32c - 0x2a8];
    Input32c_a38c0 in32c;
    char pad340[0x346 - 0x340];
    char b346;
    char pad347;
    char b348;
    char pad349[0x3b4 - 0x349];
    int state;
    float f3b8;
    float f3bc;
    float f3c0;
    float f3c4;
    float f3c8;
    float f3cc;
    V3_a38c0 p3d0;
    char pad3dc[0x3e0 - 0x3dc];
    float f3e0;
    char pad3e4[0x3f4 - 0x3e4];
    V3_a38c0 p3f4;
    char pad400[0x444 - 0x400];
    float f444;
    float f448;
    char pad44c[0x478 - 0x44c];
    float f478;
    float f47c;
    float f480;
    float f484;
    float f488;
    char pad48c[0x498 - 0x48c];
    float f498;
    float f49c;
    char pad4a0[0x4b4 - 0x4a0];
    float f4b4;
    char pad4b8[0x4bb - 0x4b8];
    char f4bb;

    void FUN_000a0dc0(float a, float b, float c);
    void FUN_000a0940(float a);
    void FUN_000a0ac0(float a, float b);
    void Update(float unused, float dt);
};

void Cam_a38c0::Update(float unused, float dt)
{
    Frame_a38c0 f;
    float dt0 = dt;

    f.dv.x = p1c4.x - p29c.x;
    f.dv.y = p1c4.y - p29c.y;
    f.dv.z = p1c4.z - p29c.z;
    f.yaw = 0.0f;
    f3b8 = dt + f3b8;
    switch (state) {
    case 0:
        f.yaw = DAT_0049ec74;
        break;
    case 1:
        f.yaw = DAT_0049ec74 * 0.5f;
        f204 = DAT_0049ec90 / f.yaw * dt + f204;
        break;
    case 2:
        f.yaw = DAT_0049ec74;
        f204 = DAT_0049ec90 / DAT_0049ec74 * dt - f204 * 0.75f;
        break;
    }
    FUN_000a0dc0(f.yaw, DAT_0049ec7c, dt0);

    if (f488 > 0.0f) {
        f.yaw = f478;
        f.pitch = f47c;
        f.len = f480;
    } else {
        f.len = f444;
        f.yaw = f3bc;
        f.pitch = f3c0;
        switch (state) {
        case 0: {
            f.dv.y = 0.0f;
            dt = f.dv.FUN_0022d110();
            f.w.x = p194.x - p1c4.x;
            f.w.y = 0.0f;
            f.w.z = p194.z - p1c4.z;
            f.w.FUN_0022d110();
            p194.x = p248.x;
            p194.y = p248.y;
            p194.z = p248.z;
            double k = f.w.x * f.dv.x;      // the projection length, once, in a register (double: MSVC spills it)
            k += f.w.y * f.dv.y;
            k += f.w.z * f.dv.z;
            k *= dt;
            p194.x = f.w.x * k + p194.x;
            p194.y = f.w.y * k + p194.y;
            p194.z = f.w.z * k + p194.z;
            // the original reloads the stored (rounded) components
            f.u.x = *(volatile float *)&p194.x - p1c4.x;
            f.u.y = *(volatile float *)&p194.y - p1c4.y;
            f.u.z = *(volatile float *)&p194.z - p1c4.z;
            FUN_000a04c0(&f.u, &f.yaw, &f.pitch, &f.len);
            f.pitch = FUN_000186b0(&f.pitch, &DAT_0049ec60, &DAT_0049ec5c);
            f3c0 = f.pitch;
            if (p3d0.y - 0.1f > p1b8.y)
                state = (b348 != 0) + 1;
            break;
        }
        case 1:
            if (f4b4 > 0.0f) {
                f.pitch = FUN_000186b0(&f3c0, &DAT_0049ec60, &DAT_0049ec5c);
            } else {
                p194.x = f.dv.x + p248.x;
                p194.y = f.dv.y + p248.y;
                f.o.z = f.dv.z + p248.z;
                p194.z = f.o.z;
                f.w.x = p194.x - p1c4.x;
                f.w.y = p194.y - p1c4.y;
                f.w.z = p194.z - p1c4.z;
                f.w.FUN_0022d110();
                f.outA = -1.0f;
                dt = 1.0f;
                f.pitch = FUN_000189c0(FUN_000186b0(&f.w.y, &f.outA, &dt)) * 57.2957764f;
                f.pitch = FUN_000186b0(&f.pitch, &DAT_0049ec60, &DAT_0049ec94);
            }
            break;
        case 2:
            if (AbsF(dt) > 1e-005f) {
                hulk_freg inv = 1.0f / dt;
                f.w.y = 0.0f;
                f.dv.x = f.dv.x * inv;
                f.dv.y = f.dv.y * inv;
                f.dv.z = f.dv.z * inv;
                f.w.x = p3d0.x - p1b8.x;
                f.w.z = p3d0.z - p1b8.z;
                if (f3b8 > 0.1f) {
                    if (f.w.FUN_000259c0() > 5.0f)
                        f.yaw = FUN_000a0450(&f.w);
                }
                if (f4bb && f3b8 < DAT_0049ecd8)
                    f.yaw = FUN_0009faa0(f3bc, f.yaw, dt0, DAT_0049ecd8);
                else
                    f4bb = 0;
                if (p3d0.y < f23c)
                    f.angA = p3d0.y;
                else
                    f.angA = f23c;
                f.outA = p1b8.y;
                if (f3c8 > 0.0f && f3cc > 0.0f) {
                    float sc = (f.dv.y < 0.0f) ? f3cc : f3c8;
                    f.outA = f.dv.y / sc + sqrt(((f.dv.y * (f.dv.y / sc)) * 0.5f + f.outA - f.angA) / f3cc * 2.0);
                    if (f.outA >= 0.0f) {
                        p3f4.x = p1b8.x;
                        p3f4.y = p1b8.y;
                        p3f4.z = p1b8.z;
                        p3f4.FUN_00011160(f.outA, &f.dv);
                        p3f4.y = f.angA;
                        f.outA = f.dv.FUN_000259c0();
                        if (!FUN_00018960(f.outA, 0.0f, 1e-005f)) {
                            f.angA = f.dv.y / f.outA;
                            f.angA = AbsF(f.angA);
                            if (f.angA < 0.95f) {
                                p1c4.FUN_00011250(&f.o, &p3f4);
                                FUN_000a04c0(&f.o, &f.outA, &f.angA, &f.angB);
                                f.yaw = FUN_000a03c0(f.yaw, f.outA - 45.0f, f.outA + 45.0f);
                                f.pitch = f.angA;
                            } else if (f.dv.y / f.outA < -0.985f) {      // the signed cosine, before the fabs
                                state = 1;
                            }
                            dt = dt0;
                        }
                        dt = dt0;
                    }
                }
            }
            if (f4b4 > 0.0f)
                f.pitch = FUN_000186b0(&f3c0, &DAT_0049ec60, &DAT_0049ec5c);
            else
                f.pitch = FUN_000186b0(&f.pitch, &DAT_0049ec60, &DAT_0049ec94);
            break;
        }
    }
    f.angC = 1.0f / f.len;

    dt = (f49c - p1c4.y) * f.angC;
    if (!(dt >= -1.0f && dt <= 1.0f))
        dt = (dt > 1.0f) ? 1.0f : -1.0f;
    f.angA = FUN_000189c0(dt) * 57.2957764f;

    dt = (f498 - p1c4.y) * f.angC;
    if (!(dt >= -0.94f && dt <= 1.0f))
        dt = (dt > 1.0f) ? 1.0f : -0.94f;
    f.angB = FUN_000189c0(dt) * 57.2957764f;

    dt = (f23c + 0.3f - p1c4.y) * f.angC;
    if (!(dt >= -1.0f && dt <= 1.0f))
        dt = (dt > 1.0f) ? 1.0f : -1.0f;
    f.angC = FUN_000189c0(dt) * 57.2957764f;

    if (!in32c.FUN_000a2370(dt0, &f.outA, &f.outB, (char *)&dt) && !(f488 > 0.0f)) {
        f3bc = FUN_000a05b0(f3bc, f.yaw, (*(float*)&DAT_0049ec44), dt0, 5.0f);
        if (f.pitch < f.angC)
            f.pitch = f.angC;
        if (f.pitch > f.angB) {
            f.pitch = f.angB;
            b346 = 1;
        } else if (f.pitch < f.angA) {
            f.pitch = f.angA;
            b346 = 1;
        }
        f3c0 = FUN_000a00e0(f3c0, f.pitch, (*(float*)&DAT_0049ec48), dt0, 5.0f);
        f3c4 = FUN_000a00e0(f3c4, f.len, DAT_0049ec54, dt0, 1.5f);
    } else {
        f3bc = f.outA + f3bc;
        f.outA = f.outB + f3c0;
        f3c0 = f.outA;
        if (f3c0 >= DAT_0049ec60 && f3c0 <= DAT_0049ec5c)
            f.outB = f.outA;
        else if (f3c0 > DAT_0049ec5c)
            f.outB = DAT_0049ec5c;
        else
            f.outB = DAT_0049ec60;
        if (f.outB < f.angC)
            f.outB = f.angC;
        if (f.outB > f.angB) {
            f.outB = f.angB;
            b346 = 1;
        } else if (f.outB < f.angA) {
            f.outB = f.angA;
            b346 = 1;
        }
        if (f.outA != f.outB)
            f3c0 = FUN_000a00e0(f.outA, f.outB, 240.0f, dt0, 0.0f);
        f47c = f3c0;
        f478 = f3bc;
        f480 = f3c4;
        if (*(char *)&dt)
            f488 = (*(float*)&DAT_0049ec98);
    }

    f484 = f448;
    V3_a38c0 *r = FUN_0009f8c0(&f.o, f3bc, f3c0, f3c4);
    p194.x = r->x + p1c4.x;
    p194.y = r->y + p1c4.y;
    f.o.z = r->z + p1c4.z;
    p194.z = f.o.z;
    FUN_000a0940((*(float*)&DAT_0049ec80));

    if (state == 0) {
        hulk_freg t = f3e0 - p1e8.y;
        if (t >= -10.0f) {
            if (t > 0.0f)
                t = 0.0f;
        } else {
            t = -10.0f;
        }
        f.w.x = p1e8.x;
        f.w.y = p1e8.y;
        f.w.z = p1e8.z;
        f.u.y = t + f.w.y - p194.y;
        f.u.x = f.w.x - p194.x;
        f.u.z = f.w.z - p194.z;
        FUN_000a04c0(&f.u, &f.outA, &dt, &f.angA);
        FUN_000a0ac0(f.outA, dt);
    } else {
        f.u.x = p1e8.x - p194.x;
        f.u.y = p1e8.y - p194.y;
        f.u.z = p1e8.z - p194.z;
        FUN_000a04c0(&f.u, &f210, &f20c, &dt);
    }
}
