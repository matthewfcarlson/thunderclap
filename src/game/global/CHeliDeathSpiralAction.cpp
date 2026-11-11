// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00017e00..0x00018570 (kind game, layer game, confidence high), dominant class CHeliDeathSpiralAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f0828742 {
#define TREE_TU_END }
namespace fn_f0828742 {} using namespace fn_f0828742;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f0828742 {
struct R_18540 {
    void call_00222970(void*, int);
};
extern void* __fastcall FUN_000592a0(void*);
extern "C" R_18540* __fastcall FUN_00059a40(void*);

} // namespace fn_f0828742

// 0x00017e00 CHeliDeathSpiralAction::vfunc_6 (875 B): equivalent/0x00017e00.cpp [wrapped: conflict: CHeliDeathSpiralAction]
// sym: ?vfunc_6@CHeliDeathSpiralAction@fn_00017e00@@UAE_NH@Z @a06e3e3871e9 @wb58f6e2082f0
namespace fn_00017e00 {
// STATUS: equivalent (tools/equiv.py level 3: 12000 inputs, branch coverage 24/24)
// CHeliDeathSpiralAction::vfunc_6 @ 0x00017e00
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
struct V3_17e00 {
    float x, y, z;
    float FUN_0022d110();
};

struct NameField_17e00 {
    void FUN_0027b040(const char *s);
};

struct Sub18_17e00 {
    void FUN_00221d20(float a);
    void FUN_0022be40(const V3_17e00 *v);
};

class JointDriver_17e00 {
public:
    virtual void v0();
    char pad4[4];
    NameField_17e00 name;
    char pad1[0x18 - 0x9];
    Sub18_17e00 s18;
    char pad2[0x70 - 0x19];
    JointDriver_17e00 *FUN_002248f0(int a);
};

struct Tracker_17e00 {
    void FUN_00222890(JointDriver_17e00 *o, float a, float b, float c, float d, float e, float f);
};

struct Mgr_17e00;

struct Player_17e00 {
    char pad0[0x10];
    Mgr_17e00 *mgr10;
    char pad14[0x8c - 0x14];
    float f8c;
    char pad90[0x334 - 0x90];
    Player_17e00 *other;
    float FUN_000354c0();
    bool FUN_00035660(V3_17e00 *out);
    bool FUN_00035550(V3_17e00 *out);
};

struct Mgr_17e00 {
    Player_17e00 *FUN_00059a30();
    Tracker_17e00 *FUN_00059a40();
    bool FUN_00059a50(V3_17e00 *out);
};

struct Holder_17e00 {
    Mgr_17e00 *FUN_000592a0();
};

struct Cfg_17e00 {
    char pad0[0x14];
    float f14;
    float f18;
    float f1c;
    char pad20[0x2c - 0x20];
    float f2c;
    float f30;
    float f34;
};

void *thunk_FUN_0008d690(unsigned int size);

class CHeliDeathSpiralAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int arg);
    virtual void vfunc_7();
    virtual void vfunc_8();
    char pad04[0x18];
    Holder_17e00 *f1c;
    Cfg_17e00 *f20;
    JointDriver_17e00 *f24;
    V3_17e00 v28;
    V3_17e00 v34;
    float f40;
    float f44;
};

bool CHeliDeathSpiralAction::vfunc_6(int arg)
{
    Mgr_17e00 *mgr = f1c->FUN_000592a0();
    Player_17e00 *pl = mgr->FUN_00059a30();
    Tracker_17e00 *tr = mgr->FUN_00059a40();
    if (tr == 0)
        return false;
    Cfg_17e00 *c0 = f20;
    float cf2c = c0->f2c;
    float cf30 = c0->f30;
    float cf34 = c0->f34;
    void *mem = thunk_FUN_0008d690((int)sizeof(JointDriver_17e00));
    JointDriver_17e00 *o = 0;
    if (mem)
        o = ((JointDriver_17e00 *)mem)->FUN_002248f0(0);
    f24 = o;
    o->name.FUN_0027b040("heliDeathSpiral");
    f24->v0();
    tr->FUN_00222890(f24, -1.0f, cf2c, 1.0f, cf30, cf34, -1.0f);

    V3_17e00 pos0;
    pos0.x = 0.0f;
    pos0.y = 0.0f;
    pos0.z = 0.0f;
    mgr->FUN_00059a50(&pos0);
    f24->s18.FUN_0022be40(&pos0);
    float ang = pl->FUN_000354c0();
    f24->s18.FUN_00221d20(ang);
    pl->FUN_00035660(&v34);

    Player_17e00 *other = pl->other;
    V3_17e00 a;
    V3_17e00 b;
    a.z = 0.0f;
    a.y = 0.0f;
    a.x = 0.0f;
    b.z = 0.0f;
    b.y = 0.0f;
    b.x = 0.0f;
    if (other) {
        other->mgr10->FUN_00059a50(&a);
        other->FUN_00035660(&b);
    }

    float k = f20->f14;
    V3_17e00 t = b;
    volatile V3_17e00 *w = (volatile V3_17e00 *)&v34;
    w->x = k * w->x;
    w->y = k * w->y;
    w->z = k * w->z;
    t.x = t.x * (1.0f - k);
    t.y = t.y * (1.0f - k);
    t.z = t.z * (1.0f - k);
    volatile V3_17e00 *tv = (volatile V3_17e00 *)&t;
    w->x = tv->x + w->x;
    w->y = tv->y + w->y;
    w->z = tv->z + w->z;

    f40 = pl->f8c;
    V3_17e00 c;
    pl->FUN_00035550(&c);
    c.y = 0.0f;
    c.FUN_0022d110();

    V3_17e00 d;
    d.x = t.x;
    d.y = 0.0f;
    d.z = t.z;
    float dlen = d.FUN_0022d110();
    float sign = -1.0f;
    if (!(d.z * c.z + d.x * c.x + d.y * c.y < 0.0f))
        sign = 1.0f;

    V3_17e00 e;
    e.x = pos0.x - a.x;
    e.y = 0.0f;
    e.z = pos0.z - a.z;
    float elen = e.FUN_0022d110();
    if (elen > 0.0f)
        f40 = sign / elen * dlen + f40;

    float lo = f20->f18;
    float hi = f20->f1c;
    if (f40 > 0.0f) {
        if (lo > f40)
            f40 = lo;
        if (hi > lo && f40 > hi)
            f40 = hi;
    } else {
        if (-lo < f40)
            f40 = -lo;
        if (hi > lo && -hi > f40)
            f40 = -hi;
    }
    v28.x = v34.x;
    v28.y = v34.y;
    v28.z = v34.z;
    f44 = pl->FUN_000354c0();
    return true;
}
} // namespace fn_00017e00


// 0x00018170 CHeliDeathSpiralAction::vfunc_7 (976 B): equivalent/0x00018170.cpp [wrapped: conflict: CHeliDeathSpiralAction]
// sym: ?vfunc_7@CHeliDeathSpiralAction@fn_00018170@@UAE_NM@Z @6dc4a302b535 @w36f232c01568
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00018170 {
// STATUS: equivalent (tools/equiv.py level 3: 3033 inputs, branch coverage 21/22; --wine 634 inputs)
// CHeliDeathSpiralAction::vfunc_7 @ 0x00018170
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

struct Vec3_18170 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Quat_18170 {
    float x, y, z, w;
    void FUN_0022b1c0(float angle);
    void FUN_0022b170(float angle, Vec3_18170 *axis);
};

void __cdecl FUN_00224d70(float angle, Vec3_18170 *v);
extern "C" void FUN_0022b080(Quat_18170 *out, Quat_18170 *a, Quat_18170 *b);

struct Xform_18170 {
    void FUN_0022be40(Vec3_18170 *pos);
    void FUN_00221cf0(Quat_18170 *q);
};

struct Target_18170 {
    char pad00[0x18];
    Xform_18170 xform;
};

struct Params {
    char pad00[0x20];
    float followRate;
    float gravity;
    float tilt;
};

struct Ground_18170 {
    float FUN_00099b70();
};

struct World {
    char pad00[8];
    Ground_18170 *ground;
};


struct Anchor_18170;

struct Other_18170 {
    char pad00[0x10];
    Anchor_18170 *anchor;
};

struct Fighter_18170 {
    char pad00[0x1d8];
    Vec3_18170 push;
    char pad1e4[0x334 - 0x1e4];
    Other_18170 *other;
    void FUN_000359c0(int mode);
    void FUN_000357e0();
    void FUN_00035660(Vec3_18170 *out);
};

struct Anchor_18170 {
    Fighter_18170 *FUN_00059a30();
    char FUN_00059a50(Vec3_18170 *out);
};

struct Owner_18170 {
    Anchor_18170 *FUN_000592a0();
};

class CHeliDeathSpiralAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(float dt);
    virtual void vfunc_8();
    char pad04[0x18];
    Owner_18170 *owner;
    Params *params;
    Target_18170 *target;
    Vec3_18170 goal;
    Vec3_18170 pos;
    float spin;
    float angle;
};

bool CHeliDeathSpiralAction::vfunc_7(float dt)
{
    if (target == 0) {
        return false;
    }
    Anchor_18170 *anchor = owner->FUN_000592a0();
    Fighter_18170 *f = anchor->FUN_00059a30();
    f->FUN_000359c0(3);
    pos.x = f->push.x + pos.x;
    pos.y = f->push.y + pos.y;
    pos.z = f->push.z + pos.z;
    f->FUN_000357e0();
    Vec3_18170 p;
    anchor->FUN_00059a50(&p);
    Vec3_18170 v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    f->FUN_00035660(&v);
    pos.y = v.y;
    Other_18170 *other = f->other;
    Vec3_18170 w;
    w.x = 0.0f;
    w.y = 0.0f;
    w.z = 0.0f;
    if (other != 0) {
        other->anchor->FUN_00059a50(&w);
    }
    hulk_freg ground = DAT_004dd700->ground->FUN_00099b70();
    if (p.y >= ground) {
        if (goal.y > 0.0f) {
            goal.y = 0.0f;
        }
        if (pos.y > 0.0f) {
            pos.y = 0.0f;
        }
    }
    goal.y = goal.y - dt * params->gravity;
    pos.y = pos.y - dt * params->gravity;

    Vec3_18170 c = pos;
    Vec3_18170 *bp = &pos;
    float rate = params->followRate;
    hulk_freg zx;
    hulk_freg zy;
    float zz;
    if (rate <= 0.0f) {
        zx = goal.x;
        zy = goal.y;
        zz = goal.z;
    } else {
        Vec3_18170 d;
        d.x = goal.x - c.x;
        d.y = goal.y - c.y;
        d.z = goal.z - c.z;
        float s = rate * dt;
        hulk_freg len = d.FUN_0022d110();
        if (len <= s) {
            zx = goal.x;
            zy = goal.y;
            zz = goal.z;
        } else {
            d.y = d.y * s;
            d.z = d.z * s;
            zx = d.x * s + c.x;
            zy = d.y + c.y;
            zz = d.z + c.z;
        }
    }
    bp->x = zx;
    bp->z = zz;
    bp->y = zy;
    Vec3_18170 pf;
    pf.x = p.x + pos.x * dt;   // the stored (float) position, reloaded
    pf.y = p.y + pos.y * dt;
    volatile float pz = zz * dt;   // stored (`fstp`) before the add, under both compilers
    pf.z = p.z + pz;
    target->xform.FUN_0022be40(&pf);
    float na = dt * spin + angle;
    angle = na;
    Quat_18170 q1;
    q1.FUN_0022b1c0(na);
    Quat_18170 q2;
    q2.x = 0.0f;
    q2.y = 0.0f;
    q2.z = 0.0f;
    q2.w = 1.0f;
    if (other != 0) {
        Vec3_18170 g;
        g.x = p.x - w.x;
        g.y = 0.0f;
        g.z = p.z - w.z;
        g.FUN_0022d110();
        FUN_00224d70(-1.5707964f, &g);
        float h = params->tilt;
        if (goal.y > pos.y) {
            float h2 = (goal.y - pos.y) * 0.033333335f;
            if (h2 <= 0.0f) {
                h = h * 0.5f;
            } else if (h2 < 1.0f) {
                h = (h + h * h2) * 0.5f;
            }
        } else {
            h = h * 0.5f;
        }
        q2.FUN_0022b170(h, &g);
    }
    Quat_18170 q3;
    FUN_0022b080(&q3, &q2, &q1);
    target->xform.FUN_00221cf0(&q3);
    return true;
}
} // namespace fn_00018170
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00018540 CHeliDeathSpiralAction::vfunc_4 (37 B): matches/0x00018540.cpp
// sym: ?vfunc_4@CHeliDeathSpiralAction@@UAEXXZ
// Same code shape as 0x00013b40 (propagated; names are from that function)
void CHeliDeathSpiralAction::vfunc_4() {
    void* a = FUN_000592a0((*(void * *)&this->f_1c));
    R_18540* b = FUN_00059a40(a);
    if (b)
        b->call_00222970((*(void * *)&this->f_24), 0);
}

