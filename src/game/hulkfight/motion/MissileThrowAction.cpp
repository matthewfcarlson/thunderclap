// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00197610..0x00198900 (kind game, layer game, confidence medium), dominant class hulkfight::motion::MissileThrowAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fbc25767 {
#define TREE_TU_END }
namespace fn_fbc25767 {} using namespace fn_fbc25767;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fbc25767 {
extern void* hulk_at_0041b4a0[];
class Ref_197f90 {
  public:
    virtual void F0();
    virtual void Release();
};
class BeamEffect_197f90 {
  public:
    void* vptr;
    void* m4;
    char pad[0xc];
    Ref_197f90* m14;
    ~BeamEffect_197f90() throw();
};
struct V3_197ff0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
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
};
struct Sub38_197ff0 {
    void FUN_001f6cd0(void *a, void *b, V3_197ff0 *c, V3_197ff0 *d, V3_197ff0 *e, int f, float g, float h, int i, int j);
};
} // namespace fn_fbc25767
struct World {
    char pad0[0x38];
    Sub38_197ff0 *f38;
    char pad3c[8];
    List_197ff0 *list;
};
namespace fn_fbc25767 {
struct Owner_197ff0 {
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
extern "C" int __cdecl FUN_00098190(int a1, int a2, int a3, int a4, hulk_intptr a5, int a6, V3_197ff0 *a7, V3_197ff0 *io, int a9, int a10, int a11, int a12);
extern "C" Scene_197ff0 *FUN_0027f250();
Rng_197ff0 *FUN_000964d0();
extern "C" void __cdecl FUN_00224db0(Mat_197ff0 *m, V3_197ff0 *a, V3_197ff0 *b);
bool FUN_00195290(V3_197ff0 *self, void **out2, void **out1, V3_197ff0 *origin, V3_197ff0 *end, V3_197ff0 *normal, void **shapeOut,
                  void *h, int flag, char *flagOut, int g);
extern "C" bool FUN_001958c0(int id, Hit_197ff0 *src, int m1, int m2, V3_197ff0 *p4, V3_197ff0 *p5, V3_197ff0 *self, int scale, int f5, int a6, int a7);
extern "C" bool FUN_00195560(V3_197ff0 *self, Hit_197ff0 *src, V3_197ff0 *b, int id, int m1, int m2, V3_197ff0 *c, int scale, int f5, int a6, int a7,
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
struct Ref { virtual void FUN_00000000(); virtual void FUN_00000001(); };
struct Data { char pad[0x14]; unsigned int a,b; };
struct Action_1984c0 { virtual void FUN_00000002(); char pad[0x18]; Action_1984c0(); };
struct AccuracyLatencyAction : Action_1984c0 { Data* data; Ref* ref; unsigned int zero1,zero2,a,b; virtual void FUN_00000003(); AccuracyLatencyAction(Data* d, Ref* r); };
extern void* hulk_at_0041b4a8[];
class Ref_198520 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_198520 {
  public:
    void* vptr;
};
class AccuracyLatencyAction_198520 : public Action_198520 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_198520* m20;
    ~AccuracyLatencyAction_198520();
};
class RefObj_198560 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_198560 {
  public:
    Action_198560();
    virtual void Update();
    char pad[0x18];
};
class MissileThrowAction_198560 : public Action_198560 {
  public:
    int mTarget;
    RefObj_198560* mObj;
    MissileThrowAction_198560(int target, RefObj_198560* obj);
    virtual void Execute();
};
extern void* hulk_at_0041b4c4[];
class Ref_1985b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1985b0 {
  public:
    void* vptr;
};
class MissileThrowAction_1985b0 : public Action_1985b0 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_1985b0* m20;
    ~MissileThrowAction_1985b0();
};

} // namespace fn_fbc25767

// 0x00197610 FUN_00197610 (2356 B): equivalent/0x00197610.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_00197610@Proj_197610@fn_00197610@@QAEXM@Z @30089d9472cc @wa2a8ab080915
namespace fn_00197610 {
// STATUS: equivalent (tools/equiv.py level 3: 19433 inputs, branch coverage 68/68)
// FUN_00197610 @ 0x00197610
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif


struct V3_197610 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    char FUN_0022d2b0(const V3_197610 *other, float eps);
};

struct Rng_197610 {
    unsigned int lo;
    unsigned int hi;
    hulk_freg FUN_00078780();
};
Rng_197610 *__cdecl FUN_000964d0();

static float RandBits(Rng_197610 *r)
{
    unsigned int a = r->lo;
    a = (a & 0xffff) * 0x9069 + (a >> 16);
    r->lo = a;
    unsigned int b = r->hi;
    b = (b & 0xffff) * 0x4650 + (b >> 16);
    r->hi = b;
    unsigned int bits = (((r->lo << 16) + (b & 0xffff)) & 0x7fffff) | 0x3f800000;
    return *(float *)&bits;
}

struct Pos10_197610 {
    void FUN_00059a50(V3_197610 *out);
};

struct Target_197610 {
    char pad00[0x10];
    Pos10_197610 *f10;
    void FUN_00035550(V3_197610 *out);
};

class Cfg_197610 {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual float c7();
    char pad04[0xf0 - 4];
    char bf0;
    char padf1[0xfd - 0xf1];
    char bfd;
    char bfe;
    char padff[0x100 - 0xff];
    V3_197610 v100;
    V3_197610 v10c;
    float f118;
    V3_197610 v11c;
    float f128;
    char b12c;
    char pad12d[3];
    float f130;
    float f134;
    void FUN_00192ea0(V3_197610 *out);
};

struct Fighter_197610 {
    int x;
};
struct Anchor_197610 {
    Fighter_197610 *FUN_00059a30();
};
struct Ref20_197610 {
};

struct Sink64 {
    void FUN_001d7590();
    V3_197610 *FUN_001d6b40();
    void FUN_001d7810(V3_197610 v);
};

struct World20_197610 {
    Target_197610 *FUN_00024280(int a, int b);
};
struct World {
    char pad00[0x20];
    World20_197610 *f20;
};

class Proj_197610 {
public:
    char pad00[0x1c];
    Cfg_197610 *cfg;
    Ref20_197610 *f20;
    V3_197610 f24;
    char pad30[0x50 - 0x30];
    Target_197610 *f50;
    char pad54[4];
    int f58;
    int f5c;
    char pad60[4];
    Sink64 *f64;
    char pad68[4];
    V3_197610 f6c;
    char pad78[0x84 - 0x78];
    float f84;
    float f88;
    float f8c;
    void FUN_00197610(float dt);
};

void Proj_197610::FUN_00197610(float dt)
{
    if (f20 == 0)
        return;
    Fighter_197610 *owner = ((Anchor_197610 *)((owners::Object_592a0 *)f20)->FUN_000592a0())->FUN_00059a30();
    if (!owner)
        return;
    f64->FUN_001d7590();
    World20_197610 *w = DAT_004dd700->f20;
    f50 = 0;
    if (w)
        f50 = w->FUN_00024280(f58, f5c);
    Target_197610 *tg = f50;
    if (!tg)
        return;
    Cfg_197610 *c = cfg;
    // the original keeps d (the facing below) and G (the FUN_00192ea0 output further down) in one frame slot,
    // and FUN_00192ea0 sees d's old contents there
    V3_197610 dG;
    if (c->bfd) {
        if (c->bfe) {
            V3_197610 P;
            tg->f10->FUN_00059a50(&P);
            V3_197610 &d = dG;
            d.x = 0;
            d.y = 0;
            d.z = 0;
            ((owners::Thing_356c0 *)tg)->FUN_000356c0((unsigned int *)(V3_197610 *)(&d));
            hulk_freg len = d.FUN_0022d110();
            hulk_freg sc;
            if (len <= 0.0f) {
                tg->FUN_00035550(&d);
                sc = 4.0f;
            } else if (len < 1.0f) {
                sc = 4.0f;
            } else {
                sc = len;
            }
            V3_197610 e = d;
            sc = sc * cfg->f118;
            e.x = e.x * sc;
            e.y = e.y * sc;
            hulk_freg ez = sc * e.z;
            f6c.x = P.x + *(volatile float *)&e.x;     // the original reloads the stored (rounded) products
            f6c.y = P.y + *(volatile float *)&e.y;
            f6c.z = P.z + ez;
        } else {
            tg->f10->FUN_00059a50(&f6c);
        }
    }
    V3_197610 *p = f64->FUN_001d6b40();
    V3_197610 D;
    D.x = f6c.x - p->x;
    D.y = f6c.y - p->y;
    hulk_freg dz = f6c.z - p->z;   // stored, and its unrounded value is one factor of dz*dz below
    D.z = dz;
    float v = f84;
    c = cfg;
    float k = 1.0f;
    float L = (float)sqrt(dz * D.z + D.y * D.y + D.x * D.x);
    hulk_freg rate = c->c7();       // the original reads f88 after the call
    hulk_freg ratio = f88 / rate;
    c = cfg;
    if (*(unsigned int *)&c->f134 != 0x3f800000) {
        if (!(ratio >= c->f134)) {
            f8c = f84;
        } else {
            if (c->bf0)
                return;
            v = f8c;
        }
    }
    if (v > dt)
        k = dt / v;
    V3_197610 E = D;
    E.FUN_0022d110();
    Rng_197610 *rnd = FUN_000964d0();
    double m;
    if (cfg->b12c)
        m = k * cfg->f130 * L;
    else
        m = k * cfg->f128;
    E.x = E.x * m;
    E.y = E.y * m;
    E.z = E.z * m;
    V3_197610 q = cfg->v100;
    if (!q.FUN_0022d2b0(&f24, 1e-05f)) {
        V3_197610 q5 = cfg->v100;
        E.x = q5.x + E.x;
        E.y = q5.y + E.y;
        E.z = q5.z + E.z;
    }
    V3_197610 q2 = cfg->v10c;
    if (!q2.FUN_0022d2b0(&f24, 1e-05f)) {
        V3_197610 q3;
        float vals[4];
        for (int i = 0; i < 4; i++) {
            q3 = cfg->v10c;
            vals[i] = rnd->FUN_00078780() * q3.x;
        }
        double mx = (vals[0] + vals[1] + vals[2] + vals[3]) * 0.25f;
        double my = ((RandBits(rnd) - 1.0f) * cfg->v10c.y
                     + (RandBits(rnd) - 1.0f) * cfg->v10c.y
                     + (RandBits(rnd) - 1.0f) * cfg->v10c.y
                     + (RandBits(rnd) - 1.0f) * cfg->v10c.y) * 0.25f;
        float mz = ((RandBits(rnd) - 1.0f) * cfg->v10c.z
                    + (RandBits(rnd) - 1.0f) * cfg->v10c.z
                    + (RandBits(rnd) - 1.0f) * cfg->v10c.z
                    + (RandBits(rnd) - 1.0f) * cfg->v10c.z) * 0.25f;
        E.x = mx + E.x;
        E.y = my + E.y;
        E.z = mz + E.z;
    } else {
        V3_197610 q4 = cfg->v11c;
        if (!q4.FUN_0022d2b0(&f24, 1e-05f)) {
            Target_197610 *t5 = f50;
            if (t5 && f64) {
                V3_197610 &G = dG;
                cfg->FUN_00192ea0(&G);
                V3_197610 &H = D;
                t5->f10->FUN_00059a50(&H);
                if (G.x > 0.0f) {
                    if (E.x > H.x)
                        E.x = E.x - G.x;
                    else if (E.x < H.x)
                        E.x = G.x + E.x;
                } else {
                    if (E.x < H.x)
                        E.x = E.x - G.x;
                    else if (E.x > H.x)
                        E.x = G.x + E.x;
                }
                if (G.y > 0.0f) {
                    if (E.y > H.y)
                        E.y = E.y - G.y;
                    else if (E.y < H.y)
                        E.y = G.y + E.y;
                } else {
                    if (E.y < H.y)
                        E.y = E.y - G.y;
                    else if (E.y > H.y)
                        E.y = G.y + E.y;
                }
                if (G.z > 0.0f) {
                    if (E.z > H.z)
                        E.z = E.z - G.z;
                    else if (E.z < H.z)
                        E.z = G.z + E.z;
                } else {
                    if (E.z < H.z)
                        E.z = E.z - G.z;
                    else if (E.z > H.z)
                        E.z = G.z + E.z;
                }
            }
        }
    }
    V3_197610 *pp = f64->FUN_001d6b40();
    V3_197610 X;
    X.x = E.x + pp->x;
    X.y = E.y + pp->y;
    X.z = E.z + pp->z;
    f64->FUN_001d7810(X);
    f84 = f84 - dt;
    f88 = dt + f88;
}
} // namespace fn_00197610
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fbc25767 {

// 0x00197f90 FUN_00197f90 (44 B): matches/0x00197f90.cpp
// sym: ??1BeamEffect_197f90@fn_fbc25767@@QAE@XZ
BeamEffect_197f90::~BeamEffect_197f90() throw() {
    vptr = hulk_at_0041b4a0;
    _ReadWriteBarrier();
    if (m14) {
        m14->Release();
        m14 = 0;
    }
    if (m4)
        m4 = 0;
}


// 0x00197ff0 FUN_00197ff0 (1220 B): equivalent/0x00197ff0.cpp
// sym: ?FUN_00197ff0@Proj_197ff0@fn_fbc25767@@QAEXM@Z @caac7dcd3e9a @w2b45cc25443c
// STATUS: equivalent (tools/equiv.py level 3: 20043 inputs, branch coverage 46/46)
// FUN_00197ff0 @ 0x00197ff0
// equiv-conv: FUN_00195290 ecx eax edx edi stack stack stack stack stack stack stack
// equiv-conv: FUN_001958c0 eax stack stack stack stack stack stack stack stack stack stack
// equiv-conv: FUN_00195560 ecx eax ebx stack stack stack stack stack stack stack stack stack stack stack
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
        if (!FUN_00098190(*(int *)&dt, 0, *(int *)&L.b.lifetime, (int)0xbf800000, (hulk_intptr)f14, 0, &f18, &f24, 0, 0, 0, 1)) {
            if (f14 != 0)
                f14->Release();
            f14 = 0;
        }
    }

    World *world = DAT_004dd700;
    L.g = (hulk_intptr)world;
    L.owner = 0;
    L.b.out2 = 0;
    L.a.hit = 0;
    L.w.x = f24.x;
    L.w.y = f24.y;
    L.w.z = f24.z;
    L.w.FUN_0022d110();
    float s = params->f50;
    struct { hulk_freg x; float y, z; } t;      // w * s: x stays in a register, y and z are stored (rounded)
    t.x = L.w.x * s;
    t.y = L.w.y * s;
    t.z = L.w.z * s;
    L.w.x = t.x + f18.x;
    L.w.y = t.y + f18.y;
    L.w.z = t.z + f18.z;

    void *owner = 0;
    Obj_197ff0 *o = ((Obj_197ff0 *)((owners::ThisWrap_00059c10 *)(world->list))->FUN_00059c10((void *)(hulk_uintptr)(int)f10));
    if (o != 0)
        owner = o->f12c;

    L.spill10 = params->fa8;
    L.flagOut = 0;
    L.hitFlag = FUN_00195290(&L.hitPos, &L.b.out2, (void **)&L.owner, &f18, &L.w, &L.c, &L.a.ptr, owner, 1,
                             &L.flagOut, L.spill10);

    Hit_197ff0 *hit;
    Collider_197ff0 *col = (Collider_197ff0 *)L.b.out2;
    if (col != 0 && col->kind == 5)
        hit = (Hit_197ff0 *)((Obj_197ff0 *)((owners::C_1d72e0 *)(col->owner))->FUN_001d72e0());
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
    if (((unsigned int)((owners::Random_11380 *)(FUN_000964d0()))->FUN_00011380(0, 0x32)) < 1) {
        if (L.owner != 0 && params->fa4 > 0) {
            ((World *)L.g)->f38->FUN_001f6cd0(L.owner, L.b.out2, &L.hitPos, &L.c, &f24, params->fa4 - 1, 1.0f, 1.0f, 0, 0);
        }
    }
}


// 0x001984c0 FUN_001984c0 (89 B): equivalent/0x001984c0.cpp
// sym: ??0AccuracyLatencyAction@fn_fbc25767@@QAE@PAUData@1@PAURef@1@@Z @2b7fd611f4ad @w6b932b61c9f2
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001984c0 @ 0x001984c0
AccuracyLatencyAction::AccuracyLatencyAction(Data* d, Ref* r) { zero1=0; zero2=0; ref=0; data=d; if(r) r->FUN_00000000(); if(ref) ref->FUN_00000001(); ref=r; a=data->a; b=data->b; }


// 0x00198520 FUN_00198520 (50 B): matches/0x00198520.cpp
// sym: ??1AccuracyLatencyAction_198520@fn_fbc25767@@QAE@XZ
AccuracyLatencyAction_198520::~AccuracyLatencyAction_198520() {
    vptr = hulk_at_0041b4a8;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_198520 *)this)->FUN_002326a0();
}


// 0x00198560 FUN_00198560 (72 B): matches/0x00198560.cpp
// sym: ??0MissileThrowAction_198560@fn_fbc25767@@QAE@HPAVRefObj_198560@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
MissileThrowAction_198560::MissileThrowAction_198560(int target, RefObj_198560* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}


// 0x001985b0 FUN_001985b0 (50 B): matches/0x001985b0.cpp
// sym: ??1MissileThrowAction_1985b0@fn_fbc25767@@QAE@XZ
MissileThrowAction_1985b0::~MissileThrowAction_1985b0() {
    vptr = hulk_at_0041b4c4;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1985b0 *)this)->FUN_002326a0();
}

} // namespace fn_fbc25767
