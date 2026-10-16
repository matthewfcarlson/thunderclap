// STATUS: equivalent (tools/equiv.py level 3: 2912 inputs, branch coverage 75/76, incomplete)
// CHand2HandAgent::vfunc_22 @ 0x00101270
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" double sqrt(double);

struct V3_101270 {
    float x, y, z;
    float FUN_0022d110();
};

struct Name_101270 {
    void FUN_0027b040(const char *s);
};

struct Obj58_101270 {
    char pad0[0x129];
    char b129;
};

struct World;
struct Arg1_101270 {
    char pad0[0x1cbc];
    int f1cbc;
};

class P5c_101270 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3(World *hub, Arg1_101270 *a1, V3_101270 *out, float a3, int z);
    char pad04[0xc];
    V3_101270 v10;
};

struct Hub20_101270 {
    void FUN_00029250(int a, V3_101270 *v, int b, int c);
};
struct World {
    char pad0[0x20];
    Hub20_101270 *p20;
};

struct Rng_101270 {
    float FUN_00078780();
};
Rng_101270 *__cdecl FUN_000964d0();

float __cdecl FUN_0010ae50(World *h, Arg1_101270 *a, float f, V3_101270 *v1, V3_101270 *v2, int z1, int z2);

struct Out_101270 {
    char pad0[0x10c];
    V3_101270 v10c;
    float f118;
    V3_101270 v11c;
    V3_101270 v128;
    char pad134[0x140 - 0x134];
    Name_101270 name;
    char pad141[7];
    char b148;
};

struct Frame_101270 {
    char pad0[3];
    char b3;            // 0x03
    float s4;           // 0x04
    float s8;           // 0x08
    volatile float Tx, Ty, Tz;   // 0x0c
    volatile float W0;          // 0x18
    volatile float Wy;          // 0x1c
    volatile float Wz;          // 0x20
};

class CHand2HandAgent {
public:
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
    virtual char v11(Arg1_101270 *a, float b, float c);
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual char v18(float f);
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22(Arg1_101270 *a0, Out_101270 *a1, float a2);
    virtual void v23();
    char pad04[0x58 - 4];
    Obj58_101270 *p58;
    P5c_101270 *p5c;
    char pad60[4];
    float f64;
    char pad68[0x70 - 0x68];
    float f70;
    char pad74[4];
    char b78;
    char pad79;
    char b7a;
    char b7b;
    char pad7c[2];
    char b7e;
    char pad7f;
    float f80;
    char pad84[4];
    V3_101270 v88;
    V3_101270 v94;
    int fa0;
    char pada4[0xb0 - 0xa4];
    V3_101270 vb0;
    V3_101270 vbc;
    float fc8;
    char padcc[0xd1 - 0xcc];
    char bd1;
    char bd2;
    char bd3;
    char padd4[0xdc - 0xd4];
    float fdc, fe0;
    char pade4[0x138 - 0xe4];
    V3_101270 v138;
    V3_101270 v144;
    V3_101270 v150;
    V3_101270 v15c;
    V3_101270 v168;
    V3_101270 v174;
    float f180;
    V3_101270 v184;
};

void CHand2HandAgent::v22(Arg1_101270 *a0, Out_101270 *a1, float a2)
{
    Frame_101270 f;
    bool b13;
    bool flag2;
    char hit;

    if (fc8 < fdc)
        b13 = true;
    else
        b13 = (b7e != 0);
    double sd = (fe0 - fdc) * 0.25f;
    f.s8 = (float)sd;
    if (sd + fdc < fc8)
        b7e = 0;
    else if (fc8 < fdc)
        b7e = 1;
    f.s4 = 1.0f;
    if (fc8 > fdc && fc8 < fe0 && !(*(char*)&DAT_004a1bfc))
        f.s4 = (fdc - fc8) / f.s8;

    Rng_101270 *rng = FUN_000964d0();
    v15c.z = 0.0f;
    v15c.y = 0.0f;
    v15c.x = 0.0f;
    v168.z = 0.0f;
    v168.y = 0.0f;
    v168.x = 0.0f;
    a1->v11c.x = vbc.x;
    a1->v11c.y = vbc.y;
    a1->v11c.z = vbc.z;
    a1->v128.x = vbc.x;
    a1->v128.y = vbc.y;
    a1->v128.z = vbc.z;
    flag2 = false;
    f.s8 = vbc.z * v94.z + vbc.y * v94.y + vbc.x * v94.x;

    if (b13) {
        if (!bd2) {
            flag2 = true;
            v168.x = vbc.x * -1.0f;
            v168.y = vbc.y * -1.0f;
            v168.z = vbc.z * -1.0f;
            f64 = f64 - a2;
        }
        if (f.s8 > 0.7f && rng->FUN_00078780() < 0.33f && !bd1 && b7b) {
            a1->name.FUN_0027b040("evade_s");
            a1->b148 = 1;
            b7b = 0;
            return;
        }
    } else {
        v168.x = vbc.x;
        v168.y = vbc.y;
        v168.z = vbc.z;
    }
    if (f80 > 0.0f) {
        v168.z = 0.0f;
        v168.y = 0.0f;
        v168.x = 0.0f;
    }

    if (!(*(char*)&DAT_004e0a99)) {
        if (bd1)
            goto L2f9;
        if (!bd3) {
            if (v18(1.5f)) {
                if (v11(a0, fc8, f.s8))
                    DAT_004dd700->p20->FUN_00029250(fa0, &v88, a0->f1cbc, 1);
            }
        }
    }
    if (!bd1 && !bd3 && f64 > 0.0f && b7a)
        v16();
L2f9:
    v138.z = 0.0f;
    v138.y = 0.0f;
    v138.x = 0.0f;
    f.s8 = 1.5f;
    if (!p58->b129)
        f.s8 = 0.9900000095367432f;
    {
        float r = FUN_0010ae50(DAT_004dd700, a0, 1.5f, &v150, &v138, 0, 0);
        if (r < 0.0f || r > f.s8) {
            p58->b129 = 0;
            v138.z = 0.0f;
            v138.y = 0.0f;
            v138.x = 0.0f;
        } else {
            p58->b129 = 1;
        }
    }
    p5c->v10.x = v168.x;
    p5c->v10.y = v168.y;
    p5c->v10.z = v168.z;
    hit = p5c->v3(DAT_004dd700, a0, &v15c, a2, 0);

    f.W0 = DAT_004a1c08 * v138.x;
    f.Wy = DAT_004a1c08 * v138.y;
    f.Wz = DAT_004a1c08 * v138.z;
    double m = 1.0f - DAT_004a1c08;
    f.Tx = m * v174.x;
    f.Ty = m * v174.y;
    f.Tz = m * v174.z;
    v174.z = f.Tz + f.Wz;
    v174.x = DAT_004a1c08 * v138.x + f.Tx;
    v174.y = f.Ty + f.Wy;

    volatile float *B = &v168.x;
    B[0] = v174.x + B[0];
    B[1] = v174.y + B[1];
    B[2] = v174.z + B[2];
    B[0] = B[0] + v144.x;
    B[1] = v144.y + B[1];
    B[2] = v144.z + B[2];
    {
        double ax = v15c.x + v15c.x;
        double ay = v15c.y + v15c.y;
        volatile float az = v15c.z + v15c.z;
        B[0] = ax + B[0];
        B[1] = ay + B[1];
        B[2] = az + B[2];
    }
    B[0] = v150.x + B[0];
    B[1] = v150.y + B[1];
    B[2] = v150.z + B[2];

    if (!hit && flag2) {
        v168.z = 0.0f;
        v168.y = 0.0f;
        v168.x = 0.0f;
        f64 = f64 - a2;
    } else {
        flag2 = false;
    }

    double len = sqrt(v168.x * v168.x + v168.y * v168.y + v168.z * v168.z);
    if (1.0f < len)
        a2 = 1.0f;
    else
        a2 = (float)len;

    if (sqrt(v168.x * v168.x + v168.y * v168.y + v168.z * v168.z) < DAT_004a1c04) {
        v168.z = 0.0f;
        v168.y = 0.0f;
        v168.x = 0.0f;
        a1->v10c.z = 0.0f;
        a1->v10c.y = 0.0f;
        a1->v10c.x = 0.0f;
        a1->f118 = 0.0f;
    } else {
        v168.FUN_0022d110();
        a1->f118 = a2;
        a1->v10c.x = v168.x;
        a1->v10c.y = v168.y;
        a1->v10c.z = v168.z;
    }

    float z0 = DAT_004a1c0c * 0.0f;
    f.W0 = z0;
    f.Wy = z0;
    double m2 = 1.0f - DAT_004a1c0c;
    f.Tx = m2 * v184.x;
    f.Ty = m2 * v184.y;
    f.Tz = m2 * v184.z;
    v184.z = f.Tz + z0;
    v184.x = f.Tx + f.W0;
    v184.y = f.Ty + f.Wy;

    if (b78 && bd3 && fc8 < fdc) {
        if (flag2 && !hit) {
            if (vb0.z * v94.z + vb0.y * v94.y + vb0.x * v94.x < -0.98f && f70 > 0.75f) {
                a1->name.FUN_0027b040("awestruck");
                a1->b148 = 1;
            }
            a1->f118 = 0.0f;
            a1->v11c.x = vbc.x;
            a1->v11c.y = vbc.y;
            a1->v11c.z = vbc.z;
            b78 = 0;
        } else {
            a1->f118 = 1.0f;
            a1->v11c.x = -vbc.x;
            a1->v11c.y = -vbc.y;
            a1->v11c.z = -vbc.z;
        }
    } else {
        a1->v11c.x = vbc.x;
        a1->v11c.y = vbc.y;
        a1->v11c.z = vbc.z;
    }
    a1->v10c.x = v168.x;
    a1->v10c.y = v168.y;
    a1->v10c.z = v168.z;
    a1->f118 = (f.s4 < a1->f118) ? f.s4 : a1->f118;
}
