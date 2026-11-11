// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001170b0..0x00117350 (kind game, layer game, confidence medium), dominant class hulkfight::ai::MotionBoostAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fac5522d {
#define TREE_TU_END }
namespace fn_fac5522d {} using namespace fn_fac5522d;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fac5522d {
class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_1170b0 {
  public:
    Action_1170b0();
    virtual void Fn();
    char pad[24];
};
struct Triple {
    int a;
    Ref* p;
    int b;
    Triple() : a(0), p(0), b(0) {}
    void Set(Ref* r) {
        if (r)
            r->AddRef();
        if (p)
            p->Release();
        p = r;
    }
};
class MotionBoostAction : public Action_1170b0 {
  public:
    MotionBoostAction(int, Ref*);
    virtual void Fn();
    Triple t;
    int c;
    int d;
    int e;
};
extern void* g_vftable_117100[];
class Ref_117100 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_117100 {
  public:
    void* vptr;
};
class MotionBoostAction_117100 : public Action_117100 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_117100* m20;
    Ref_117100* m24;
    ~MotionBoostAction_117100();
};


// 0x001170b0 FUN_001170b0 (80 B): matches/0x001170b0.cpp
// sym: ??0MotionBoostAction@fn_fac5522d@@QAE@HPAVRef@1@@Z
MotionBoostAction::MotionBoostAction(int x, Ref* r) : Action_1170b0() {
    t.a = x;
    t.Set(r);
    e = 0;
    d = 0;
    c = 0;
}


// 0x00117100 FUN_00117100 (69 B): matches/0x00117100.cpp
// sym: ??1MotionBoostAction_117100@fn_fac5522d@@QAE@XZ
MotionBoostAction_117100::~MotionBoostAction_117100() {
    vptr = g_vftable_117100;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_117100 *)this)->FUN_002326a0();
}

} // namespace fn_fac5522d

// 0x00117150 hulkfight::ai::MotionBoostAction::vfunc_5 (500 B): equivalent/0x00117150.cpp [wrapped: conflict: MotionBoostAction]
// sym: ?FUN_00117150@MotionBoostAction@fn_00117150@@QAEDHH@Z
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00117150 {
// STATUS: equivalent (tools/equiv.py level 3: 3038 inputs, branch coverage 29/30, incomplete)
// hulkfight::ai::MotionBoostAction::vfunc_5 @ 0x00117150
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

struct V3_117150 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    char FUN_0022d2b0(V3_117150 *p, float eps);
};

class RefCounted_117150 {
public:
    virtual void addRef();
    virtual void release();
};

struct ActionParams_117150 {
    char pad00[0x14];
    float limit;             // 0x14
    char pad18[0x24 - 0x18];
    unsigned int extra;      // 0x24
};

struct Camera {
    void FUN_00059a50(V3_117150 *out);
};

struct Other_117150 {
    char pad[0x1b0];
    int id;
};

struct Reg124_117150 {
    char pad00[0x11c];
    Other_117150 *other;            // 0x11c
    char pad120[0x12c - 0x120];
    RefCounted_117150 *target;      // 0x12c
};

struct Reg20_117150 {
    char pad[0x124];
    Reg124_117150 *p124;
};

struct World {
    char pad[0x20];
    Reg20_117150 *p20;
};


struct Pad_117150 {
    char pad00[0x10];
    Camera *camera;          // 0x10
    char pad14[0x11c - 0x14];
    Other_117150 *other;            // 0x11c
    char pad120[0x328 - 0x120];
    RefCounted_117150 *lock;        // 0x328
    char pad32c[0x2064 - 0x32c];
    float push[3];           // 0x2064
    unsigned int pushExtra;  // 0x2070
    char pad2074[0x20a8 - 0x2074];
    int f20a8;
    void FUN_0003ffa0(RefCounted_117150 *t, int flag);
};

struct Fighter_117150 {
    Pad_117150 *FUN_00059a30();
};

struct Owner20_117150 {
};

class MotionBoostAction {
public:
    virtual void v0();
    char pad04[0x1c - 4];
    ActionParams_117150 *params;    // 0x1c
    Owner20_117150 *owner;          // 0x20
    RefCounted_117150 *held;        // 0x24
    V3_117150 pos;                  // 0x28

    char FUN_00117150(int a, int b);
};


char MotionBoostAction::FUN_00117150(int a, int b)
{
    if (a != 0)
        return 1;
    if (owner == 0)
        return 0;

    if (!(DAT_004e0ca4 & 1))
        DAT_004e0ca4 |= 1;
    (*(V3_117150*)&DAT_004e0c98).z = 0.0f;
    (*(V3_117150*)&DAT_004e0c98).y = 0.0f;
    (*(V3_117150*)&DAT_004e0c98).x = 0.0f;
    if (pos.FUN_0022d2b0(((V3_117150*)&DAT_004e0c98), 1e-5f))
        return 0;

    Pad_117150 *pad = ((Fighter_117150 *)((owners::Object_592a0 *)owner)->FUN_000592a0())->FUN_00059a30();
    RefCounted_117150 *target = pad->lock;
    if (target == 0) {
        target = held;
        if (target == 0) {
            if (pad->f20a8 >= 0)
                return 1;
            if (pad->other == 0)
                return 1;
            Reg124_117150 *r = DAT_004dd700->p20->p124;
            if (r == 0)
                return 1;
            target = r->target;
            if (target == 0)
                return 1;
            if (r->other == 0)
                return 1;
            if (pad->other->id == r->other->id)
                return 1;
            pad->FUN_0003ffa0(target, 0);
        }
    }
    if (target != 0)
        target->addRef();
    if (held != 0)
        held->release();
    held = target;

    V3_117150 camPos;
    camPos.x = 0.0f;
    camPos.y = 0.0f;
    camPos.z = 0.0f;
    pad->camera->FUN_00059a50(&camPos);

    V3_117150 d;
    d.x = pos.x - camPos.x;
    d.y = pos.y - camPos.y;
    d.z = pos.z - camPos.z;
    float len = d.FUN_0022d110();
    float ex = d.x * -1.0f;
    ActionParams_117150 *pr = params;
    unsigned int extra = pr->extra;
    float ey = d.y * -1.0f;
    float ez = d.z * -1.0f;
    if (len < pr->limit)
        return 0;
    pad->push[0] = ex;
    pad->push[1] = ey;
    pad->push[2] = ez;
    pad->pushExtra = extra;
    ((owners::C_353d0 *)pad)->FUN_000353d0((const int *)(V3_117150 *)(&pos));
    return 1;
}
} // namespace fn_00117150
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

