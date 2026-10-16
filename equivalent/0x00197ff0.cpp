// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 44/46, incomplete)
// FUN_00197ff0 @ 0x00197ff0
#include "decls/address.h"
struct V3_197ff0 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(V3_197ff0 *other, float limit);
};

struct Mat_197ff0 {
    float m[16];
    void FUN_0022b980();
};

class RefObj_197ff0 {
public:
    virtual void v0();
    virtual void Release();
};

struct Obj_197ff0 {
    char pad0[0x12c];
    void *f12c;
};

struct List_197ff0 {
    Obj_197ff0 *FUN_00059c10(int id);
};

struct Sub38_197ff0 {
    void FUN_001f6cd0(void *a, void *b, V3_197ff0 *c, V3_197ff0 *d, V3_197ff0 *e, int f, float g, float h, int i, int j);
};

struct World {
    char pad0[0x38];
    Sub38_197ff0 *f38;
    char pad3c[8];
    List_197ff0 *list;
};

struct Owner_197ff0 {
    Obj_197ff0 *FUN_001d72e0();
};

struct Collider_197ff0 {
    char pad0[0x38];
    int kind;
    Owner_197ff0 *owner;
};

struct Hit_197ff0 {
    char pad0[0xc];
    int type;
};

struct Rng_197ff0 {
    unsigned int FUN_00011380(int lo, int hi);
};

struct Scene_197ff0 {
    void *FUN_00283ca0(V3_197ff0 *a, V3_197ff0 *b, V3_197ff0 *c, int d);
    void FUN_00283450(void *e, V3_197ff0 *b, V3_197ff0 *c, int d);
    void FUN_0027ffb0(void *e);
    int FUN_0027ffc0(void *e, Mat_197ff0 *m);
    void *FUN_00283a40(V3_197ff0 *a, Mat_197ff0 *b, int c, int d);
};

struct Params {
    char pad0[0x18];
    V3_197ff0 f18;
    char pad24[0x50 - 0x24];
    float f50;
    char pad54[8];
    float f5c;
    char pad60[4];
    int f64;
    int f68;
    char pad6c[4];
    float f70[2];
    V3_197ff0 f78;
    int f84;
    char pad88[0x90 - 0x88];
    int f90;
    int f94;
    int f98;
    char f9c;
    char pad9d[3];
    int fa0;
    int fa4;
    int fa8;
    char fac;
    char pada9[3];
    int fb0;
};

int __cdecl FUN_00098190(int a1, int a2, int a3, int a4, int a5, int a6, V3_197ff0 *a7, V3_197ff0 *io, int a9, int a10, int a11, int a12);
Scene_197ff0 *FUN_0027f250();
Rng_197ff0 *FUN_000964d0();
float FUN_000964e0();
void __cdecl FUN_00224db0(Mat_197ff0 *m, V3_197ff0 *a, V3_197ff0 *b);

// equiv-conv: FUN_00195290 ecx eax edx edi stack stack stack stack stack stack stack
bool FUN_00195290(V3_197ff0 *self, void **out2, void **out1, V3_197ff0 *origin, V3_197ff0 *end, V3_197ff0 *normal, void **shapeOut,
                  void *h, int flag, char *flagOut, int g);
// equiv-conv: FUN_001958c0 eax stack stack stack stack stack stack stack stack stack stack
bool FUN_001958c0(int id, Hit_197ff0 *src, int m1, int m2, V3_197ff0 *p4, V3_197ff0 *p5, V3_197ff0 *self, int scale, int f5, int a6, int a7);
// equiv-conv: FUN_00195560 ecx eax ebx stack stack stack stack stack stack stack stack stack stack stack
bool FUN_00195560(V3_197ff0 *self, Hit_197ff0 *src, V3_197ff0 *b, int id, int m1, int m2, V3_197ff0 *c, int scale, int f5, int a6, int a7,
                  int a8, int f9, int a10);

class Proj_197ff0 {
public:
    char pad0[4];
    Params *params;
    void *f8;
    void *fc;
    int f10;
    RefObj_197ff0 *f14;
    V3_197ff0 f18;
    V3_197ff0 f24;
    void FUN_00197ff0(float dt);
};

void Proj_197ff0::FUN_00197ff0(float dt)
{
    struct Frame {
        union {
            Hit_197ff0 *hit;
            void *ptr;
            float f;
            unsigned int u;
        } a;                       // 0x00
        char pad04[2];
        char hitFlag;              // 0x06
        char flagOut;              // 0x07
        int spill08;               // 0x08
        union {
            void *out2;
            float lifetime;
        } b;                       // 0x0c
        int spill10;               // 0x10
        V3_197ff0 w;                      // 0x14
        V3_197ff0 dir;                    // 0x20
        int g;                     // 0x2c
        V3_197ff0 hitPos;                 // 0x30
        void *owner;               // 0x3c
        int f9;                    // 0x40
        V3_197ff0 c;                      // 0x44
        int tmp50;                 // 0x50
        Mat_197ff0 m1;                    // 0x54
        Mat_197ff0 m0;                    // 0x94
    } L;

    L.a.u = *(unsigned int *)&dt & 0x7fffffff;
    if (L.a.f <= 1e-5f)
        return;

    L.b.lifetime = params->f5c;
    if (f14 != 0 && L.b.lifetime > 0.0f) {
        if (!FUN_00098190(*(int *)&dt, 0, *(int *)&L.b.lifetime, (int)0xbf800000, (int)f14, 0, &f18, &f24, 0, 0, 0, 1)) {
            if (f14 != 0)
                f14->Release();
            f14 = 0;
        }
    }

    World *world = DAT_004dd700;
    L.g = (int)world;
    L.owner = 0;
    L.b.out2 = 0;
    L.a.hit = 0;
    L.w.x = f24.x;
    L.w.y = f24.y;
    L.w.z = f24.z;
    L.w.FUN_0022d110();
    float s = params->f50;
    float ty = L.w.y * s;
    float tz = L.w.z * s;
    L.w.x = L.w.x * s + f18.x;
    L.w.y = ty + f18.y;
    L.w.z = tz + f18.z;

    void *owner = 0;
    Obj_197ff0 *o = world->list->FUN_00059c10(f10);
    if (o != 0)
        owner = o->f12c;

    L.spill10 = params->fa8;
    L.flagOut = 0;
    L.hitFlag = FUN_00195290(&L.hitPos, &L.b.out2, (void **)&L.owner, &f18, &L.w, &L.c, &L.a.ptr, owner, 1,
                             &L.flagOut, L.spill10);

    Hit_197ff0 *hit;
    Collider_197ff0 *col = (Collider_197ff0 *)L.b.out2;
    if (col != 0 && col->kind == 5)
        hit = (Hit_197ff0 *)col->owner->FUN_001d72e0();
    else
        hit = L.a.hit;

    if (hit != 0) {
        if (hit->type == 5) {
            if (L.flagOut)
                L.a.u = 0;
            else
                L.a.u = params->f90;
            L.spill10 = params->fa0;
            char r = FUN_001958c0(f10, hit, params->f84, params->fb0, &L.hitPos, &L.c, &f24, L.spill10, L.a.u, 0, params->f68);
            if (!r)
                L.hitFlag = r;
        } else if (hit->type == 1) {
            if (L.flagOut)
                L.a.u = 0;
            else
                L.a.u = params->f94;
            Params *p = params;
            char *q10 = (char *)&L.spill10;
            *q10 = p->f9c;
            L.f9 = p->f98;
            *(char *)&L.tmp50 = p->fac;
            L.spill08 = p->fa0;
            char r = FUN_00195560(&f24, hit, &L.hitPos, f10, p->f84, p->fb0, &L.c, L.spill08, L.a.u, 0,
                                  p->f68, L.tmp50, L.f9, L.spill10);
            if (!r)
                L.hitFlag = r;
        }
    }

    Scene_197ff0 *scene = FUN_0027f250();
    L.m0.FUN_0022b980();
    if (!L.hitFlag) {
        if (f8 == 0) {
            L.spill08 = params->f64;
            f8 = scene->FUN_00283ca0(&params->f18, &f18, &L.w, params->f64);
        } else {
            scene->FUN_00283450(f8, &f18, &L.w, params->f64);
        }
        scene->FUN_0027ffb0(fc);
        fc = 0;
        return;
    }
    if (f8 == 0) {
        L.spill08 = params->f64;
        f8 = scene->FUN_00283ca0(&params->f18, &f18, &L.hitPos, params->f64);
    } else {
        scene->FUN_00283450(f8, &f18, &L.hitPos, params->f64);
    }
    L.m1.FUN_0022b980();
    L.dir = params->f78;
    L.a.f = L.dir.FUN_0022d110();
    L.a.u &= 0x7fffffff;
    if (L.a.f <= 1e-5f) {
        L.dir.x = FUN_000964e0() + 0.001f;
        L.dir.y = FUN_000964e0() + 0.001f;
        L.dir.z = FUN_000964e0() + 0.001f;
        L.dir.FUN_0022d110();
    }
    if (!L.dir.FUN_0022d2b0(&L.c, 1e-5f))
        FUN_00224db0(&L.m1, &L.dir, &L.c);
    L.m1.m[12] = L.hitPos.x;
    L.m1.m[13] = L.hitPos.y;
    L.m1.m[14] = L.hitPos.z;
    if (!scene->FUN_0027ffc0(fc, &L.m1))
        fc = scene->FUN_00283a40((V3_197ff0 *)&params->f70, &L.m1, params->f64, 0x3f800000);
    if (FUN_000964d0()->FUN_00011380(0, 0x32) < 1) {
        if (L.owner != 0 && params->fa4 > 0) {
            ((World *)L.g)->f38->FUN_001f6cd0(L.owner, L.b.out2, &L.hitPos, &L.c, &f24, params->fa4 - 1, 1.0f, 1.0f, 0, 0);
        }
    }
}
