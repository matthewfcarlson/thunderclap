// STATUS: equivalent (tools/equiv.py level 3: 19831 inputs, branch coverage 28/28)
// CHand2HandAgent::vfunc_20 @ 0x001005c0
#include "decls/data/game/global.h"

extern "C" double sqrt(double);

struct Vec3_1005c0 {
    float x, y, z;
    float FUN_0022d110() throw();
    char FUN_0022d2b0(const Vec3_1005c0 *z, float eps) throw();
};

struct Obj104;

class CHand2HandAgent;

struct World;
struct List_1005c0 {
    void FUN_00029250(int a, Vec3_1005c0 *p, int b, int c) throw();
};
struct World2_1005c0 {
    char pad00[0x20];
    List_1005c0 *list;
};

struct Ctx1_1005c0 {
    char pad[0x1cbc];
    int f1cbc;
};

struct Out_1005c0 {
    char pad00[0x10c];
    float v10c[3];
    float f118;
    float v11c[3];
};

union Arg3_1005c0 {
    float f;
    unsigned int u;
};

class Obj104 {
public:
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4(World2_1005c0 *w, Arg3_1005c0 a3, int z) throw();
    void FUN_001048d0(CHand2HandAgent *a) throw();
    void FUN_00104c60(World2_1005c0 *w, Vec3_1005c0 *a, Vec3_1005c0 *b, float c, int d, float e, float f) throw();
};

struct Obj58_1005c0 {
    char pad[0x129];
    char b129;
    Obj104 *FUN_000fefc0() throw();
};

class Obj5c {
public:
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3(World2_1005c0 *w, Ctx1_1005c0 *c, Vec3_1005c0 *out, Arg3_1005c0 a3, int z) throw();
    char pad04[0xc];
    Vec3_1005c0 v10;
};

extern World2_1005c0 *DAT_004dd700;

char __cdecl FUN_00036b10(World2_1005c0 *w, Vec3_1005c0 *a, Vec3_1005c0 *b, Vec3_1005c0 *c, Vec3_1005c0 *d, char *e, char *f) throw();
float __cdecl FUN_0010ae50(World2_1005c0 *w, Ctx1_1005c0 *c, float thr, Vec3_1005c0 *out, Vec3_1005c0 *v138, int a, int b) throw();

class CHand2HandAgent {
public:
    virtual void vfunc_0() throw();
    virtual void vfunc_1() throw();
    virtual void vfunc_2() throw();
    virtual void vfunc_3() throw();
    virtual void vfunc_4() throw();
    virtual void vfunc_5() throw();
    virtual void vfunc_6() throw();
    virtual void vfunc_7() throw();
    virtual void vfunc_8() throw();
    virtual void vfunc_9() throw();
    virtual void vfunc_10() throw();
    virtual char vfunc_11(Ctx1_1005c0 *c, int a, Arg3_1005c0 b) throw();
    virtual void vfunc_12() throw();
    virtual void vfunc_13() throw();
    virtual void vfunc_14() throw();
    virtual void vfunc_15() throw();
    virtual void vfunc_16() throw();
    virtual void vfunc_17() throw();
    virtual char vfunc_18(float f) throw();
    virtual void vfunc_19() throw();
    virtual void vfunc_20(Ctx1_1005c0 *c, Out_1005c0 *o, Arg3_1005c0 a3);
    char pad04[0x54];
    Obj58_1005c0 *f58;
    Obj5c *f5c;
    char pad60[0x28];
    Vec3_1005c0 v88;
    Vec3_1005c0 v94;
    int fa0;
    char pada4[0x18];
    Vec3_1005c0 vbc;
    int fc8;
    char padcc[5];
    char bd1;
    char padd2;
    char bd3;
    char padd4[0x104 - 0xd4];
    Vec3_1005c0 v104;
    char pad110[0x138 - 0x110];
    Vec3_1005c0 v138;
    Vec3_1005c0 v144;
    char pad150[0x15c - 0x150];
    Vec3_1005c0 v15c;
    Vec3_1005c0 v168;
    Vec3_1005c0 v174;
    float f180;
    Vec3_1005c0 v184;
};

void CHand2HandAgent::vfunc_20(Ctx1_1005c0 *a1, Out_1005c0 *a2, Arg3_1005c0 a3)
{
    struct Frame {
        char pad0[2];
        char b12;
        char b13;
        float thr;
        Vec3_1005c0 V;
        float tmp[3];
        Vec3_1005c0 P;
        Vec3_1005c0 Zv;
        Vec3_1005c0 F48;
        Vec3_1005c0 F54;
        Vec3_1005c0 O50;
    } f;

    f.V = v88;
    double dx = v88.x - v104.x;
    double dy = v88.y - v104.y;
    double dz = v88.z - v104.z;
    double L = sqrt(dz * dz + dy * dy + dx * dx);
    volatile float Lz = (float)(L * v144.z);
    f.P.x = f.V.x + L * v144.x;
    f.P.z = f.V.z + Lz;
    f.V.y = f.V.y + 1.25f;
    f.P.y = f.V.y;
    if (!FUN_00036b10(DAT_004dd700, &f.V, &f.P, &f.F54, &f.F48, &f.b13, &f.b12)) {
        Obj104 *o = f58->FUN_000fefc0();
        o->FUN_001048d0(this);
        o->FUN_00104c60(DAT_004dd700, &v88, &f.P, 1.0f, 0, 0.5f, 1.0f);
        o->v4(DAT_004dd700, a3, 0);
        return;
    }
    v168.z = 0.0f;
    v168.y = 0.0f;
    v168.x = 0.0f;
    v15c.z = 0.0f;
    v15c.y = 0.0f;
    v15c.x = 0.0f;
    v138.z = 0.0f;
    v138.y = 0.0f;
    v138.x = 0.0f;
    f.thr = 1.5f;
    if (f58->b129 == 0)
        f.thr = 0.99f;
    float r = FUN_0010ae50(DAT_004dd700, a1, 1.5f, &f.O50, &v138, 1, 0);
    if (r < 0.0f || r > f.thr) {
        f58->b129 = 0;
        v138.z = 0.0f;
        v138.y = 0.0f;
        v138.x = 0.0f;
    } else {
        f58->b129 = 1;
    }
    f5c->v10 = v144;
    f5c->v3(DAT_004dd700, a1, &v15c, a3, 0);
    v15c.x = v15c.x + v15c.x;
    v15c.y = v15c.y + v15c.y;
    v15c.z = v15c.z + v15c.z;
    double bx = DAT_004a1c08 * v138.x;
    volatile float by = DAT_004a1c08 * v138.y;
    volatile float bz = DAT_004a1c08 * v138.z;
    double w = 1.0f - DAT_004a1c08;
    volatile float t0 = w * v174.x;
    volatile float t1 = w * v174.y;
    volatile float t2 = w * v174.z;
    float nx = bx + t0;
    volatile float ny = t1 + by;
    volatile float nz = t2 + bz;
    v174.z = nz;
    v174.x = nx;
    v174.y = ny;
    double x1 = v174.x + v144.x;
    volatile float y1 = v144.y + v174.y;
    volatile float z1 = v144.z + v174.z;
    double x2 = x1 + v15c.x;
    double y2 = y1 + v15c.y;
    volatile float z2 = z1 + v15c.z;
    f.Zv.x = 0.0f;
    f.Zv.y = 0.0f;
    v168.z = z2;
    v168.x = (float)x2;
    v168.y = (float)y2;
    v168.y = 0.0f;
    f.Zv.z = 0.0f;
    float clamp;
    if (!v144.FUN_0022d2b0(&f.Zv, 1e-05f)) {
        if (1.0f < f180) {
            a3.f = 1.0f;
        } else {
            float v = f180;
            if (0.0f < v)
                a3.f = v;
            else
                a3.u = 0;
        }
    } else {
        double l3 = sqrt(v168.x * v168.x + v168.y * v168.y + v168.z * v168.z);
        a3.f = (float)l3;
        if (1.0f < a3.f) {
            a3.f = 1.0f;
        } else {
            float v = a3.f;
            if (0.0f < v)
                a3.f = v;
            else
                a3.u = 0;
        }
    }
    double l4 = sqrt(v168.x * v168.x + v168.y * v168.y + v168.z * v168.z);
    if (l4 < DAT_004a1c04) {
        v168.z = 0.0f;
        v168.y = 0.0f;
        v168.x = 0.0f;
        a2->v10c[2] = 0.0f;
        a2->v10c[1] = 0.0f;
        a2->v10c[0] = 0.0f;
        a2->f118 = 0.0f;
    } else {
        v168.FUN_0022d110();
        a2->f118 = a3.f;
        a2->v10c[0] = v168.x;
        a2->v10c[1] = v168.y;
        a2->v10c[2] = v168.z;
    }
    double z0 = DAT_004a1c0c * 0.0f;
    a2->v11c[0] = vbc.x;
    a2->v11c[1] = vbc.y;
    a2->v11c[2] = vbc.z;
    f.Zv.x = (float)z0;
    f.Zv.y = (float)z0;
    double w2 = 1.0f - DAT_004a1c0c;
    volatile float u0 = w2 * v184.x;
    volatile float u1 = w2 * v184.y;
    volatile float u2 = w2 * v184.z;
    double ax = u0 + f.Zv.x;
    double ay = u1 + f.Zv.y;
    volatile float az = u2 + z0;
    v184.z = az;
    v184.x = (float)ax;
    v184.y = (float)ay;
    a3.f = v94.z * vbc.z + v94.y * vbc.y + vbc.x * v94.x;
    if ((*(char*)&DAT_004e0a99) != 0)
        return;
    if (bd1)
        return;
    if (bd3)
        return;
    if (!vfunc_18(1.5f))
        return;
    if (!vfunc_11(a1, fc8, a3))
        return;
    DAT_004dd700->list->FUN_00029250(fa0, &v88, a1->f1cbc, 1);
}
