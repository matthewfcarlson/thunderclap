// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000c9720..0x000ca850 (kind game, layer game, confidence high), dominant class Overlay
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd3ccc71 {
#define TREE_TU_END }
namespace fn_fd3ccc71 {} using namespace fn_fd3ccc71;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fd3ccc71 {
struct Vec3_c9720 { float x,y,z; };
struct Vec2_c9720 { float x,y; };
struct Object {
 char pad0[0x38];
 float x,y;
 char pad1[0x210-0x40];
 float margin;
 Vec2_c9720* FUN_000c9460(Vec3_c9720* output, Vec3_c9720 input);
 void target(Vec3_c9720 input);
};
struct V3_c9810 {
    float x, y, z;
};
struct V2_c9810 {
    float x, y;
};
struct Mat4_c9810 {
    float m[16];
    void FUN_0022b980();
};
struct Planar {
    float x, y, z;
};
struct Body_c9810 {
    char pad0[0x10];
    void *f10;
    char FUN_00035550_dummy;
};
struct Probe_c9810 {
    void FUN_00035550(V3_c9810 *out);
    hulk_freg FUN_00035690();
};
struct WorldSub {
    Probe_c9810 *FUN_00024280(int a, int b);
};
struct Slots_c9810 {
    void FUN_001e5bc0(int handle);
    void FUN_001dd470(int handle, Mat4_c9810 *m, int z);
};
} // namespace fn_fd3ccc71
struct World {
    char pad0[0xc];
    Slots_c9810 *f0c;
    char pad10[0x20 - 0x10];
    WorldSub *f20;
};
namespace fn_fd3ccc71 {
struct Shot_c9810 {
    int id;                // 0
    V3_c9810 pos;                // 4
    V2_c9810 v10;                // 0x10
    Planar w;              // 0x18
    char pad24[0x28 - 0x24];
    int a28;
    int b2c;
    char pad30[0x3c - 0x30];
    char flag3c;
    char pad3d[3];
};
struct Fx_c9810 {
    int active;            // 0
    char pad4[0x18 - 4];
    float f18, f1c, f20;
    V3_c9810 euler;              // 0x24
    int handle;            // 0x30
    char pad34[4];
};
class Tracker_c9810 {
public:
    char pad0[0x10];
    void *f10;
    char pad14[0x20 - 0x14];
    char f20;
    char pad21[0x21c - 0x21];
    float f21c;
    float f220;
    char b224;
    char pad225[0x258 - 0x225];
    Shot_c9810 shots[0x80];
    Fx_c9810 fx[0x20];
    char b2958;
    char b2959;

    char FUN_000c8550(int idx, V3_c9810 *out);
    char FUN_000c8630(int idx, V3_c9810 *out);
    void FUN_000c9720(V3_c9810 v);
    V2_c9810 *FUN_000c9460(V2_c9810 *out, V3_c9810 v);
    void FUN_000c9100(int idx);
    void FUN_000c9810(float dt);
};
struct Frame_c9810 {
    union {
        V3_c9810 out;
        V2_c9810 ret;
        V3_c9810 euler;
    } u;                   // 0x10
    V3_c9810 tmp;                // 0x1c
    V3_c9810 p;                  // 0x28
    Mat4_c9810 mat;              // 0x34
};
class DynamicCaster_c9ba0 {
  public:
    virtual void cast();
};
class Obj {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int d(DynamicCaster_c9ba0*, __int64);
};
} // namespace fn_fd3ccc71
extern "C" __int64 FUN_0027b020(void*);

namespace fn_fd3ccc71 {

// 0x000c9720 FUN_000c9720 (189 B): equivalent/0x000c9720.cpp
// sym: ?target@Object@fn_fd3ccc71@@QAEXUVec3_c9720@2@@Z @e09560ed15cf @wcc9cbaa0c760
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000c9720 @ 0x000c9720
void Object::target(Vec3_c9720 input) {
 Vec2_c9720* result = FUN_000c9460(&input,input);
 double upper = 1.0f - (double)margin;
 x = result->x;
 y = result->y;
 if (!(x >= margin && upper >= x)) x = upper < x ? (float)upper : margin;
 if (!(y >= margin && upper >= y)) y = upper < y ? (float)upper : margin;
}


// 0x000c9810 FUN_000c9810 (856 B): equivalent/0x000c9810.cpp
// sym: ?FUN_000c9810@Tracker_c9810@fn_fd3ccc71@@QAEXM@Z @f92ecefc8608 @w4c5ba2155fd7
// STATUS: equivalent (tools/equiv.py level 3: 377 inputs, branch coverage 46/50, incomplete)
// FUN_000c9810 @ 0x000c9810
void Tracker_c9810::FUN_000c9810(float dt)
{
    if (f10 == 0)
        return;
    Frame_c9810 f;
    int i;
    if (f20 == 1) {
        int idx = 0;
        for (i = 0; i < 0x80; i++) {
            if (shots[i].flag3c == 1) {
                idx = i;
                break;
            }
        }
        if (FUN_000c8550(idx, &f.u.out) == 1)
            FUN_000c9720(f.u.out);
    }

    f220 = dt + f220;
    for (i = 0; i < 0x80; i++) {
        Shot_c9810 *s = &shots[i];
        if (s->id == -1)
            continue;
        if (!FUN_000c8550(i, &f.tmp)) {
            FUN_000c9100(i);
            continue;
        }
        s->pos = f.tmp;
        V2_c9810 *r = FUN_000c9460(&f.u.ret, f.tmp);
        s->v10.x = r->x;
        s->v10.y = r->y;
        if (s->id != 0)
            continue;
        Probe_c9810 *probe = DAT_004dd700->f20->FUN_00024280(s->a28, s->b2c);
        probe->FUN_00035550(&f.p);
        f.mat.FUN_0022b980();
        ((owners::Mat_22bab0 *)&(f.mat))->FUN_0022bab0(4.712389f);
        s->w.x = f.p.x;
        s->w.y = f.p.z;
        s->w.z = 0.0f;
        ((owners::Obj_22d260 *)&(s->w))->FUN_0022d260((owners::Obj_22d260 *)(const Mat4_c9810 *)(&f.mat));
        if (!b2958)
            continue;
        float t = probe->FUN_00035690();
        if ((t > DAT_0049fbcc && f21c < DAT_0049fbd0) || (t < DAT_0049fbd0 && f21c > DAT_0049fbcc)) {
            f21c = t;
            f220 = 0.0f;
            b224 = 0;
            b2959 = 0;
        }
        if (b2959) {
            f220 = DAT_0049fbd4;
            b224 = 0;
        }
        if (!b224 && f220 >= DAT_0049fbd4) {
            if (t > DAT_0049fbcc)
                ((owners::Obj_c8f50 *)this)->FUN_000c8f50(DAT_0049fbbc);
            else
                ((owners::Obj_c8f50 *)this)->FUN_000c8f50(DAT_0049fbb8);
        }
    }

    for (i = 0; i < 0x20; i++) {
        Fx_c9810 *e = &fx[i];
        if (e->active == 0)
            continue;
        if (!FUN_000c8630(i, &f.tmp)) {
            if (i < 0 || i >= 0x20)
                continue;
            if (e->active == 0)
                continue;
            DAT_004dd700->f0c->FUN_001e5bc0(e->handle);
            e->handle = -1;
            e->active = 0;
            continue;
        }
        f.p.x = f.tmp.x + e->f18;
        f.u.euler = e->euler;
        f.p.y = f.tmp.y + e->f1c;
        f.p.z = f.tmp.z + e->f20;
        f.mat.FUN_0022b980();
        ((owners::Target_22be40 *)&(f.mat))->FUN_0022be40((const int *)(const V3_c9810 *)(&f.p));
        ((owners::Matrix_22bc20 *)&(f.mat))->FUN_0022bc20(f.u.euler.x * 0.017453292f, f.u.euler.y * 0.017453292f, f.u.euler.z * 0.017453292f);
        DAT_004dd700->f0c->FUN_001dd470(e->handle, &f.mat, 0);
    }
}


// 0x000c9ba0 FUN_000c9ba0 (42 B): matches/0x000c9ba0.cpp
// sym: _FUN_000c9ba0
extern "C" hulk_intptr FUN_000c9ba0(Obj* obj, void* input) {
    __int64 p = FUN_0027b020(input);
    DynamicCaster_c9ba0 caster;
    return obj->d(&caster, p);
}

} // namespace fn_fd3ccc71

// 0x000ca3a0 FUN_000ca3a0 (914 B): equivalent/0x000ca3a0.cpp [wrapped: conflict: CHudMap; World; content::LoadInventory::DynamicCaster; pure3d::Entity]
// sym: ??0CHudMap@fn_000ca3a0@@QAE@XZ @cb65cfcc8957 @wef27afd02d47
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_000ca3a0 {
// STATUS: equivalent (tools/equiv.py level 3: 566 inputs, branch coverage 29/30, incomplete)
// FUN_000ca3a0 @ 0x000ca3a0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
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
extern "C" double sin(double);
#endif


namespace pure3d { class DrawableHierarchy; class Geometry; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }

struct V3_ca3a0 {
    float x, y, z;
};

struct NameHolder_ca3a0 {
    char pad[8];
    void FUN_0027b040(const char *name);
};

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void v0_00038290();
    char pad04[4];
    NameHolder_ca3a0 nameHolder;
    void FUN_0027b070();
    Entity() { FUN_0027b070(); }
};
}

struct Id64_ca3a0 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af00();
};

struct Obj_ca3a0 {
    virtual void init();
    virtual void release();
};

struct Inner_ca3a0 {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
    virtual void set(unsigned int, unsigned int);
    virtual void enable(unsigned int, unsigned int);
};

struct Shader_ca3a0 : Obj_ca3a0 {
    char pad[12];
    Inner_ca3a0 *inner;           // 0x10
    int f14;
    int f18;
    Shader_ca3a0 *FUN_0028edb0();
};

struct Loaded_ca3a0 : Obj_ca3a0 {
};

struct Inventory_ca3a0 {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual Loaded_ca3a0 *find(void *caster, unsigned __int64 key);
};

struct Level_ca3a0;
struct Window_ca3a0 { Level_ca3a0 *FUN_00086310(); };
struct World {
    char pad0[0x54];
    Window_ca3a0 *window;
};
struct Level_ca3a0 {
    char *FUN_000897e0();
};

struct MapIcon {
    int id;                 // 0x00
    int f04, f08, f0c, f10, f14, f18, f1c, f20;
    char pad24[4];
    Id64_ca3a0 name;              // 0x28
    int f30, f34, f38;
    char b3c, b3d;
    char pad3e[2];
};

struct Marker_ca3a0 {
    int f00, f04, f08, f0c;
    Id64_ca3a0 name;              // 0x10
    int f18, f1c, f20, f24, f28, f2c, f30, f34;
};

void *thunk_FUN_0008d690(unsigned int size);

struct Frame_ca3a0 {
    union {
        char buf[4];
        Loaded_ca3a0 **p;
    } u10;                      // 0x10
    char buf14[4];              // 0x14
    int pad18;
    const char *names[11];      // 0x1c
};

class CHudMap : public pure3d::Entity {
public:
    int f10;
    Shader_ca3a0 *res;          // 0x14
    Loaded_ca3a0 *radar;          // 0x18
    Loaded_ca3a0 *arrow;          // 0x1c
    char b20;
    char pad21[3];
    int f24, f28, f2c, f30;
    char pad34[4];
    int f38, f3c, f40, f44, f48, f4c;
    float wave[28];         // 0x50
    V3_ca3a0 ring[28];            // 0xc0
    int f210;
    float scale;            // 0x214
    int f218;
    int f21c, f220;
    char b224;
    char pad225[3];
    int f228;
    Loaded_ca3a0 *icons[10];      // 0x22c
    int f254;
    MapIcon marks[128];     // 0x258
    Marker_ca3a0 pins[32];        // 0x2258
    char b2958, b2959;
    CHudMap();
    void FUN_000c9bd0(char *name);
    int FUN_000c7d10(int a, const char *name);
};

CHudMap::CHudMap()
{
    f10 = 0;
    f24 = 0;
    f28 = 0;
    f2c = 0;
    f30 = 0;
    f38 = 0;
    f3c = 0;
    f40 = 0;
    f44 = 0;
    f48 = 0;
    f4c = 0;
    f21c = 0;
    f220 = 0;
    b224 = 1;
    f228 = 0x96;
    int i;
    for (i = 0; i < 0x80; i++) {
        MapIcon *e = &marks[i];
        e->id = -1;
        e->f04 = 0;
        e->f08 = 0;
        e->f0c = 0;
        e->f10 = 0;
        e->f14 = 0;
        e->f18 = 0;
        e->f1c = 0;
        e->f20 = 0;
        e->name.FUN_0027af00();
        e->f30 = -1;
        e->f34 = 0;
        e->f38 = 0;
        e->b3c = 0;
        e->b3d = 0;
    }
    for (i = 0; i < 0x20; i++) {
        Marker_ca3a0 *m = &pins[i];
        m->f00 = 0;
        m->f04 = 0;
        m->f08 = 0;
        m->f0c = 0;
        m->name.FUN_0027af00();
        m->f18 = 0;
        m->f1c = 0;
        m->f20 = 0;
        m->f24 = 0;
        m->f28 = 0;
        m->f2c = 0;
        m->f30 = -1;
        m->f34 = -1;
    }
    b2958 = 1;
    b2959 = 0;
    Shader_ca3a0 *r = (Shader_ca3a0 *)thunk_FUN_0008d690(0x20);
    if (r != 0)
        r = r->FUN_0028edb0();
    else
        r = 0;
    res = r;
    r->init();
    res->inner->set(0x584554, 0);
    Shader_ca3a0 *r2 = res;
    r2->inner->enable(0x444d4c42, 1);
    r2->f18 = 1;
    FUN_000c9bd0(DAT_004dd700->window->FUN_00086310()->FUN_000897e0());
    scale = DAT_004de604 * 0.1f;
    for (i = 0; i < 0x1c; i++)
        wave[i] = (float)sin((double)i * 0.224399477f);
    for (i = 0; i < 0x1c; i++) {
        ring[i].x = wave[(i + 7) % 0x1c] * scale;
        ring[i].z = 0;
        ring[i].y = wave[i] * scale;
    }
    Frame_ca3a0 f;
    {
        Inventory_ca3a0 *inv = (*(Inventory_ca3a0**)&DAT_004dd9cc);
        unsigned __int64 k1 = FUN_0027b020("radarBottomLeft");
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> *casterA =
            new (f.u10.buf) content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>;
        Loaded_ca3a0 *l = inv->find(casterA, k1);
        radar = l;
        if (l != 0)
            l->init();
    }
    {
        Inventory_ca3a0 *inv = (*(Inventory_ca3a0**)&DAT_004dd9cc);
        unsigned __int64 k2 = FUN_0027b020("north_arrow");
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> *casterB =
            new (f.buf14) content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>;
        Loaded_ca3a0 *l = inv->find(casterB, k2);
        arrow = l;
        if (l != 0)
            l->init();
    }
    f.names[0] = "hulkMapIconShape";
    f.names[1] = "enemyMapIconShape";
    f.names[2] = "smashMapIconShape";
    f.names[3] = "grabMapIconShape";
    f.names[4] = "defendMapIconShape";
    f.names[5] = "gotoMapIconShape";
    f.names[6] = "jumpMapIconShape";
    f.names[7] = "sidemissionMapIconShape";
    f.names[8] = "storymissionMapIconShape";
    f.names[9] = "sidemissionnewMapIconShape";
    f.names[10] = 0;
    f.u10.p = icons;
    for (i = 0; i < 10; i++) {
        Inventory_ca3a0 *inv = (*(Inventory_ca3a0**)&DAT_004dd9cc);
        unsigned __int64 k3 = FUN_0027b020(f.names[i]);
        content::LoadInventory::DynamicCaster<pure3d::Geometry> *caster =
            new (f.buf14) content::LoadInventory::DynamicCaster<pure3d::Geometry>;
        Loaded_ca3a0 *l = inv->find(caster, k3);
        *f.u10.p = l;
        if (l != 0)
            l->init();
        f.u10.p++;
    }
    int idx = FUN_000c7d10(0, "hulk");
    if (idx >= 0 && idx < 0x80) {
        MapIcon *e = &marks[idx];
        if (e->id != -1 && e != 0) {
            int k;
            for (k = 0; k < 0x80; k++) {
                if (marks[k].b3c == 1) {
                    marks[k].b3c = 0;
                    break;
                }
            }
            e->b3c = 1;
        }
    }
    b20 = 1;
}
} // namespace fn_000ca3a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fd3ccc71 {

// 0x000ca770 Overlay::vfunc_1 (1 B): matches/0x000ca770.cpp
// sym: ?FUN_000ca770@fn_fd3ccc71@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000ca770() {}


// 0x000ca780 Overlay::vfunc_2 (1 B): matches/0x000ca780.cpp
// sym: ?FUN_000ca780@fn_fd3ccc71@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000ca780() {}

} // namespace fn_fd3ccc71

// 0x000ca790 Overlay::vfunc_5 (3 B): matches/0x000ca790.cpp
// sym: ?vfunc_5@Overlay@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void Overlay::vfunc_5(int a) {
    (void)a;
}


// 0x000ca7a0 Overlay::vfunc_0 (31 B): matches/0x000ca7a0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_000ca7a0@@UAEPAV123@E@Z
namespace fn_000ca7a0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_0040a47c[];
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_0040a47c;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_000ca7a0

