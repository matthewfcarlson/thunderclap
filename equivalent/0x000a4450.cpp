// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 48/50, incomplete)
// FUN_000a4450 @ 0x000a4450
extern "C" double fabs(double);

struct V3_a4450 {
    float x, y, z;
    float FUN_0022d110();
};

struct Obj350_a4450 {
    void FUN_00035550(V3_a4450 *out);
};

struct Sub32c_a4450 {
    char pad[0x24];
    bool FUN_000a2370(float dt, float *a, float *b, char *flag);
};

extern float DAT_0049ec74;
extern float DAT_0049ec7c;
extern float DAT_0049ec80;
extern float DAT_0049ec98;
extern float DAT_004056f0;
extern float DAT_0049ed2c;

V3_a4450 *__cdecl FUN_0009f8c0(V3_a4450 *out, float a, float b, float c);
V3_a4450 *__cdecl FUN_0009fef0(V3_a4450 *out, V3_a4450 *from, V3_a4450 *to, float maxAngle);
void __cdecl FUN_000a04c0(V3_a4450 *v, float *a, float *b, float *c);
float __cdecl FUN_000a0450(V3_a4450 *v);
float __cdecl FUN_000a02a0(float v);
float __cdecl FUN_000a00e0(float a, float b, float c, float d, float e);
float __cdecl FUN_00018a20(float v);
bool __cdecl FUN_00018960(float a, float b, float c);
float __cdecl FUN_000186b0(float *v, float *lo, float *hi);

struct Frame_a4450 {
    char pad0[3];
    char flag;      // 0x03
    float f48;      // 0x04
    float f44;      // 0x08
    float f40;      // 0x0c
    V3_a4450 C;           // 0x10
    V3_a4450 A;           // 0x1c
    V3_a4450 B;           // 0x28
    V3_a4450 D;           // 0x34
    V3_a4450 F;           // 0x40
};

class Ctl_a4450 {
public:
    char pad0[0x194];
    float f194, f198, f19c;
    char pad1a0[0x1b8 - 0x1a0];
    float f1b8, f1bc, f1c0;
    float f1c4, f1c8, f1cc;
    char pad1d0[0x1e8 - 0x1d0];
    float f1e8, f1ec, f1f0;
    char pad1f4[0x20c - 0x1f4];
    float f20c, f210;
    char pad214[0x248 - 0x214];
    float f248, f24c, f250;
    char pad254[0x290 - 0x254];
    float f290, f294, f298;
    char pad29c[0x32c - 0x29c];
    Sub32c_a4450 s32c;
    Obj350_a4450 *f350;
    char pad354[0x400 - 0x354];
    float f400, f404, f408;
    char pad40c[0x444 - 0x40c];
    float f444, f448;
    char pad44c[0x478 - 0x44c];
    float f478, f47c, f480, f484, f488;

    void FUN_000a0dc0(float a, float b, float c);
    void FUN_000a0940(float v);
    void FUN_000a4450(int unused, float dt);
};

void Ctl_a4450::FUN_000a4450(int unused, float dt)
{
    Frame_a4450 f;
    float dt0 = dt;

    FUN_000a0dc0(DAT_0049ec74, DAT_0049ec7c * 0.5f, dt0);
    if (f488 > 0.0f) {
        V3_a4450 *r = FUN_0009f8c0(&f.D, f478, f47c, 1.0f);
        f.A = *r;
    } else {
        f.A.x = f248 - f1c4;
        f.A.y = f24c - f1c8;
        f.D.z = f250 - f1cc;
        f.A.z = f.D.z;
        f.A.FUN_0022d110();
        FUN_000a04c0(&f.A, &f478, &f47c, &f.f40);
    }
    f.C = f.A;
    f480 = f444;
    f484 = f448;
    f350->FUN_00035550(&f.B);
    f.B.FUN_0022d110();
    f.B.x = f.B.x * -1.0f;
    f.B.y = f.B.y * -1.0f;
    f.B.z = f.B.z * -1.0f;

    if (f.B.x != f400 || f.B.y != f404 || f.B.z != f408) {
        if (f400 != 0.0f || f404 != 0.0f || f408 != 0.0f) {
            if (f.B.z * f408 + f.B.y * f404 + f.B.x * f400 < 0.5f)
                f488 = 0.0f;
        }
    }
    f400 = f.B.x;
    f404 = f.B.y;
    f408 = f.B.z;
    f.f48 = 60.0f;

    if (s32c.FUN_000a2370(dt0, &f.f40, &f.f44, &f.flag)) {
        f.f40 = f.f40 + f478;
        f478 = f.f40;
        f47c = f.f44 + f47c;
        float val;
        if (f47c >= -75.0f && f47c <= 75.0f)
            val = f47c;
        else if (f47c > 75.0f)
            val = 75.0f;
        else
            val = -75.0f;
        f.f44 = val;
        f47c = val;
        V3_a4450 *r = FUN_0009f8c0(&f.D, f.f40, val, 1.0f);
        f.C = *r;
        f.A = *r;
        if (f.flag)
            f488 = DAT_0049ec98;
    } else if (f488 > 0.0f) {
        float val;
        if (f47c >= -75.0f && f47c <= 75.0f)
            val = f47c;
        else if (f47c > 75.0f)
            val = 75.0f;
        else
            val = -75.0f;
        float p478 = f478;
        f.f44 = val;
        f47c = val;
        V3_a4450 *r = FUN_0009f8c0(&f.D, p478, val, 1.0f);
        f.C = *r;
        f.A = *r;
    } else if (f.A.z * f.B.z + f.A.y * f.B.y + f.A.x * f.B.x < 0.0f) {
        V3_a4450 *r = FUN_0009fef0(&f.D, &f.B, &f.A, 89.9f);
        f.C = *r;
        f.f48 = 200.0f;
    } else if (fabs(f47c) > 75.0f) {
        f.f40 = -75.0f;
        float res = FUN_000186b0(&f47c, &f.f40, &DAT_004056f0);
        f.f40 = res;
        f47c = res;
        V3_a4450 *r = FUN_0009f8c0(&f.D, f478, res, 1.0f);
        f.C = *r;
        f.f48 = 200.0f;
    } else {
        f.D.x = f1b8 - f290;
        f.D.y = f1bc - f294;
        f.D.z = f1c0 - f298;
        f.f44 = 1.0f;
        if (!FUN_00018960(dt, 0.0f, 1e-5f))
            f.f44 = 1.0f / dt;
        if (f.D.FUN_0022d110() * f.f44 >= DAT_0049ed2c) {
            f.f44 = f.D.z * f.B.z + f.D.y * f.B.y + f.D.x * f.B.x;
            if (fabs(f.f44) <= 0.1f) {
                V3_a4450 *r = FUN_0009fef0(&f.F, &f.B, &f.D, -60.0f);
                f.C = *r;
            }
        }
    }

    f.f40 = f.C.z * f.A.z + f.C.y * f.A.y + f.C.x * f.A.x;
    f.f44 = f.f40 - 1.0f;
    if (fabs(f.f44) <= 1e-5f) {
        f.C = f.A;
    } else {
        f.f44 = f.f48 * dt;
        dt = FUN_00018a20(f.f40) * 57.2957763671875f;
        f.f40 = FUN_000a0450(&f.A);
        f.f40 = FUN_000a02a0(f.f40 - FUN_000a0450(&f.C));
        f.f40 = fabs(f.f40);
        double ret = FUN_000a00e0(0.0f, dt, f.f48, dt0, f.f48 * 0.2f);
        dt = dt * ret;
        double mx = ret * f.f40;
        double X = dt;
        if (dt < mx)
            X = mx;
        if (X > f.f44)
            dt = (dt / X) * f.f44;
        V3_a4450 *r = FUN_0009fef0(&f.F, &f.A, &f.C, dt);
        f.C = *r;
    }

    f.D.x = f.C.x * f444;
    f.D.y = f.C.y * f444;
    f.D.z = f444 * f.C.z + f1cc;
    f194 = f.D.x + f1c4;
    f198 = f.D.y + f1c8;
    f19c = f.D.z;
    FUN_000a0940(DAT_0049ec80);
    f.D.x = f1e8 - f194;
    f.D.y = f1ec - f198;
    f.D.z = f1f0 - f19c;
    FUN_000a04c0(&f.D, &f210, &f20c, &dt);
}
