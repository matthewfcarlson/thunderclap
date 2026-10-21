// STATUS: equivalent (tools/equiv.py level 3: 19818 inputs, branch coverage 68/72, incomplete)
// CHand2HandAgent::vfunc_21 @ 0x00100b30
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" double sqrt(double);

struct V3_100b30 {
    float x, y, z;
    float FUN_0022d110();
    void Add(const V3_100b30 &o) { x = x + o.x; y = o.y + y; z = o.z + z; }
};

struct Name_100b30 {
    void FUN_0027b040(const char *s);
};

struct Obj58_100b30 {
    char pad0[0x129];
    char b129;
};

struct World;
struct Arg1_100b30 {
    char pad0[0x1cbc];
    int f1cbc;
};

class P5c_100b30 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3(World *hub, Arg1_100b30 *a1, V3_100b30 *out, float a3, int z);
    char pad04[0xc];
    V3_100b30 v10;
};

struct Hub20_100b30 {
    void FUN_00029250(int a, V3_100b30 *v, int b, int c);
};
struct World {
    char pad0[0x20];
    Hub20_100b30 *p20;
};

float __cdecl FUN_0010ae50(World *h, Arg1_100b30 *a, float f, V3_100b30 *v1, V3_100b30 *v2, int z1, int z2);

struct Out_100b30 {
    char pad0[0x10c];
    V3_100b30 v10c;
    float f118;
    V3_100b30 v11c;
    V3_100b30 v128;
    char pad134[0x140 - 0x134];
    Name_100b30 name;
    char pad141[7];
    char b148;
};

struct Frame_100b30 {
    char pad0[2];
    char b2;
    char b3;
    float s4;
    float s8;
    float sc;
    volatile float Tx, Ty, Tz;
    V3_100b30 U;
    volatile float Wx, Wy, Wz;
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
    virtual char v11(Arg1_100b30 *a, float b, float c);
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual char v18(float f);
    virtual void v19();
    virtual void v20();
    virtual void v21(Arg1_100b30 *a0, Out_100b30 *a1, float a2);
    virtual void v22();
    virtual void v23();
    char pad04[0x58 - 4];
    Obj58_100b30 *p58;
    P5c_100b30 *p5c;
    char pad60[4];
    float f64;
    char pad68[0x70 - 0x68];
    float f70;
    char pad74[4];
    char b78;
    char pad79[4];
    char b7d;
    char pad7e;
    char b7f;
    float f80;
    char pad84[4];
    V3_100b30 v88;
    V3_100b30 v94;
    int fa0;
    char pada4[0xb0 - 0xa4];
    V3_100b30 vb0;
    V3_100b30 vbc;
    float fc8;
    char padcc[0xd1 - 0xcc];
    char bd1;
    char bd2;
    char bd3;
    float fd4, fd8, fdc, fe0;
    char pade4[0x124 - 0xe4];
    int f124;
    char pad128[0x130 - 0x128];
    float f130;
    char pad134[0x138 - 0x134];
    V3_100b30 v138;
    V3_100b30 v144;
    char pad150[0x15c - 0x150];
    V3_100b30 v15c;
    V3_100b30 v168;
    V3_100b30 v174;
    float f180;
    V3_100b30 v184;
};

void CHand2HandAgent::v21(Arg1_100b30 *a0, Out_100b30 *a1, float a2)
{
    Frame_100b30 f;

    f.s8 = (fe0 - fdc) * 0.25f;
    if (fd8 - f.s8 > fc8)
        b7f = 0;
    else if (fc8 > fd8)
        b7f = 1;
    f.s4 = 1.0f;
    if (fc8 > fd4 && fc8 < fd8 && !(*(char*)&DAT_004a1bfc))
        f.s4 = (fd8 - fc8) / f.s8;

    v15c.z = 0.0f;
    v15c.y = 0.0f;
    v15c.x = 0.0f;
    v168.z = 0.0f;
    v168.y = 0.0f;
    v168.x = 0.0f;
    f.b2 = 0;
    f.sc = vbc.z * v94.z + vbc.y * v94.y + vbc.x * v94.x;

    if (fc8 < fd4) {
        if (!bd2) {
            f.b2 = 1;
            v168.x = vbc.x * -1.0f;
            v168.y = vbc.y * -1.0f;
            v168.z = vbc.z * -1.0f;
        }
    } else {
        if (!bd1 && !bd3 && b7d && f130 > 2.0f && fc8 > 7.0f && fc8 < 10.0f && f124 > 0) {
            a1->name.FUN_0027b040("gesture_1");
            a1->b148 = 1;
            b7d = 0;
            return;
        }
        v168 = vbc;
    }
    if (f80 > 0.0f) {
        v168.z = 0.0f;
        v168.y = 0.0f;
        v168.x = 0.0f;
    }
    v138.z = 0.0f;
    v138.y = 0.0f;
    v138.x = 0.0f;
    f.U.x = vbc.x;
    f.U.y = vbc.y;
    f.U.z = vbc.z;
    f.s8 = 1.5f;
    if (!p58->b129)
        f.s8 = 0.9900000095367432f;
    float r = FUN_0010ae50(DAT_004dd700, a0, 1.5f, &f.U, &v138, 0, 0);
    if (r < 0.0f || r > f.s8) {
        p58->b129 = 0;
        v138.z = 0.0f;
        v138.y = 0.0f;
        v138.x = 0.0f;
    } else {
        p58->b129 = 1;
    }
    p5c->v10.x = v168.x;
    p5c->v10.y = v168.y;
    p5c->v10.z = v168.z;
    char hit = p5c->v3(DAT_004dd700, a0, &v15c, a2, 0);
    f.b3 = hit;
    v15c.x = v15c.x + v15c.x;
    v15c.y = v15c.y + v15c.y;
    v15c.z = v15c.z + v15c.z;

    f.Wy = DAT_004a1c08 * v138.y;
    f.Wz = DAT_004a1c08 * v138.z;
    double m = 1.0f - DAT_004a1c08;
    f.Tx = m * v174.x;
    f.Ty = m * v174.y;
    f.Tz = m * v174.z;
    v174.z = f.Tz + f.Wz;
    v174.x = DAT_004a1c08 * v138.x + f.Tx;
    v174.y = f.Ty + f.Wy;

    v168.Add(v174);
    v168.Add(v144);
    v168.Add(v15c);

    if (!hit && f.b2) {
        v168.z = 0.0f;
        v168.y = 0.0f;
        v168.x = 0.0f;
        f64 = f64 - a2;
    } else {
        f.b2 = 0;
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
    f.Wx = z0;
    f.Wy = z0;
    double m2 = 1.0f - DAT_004a1c0c;
    f.Tx = m2 * v184.x;
    f.Ty = m2 * v184.y;
    f.Tz = m2 * v184.z;
    v184.z = f.Tz + z0;
    v184.x = f.Tx + f.Wx;
    v184.y = f.Ty + f.Wy;

    if (b78 && bd3 && fc8 < fd4) {
        if (f.b2 && !hit) {
            if (vb0.z * v94.z + vb0.y * v94.y + vb0.x * v94.x < -0.98f && f70 > 0.75f) {
                a1->name.FUN_0027b040("awestruck");
                a1->b148 = 1;
                bd1 = 1;
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

    if ((*(char*)&DAT_004e0a99) || bd1 || bd3)
        return;
    if (!v18(1.5f))
        return;
    if (!(fc8 < fd4))
        return;
    if (!v11(a0, fc8, f.sc))
        return;
    DAT_004dd700->p20->FUN_00029250(fa0, &v88, a0->f1cbc, 1);
}
