// STATUS: equivalent (tools/equiv.py level 3: 2345 inputs, branch coverage 44/44)
// CHand2HandAgent::vfunc_23 @ 0x00101a30
#include "decls/address.h"
extern "C" double sqrt(double);

struct V3_101a30 {
    float x, y, z;
    float FUN_0022d110();
};

struct Name_101a30 {
    void FUN_0027b040(const char *s);
};

struct Rng_101a30 {
    float FUN_00078780();
};
Rng_101a30 *FUN_000964d0();

struct Obj58_101a30 {
    char pad0[0x129];
    char b129;
};

struct Pos10_101a30 {
    V3_101a30 v;
};

class P5c_101a30 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(struct World *hub, struct Arg1_101a30 *a1, V3_101a30 *out, int a3, int z);
    char pad04[0xc];
    V3_101a30 v10;
};

struct Arg1_101a30 {
    char pad0[0x1cbc];
    int f1cbc;
};

struct Hub20_101a30 {
    void FUN_00029250(int a, V3_101a30 *v, int b, int c);
};
struct World {
    char pad0[0x20];
    Hub20_101a30 *p20;
};
extern float DAT_004a1c00;
extern float DAT_004a1c04;
extern float DAT_004a1c08;
extern float DAT_004a1c0c;
extern char DAT_004e0a99;

float FUN_0010ae50(World *h, Arg1_101a30 *a, float f, V3_101a30 *v1, V3_101a30 *v2, int z1, int z2);

struct Out_101a30 {
    char pad0[0x10c];
    V3_101a30 v10c;
    float f118;
    V3_101a30 v11c;
    V3_101a30 v128;
    char pad134[0x140 - 0x134];
    Name_101a30 name;
    char pad141[7];
    char b148;
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
    virtual char v11(Arg1_101a30 *a, int b, float c);
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
    virtual void v22();
    virtual void v23(Arg1_101a30 *a1, Out_101a30 *out, int a3);
    char pad04[0x58 - 4];
    Obj58_101a30 *p58;
    P5c_101a30 *p5c;
    char pad60[4];
    float f64;
    char pad68[0x78 - 0x68];
    char b78;
    char pad79;
    char b7a;
    char pad7b;
    char b7c;
    char pad7d[3];
    float f80;
    char pad84[4];
    V3_101a30 v88;
    float f94, f98, f9c;
    int pa0;
    char pada4[0xb0 - 0xa4];
    V3_101a30 vB0;
    V3_101a30 vBC;
    int c8;
    char padcc[0xd1 - 0xcc];
    char d1;
    char padd2;
    char d3;
    char padd4[0x128 - 0xd4];
    int i128;
    char pad12c[0x138 - 0x12c];
    V3_101a30 v138;
    char pad144[0x150 - 0x144];
    V3_101a30 v150;
    V3_101a30 v15c;
    V3_101a30 v168;
    V3_101a30 v174;
    char pad180[4];
    V3_101a30 v184;
};

void CHand2HandAgent::v23(Arg1_101a30 *a1, Out_101a30 *out, int a3)
{
    Rng_101a30 *rng = FUN_000964d0();
    v168.z = 0;
    v168.y = 0;
    v168.x = 0;
    v15c.z = 0;
    v15c.y = 0;
    v15c.x = 0;
    b78 = 0;
    out->v11c.x = vBC.x;
    out->v11c.y = vBC.y;
    out->v11c.z = vBC.z;
    out->v128.x = vBC.x;
    out->v128.y = vBC.y;
    out->v128.z = vBC.z;
    if (!d1 && !d3 && f64 > 0.0f && b7a)
        v16();
    v138.z = 0;
    v138.y = 0;
    v138.x = 0;
    float thr = 1.5f;
    if (!p58->b129)
        thr = 0.99f;
    float t = FUN_0010ae50(DAT_004dd700, a1, 1.5f, &v150, &v138, 0, 0);
    if (!(t < 0.0f) && !(t > thr)) {
        p58->b129 = 1;
    } else {
        p58->b129 = 0;
        v138.z = 0;
        v138.y = 0;
        v138.x = 0;
    }
    {
        double lx = (double)DAT_004a1c08 * v138.x;
        volatile float ly = DAT_004a1c08 * v138.y;
        volatile float lz = DAT_004a1c08 * v138.z;
        double m = (double)1.0f - DAT_004a1c08;
        volatile float a0 = (float)(m * v174.x);
        volatile float a1_ = (float)(m * v174.y);
        volatile float a2 = (float)(m * v174.z);
        v174.z = a2 + lz;
        v174.x = (float)(lx + a0);
        v174.y = a1_ + ly;
    }
    v168.z = v174.z + v150.z;
    v168.x = v150.x + v174.x;
    v168.y = v174.y + v150.y;
    p5c->v10.x = v168.x;
    p5c->v10.y = v168.y;
    p5c->v10.z = v168.z;
    p5c->v3(DAT_004dd700, a1, &v15c, a3, 0);
    v168.x = v15c.x + v168.x;
    v168.y = v15c.y + v168.y;
    v168.z = v15c.z + v168.z;
    V3_101a30 W;
    double P0 = (double)vBC.y * 0.0f;
    W.x = (float)(P0 - vBC.z);
    W.y = (float)((double)vBC.z * 0.0f - (double)vBC.x * 0.0f);
    W.z = (float)(vBC.x - P0);
    W.FUN_0022d110();
    double d = W.z * v168.z + W.y * v168.y + W.x * v168.x;
    W.x = (float)(W.x * d);
    W.y = (float)(W.y * d);
    W.z = (float)(W.z * d);
    {
        double lx = W.x * (double)DAT_004a1c0c;
        volatile float by = W.y * DAT_004a1c0c;
        volatile float bz = W.z * DAT_004a1c0c;
        double m = (double)1.0f - DAT_004a1c0c;
        volatile float c0 = (float)(m * v184.x);
        volatile float c1 = (float)(m * v184.y);
        volatile float c2 = (float)(m * v184.z);
        v184.z = c2 + bz;
        v184.x = (float)(lx + c0);
        v184.y = c1 + by;
    }
    v168.x = v184.x;
    v168.y = v184.y;
    v168.z = v184.z;
    volatile float *pv = &v168.x;
    float lz1 = pv[2];
    float ly1 = pv[1];
    float lx1 = pv[0];
    double len = sqrt(lx1 * lx1 + ly1 * ly1 + lz1 * lz1);
    float cap = (float)len;
    if (1.0f < len)
        cap = 1.0f;
    float lz2 = pv[2];
    float ly2 = pv[1];
    float lx2_ = pv[0];
    if (sqrt(lx2_ * lx2_ + ly2 * ly2 + lz2 * lz2) < DAT_004a1c04) {
        v168.x = 0;
        v168.y = 0;
        v168.z = 0;
        out->v10c.z = 0;
        out->v10c.y = 0;
        out->v10c.x = 0;
        out->f118 = 0;
    } else {
        v168.FUN_0022d110();
        out->f118 = cap;
        out->v10c.x = v168.x;
        out->v10c.y = v168.y;
        out->v10c.z = v168.z;
    }
    char d1v = d1;
    float D1 = vBC.z * f9c + vBC.y * f98 + vBC.x * f94;
    if (!d1v && !d3 && f64 > 0.0f && b7c) {
        double E = vB0.z * f9c + vB0.y * f98 + vB0.x * f94;
        int i = i128;
        const char *nm = 0;
        if (E < -0.93f) {
            if (i <= 0)
                nm = "taunt";
            else if (rng->FUN_00078780() < 0.5f)
                nm = "taunt";
            else
                nm = "gesture_2";
        } else if (i > 0) {
            nm = "gesture_2";
        }
        if (nm) {
            out->name.FUN_0027b040(nm);
            out->b148 = 1;
            b7c = 0;
            return;
        }
    }
    if (!DAT_004e0a99 && !d1v && !d3) {
        if (v18(1.5f)) {
            if (v11(a1, c8, D1))
                DAT_004dd700->p20->FUN_00029250(pa0, &v88, a1->f1cbc, 1);
        }
    }
    *(int *)&f80 = *(int *)&DAT_004a1c00;
}
