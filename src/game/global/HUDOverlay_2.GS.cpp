// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000cc7e0..0x000d40e0 (kind game, layer game, confidence high), dominant class HUDOverlay
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb5eeb37 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb5eeb37 {} using namespace fn_fb5eeb37;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fb5eeb37 {
namespace pure3d {
class DrawableHierarchy_d3f10;
}
namespace content {
class LoadInventory_d3f10 {
  public:
    template <class T> class DynamicCaster {
      public:
        virtual T* Cast(void* p);
    };
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual void* Find(const DynamicCaster<pure3d::DrawableHierarchy_d3f10>& c, __int64 uid);
};
}
struct Lookup_d3f10 {
    int idx;
    int kind;
};
struct Provider_d3f10 {
    hulk_intptr FUN_000ad7b0(int a, int b, int c);
    hulk_intptr FUN_000ad580(int a, int b, int c);
};
} // namespace fn_fb5eeb37
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* strstr(const char*, const char*);
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int sprintf(char*, const char*, ...);
#endif
namespace fn_fb5eeb37 {
const char* __cdecl FUN_000b09c0(int a, int b);
const char* __cdecl FUN_000b08a0(int a, int b);
struct Finder_d3f10 {
    char pad[4];
    Finder_d3f10* sub;
    void* FUN_000d3f10(const char* name);
};

} // namespace fn_fb5eeb37

// 0x000d3170 FUN_000d3170 (3067 B): equivalent/0x000d3170.cpp [wrapped: helper definitions (5 out-of-line function bodies)]
// sym: ?FUN_000d3170@Hud_d3170@fn_000d3170@@QAEXPAUA1@2@HPAUA3@2@@Z
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_000d3170 {
// STATUS: equivalent (tools/equiv.py level 3: 125 inputs, branch coverage 123/130, incomplete)
// FUN_000d3170 @ 0x000d3170
// cl-flags: /GS
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

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

namespace pure3d {
class CompositeDrawable;
class Locator;
class Geometry;
}


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int sprintf(char *, const char *, ...);
#endif

extern "C" int __cdecl FUN_00266da0(hulk_intptr mode);
void *__cdecl FUN_0008d690(unsigned int size);
void *thunk_FUN_0008d690(unsigned int size);
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

extern char DAT_0049fd74[];
extern char DAT_004a0520[];


struct Res_d3170 {
    virtual void AddRef();
    virtual void Release();
};

class Inventory_d3170 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Res_d3170 *get(void *caster, unsigned int lo, unsigned int hi);
};

struct Loc_d3170 : Res_d3170 {
    char pad04[0xc];
    float f10;
};

struct Composite_d3170 : Res_d3170 {
    char pad04[0x44];
    Res_d3170 *child48;
    void FUN_002998d0(int v);
};

struct Geom_d3170 : Res_d3170 {
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void g13();
    virtual void g14();
    virtual void g15();
    virtual int count();
    virtual void g17();
    virtual void *item(int i);
};

struct Inner_d3170 {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
    virtual void a5(unsigned int tag, int v);
    virtual void a6(unsigned int tag, int v);
};

struct Fade_d3170 : Res_d3170 {
    char pad04[0xc];
    Inner_d3170 *inner;
    int f14;
    int f18;
    Fade_d3170 *FUN_0028ee60(unsigned int tag, int z);
    Fade_d3170 *FUN_0028edb0();
};

struct Hud_d3170;

struct A1 {
    char pad[0x2c];
    int f2c;
};

struct A3 {
    char pad[0x2c];
    int f2c;
    float FUN_000d6d90(Hud_d3170 *h);
};

struct V3_d3170 {
    float x, y, z;
};
float __cdecl FUN_000f6a70(int a, V3_d3170 *v, int b);

struct Sub54 {
    int f0;
    void FUN_000f8500(const char *name, int a, int b);
};

struct Obj88 : Res_d3170 {
    void FUN_000c9bd0(int v);
    Obj88 *FUN_000ca3a0();
};

struct Obj8c_d3170 : Res_d3170 {
    Obj8c_d3170 *FUN_000c7630();
};

struct Flags_d3170 {
    int FUN_000897e0();
};
struct Holder_d3170 {
    Flags_d3170 *FUN_00086310();
    struct Pad_d3170 *FUN_00086370();
};
struct Pad_d3170 {
    int FUN_00090110();
};
struct World {
    char pad0[0x54];
    Holder_d3170 *f54;
};



static Res_d3170 *GetLocator(void *slot, const char *name)
{
    Inventory_d3170 *inv = (*(Inventory_d3170**)&DAT_004dd9cc);
    unsigned __int64 h = FUN_0027b020(name);
    new (slot) content::LoadInventory::DynamicCaster<pure3d::Locator>;
    return inv->get(slot, (unsigned int)h, (unsigned int)(h >> 32));
}

static Composite_d3170 *GetComposite(void *slot, const char *name)
{
    Inventory_d3170 *inv = (*(Inventory_d3170**)&DAT_004dd9cc);
    unsigned __int64 h = FUN_0027b020(name);
    new (slot) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>;
    return (Composite_d3170 *)inv->get(slot, (unsigned int)h, (unsigned int)(h >> 32));
}

static Res_d3170 *GetGeometry(void *slot, const char *name)
{
    Inventory_d3170 *inv = (*(Inventory_d3170**)&DAT_004dd9cc);
    unsigned __int64 h = FUN_0027b020(name);
    new (slot) content::LoadInventory::DynamicCaster<pure3d::Geometry>;
    return inv->get(slot, (unsigned int)h, (unsigned int)(h >> 32));
}

class Hud_d3170 {
public:
    char pad00[0xc];
    A1 *f0c;
    Res_d3170 *f10;
    Res_d3170 *f14;
    Res_d3170 *f18;
    char pad1c[0x28 - 0x1c];
    int f28, f2c, f30, f34, f38, f3c, f40, f44, f48, f4c;
    char b50;
    char pad51[3];
    Sub54 f54;
    char pad58[0x78 - 0x58];
    float f78;
    int f7c;
    int f80;
    int f84;
    Obj88 *f88;
    Obj8c_d3170 *f8c;
    Fade_d3170 *f90;
    char pad94[0xa8 - 0x94];
    int fa8;
    int fac;
    int fb0;
    int fb4;
    char pad_b8[4];
    char bbc;
    char padbd[0x13c - 0xbd];
    int f13c;
    float f140;
    int f144;
    char pad148[0x198 - 0x148];
    Composite_d3170 *f198;
    Res_d3170 *f19c;
    int f1a0;
    char pad1a4[0x1bc - 0x1a4];
    Loc_d3170 *top[3];
    Loc_d3170 *bot[3];
    Loc_d3170 *dist[3];
    char pad1e0[0x1ec - 0x1e0];
    float diff[3];
    Composite_d3170 *f1f8;
    Res_d3170 *f1fc;
    char pad200[0x21c - 0x200];
    Fade_d3170 *f21c;
    float f220;
    char b224;
    char b225;
    char pad226[2];
    float f228;
    float f22c;
    float f230;
    Fade_d3170 *f234;
    int f238;
    char pad23c[0x244 - 0x23c];
    Composite_d3170 *f244;
    Res_d3170 *f248;
    char pad24c[4];
    Res_d3170 *f250;
    Composite_d3170 *f254;
    Composite_d3170 *f258;
    Res_d3170 *f25c;
    Res_d3170 *f260;
    char pad264[0x464 - 0x264];
    Loc_d3170 *f464;
    Res_d3170 *f468;
    Loc_d3170 *f46c;
    float f470;
    char pad474[0x498 - 0x474];
    int f498;
    float f49c;
    Composite_d3170 *f4a0;
    char pad4a4[0x4ac - 0x4a4];
    Res_d3170 *f4ac;
    char pad4b0[0x508 - 0x4b0];
    Res_d3170 *f508;

    void FUN_000d2c30();
    void FUN_000ce750(int v);
    void FUN_000d3170(A1 *a1, int a2, A3 *a3);
};

static void Assign(Res_d3170 *&slot, Res_d3170 *v)
{
    if (v)
        v->AddRef();
    if (slot)
        slot->Release();
    slot = v;
}

struct Frame_d3170 {
    unsigned int c7c;
    unsigned int c78;
    union { int i; volatile float s74; } u74;
    union { int cnt; volatile float s70; unsigned int c70; } u70;
    V3_d3170 vec;
    volatile float s60;
    volatile float s5c;
    volatile float s58;
    volatile float s54;
    volatile float s50;
    int s4c;
    int saved;
    char buf[0x40];
};

void Hud_d3170::FUN_000d3170(A1 *a1, int a2, A3 *a3)
{
    Frame_d3170 f;
    f.saved = FUN_00266da0(0xe);
    f7c = a2;
    f0c = a1;
    f80 = a1->f2c;

    f.vec.x = DAT_004de600 * -0.5f;
    f.vec.y = DAT_004de604 * 0.5f;
    f.vec.z = 0.0f;
    f78 = FUN_000f6a70(a3->f2c, &f.vec, a2);

    if (f14) {
        f14->Release();
        f14 = 0;
    }
    if (f18) {
        f18->Release();
        f18 = 0;
    }
    f84 = 0xff;
    f54.FUN_000f8500("TBS_STATS_EXPERIENCE_POINTS", f7c, 1);
    f54.f0 = 0;

    // HUD layout constants
    f.s60 = DAT_004de600 * -0.5f;
    f.vec.x = DAT_004de600;
    f.vec.y = DAT_004de604;
    DAT_004ddf14 = 0;
    DAT_004ddeb8 = 0;
    DAT_004ddea0 = 0;
    DAT_004ddf08 = 0;
    f.s50 = f.vec.y * -0.1f;
    f.u74.s74 = f.s50;
    DAT_004ddf0c = f.vec.x * 0.06f + f.s60;
    DAT_004ddf10 = f.s50 + DAT_004de604 * 0.5f;
    f.s5c = DAT_004de604 * -0.5f;
    DAT_004ddeb0 = f.vec.x * 0.1f + f.s60;
    DAT_004ddeb4 = f.vec.y * 0.36f + f.s5c;
    DAT_004dde98 = f.vec.x * 0.1f + f.s60;
    DAT_004dde9c = f.vec.y * 0.4f + f.s5c;
    f.s50 = f.vec.y * -0.18f;
    DAT_004ddf00 = f.vec.x * 0.04f + DAT_004de600 * -0.5f;
    DAT_004ddf04 = f.s50 + DAT_004de604 * 0.5f;
    f.u70.s70 = 0.5f * f.vec.x;
    (*(float*)&DAT_004dded0) = 0;
    f.s50 = -(0.1f * f.vec.y);
    (*(float*)((char*)&DAT_004ddea4 + 8)) = 0;
    DAT_004ddec8 = f.u70.s70 + DAT_004de600 * -0.5f;
    DAT_004ddecc = f.s50 + DAT_004de604 * 0.5f;
    f.s54 = DAT_004de600 * -0.5f;
    f.s5c = -(0.14f * f.vec.y);
    (*(float*)&DAT_004ddea4) = f.u70.s70 + f.s54;
    (*(float*)((char*)&DAT_004ddea4 + 4)) = f.s5c + DAT_004de604 * 0.5f;

    Res_d3170 *r;
    {
        Fade_d3170 *p = (Fade_d3170 *)FUN_0008d690(0x10);
        Fade_d3170 *e = 0;
        if (p)
            e = p->FUN_0028ee60(0x45444146, 0);
        if (e)
            e->AddRef();
        if (f21c)
            f21c->Release();
        f21c = e;
    }
    {
        Fade_d3170 *p = (Fade_d3170 *)thunk_FUN_0008d690(0x20);
        Fade_d3170 *e = 0;
        if (p)
            e = p->FUN_0028edb0();
        if (e)
            e->AddRef();
        if (f234)
            f234->Release();
        f234 = e;
        e->inner->a6(0x444d4c42, 1);
    }
    f220 = 1.0f;
    f238 = 0;
    b224 = 0;
    b225 = 0;
    f230 = 0;
    f228 = 0;
    f22c = 0;
    f.s5c = f.u74.s74;
    f.s54 = DAT_004de600 * 0.5f;
    DAT_004ddefc = 0;
    DAT_004ddec4 = 0;
    DAT_004ddf1c = 0;
    (*(float*)&DAT_004ddf20) = 0;
    (*(float*)&DAT_004ddef4) = f.vec.x * -0.08f + f.s54;
    DAT_004ddef8 = f.s5c + DAT_004de604 * 0.5f;
    f.s5c = DAT_004de604 * 0.5f;
    f.s50 = f.vec.y * -0.127f;
    DAT_004ddebc = f.vec.x * 0.05f + DAT_004de600 * -0.5f;
    DAT_004ddec0 = f.s50 + f.s5c;
    DAT_004ddf18 = f.vec.x * 0.0333f;
    {
        Obj88 *p = (Obj88 *)thunk_FUN_0008d690(0x2960);
        Obj88 *e = 0;
        if (p)
            e = p->FUN_000ca3a0();
        if (e)
            e->AddRef();
        if (f88)
            f88->Release();
        f88 = e;
    }
    f88->FUN_000c9bd0(DAT_004dd700->f54->FUN_00086310()->FUN_000897e0());
    {
        Obj8c_d3170 *p = (Obj8c_d3170 *)thunk_FUN_0008d690(0x260);
        Obj8c_d3170 *e = 0;
        if (p)
            e = p->FUN_000c7630();
        if (e)
            e->AddRef();
        if (f8c)
            f8c->Release();
        f8c = e;
    }
    {
        Fade_d3170 *p = (Fade_d3170 *)thunk_FUN_0008d690(0x20);
        Fade_d3170 *e = 0;
        if (p)
            e = p->FUN_0028edb0();
        if (e)
            e->AddRef();
        if (f90)
            f90->Release();
        f90 = e;
        e->inner->a5(0x584554, 0);
    }
    Fade_d3170 *f90v = f90;
    f90v->inner->a6(0x444d4c42, 1);
    f90v->f18 = 1;
    fac = DAT_004dd700->f54->FUN_00086370()->FUN_00090110();
    fa8 = 0;
    fb4 = 0;
    fb0 = 0;
    bbc = 0;
    f13c = 0;
    f140 = -1.0f;
    f144 = 0;
    f1a0 = 0;
    FUN_000d2c30();

    Composite_d3170 *comp = GetComposite(&f.u70.c70, "criticalmass");
    comp->FUN_002998d0(0);
    Assign((Res_d3170 *&)f198, comp);
    r = comp->child48;
    Assign(f19c, r);

    f.u74.i = 1;
    f.u70.cnt = 3;
    do {
        sprintf(f.buf, "LOC_criticalmass%d_topShape", f.u74.i);
        Assign((Res_d3170 *&)top[f.u74.i - 1], GetLocator(&f.c78, f.buf));
        sprintf(f.buf, "LOC_criticalmass%d_botShape", f.u74.i);
        Assign((Res_d3170 *&)bot[f.u74.i - 1], GetLocator(&f.c7c, f.buf));
        sprintf(f.buf, "LOC_criticalmass%d_topdistanceShape", f.u74.i);
        Loc_d3170 *d = (Loc_d3170 *)GetLocator(&f.c7c, f.buf);
        Assign((Res_d3170 *&)dist[f.u74.i - 1], d);
        diff[f.u74.i - 1] = d->f10 - top[f.u74.i - 1]->f10;
        f.u74.i++;
        f.u70.cnt--;
    } while (f.u70.cnt != 0);

    comp = GetComposite(&f.c7c, "timer");
    if (comp) {
        comp->AddRef();
        if (f1f8)
            f1f8->Release();
        f1f8 = comp;
    }

    Res_d3170 *g = GetGeometry(&f.c7c, "HUDNumbersShape");
    if (g) {
        g->AddRef();
        Geom_d3170 *gg = (Geom_d3170 *)g;
        f.u74.i = 0;
        if (gg->count() > 0) {
            Res_d3170 **slot = &f1fc;
            do {
                Res_d3170 *o = (Res_d3170 *)FUN_00344e74(gg->item(f.u74.i), 0, DAT_0049fd74, DAT_004a0520, 0);
                if (o)
                    o->AddRef();
                if (*slot)
                    (*slot)->Release();
                *slot = o;
                slot++;
                f.u74.i++;
            } while (f.u74.i < gg->count());
        }
        g->Release();
    }

    comp = GetComposite(&f.c7c, "ers");
    Assign((Res_d3170 *&)f244, comp);
    if (comp) {
        f244->FUN_002998d0(0);
        r = f244->child48;
        Assign(f248, r);
        FUN_000ce750(0);
    }

    comp = GetComposite(&f.c7c, "enemy_health");
    Assign(f250, comp);

    comp = GetComposite(&f.c7c, "prop_healthcell");
    Assign((Res_d3170 *&)f254, comp);
    if (comp) {
        f254->FUN_002998d0(0);
        r = f254->child48;
        Assign(f25c, r);
    }

    comp = GetComposite(&f.c7c, "enemy_healthcell");
    Assign((Res_d3170 *&)f258, comp);
    if (comp) {
        f258->FUN_002998d0(0);
        r = f258->child48;
        Assign(f260, r);
    }

    Assign((Res_d3170 *&)f464, GetLocator(&f.c7c, "LOC_enemy_health_topShape"));
    Assign(f468, GetLocator(&f.c7c, "LOC_enemy_health_bottomShape"));
    Loc_d3170 *dl = (Loc_d3170 *)GetLocator(&f.c7c, "LOC_enemy_health_distanceShape");
    Assign((Res_d3170 *&)f46c, dl);
    f470 = f464->f10 - dl->f10;
    f498 = -1;
    f49c = -1.0f;

    comp = GetComposite(&f.c7c, "chaseHUD");
    Assign((Res_d3170 *&)f4a0, comp);
    if (comp) {
        f4a0->FUN_002998d0(0);
        r = f4a0->child48;
        Assign(f4ac, r);
    }
    b50 = 0;

    comp = GetComposite(&f.c7c, "HUD_trainingoverlay");
    Assign(f508, comp);

    f28 = 0;
    f2c = 0;
    f30 = 0;
    f34 = 0;
    f38 = 0;
    f3c = 0;
    f40 = 0;
    f44 = 0;
    f48 = 0;
    f4c = 0;
    a3->FUN_000d6d90(this);
    FUN_00266da0(f.saved);
}
} // namespace fn_000d3170
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fb5eeb37 {

// 0x000d3f10 FUN_000d3f10 (392 B): equivalent/0x000d3f10.cpp
// sym: ?FUN_000d3f10@Finder_d3f10@fn_fb5eeb37@@QAEPAXPBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 20136 inputs, branch coverage 33/34, incomplete)
// FUN_000d3f10 @ 0x000d3f10
void* Finder_d3f10::FUN_000d3f10(const char* name) {
    char buf[64];
    int i = 0;
    const char* s = ((const char**)&DAT_0040b020)[0];
    for (;;) {
        if (s == 0) {
            return 0;
        }
        if (strcmp(s, name) == 0) break;
        s = ((const char**)&DAT_0040b020)[i + 1];
        i++;
    }
    int idx = ((Lookup_d3f10*)&DAT_004a0560)[i].idx;
    int kind = ((Lookup_d3f10*)&DAT_004a0560)[i].kind;
    const char* text = 0;
    if (kind == 3) {
        text = ((const char**)&DAT_004a0658)[idx];
    } else {
        Provider_d3f10* p;
        int n = 0;
        do {
            p = ((Provider_d3f10 *)((owners::C_ae640 *)sub)->FUN_000ae640(n));
            if (p) break;
            n++;
        } while (n < 1);
        kind = ((Lookup_d3f10*)&DAT_004a0560)[i].kind;
        if (kind == 1) {
            if (p) text = (const char*)p->FUN_000ad7b0(0, idx, 0);
            else text = FUN_000b09c0(idx, 0);
        } else if (kind == 2) {
            if (p) text = (const char*)p->FUN_000ad580(0, idx, 0);
            else text = FUN_000b08a0(idx, 0);
        }
    }
    if (strstr(text, (*(const char**)&DAT_004a06a4)) == text)
        text += strlen((*(const char**)&DAT_004a06a4));
    const char* prefix = (((Lookup_d3f10*)&DAT_004a0560)[i].kind == 3) ? "" : "xbox_ctrlr_btn_";
    sprintf(buf, "%s%s%s", prefix, text, (*(const char**)&DAT_004a06a0));
    content::LoadInventory_d3f10* ld = (*(content::LoadInventory_d3f10**)&DAT_004dd9cc);
    __int64 uid = FUN_0027b020(buf);
    void* r = ld->Find(content::LoadInventory_d3f10::DynamicCaster<pure3d::DrawableHierarchy_d3f10>(), uid);
    return r;
}

} // namespace fn_fb5eeb37
