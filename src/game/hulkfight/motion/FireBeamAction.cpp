// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00196220..0x00197610 (kind game, layer game, confidence medium), dominant class hulkfight::motion::FireBeamAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f9476b2e {
#define TREE_TU_END }
namespace fn_f9476b2e {} using namespace fn_f9476b2e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f9476b2e {
class RefObj_196220 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_196220 {
  public:
    Action_196220();
    virtual void Update();
    char pad[0x18];
};
class FireMissileAction_196220 : public Action_196220 {
  public:
    int mTarget;
    RefObj_196220* mObj;
    FireMissileAction_196220(int target, RefObj_196220* obj);
    virtual void Execute();
};
extern void* hulk_at_0041b414[];
class Ref_196270 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_196270 {
  public:
    void* vptr;
};
class FireMissileAction_196270 : public Action_196270 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_196270* m20;
    ~FireMissileAction_196270();
};
class Item_196640 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_196640 {
  public:
    char pad[0x50];
    Item_196640* item;
    void Set(Item_196640* p);
};


// 0x00196220 FUN_00196220 (72 B): matches/0x00196220.cpp
// sym: ??0FireMissileAction_196220@fn_f9476b2e@@QAE@HPAVRefObj_196220@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
FireMissileAction_196220::FireMissileAction_196220(int target, RefObj_196220* obj) {
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


// 0x00196270 FUN_00196270 (50 B): matches/0x00196270.cpp
// sym: ??1FireMissileAction_196270@fn_f9476b2e@@QAE@XZ
FireMissileAction_196270::~FireMissileAction_196270() {
    vptr = hulk_at_0041b414;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_196270 *)this)->FUN_002326a0();
}

} // namespace fn_f9476b2e

// 0x001962b0 FUN_001962b0 (882 B): equivalent/0x001962b0.cpp [wrapped: conflict: CProjectile; hulkfight::motion::ProjectileMissile]
// sym: ??0ProjectileMissile@motion@hulkfight@fn_001962b0@@QAE@PAUMissileCfg@3@H@Z @5d4705001ab3 @w3e0447f0b2e3
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_001962b0 {
// STATUS: equivalent (tools/equiv.py level 3: 19910 inputs, branch coverage 8/8)
// FUN_001962b0 @ 0x001962b0
// equiv-map: ?thunk_FUN_0027d410@Node@@QAEXPAUId64@@@Z = 0x001d6630
// equiv-map: ??0CProjectile@@QAE@XZ = 0x001b6800
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

struct V3_1962b0 {
    float x, y, z;
};

struct Mat4_1962b0 {
    float m[16];
    void FUN_0022b980();
};

struct Id64 {
    int lo;
    int hi;
};

struct MissileCfg {
    char pad0[0x18];
    Id64 id;            // 0x18
    char pad20[0x60 - 0x20];
    int f60;
    int f64;
    char pad68[0x70 - 0x68];
    float f70;
    char pad74;
    char b75;
    char pad76;
    char b77;
    int f78;
    int f7c;
    int f80;
    int f84;
    int f88;
    int f8c;
    float f90;
    char b94;
    char b95;
    char b96;
    char pad97;
    int f98;
    int f9c;
    float fa0;
    int fa4;
    char pada8[4];
    int fac;
    int fb0;
};

struct Rng_1962b0 {
    unsigned s0;
    unsigned s1;
};

struct Node {
    char pad0[8];
    char sub8[4];
    char pad0c[0xec - 0xc];
    int fec;
    char pad_f0[0x144 - 0xf0];
    char b144;
    char pad145[0x1d8 - 0x145];
    char b1d8;
    int FUN_001d6c70();
    int FUN_001d6b40();
    void thunk_FUN_0027d410(Id64 *id);
};

struct Mgr;

struct Factory_1962b0 {
    Node *FUN_001e4760(int name, char *buf, int a, Mat4_1962b0 *m, int b, int c, int d);
    int FUN_001dbfe0(char *buf);
    void FUN_001e3200(char *buf, int lo, int hi);
    void FUN_001dc230(int h, int mode);
};

struct Handle_1962b0 {
    void FUN_001eb7e0(void *p, void *q, int h, V3_1962b0 *zero, V3_1962b0 *up, V3_1962b0 pos, int mode);
};

struct Scene_1962b0 {
    Handle_1962b0 *FUN_000862e0();
};

struct World {
    char pad0[0xc];
    Factory_1962b0 *factory;   // 0xc
    char pad10[0x54 - 0x10];
    Scene_1962b0 *scene;       // 0x54
};

class CProjectile {
public:
    CProjectile();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

extern "C" Rng_1962b0 *__cdecl FUN_000964d0();
extern "C" int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);

namespace hulkfight {
namespace motion {

class ProjectileMissile : public CProjectile {
public:
    int f04[2];             // 0x04
    int f0c;
    char pad10[8];
    int f18;
    char b1c;
    char b1d;
    char b1e;
    char pad1f;
    int f20;
    int f24;
    char b28;
    char pad29[3];
    int f2c;
    int f30;
    int f34;
    char b38;
    char pad39[3];
    MissileCfg *cfg;        // 0x3c
    int h40;
    int f44;
    int f48;
    int f4c;
    int f50;
    char pad54[0xc];
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    float f74;
    int f78;
    int f7c;
    int f80;
    int f84;
    int f88;
    float f8c;
    int f90;
    int f94;
    int f98;
    int f9c;
    int fa0;
    char ba4;
    char pada5[3];
    int fa8;
    int fac;
    int fb0;
    int fb4;
    int fb8;
    int fbc;
    int fc0;
    int fc4;
    int fc8;
    int fcc;
    float fd0;
    int fd4;
    float fd8;
    ProjectileMissile(MissileCfg *src, hulk_intptr name);
};

}
}

hulkfight::motion::ProjectileMissile::ProjectileMissile(MissileCfg *src, hulk_intptr name)
{
    h40 = -1;
    f44 = 0;
    f48 = 0;
    f4c = 0;
    f50 = 0;
    f60 = 0;
    f64 = 0;
    f68 = 0;
    f6c = 0;
    f70 = 0;
    f74 = -1.0f;
    f78 = 0;
    f7c = 0;
    f84 = 0;
    f88 = 0;
    f8c = 0;
    f90 = 0;
    f94 = 0;
    f9c = 1;
    fa0 = 0;
    cfg = src;
    f0c = src->fb0;
    ba4 = src->b77;
    fb8 = src->f80;
    fa8 = src->f78;
    fac = src->f7c;
    fb4 = src->f88;
    fb0 = 0;
    fc8 = src->f98;
    fc4 = 0;
    fbc = 0;
    fcc = src->f9c;
    float t = src->fa0;
    fd0 = t;
    fd8 = t + *(float *)&fac;
    fd4 = src->f84;
    f98 = 0;
    b38 = src->b75;
    f18 = (int)(__int64)src->f90;
    b1c = src->b94;
    b1d = src->b95;
    b1e = src->b96;
    f20 = src->fa4;
    f24 = *(int *)&src->fa0;
    char flag = b1c;
    b28 = 0;
    f2c = src->fac;
    f30 = src->f8c;
    f34 = 0;
    int pick;
    if (flag != 0) {
        Rng_1962b0 *rng = FUN_000964d0();
        rng->s0 = (rng->s0 & 0xffff) * 0x9069 + (rng->s0 >> 16);
        rng->s1 = (rng->s1 & 0xffff) * 0x4650 + (rng->s1 >> 16);
        pick = (int)(__int64)(((rng->s0 << 16) + (rng->s1 & 0xffff)) % 3) - 1;
    } else {
        pick = f18;
    }
    fc0 = pick;
    Factory_1962b0 *factory = DAT_004dd700->factory;
    FUN_00267760(DAT_004e15d0, 0x100, "projectile_missile_%d", (*(int*)&DAT_004e16d0));
    (*(int*)&DAT_004e16d0) = (*(int*)&DAT_004e16d0) + 1;
    Mat4_1962b0 m;
    m.FUN_0022b980();
    Node *node = factory->FUN_001e4760(name, DAT_004e15d0, 0, &m, 0, 0, 0);
    if (node == 0) {
        h40 = factory->FUN_001dbfe0(DAT_004e15d0);
        if ((cfg->id.lo | cfg->id.hi) != 0)
            factory->FUN_001e3200(DAT_004e15d0, cfg->id.lo, cfg->id.hi);
    } else {
        h40 = node->FUN_001d6c70();
        hulk_intptr base = node->fec;
        node->b144 = 1;
        node->b1d8 = 1;
        V3_1962b0 zero;
        V3_1962b0 up;
        zero.x = 0;
        zero.y = 0;
        zero.z = 0;
        up.x = 0;
        up.y = 1.0f;
        up.z = 0;
        V3_1962b0 origin;
        origin.x = 0;
        origin.y = 0;
        origin.z = 0;
        Scene_1962b0 *scene = DAT_004dd700->scene;
        int h = node->FUN_001d6b40();
        Handle_1962b0 *hd = scene->FUN_000862e0();
        hd->FUN_001eb7e0(node->sub8, (char *)base + 8, h, &zero, &up, origin, 3);
        if ((cfg->id.lo | cfg->id.hi) != 0)
            node->thunk_FUN_0027d410(&cfg->id);
    }
    factory->FUN_001dc230(h40, 3);
    float v = cfg->f70;
    f7c = *(int *)&v;
    f80 = *(int *)&v;
    f84 = cfg->f60;
    f88 = cfg->f64;
    f8c = -1.0f;
}
} // namespace fn_001962b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00196630 hulkfight::motion::ProjectileMissile::vfunc_3 (4 B): matches/0x00196630.cpp
// sym: ?vfunc_3@ProjectileMissile@motion@hulkfight@@UAEPAXXZ
void* hulkfight::motion::ProjectileMissile::vfunc_3() {
    return (void*)((hulkfight::motion::ProjectileMissile*)((char*)this + 0x60));
}

namespace fn_f9476b2e {

// 0x00196640 FUN_00196640 (38 B): matches/0x00196640.cpp
// sym: ?Set@Owner_196640@fn_f9476b2e@@QAEXPAVItem_196640@2@@Z
void Owner_196640::Set(Item_196640* p) {
    if (p)
        p->A();
    if (item)
        item->B();
    item = p;
}

} // namespace fn_f9476b2e

// 0x00196670 FUN_00196670 (117 B): matches/0x00196670.cpp [wrapped: conflict: hulkfight::motion::FireBeamAction]
// sym: ??1FireBeamAction@motion@hulkfight@fn_00196670@@UAE@XZ
namespace fn_00196670 {
class Ref_196670 {
  public:
    virtual void Free();
    virtual void Rel();
};
class Del_196670 {
  public:
    virtual void Dtor(int f);
};
class Action_196670 {
  public:
    virtual ~Action_196670() throw();
    int b[6];
};
namespace hulkfight {
namespace motion {
class FireBeamAction : public Action_196670 {
  public:
    virtual ~FireBeamAction() throw();
    int i1c;
    Ref_196670* r20;
    char pad[0x10];
    Ref_196670* r34;
    Ref_196670* r38;
    char pad2[0x10];
    Ref_196670* r4c;
    char pad3[0x14];
    Ref_196670* r64;
    Del_196670* r68;
};
} // namespace motion
} // namespace hulkfight
inline void Rl(Ref_196670*& r) {
    if (r) {
        r->Rel();
        r = 0;
    }
}
hulkfight::motion::FireBeamAction::~FireBeamAction() throw() {
    Rl(r38);
    Rl(r34);
    Rl(r20);
    Rl(r4c);
    if (i1c)
        i1c = 0;
    Rl(r64);
    if (r68)
        r68->Dtor(1);
}
} // namespace fn_00196670


// 0x00197540 hulkfight::motion::FireBeamAction::vfunc_4 (196 B): equivalent/0x00197540.cpp [wrapped: conflict: World; hulkfight::motion::FireBeamAction]
// sym: ?vfunc_4@FireBeamAction@motion@hulkfight@fn_00197540@@UAEXXZ @94125230b9fd @wae591e789998
namespace fn_00197540 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// hulkfight::motion::FireBeamAction::vfunc_4 @ 0x00197540
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

struct Ref_197540 { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Beam_197540 { char pad[0x12c]; unsigned int value; };
struct Lookup_197540 { Beam_197540* FUN_00024280(unsigned int, unsigned int); };
struct Receiver_197540 { void FUN_0003ffa0(unsigned int, int); };
struct Intermediate_197540 { Receiver_197540* FUN_00059a30(); };
struct Source_197540 { Intermediate_197540* FUN_000592a0(); };
struct Effects_197540 { void FUN_0027ffb0(unsigned int); };
extern "C" Effects_197540* __cdecl FUN_0027f250();
struct Manager_197540 { void FUN_001e5720(Ref_197540*); };
struct World { char pad0[0xc]; Manager_197540* manager; char pad1[0x10]; Lookup_197540* lookup; };
struct Resources_197540 { char pad[8]; unsigned int first; unsigned int second; };
namespace hulkfight { namespace motion {
struct FireBeamAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
 char pad0[0x1c]; Source_197540* source;
 char pad1[0x28]; unsigned int fallback; Beam_197540* beam; char pad2[4]; unsigned int key1; unsigned int key2; char pad3[4]; Ref_197540* ref; Resources_197540* resources;
};
void FireBeamAction::vfunc_4() {
 if (!source) return;
 Receiver_197540* receiver = source->FUN_000592a0()->FUN_00059a30();
 if (!receiver) return;
 Lookup_197540* lookup = DAT_004dd700->lookup;
 beam = 0;
 if (lookup) beam = lookup->FUN_00024280(key1,key2);
 receiver->FUN_0003ffa0(beam ? beam->value : fallback,0);
 Effects_197540* effects = FUN_0027f250();
 if (effects) {
 if (resources && resources->first) effects->FUN_0027ffb0(resources->first);
 if (resources && resources->second) effects->FUN_0027ffb0(resources->second);
 }
 DAT_004dd700->manager->FUN_001e5720(ref);
 if (ref) { ref->vfunc_1(); ref = 0; }
}
}}
} // namespace fn_00197540
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

