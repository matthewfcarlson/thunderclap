// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00116c10..0x001170b0 (kind game, layer game, confidence medium), dominant class hulkfight::ai::MotionChaseAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fae0ed28 {
#define TREE_TU_END }
namespace fn_fae0ed28 {} using namespace fn_fae0ed28;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fae0ed28 {
class Other_116c10 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_116c10 {
  public:
    Action_116c10();
    virtual void X();
    char pad[0x18];
};
struct S_116c10 {
    int a;
    Other_116c10* b;
    int c;
    S_116c10() throw() {
        a = 0;
        b = 0;
        c = 0;
    }
};
class MotionChaseAction : public Action_116c10 {
  public:
    virtual void A();
    S_116c10 s;
    MotionChaseAction(int, Other_116c10*);
};
extern void* g_vftable_116c60[];
class Ref_116c60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_116c60 {
  public:
    void* vptr;
};
class MotionChaseAction_116c60 : public Action_116c60 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_116c60* m20;
    Ref_116c60* m24;
    ~MotionChaseAction_116c60();
};
struct Vec3_116cb0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Mount {
    char pad0[0x18];
    bool FUN_00059a50(Vec3_116cb0 *out);
};
struct Target_116cb0 : RefCounted {
    char pad04[0x3c];
    Vec3_116cb0 pos;
};
struct Slot1b0 {
    char pad0[0x1b0];
    int f1b0;
};
struct Hub124 {
    char pad0[0x11c];
    Slot1b0 *p11c;
    char pad120[0x12c - 0x120];
    void *p12c;
};
struct Hub20 {
    char pad0[0x124];
    Hub124 *p124;
};
} // namespace fn_fae0ed28
struct World {
    char pad0[0x20];
    Hub20 *p20;
};
namespace fn_fae0ed28 {
struct Stats {
    char pad0[0x10];
    Mount *mount;
    char pad14[0x11c - 0x14];
    Slot1b0 *p11c;
    char pad120[0x328 - 0x120];
    Target_116cb0 *target;
    char pad32c[0x2064 - 0x32c];
    Vec3_116cb0 aim;
    float f2070;
    char pad2074[0x20a8 - 0x2074];
    int f20a8;
    void FUN_0003ffa0(void *p, int v);
};
void *__fastcall FUN_000592a0(void *owner);
extern "C" Stats *__fastcall FUN_00059a30(void *x);
struct Tuning {
    char pad0[0x14];
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
};
} // namespace fn_fae0ed28
namespace hulkfight { namespace ai {
class MotionChaseAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a1, int a2);
    char pad04[0x18];
    Tuning *tuning;
    void *owner;
    RefCounted *held;
};
} }

namespace fn_fae0ed28 {

// 0x00116c10 FUN_00116c10 (79 B): matches/0x00116c10.cpp
// sym: ??0MotionChaseAction@fn_fae0ed28@@QAE@HPAVOther_116c10@1@@Z
MotionChaseAction::MotionChaseAction(int value, Other_116c10* other) {
    s.a = value;
    if (other)
        other->AddRef();
    if (s.b)
        s.b->Release();
    s.b = other;
}


// 0x00116c60 FUN_00116c60 (69 B): matches/0x00116c60.cpp
// sym: ??1MotionChaseAction_116c60@fn_fae0ed28@@QAE@XZ
MotionChaseAction_116c60::~MotionChaseAction_116c60() {
    vptr = g_vftable_116c60;
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
    ((fight::Action *)(Action_116c60 *)this)->FUN_002326a0();
}

} // namespace fn_fae0ed28

// 0x00116cb0 hulkfight::ai::MotionChaseAction::vfunc_5 (1017 B): equivalent/0x00116cb0.cpp
// sym: ?vfunc_5@MotionChaseAction@ai@hulkfight@@UAE_NHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20017 inputs, branch coverage 56/58, incomplete)
// hulkfight::ai::MotionChaseAction::vfunc_5 @ 0x00116cb0
namespace hulkfight { namespace ai {
bool MotionChaseAction::vfunc_5(int a1, int a2)
{
    if (a1 != 0)
        return true;
    if (owner == 0)
        return false;

    Stats *stats = FUN_00059a30(FUN_000592a0(owner));
    Target_116cb0 *target = stats->target;
    if (target == 0) {
        target = (Target_116cb0 *)held;
        if (target == 0) {
            if (stats->f20a8 >= 0)
                return true;
            Slot1b0 *s = stats->p11c;
            if (s == 0)
                return true;
            Hub124 *hub = DAT_004dd700->p20->p124;
            if (hub == 0)
                return true;
            void *other = hub->p12c;
            if (other == 0)
                return true;
            Slot1b0 *t = hub->p11c;
            if (t == 0)
                return true;
            if (s->f1b0 == t->f1b0)
                return true;
            stats->FUN_0003ffa0(other, 0);
            return true;
        }
    }
    target->AddRef();
    if (held != 0)
        held->Release();
    held = target;

    struct Frame {
        float f14;
        float f18;
        float height;
        Vec3_116cb0 a;
        Vec3_116cb0 d;
        Vec3_116cb0 q;
        Vec3_116cb0 p;
    } fr;
    fr.p = target->pos;
    fr.q.x = 0.0f;
    fr.q.y = 0.0f;
    fr.q.z = 0.0f;
    stats->mount->FUN_00059a50(&fr.q);

    fr.d.x = fr.p.x - fr.q.x;
    fr.d.y = 0.0f;
    fr.d.z = fr.p.z - fr.q.z;
    fr.height = -(fr.p.y - fr.q.y);
    float dist = fr.d.FUN_0022d110();

    Tuning *tn = tuning;
    fr.a.x = 0.0f;
    fr.a.y = 0.0f;
    fr.a.z = 0.0f;
    fr.f14 = tn->f14;
    fr.f18 = tn->f18;
    float x;
    if (dist < fr.f14) {
        fr.a.x = fr.d.x * -1.0f;
        fr.a.y = fr.d.y * -1.0f;
        fr.a.z = fr.d.z * -1.0f;
        x = tn->f24;
    } else if (dist > fr.f18) {
        fr.a = fr.d;
        x = tn->f24;
    } else {
        x = 0.0f;
    }
    float f20 = tn->f20;
    bool reread = false;
    if (fr.height < tn->f1c) {
        if (!(dist >= fr.f14) == false && dist <= fr.f18) {
            fr.a.y = 1.0f;
            reread = true;
        } else if (dist < fr.f14 && fr.f14 > 0.0f) {
            fr.a.y = 1.0f - (fr.f14 - dist) / fr.f14;
            reread = true;
        } else if (dist > fr.f18) {
            volatile float dbl = fr.f18 + fr.f18;
            if (dist < dbl && fr.f18 > 0.0f) {
                fr.a.y = (dbl - dist) / dbl;
                reread = true;
            } else {
                fr.a.y = 0.0f;
            }
        } else {
            fr.a.y = 0.0f;
        }
    } else if (fr.height > f20) {
        if (!(dist >= fr.f14) == false && dist <= fr.f18) {
            fr.a.y = -1.0f;
            reread = true;
        } else if (dist < fr.f14 && fr.f14 > 0.0f) {
            fr.a.y = (fr.f14 - dist) / fr.f14 - 1.0f;
            reread = true;
        } else if (dist > fr.f18) {
            volatile float dbl = fr.f18 + fr.f18;
            if (dist < dbl && fr.f18 > 0.0f) {
                fr.a.y = -((dbl - dist) / dbl);
                reread = true;
            } else {
                fr.a.y = 0.0f;
            }
        } else {
            fr.a.y = 0.0f;
        }
    }
    if (reread) {
        fr.a.FUN_0022d110();
        x = tuning->f24;
    }
    stats->aim = fr.a;
    stats->f2070 = x;
    return true;
}
} }

