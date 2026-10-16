// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 31/32, incomplete)
// hulkfight::motion::ProjectileGroundShockwave::vfunc_4 @ 0x00198b30
#include "decls/address.h"
extern "C" double sqrt(double);
extern "C" void *memcpy(void *d, const void *s, unsigned int n);

struct V3_198b30 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(const V3_198b30 *other, float eps);
};

struct Mat_198b30 {
    float m[16];
    void FUN_0022b980();
};

struct Rng_198b30 {
    float FUN_000787e0(float lo, float hi);
};

extern "C" Rng_198b30 *__cdecl FUN_000964d0();
extern "C" void __cdecl FUN_00224d70(float angle, V3_198b30 *v);
extern "C" float __cdecl FUN_00224f10(V3_198b30 *v);
extern "C" void __cdecl FUN_00224db0(Mat_198b30 *m, V3_198b30 *from, V3_198b30 *to);
extern "C" float __cdecl FUN_0004af40(float lo, float hi, float v);
extern V3_198b30 DAT_004c1368;

struct Raycast {
    bool FUN_00201f20(V3_198b30 *p, int flag, V3_198b30 *hitA, V3_198b30 *hitB, int *o3, int *o4);
};

struct Spawner_198b30 {
    void FUN_001f6cd0(int a, int b, V3_198b30 *hitA, V3_198b30 *hitB, V3_198b30 *dir, int c, int d, int e, int *handle, int z);
};

class Pending;
class ProjectileGroundShockwave;

struct Registry_198b30 {
    void FUN_001ebf50(int handle, void *owner);
};

struct World {
    char pad0[0x24];
    Raycast *ray;       // 0x24
    char pad28[0x34 - 0x28];
    Registry_198b30 *reg;      // 0x34
    Spawner_198b30 *spawn;     // 0x38
};

struct Decal {
    void FUN_0027ffc0(void *what, Mat_198b30 *m);
};
Decal *FUN_0027f250();

struct Node {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(Mat_198b30 *m, float dt);
    char pad04[0x0c];
    Mat_198b30 mat;
};

struct Cfg_198b30 {
    char pad0[0x28];
    float f28;
    float f2c;
    char pad30[0x3c - 0x30];
    float f3c;
    char pad40[0x48 - 0x40];
    V3_198b30 vec48;
    int i54;
    int i58;
    float f5c;
    int cntA;       // 0x60
    float f64;
    float f68;
    int cntB;       // 0x6c
    int i70;
};

struct Frame_198b30 {
    float s0;       // S0
    float s4;       // S4
    V3_198b30 disp;        // S8
    int o4;         // S20
    union {         // S24
        int handle;
        float f64;
    };
    V3_198b30 g;           // S28
    int o3;         // S40
    int s44;        // S44
    float step;     // S48
    float c3c;      // S52
    float c68;      // S56
    V3_198b30 P;           // S60
    int a1;         // S72
    Raycast *ray;   // S76
    V3_198b30 hitA;        // S80
    V3_198b30 hitB;        // S92
    Mat_198b30 mat;        // S104
    Mat_198b30 mat2;       // S168
};

namespace hulkfight {
namespace motion {

class ProjectileGroundShockwave {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(float dt);
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad04[0x8];
    float life;     // 0xc
    char active;    // 0x10
    char pad11[7];
    Cfg_198b30 *cfg;       // 0x18
    char pad1c[8];
    Node *node;     // 0x24
    V3_198b30 vel;         // 0x28
    void *p34;      // 0x34
    float acc;      // 0x38
};

void ProjectileGroundShockwave::vfunc_4(float dt)
{
    if (active)
        return;
    union { float f; unsigned int u; } ab;
    ab.f = dt;
    ab.u &= 0x7fffffff;
    if (ab.f <= 1e-5f)
        return;

    Frame_198b30 f;
    V3_198b30 *pv = &vel;
    Cfg_198b30 *c0 = cfg;
    double k = (double)c0->f28 / (double)c0->f2c;
    f.s4 = life;
    f.disp.x = pv->x;
    f.disp.y = pv->y;
    f.disp.z = pv->z;
    memcpy(&f.mat, &node->mat, 0x40);
    World *mgr = DAT_004dd700;
    double sc = k * dt;
    f.disp.x = (float)(f.disp.x * sc);
    f.disp.y = (float)(f.disp.y * sc);
    f.disp.z = (float)(f.disp.z * sc);
    f.mat.m[12] = f.mat.m[12] + f.disp.x;
    f.mat.m[13] = f.mat.m[13] + f.disp.y;
    f.mat.m[14] = f.mat.m[14] + f.disp.z;
    f.P.x = f.mat.m[12];
    f.P.y = f.mat.m[13];
    f.P.z = f.mat.m[14];
    f.c3c = c0->f3c;
    f.P.y = f.P.y + f.c3c;
    f.ray = mgr->ray;
    f.o3 = 0;
    f.o4 = 0;
    bool hit = f.ray->FUN_00201f20(&f.P, 1, &f.hitA, &f.hitB, &f.o3, &f.o4);

    float X;
    if (hit) {
        f.s0 = f.hitA.y - f.mat.m[13];
        ab.f = f.s0;
        ab.u &= 0x7fffffff;
        f.s0 = ab.f;
        if (!(f.s0 > f.c3c))
            X = f.s4;
        else
            X = 0.0f;
    } else {
        X = 0.0f;
    }
    double nl = (double)X - (double)dt;
    life = (float)nl;
    if (nl < 0.0)
        return;

    node->v6(&f.mat, dt);
    f.s4 = (float)sqrt(f.disp.z * f.disp.z + f.disp.y * f.disp.y + f.disp.x * f.disp.x);
    if (p34 != 0) {
        Decal *dc = FUN_0027f250();
        f.mat2.FUN_0022b980();
        f.g = cfg->vec48;
        f.g.FUN_0022d110();
        if (!vel.FUN_0022d2b0(&f.g, 1e-5f))
            FUN_00224db0(&f.mat2, &f.g, &vel);
        f.mat2.m[12] = f.mat.m[12];
        f.mat2.m[13] = f.mat.m[13];
        f.mat2.m[14] = f.mat.m[14];
        dc->FUN_0027ffc0(p34, &f.mat2);
    }

    Cfg_198b30 *c1 = cfg;
    f.s0 = c1->f5c;
    if (!(f.s0 > 0.0f))
        return;
    double acc2 = (double)f.s4 + (double)acc;
    acc = (float)acc2;
    if (!(acc2 > (double)f.s0))
        return;
    acc = (float)(acc2 - (double)f.s0);
    if (f.o3 != 0) {
        int cnt = c1->i54;
        if (cnt > 0) {
            Rng_198b30 *rng = FUN_000964d0();
            f.s4 = rng->FUN_000787e0(0.0f, 6.2831855f);
            f.g = DAT_004c1368;
            FUN_00224d70(f.s4, &f.g);
            int c58 = cfg->i58;
            f.s4 = *(float *)&c58;
            f.handle = 0;
            mgr->spawn->FUN_001f6cd0(f.o3, f.o4, &f.hitA, &f.hitB, &f.g, cnt - 1, c58, c58, &f.handle, 0);
            mgr->reg->FUN_001ebf50(f.handle, (void *)this);
        }
    }

    Cfg_198b30 *c2 = cfg;
    int A = c2->cntA;
    int B = c2->cntB;
    if (A <= 0)
        return;
    if (B <= 0)
        return;
    f.c68 = c2->f68;
    float h = f.c68 * 0.5f;
    f.a1 = A - 1;
    f.f64 = c2->f64;
    f.s44 = c2->i70;
    float phi = FUN_00224f10(&vel);
    f.s4 = phi - h;
    f.s0 = phi + h;
    f.step = (float)((double)f.c68 / (double)B);
    Rng_198b30 *rng2 = FUN_000964d0();
    float lo = f.s4;
    float hi = f.s0;
    f.s0 = rng2->FUN_000787e0(lo, hi);
    int n = B;
    int ebx = f.s44;
    do {
        float want = f.s0 + f.step;
        f.s0 = FUN_0004af40(f.s4, hi, want);
        f.g = DAT_004c1368;
        FUN_00224d70(f.s0, &f.g);
        float gx = f.g.x * f.f64;
        float gy = f.g.y * f.f64;
        float gz = f.g.z * f.f64;
        f.disp.z = gz;
        f.disp.x = f.mat.m[12] + gx;
        f.disp.z = f.mat.m[14] + f.disp.z;
        f.disp.y = f.mat.m[13] + gy + f.c3c;
        if (f.ray->FUN_00201f20(&f.disp, 1, &f.hitA, &f.hitB, &f.o3, &f.o4)) {
            f.s44 = 0;
            mgr->spawn->FUN_001f6cd0(f.o3, f.o4, &f.hitA, &f.hitB, &f.g, f.a1, ebx, ebx, &f.s44, 0);
        }
        n--;
    } while (n != 0);
}

}
}
