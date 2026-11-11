// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001399d0..0x0013e810 (kind game, layer game, confidence high), dominant class hulkfight::motion::AnimationVelocityScaledAction
#include "tree_prelude.h"
#include "compat/ptr.h"


// 0x0013d940 hulkfight::motion::AnimationVelocityScaledAction::vfunc_3 (1306 B): equivalent/0x0013d940.cpp [isolated: helper definitions (2 out-of-line function bodies); compile error C2027: use of undefined type 'fn_fa36bb23::Node']
// sym: ?vfunc_3@AnimationVelocityScaledAction@motion@hulkfight@fn_f2ea2d39@@UAEDHH@Z @ef7be189dab2 @w2b45b99a543e
#include "gen/owners.h"
namespace fn_f2ea2d39 {} using namespace fn_f2ea2d39;
namespace fn_f2ea2d39 {
// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 68/68)
// hulkfight::motion::AnimationVelocityScaledAction::vfunc_3 @ 0x0013d940
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {
extern World* DAT_004dd700;

struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*
extern Gfx* DAT_0052c2a8;

struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name
extern Singleton_4dd6ec* DAT_004dd6ec;
}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)


} // namespace fn_f2ea2d39
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_f2ea2d39 {

void *thunk_FUN_0008d690(unsigned int size);

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

namespace pure3d { class Animation; }

struct Id64_13d940 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af70(Id64_13d940 *src);
};

struct V3_13d940 {
    float x, y, z;
    hulk_freg FUN_00018990();
};

namespace choreo2 {
class Driver {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[4];
    Id64_13d940 id;
};

class AnimationDriver : public Driver {
public:
    char pad10[0x20 - 0x10];
    void *anim;
    char pad24[0x23c - 0x24];
    float speed;
};
}

struct Anim_13d940 {
    char pad0[8];
    Id64_13d940 id;
    char pad10[8];
    char b18;
};

struct AnimationDriver_13d940 : public choreo2::Driver {
    char pad10[0x20 - 0x10];
    struct Node *node;
    char pad24[0x224 - 0x24];
    char flagA;
    char flagB;
    char pad226[0x22c - 0x226];
    int e0;
    int e1;
    AnimationDriver_13d940 *FUN_00225950(void *h, Anim_13d940 *a);
    void FUN_002250e0(float v);
    void FUN_00225140(float v);
    void FUN_00225cf0(float v);
    void FUN_00225e00(float vres, float v, int e0, int e1);
    float FUN_00225b30();
    void FUN_002251d0(void *layers10, int e0, int e1, V3_13d940 *out);
    void FUN_002224a0(int v);
};

struct Node {
    char pad0[0x10];
    float f10;
    float f14;
};

struct Rig_13d940 {
    int FUN_0027b670(unsigned int lo, unsigned int hi);
};

struct Stats_13d940 {
    void FUN_00035660(V3_13d940 *out);
    hulk_freg FUN_00035690();
    float FUN_00035680();
    void FUN_000356c0(V3_13d940 *out);
    hulk_freg FUN_00035700();
    float FUN_000356f0();
};

class Owner_13d940;
struct Context { char pad[4]; };
Context *__fastcall FUN_000592a0(Owner_13d940 *owner);
Stats_13d940 *__fastcall FUN_00059a30(Context *ctx);

struct LayerSet_13d940 {
    char pad0[0x68];
    unsigned int count;
    char pad6c[0x10 - 0xc];
    Rig_13d940 *FUN_002226b0();
    choreo2::Driver *FUN_00222e20(unsigned int index);
    void FUN_00222890(AnimationDriver_13d940 *d, float dur, int a, float b, int c, int e, float f);
};
LayerSet_13d940 *__fastcall FUN_00059a40(Context *ctx);

extern "C" hulk_freg __cdecl FUN_00225be0(float c30, int e0, int e1, int z);
extern "C" hulk_freg __cdecl FUN_000964e0();
extern "C" double sqrt(double);

class Factory_13d940 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Anim_13d940 *f3(content::LoadInventory::DynamicCaster<pure3d::Animation> *caster, unsigned int lo, unsigned int hi);
};

struct Holder44_13d940 { Factory_13d940 *FUN_00203d70(); };
struct Holder28_13d940 { Holder44_13d940 *FUN_000862a0(); };
struct World { char pad0[0x54]; Holder28_13d940 *holder; };

class Owner_13d940 {
public:
    virtual void v0();
};

class Cfg_13d940 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    char pad04[0x14];
    unsigned int keyLo;   // 0x18
    unsigned int keyHi;   // 0x1c
    int mode20;
    char pad24[4];
    float f28;
    float f2c;
    float f30;
    float f34;
    float f38;
    int mode3c;
    Id64_13d940 id40;
    int i48;
    int i4c;
    int i50;
};

namespace hulkfight { namespace motion {

class AnimationVelocityScaledAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual char vfunc_3(int a0, int a1);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x18];
    Cfg_13d940 *cfg;       // 0x1c
    Owner_13d940 *owner;   // 0x20
    AnimationDriver_13d940 *player; // 0x24
};

struct Frame_13d940 {
    char caster[4];
    char pad4[28];
    V3_13d940 vec;
};

static float AbsF(float v)
{
    union { float f; unsigned int u; } b;
    b.f = v;
    b.u &= 0x7fffffff;
    return b.f;
}

char AnimationVelocityScaledAction::vfunc_3(int a0, int a1)
{
    if (owner == 0)
        return 0;
    Context *ctx = FUN_000592a0(owner);
    Stats_13d940 *stats = FUN_00059a30(ctx);
    LayerSet_13d940 *layers = FUN_00059a40(ctx);
    if (layers == 0)
        return 0;
    Rig_13d940 *h = layers->FUN_002226b0();
    unsigned int lo = cfg->keyLo;
    unsigned int hi = cfg->keyHi;
    Frame_13d940 f;
    Factory_13d940 *fa = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    Anim_13d940 *anim = fa->f3(new (f.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>, lo, hi);
    if (anim == 0)
        return 0;

    bool flagA;
    bool flagB;
    bool fresh = true;
    float foundSpeed = 0.0f;
    int mode = cfg->mode3c;
    if (mode == 2 || (mode == 0 && anim->b18 != 0)) {
        flagA = true;
        if (layers->count != 0) {
            unsigned int i = 0;
            do {
                choreo2::Driver *drv = layers->FUN_00222e20(i);
                if (drv->id.lo == lo && drv->id.hi == hi) {
                    choreo2::AnimationDriver *ad = dynamic_cast<choreo2::AnimationDriver *>(drv);
                    if (ad && ad->anim == (void *)anim) {
                        foundSpeed = ad->speed;
                        fresh = (foundSpeed < 0.0f);
                        break;
                    }
                }
                i++;
            } while (i < layers->count);
        }
    } else {
        flagA = false;
    }

    void *mem = thunk_FUN_0008d690(0x240);
    AnimationDriver_13d940 *p = 0;
    if (mem)
        p = ((AnimationDriver_13d940 *)mem)->FUN_00225950(h, anim);
    if (p)
        p->AddRef();
    if (player)
        player->Release();
    player = p;
    if (fresh) {
        flagB = true;
    } else {
        p->FUN_00225cf0(foundSpeed);
        flagB = false;
    }

    player->id.FUN_0027af70(&anim->id);
    player->FUN_002250e0(cfg->f34);
    if (cfg->f38 < cfg->f34)
        player->FUN_00225140(player->node->f10 - 1.0f);
    else
        player->FUN_00225140(cfg->f38);

    int e0 = player->e0;
    int e1 = player->e1;
    float q = player->node->f14;
    if (q < 0.0f)
        q = 1.0f;
    float adiff = AbsF(*(float *)&e1 - *(float *)&e0);
    double rate80 = (double)adiff / (double)q;
    volatile float rate = (float)rate80;
    float s = 0.0f;
    if (rate80 > 0.0) {
        f.vec.x = 0.0f;
        f.vec.y = 0.0f;
        f.vec.z = 0.0f;
        player->FUN_002251d0((char *)layers + 0x10, e0, e1, &f.vec);
        s = (float)(sqrt(f.vec.z * f.vec.z + f.vec.y * f.vec.y + f.vec.x * f.vec.x) / rate);
    }

    float val;
    switch (cfg->mode20) {
    case 0:
        f.vec.x = 0.0f;
        f.vec.y = 0.0f;
        f.vec.z = 0.0f;
        stats->FUN_00035660(&f.vec);
        val = f.vec.FUN_00018990();
        break;
    case 1:
        val = stats->FUN_00035690();
        break;
    case 2:
        val = stats->FUN_00035680();
        break;
    case 3:
        f.vec.x = 0.0f;
        f.vec.y = 0.0f;
        f.vec.z = 0.0f;
        stats->FUN_000356c0(&f.vec);
        val = f.vec.FUN_00018990();
        break;
    case 4:
        val = stats->FUN_00035700();
        break;
    case 5:
        val = stats->FUN_000356f0();
        break;
    default:
        val = 0.0f;
        break;
    }
    float v = val / s;
    Cfg_13d940 *c = cfg;
    if (v < c->f28)
        v = c->f28;
    if (c->f2c > 0.0f && v > c->f2c)
        v = c->f2c;

    unsigned int rlo = c->id40.lo;
    unsigned int rhi = c->id40.hi;
    if ((rlo | rhi) != 0) {
        int r = h->FUN_0027b670(rlo, rhi);
        if (r)
            player->FUN_002224a0(r);
    }

    int c48 = cfg->i48;
    int c4c = cfg->i4c;
    int c50 = cfg->i50;
    player->flagA = flagA;
    player->flagB = (cfg->mode3c == 3);
    float arg1 = cfg->v7();
    player->FUN_00225e00(arg1, v, e0, e1);
    float arg2 = player->FUN_00225b30();
    layers->FUN_00222890(player, arg2, c48, 1.0f, c4c, c50, -1.0f);

    float c30 = cfg->f30;
    float t;
    if (c30 < 0.0f) {
        int a0v = player->e0;
        float diff = *(float *)&player->e1 - *(float *)&a0v;
        t = FUN_000964e0() * diff + *(float *)&a0v;
        player->FUN_00225cf0(t);
    } else if (flagB) {
        int pe0 = player->e0;
        int pe1 = player->e1;
        t = FUN_00225be0(c30, pe0, pe1, 0);
        player->FUN_00225cf0(t);
    }
    return 1;
}

}}
} // namespace fn_f2ea2d39

