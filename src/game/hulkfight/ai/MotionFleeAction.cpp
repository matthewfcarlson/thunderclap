// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001178e0..0x00117ab0 (kind game, layer game, confidence medium), dominant class hulkfight::ai::MotionFleeAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fa726a27 {
#define TREE_TU_END }
namespace fn_fa726a27 {} using namespace fn_fa726a27;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fa726a27 {
class Other_1178e0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_1178e0 {
  public:
    Action_1178e0();
    virtual void X();
    char pad[0x18];
};
struct S_1178e0 {
    int a;
    Other_1178e0* b;
    int c;
    S_1178e0() throw() {
        a = 0;
        b = 0;
        c = 0;
    }
};
class MotionFleeAction : public Action_1178e0 {
  public:
    virtual void A();
    S_1178e0 s;
    MotionFleeAction(int, Other_1178e0*);
};
extern void* hulk_at_0040ed48[];
class Ref_117930 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_117930 {
  public:
    void* vptr;
};
class MotionFleeAction_117930 : public Action_117930 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_117930* m20;
    Ref_117930* m24;
    ~MotionFleeAction_117930();
};
struct Vec3_117980 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Refd_117980 {
    virtual void addRef();
    virtual void release();
    char pad[0x3c];
    Vec3_117980 pos;
};
struct Locator {
    void FUN_00059a50(Vec3_117980 *out);
};
struct Fighter_117980 {
    char pad0[0x10];
    Locator *locator;
    char pad1[0x328 - 0x14];
    Refd_117980 *target;
    char pad2[0x2064 - 0x32c];
    Vec3_117980 flee_dir;
    int flee_extra;
};
struct Owner_117980 {
    Fighter_117980 *FUN_00059a30();
};
struct Holder_117980 {
    Owner_117980 *FUN_000592a0();
};
struct Info_117980 {
    char pad[0x14];
    int value;
};
} // namespace fn_fa726a27
namespace hulkfight { namespace ai {
struct MotionFleeAction {
    char pad0[0x1c];
    Info_117980 *info;
    Holder_117980 *holder;
    Refd_117980 *cached;

    bool vfunc_5(int skip, int arg);
};
} }

namespace fn_fa726a27 {

// 0x001178e0 FUN_001178e0 (79 B): matches/0x001178e0.cpp
// sym: ??0MotionFleeAction@fn_fa726a27@@QAE@HPAVOther_1178e0@1@@Z
MotionFleeAction::MotionFleeAction(int value, Other_1178e0* other) {
    s.a = value;
    if (other)
        other->AddRef();
    if (s.b)
        s.b->Release();
    s.b = other;
}


// 0x00117930 FUN_00117930 (69 B): matches/0x00117930.cpp
// sym: ??1MotionFleeAction_117930@fn_fa726a27@@QAE@XZ
MotionFleeAction_117930::~MotionFleeAction_117930() {
    vptr = hulk_at_0040ed48;
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
    ((fight::Action *)(Action_117930 *)this)->FUN_002326a0();
}

} // namespace fn_fa726a27

// 0x00117980 hulkfight::ai::MotionFleeAction::vfunc_5 (300 B): equivalent/0x00117980.cpp
// sym: ?vfunc_5@MotionFleeAction@ai@hulkfight@@QAE_NHH@Z @c42ec8b2ad34 @wad3323eee1b9
// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 10/10)
// hulkfight::ai::MotionFleeAction::vfunc_5 @ 0x00117980
bool hulkfight::ai::MotionFleeAction::vfunc_5(int skip, int arg)
{
    if (skip == 0) {
        if (holder == 0)
            return false;
        Fighter_117980 *f = holder->FUN_000592a0()->FUN_00059a30();
        Refd_117980 *t = f->target;
        if (t == 0)
            t = cached;
        if (t != 0) {
            t->addRef();
            if (cached != 0)
                cached->release();
            cached = t;

            Vec3_117980 p = t->pos;
            Vec3_117980 q;
            q.x = 0.0f;
            q.y = 0.0f;
            q.z = 0.0f;
            f->locator->FUN_00059a50(&q);

            Vec3_117980 d;
            d.x = p.x - q.x;
            d.y = 0.0f;
            d.z = p.z - q.z;
            d.FUN_0022d110();

            f->flee_dir.x = d.x * -1.0f;
            f->flee_dir.y = d.y * -1.0f;
            f->flee_dir.z = d.z * -1.0f;
            f->flee_extra = info->value;
        }
    }
    return true;
}

