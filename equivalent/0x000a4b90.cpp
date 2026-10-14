// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 45/46, incomplete)
// FUN_000a4b90 @ 0x000a4b90
extern float DAT_0049ec74;
extern float DAT_0049ec7c;
extern float DAT_0049ec80;
extern float DAT_0049ec98;
extern float DAT_0049ed30;

struct V3 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_000111b0(const V3 *a, const V3 *b);
};

V3 *__cdecl FUN_0009f8c0(V3 *out, float yaw, float pitch, float scale);
V3 *__cdecl FUN_0009fef0(V3 *out, V3 *from, V3 *to, float maxAngle);
void __cdecl FUN_000a04c0(V3 *dir, float *yaw, float *pitch, float *len);
float __cdecl FUN_00018a20(float v);
float __cdecl FUN_000a0450(V3 *v);
float __cdecl FUN_000a02a0(float a);
float __cdecl FUN_000a00e0(float a, float b, float c, float d, float e);

struct Obj350 {
    void FUN_00035550(V3 *out);
};

struct Input32c {
    char pad00[8];
    float f8;
    float fc;
    float f10;
    char b14;
    char FUN_000a2370(float dt, float *outA, float *outB, char *outC);
};

struct Frame {
    char pad0[3];
    char b13;           // 0x03
    float f14;          // 0x04 (clamp temp / angle)
    float f18;          // 0x08
    float f1c;          // 0x0c
    float f20;          // 0x10
    V3 vB;              // 0x14
    V3 dirV;            // 0x20
    V3 w;               // 0x2c
    V3 d2;              // 0x38
    V3 c;               // 0x44
    V3 tmp;             // 0x50 (out / up vector)
};

class Cam {
public:
    char pad000[0x194];
    V3 p194;
    char pad1a0[0x1b8 - 0x1a0];
    V3 p1b8;
    V3 p1c4;
    char pad1d0[0x1e8 - 0x1d0];
    V3 p1e8;
    char pad1f4[0x20c - 0x1f4];
    float f20c;
    float f210;
    char pad214[0x22c - 0x214];
    float f22c;
    char pad230[0x23c - 0x230];
    float f23c;
    char pad240[0x248 - 0x240];
    V3 p248;
    char pad254[0x290 - 0x254];
    V3 p290;
    char pad29c[0x308 - 0x29c];
    float f308;
    char pad30c[0x314 - 0x30c];
    float f314;
    char pad318[0x320 - 0x318];
    int f320;
    int f324;
    int f328;
    Input32c in32c;
    char pad344[0x350 - 0x344];
    Obj350 *f350;
    char pad354[0x394 - 0x354];
    int f394;
    char pad398[0x3b4 - 0x398];
    int f3b4;
    int f3b8;
    float f3bc;
    float f3c0;
    float f3c4;
    char pad3c8[0x3d0 - 0x3c8];
    V3 p3d0;
    char pad3dc[0x3e8 - 0x3dc];
    V3 p3e8;
    char pad3f4[0x40c - 0x3f4];
    float f40c;
    char pad410[0x444 - 0x410];
    float f444;
    float f448;
    char pad44c[0x478 - 0x44c];
    float f478;
    float f47c;
    float f480;
    float f484;
    float f488;

    void FUN_000a0dc0(float a, float b, float c);
    void FUN_000a0940(float a);
    void Update(float unused, float dt);
};

void Cam::Update(float unused, float dt)
{
    FUN_000a0dc0(DAT_0049ec74, DAT_0049ec7c * 0.5f, dt);

    Frame f;

    if (f488 > 0.0f) {
        V3 *r = FUN_0009f8c0(&f.tmp, f478, f47c, 1.0f);
        f.dirV = *r;
    } else {
        f.dirV.x = p248.x - p1c4.x;
        f.dirV.y = p248.y - p1c4.y;
        f.tmp.z = p248.z - p1c4.z;      // the original passes dz through this stack slot
        f.dirV.z = f.tmp.z;
        f.dirV.FUN_0022d110();
        FUN_000a04c0(&f.dirV, &f478, &f47c, &f.f20);
    }
    f.vB = f.dirV;
    f22c = f308;
    f480 = f444;
    f484 = f448;
    f350->FUN_00035550(&f.w);
    f.w.FUN_0022d110();
    f.f18 = 120.0f;
    f.w.x = f.w.x * -1.0f;
    f.w.y = f.w.y * -1.0f;
    f.w.z = f.w.z * -1.0f;

    float dot = f.w.z * f.dirV.z + f.w.y * f.dirV.y + f.w.x * f.dirV.x;
    if (dot >= -1.0f && dot <= 1.0f)
        f.f14 = dot;
    else
        f.f14 = (dot > 1.0f) ? 1.0f : -1.0f;
    f.f14 = FUN_00018a20(f.f14) * 57.2957764f;
    if (f.f14 > 76.0f) {
        V3 *r = FUN_0009fef0(&f.tmp, &f.w, &f.dirV, 75.0f);
        f.vB = *r;
        f.f18 = 600.0f;
        f488 = 0.0f;
    } else {
        char got = in32c.FUN_000a2370(dt, &f.f20, &f.f1c, &f.b13);
        if (got) {
            f.f14 = f.f20 + f478;       // the new yaw/pitch round-trip through stack temps
            f478 = f.f14;
            f.f20 = f.f1c + f47c;
            f47c = f.f20;
            V3 *r = FUN_0009f8c0(&f.tmp, f478, f47c, 1.0f);
            f.vB = *r;
            float d2 = f.vB.z * f.w.z + f.vB.y * f.w.y + f.vB.x * f.w.x;
            if (d2 >= -1.0f && d2 <= 1.0f)
                f.f14 = d2;
            else
                f.f14 = (d2 > 1.0f) ? 1.0f : -1.0f;
            if (FUN_00018a20(f.f14) * 57.2957764f > 75.0f) {
                V3 *r2 = FUN_0009fef0(&f.tmp, &f.w, &f.vB, 75.0f);
                f.vB = *r2;
                FUN_000a04c0(&f.vB, &f478, &f47c, &f.f20);
            }
            f.dirV = f.vB;
            if (f.b13)
                f488 = DAT_0049ec98;
        } else if (f488 > 0.0f) {
            V3 *r = FUN_0009f8c0(&f.tmp, f478, f47c, 1.0f);
            f.vB = *r;
            f.dirV = f.vB;
        } else {
            if (f.f14 > 60.0f) {
                V3 *r = FUN_0009fef0(&f.tmp, &f.w, &f.dirV, 60.0f);
                f.vB = *r;
            }
            f.d2.x = p1b8.x - p290.x;
            f.d2.y = p1b8.y - p290.y;
            f.d2.z = p1b8.z - p290.z;
            unsigned int bits = *(unsigned int *)&dt & 0x7fffffff;
            f.f1c = 1.0f;
            if (!(*(float *)&bits <= 1e-05f))
                f.f1c = 1.0f / dt;
            float speed = f.d2.FUN_0022d110() * f.f1c;
            if (!(speed < DAT_0049ed30)) {
                float dw = f.d2.z * f.w.z + f.d2.y * f.w.y + f.d2.x * f.w.x;
                unsigned int b2 = *(unsigned int *)&dw & 0x7fffffff;
                if (*(float *)&b2 <= 0.1f) {
                    f.tmp.x = 0;
                    f.tmp.y = 1.0f;
                    f.tmp.z = 0;
                    f.c.FUN_000111b0(&f.w, &f.tmp);
                    f.c.FUN_0022d110();
                    f22c = (f.c.z * f.d2.z + f.c.y * f.d2.y + f.c.x * f.d2.x) * -45.0f;
                }
            }
        }
    }

    float dot3 = f.vB.z * f.dirV.z + f.vB.y * f.dirV.y + f.vB.x * f.dirV.x;
    f.f1c = dot3;
    {
        float t = dot3 - 1.0f;
        unsigned int b3 = *(unsigned int *)&t & 0x7fffffff;
        if (*(float *)&b3 <= 1e-05f) {
            f.vB = f.dirV;
        } else {
            f.f20 = f.f18 * dt;
            f.f14 = FUN_00018a20(dot3) * 57.2957764f;
            f.f1c = FUN_000a0450(&f.dirV);
            float yawB = FUN_000a0450(&f.vB);
            float dyaw = FUN_000a02a0(f.f1c - yawB);
            f.f1c = dyaw;
            unsigned int ab = *(unsigned int *)&dyaw & 0x7fffffff;
            f.f1c = *(float *)&ab;
            float step = FUN_000a00e0(0.0f, f.f14, f.f18, dt, f.f18 * 0.2f);
            double S = step * f.f1c;
            f.f14 = (float)(f.f14 * step);
            double Rv = (f.f14 < S) ? S : (double)f.f14;
            if (Rv > f.f20)
                f.f14 = (float)(f.f14 / Rv * f.f20);
            V3 *r = FUN_0009fef0(&f.tmp, &f.dirV, &f.vB, f.f14);
            f.vB = *r;
        }
    }

    volatile float tx = f.vB.x * f444;
    volatile float ty = f.vB.y * f444;
    p194.x = tx + p1c4.x;
    p194.y = ty + p1c4.y;
    p194.z = f444 * f.vB.z + p1c4.z;

    if (f40c > 0.0f) {
        f40c = f40c - dt;
        if (f40c <= 0.0f || (f23c - f314) > 10.0f) {
            if (f320 == 7)
                f324 = f328;
            else
                f324 = f320;
            f320 = 1;
            f394 = 0;
            f3b4 = 2;
            f3b8 = 0;
            p3d0 = p1b8;
            p3e8 = p194;
            V3 t;
            t.x = p194.x - p1c4.x;
            t.y = p194.y - p1c4.y;
            t.z = p194.z - p1c4.z;
            FUN_000a04c0(&t, &f3bc, &f3c0, &f3c4);
            f40c = 0.0f;
            f488 = 0.0f;
        }
    }

    FUN_000a0940(DAT_0049ec80);
    V3 t2;
    t2.x = p1e8.x - p194.x;
    t2.y = p1e8.y - p194.y;
    t2.z = p1e8.z - p194.z;
    FUN_000a04c0(&t2, &f210, &f20c, &dt);
}
