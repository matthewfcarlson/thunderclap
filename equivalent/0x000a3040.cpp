// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 73/74, incomplete)
// FUN_000a3040 @ 0x000a3040
#include "decls/data/game/global.h"

extern "C" double __cdecl sqrt(double);
struct V3_a3040 { float x, y, z; };

static float AbsF(float v)
{
    union { float f; unsigned int u; } c;
    c.f = v;
    c.u &= 0x7fffffff;
    return c.f;
}

V3_a3040 *__cdecl FUN_0009f8c0(V3_a3040 *out, float yaw, float pitch, float scale);
void __cdecl FUN_000a04c0(V3_a3040 *dir, float *yaw, float *pitch, float *len);
float __cdecl FUN_000189c0(float v);
float __cdecl FUN_000186b0(float *v, float *lo, float *hi);
float __cdecl FUN_000186f0(float *a, float *b);
float __cdecl FUN_000a00e0(float a, float b, float c, float d, float e);

struct Obj350_a3040 {
    char pad00[0x8c];
    float f8c;
};

struct Input32c_a3040 {
    char pad00[8];
    float f8;
    float fc;
    float f10;
    char b14;
    char FUN_000a2370(float dt, float *outA, float *outB, char *outC);
};

struct Frame_a3040 {
    char pad0[3];
    char flag;          // 0x03
    float pitch;        // 0x04
    float outB;         // 0x08
    float v14;          // 0x0c
    float angC;         // 0x10
    float yaw;          // 0x14
    float angB;         // 0x18
    float angA;         // 0x1c
    float len;          // 0x20 (also v28)
    float inv;          // 0x24 (also v2c)
    float outA;         // 0x28
    float v34;          // 0x2c
    V3_a3040 out;             // 0x30
    V3_a3040 dir;             // 0x3c
};

class Cam_a3040 {
public:
    char pad000[0x194];
    V3_a3040 p194;
    char pad1a0[0x1c4 - 0x1a0];
    V3_a3040 p1c4;
    V3_a3040 p1d0;
    char pad1dc[0x1e8 - 0x1dc];
    V3_a3040 p1e8;
    char pad1f4[0x20c - 0x1f4];
    float f20c;
    float f210;
    char pad214[0x21c - 0x214];
    float f21c;
    char pad220[0x22c - 0x220];
    float f22c;
    char pad230[0x23c - 0x230];
    float f23c;
    char pad240[0x248 - 0x240];
    V3_a3040 p248;
    char pad254[0x2f4 - 0x254];
    float f2f4;
    char pad2f8[0x32c - 0x2f8];
    Input32c_a3040 in32c;
    char pad344[0x346 - 0x344];
    char b346;
    char pad347[0x350 - 0x347];
    Obj350_a3040 *f350;
    char pad354[0x410 - 0x354];
    unsigned int f410;
    char pad414[0x444 - 0x414];
    float f444;
    float f448;
    float f44c;
    char pad450[0x478 - 0x450];
    float f478;
    float f47c;
    float f480;
    float f484;
    float f488;
    char pad48c[0x498 - 0x48c];
    float f498;
    float f49c;

    void FUN_000a0dc0(float a, float b, float c);
    void FUN_000a0940(float a);
    void Update(float unused, float dt);
};

void Cam_a3040::Update(float unused, float dt)
{
    FUN_000a0dc0((*(float*)&DAT_0049ec78), DAT_0049ec7c, dt);

    Frame_a3040 f;
    f.v34 = f444;
    if (f488 > 0.0f) {
        f.yaw = f478;
        f.pitch = f47c;
        f.len = f480;
        f.v14 = f484;
    } else {
        f.dir.x = p248.x - p1c4.x;
        f.dir.y = p248.y - p1c4.y;
        f.dir.z = p248.z - p1c4.z;
        FUN_000a04c0(&f.dir, &f.yaw, &f.pitch, &f.len);
        f.v14 = f2f4;
    }
    f.inv = 1.0f / f.len;

    // the three clamp temporaries all live in the outB stack slot
    f.outB = (f49c - p1c4.y) * f.inv;
    if (!(f.outB >= -1.0f && f.outB <= 1.0f))
        f.outB = (f.outB > 1.0f) ? 1.0f : -1.0f;
    f.angA = FUN_000189c0(f.outB) * 57.2957764f;

    f.outB = (f498 - p1c4.y) * f.inv;
    if (!(f.outB >= -0.94f && f.outB <= 1.0f))
        f.outB = (f.outB > 1.0f) ? 1.0f : -0.94f;
    f.angB = FUN_000189c0(f.outB) * 57.2957764f;

    f.outB = (f23c + 0.3f - p1c4.y) * f.inv;
    if (!(f.outB >= -1.0f && f.outB <= 1.0f))
        f.outB = (f.outB > 1.0f) ? 1.0f : -1.0f;
    f.angC = FUN_000189c0(f.outB) * 57.2957764f;

    bool gotoFinal = false;

    if (!(DAT_0049ec60 - 2.0f > f.pitch) && !(DAT_0049ec5c + 2.0f < f.pitch)) {
        char got = in32c.FUN_000a2370(dt, &f.outA, &f.outB, &f.flag);
        if (got) {
            f.yaw = f.outA + f.yaw;
            f.inv = f448;
            f.outB = f.pitch - f.v14 + f.outB + f.inv;
            f.outB = FUN_000186b0(&f.outB, &DAT_0049ec60, &DAT_0049ec5c);
            if (f.outB < f.angC) {
                float t = f.angC - f.outB;
                f.outB = f.angC;
                f.inv = t + f.inv;
            }
            if (f.outB > f.angB) {
                f.outB = f.angB;
                f.inv = f448;
                b346 = 1;
            } else if (f.outB < f.angA) {
                f.outB = f.angA;
                b346 = 1;
            }
            f.pitch = FUN_000a00e0(f.pitch, f.outB, (*(float*)&DAT_0049ec48), dt, 5.0f);
            f.v14 = FUN_000a00e0(f.v14, f.inv, (*(float*)&DAT_0049ec48), dt, 5.0f);
            f480 = f.v34;
            f478 = f.yaw;
            f47c = f.outB;
            f484 = f.inv;
            if (f.flag)
                f488 = (*(float*)&DAT_0049ec98);
            f.len = f.v34;
            gotoFinal = true;
        } else {
            float vz = p1d0.z;
            float vx = p1d0.x;
            double speed = sqrt((double)(vz * vz + vx * vx));
            if ((speed < DAT_0049ed28 || speed != speed) && !(f.pitch < f.angC) && !(f.pitch < f.angA) && !(f.pitch > f.angB)) {
                f.pitch = FUN_000186b0(&f.pitch, &DAT_0049ec60, &DAT_0049ec5c);
            } else {
                f.outA = DAT_0049ed24 * speed;
                f.outA = FUN_000a00e0(f.pitch, f44c, f.outA, dt, 2.0f);
                f.outB = f.pitch;
                if (f.pitch < f.angC)
                    f.outB = f.angC;
                if (f.outB > f.angB) {
                    f.outB = f.angB;
                    b346 = 1;
                } else if (f.outB < f.angA) {
                    f.outB = f.angA;
                    b346 = 1;
                }
                if (f.pitch != f.outB) {
                    float r = FUN_000a00e0(f.pitch, f.outB, (*(float*)&DAT_0049ec48), dt, 2.0f);
                    float d1 = f.outA - f.pitch;
                    float d2 = r - f.pitch;
                    float ad1 = AbsF(d1);
                    float ad2 = AbsF(d2);
                    if (ad2 > ad1)
                        f.pitch = r;
                    else if (d2 * d1 < 0.0f)
                        f.pitch = r;
                    else
                        f.pitch = f.outA;
                } else {
                    f.pitch = f.outA;
                }
            }
            f.len = f.v34;
            if (f488 > 0.0f)
                f.yaw = f478;
            f.v14 = FUN_000a00e0(f.v14, f448, (*(float*)&DAT_0049ec48), dt, 5.0f);
            if ((f410 >> 6) & 1) {
                f.outA = f350->f8c * 57.2957764f;
                float angv = f.outA;
                float absang = AbsF(angv);
                if (absang > 30.0f) {
                    f.v34 = 180.0f;
                    f22c = FUN_000186f0(&f.outA, &f.v34) * -0.025f;
                }
            }
            f478 = f.yaw;
            f47c = f.pitch;
            f480 = f.len;
            f484 = f.v14;
        }
    } else {
        if (f.pitch >= DAT_0049ec60 && f.pitch <= DAT_0049ec5c)
            f.outB = f.pitch;
        else if (f.pitch > DAT_0049ec5c)
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
        f.pitch = FUN_000a00e0(f.pitch, f.outB, (*(float*)&DAT_0049ec48), dt, 0.0f);
        f47c = f.pitch;
        f488 = 0.0f;
        f478 = f.yaw;
        f480 = f.len;
        f484 = f.v14;
    }

    FUN_0009f8c0(&f.out, f.yaw, f.pitch, f.len);
    double dx = p248.x - p1c4.x;
    float dy = p248.y - p1c4.y;
    double dz = p248.z - p1c4.z;
    double ex = f.out.x - dx;
    double ey = f.out.y - dy;
    double ez = f.out.z - dz;
    float exf = (float)ex;
    float eyf = (float)ey;
    float ezf = (float)ez;
    double L = sqrt(ez * ez + ey * ey + ex * ex);
    float M = DAT_0049ec54 * dt;
    if (L > M) {
        double ratio = M / L;
        f.out.x = (float)(exf * ratio + dx);
        f.out.y = (float)(eyf * ratio + dy);
        f.out.z = (float)(ezf * ratio + dz);
    }
    p194.x = f.out.x + p1c4.x;
    p194.y = f.out.y + p1c4.y;
    p194.z = f.out.z + p1c4.z;
    FUN_000a0940((*(float*)&DAT_0049ec80));
    V3_a3040 t2;
    t2.x = p1e8.x - p194.x;
    t2.y = p1e8.y - p194.y;
    t2.z = p1e8.z - p194.z;
    FUN_000a04c0(&t2, &f210, &f20c, &dt);
    f21c = f.v14;
}
