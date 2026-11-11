// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0011dd10..0x0011e100 (kind game, layer game, confidence medium), dominant class hulkfight::ai::StrafeCircleHBAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f5b65867 {
#define TREE_TU_END }
namespace fn_f5b65867 {} using namespace fn_f5b65867;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f5b65867 {
class Action_11dd10 {
  public:
    Action_11dd10();
    virtual void Fn();
    virtual void Release();
};
class StrafeCircleHBAction : public Action_11dd10 {
  public:
    char pad[0x1c - 4];
    int mArg;
    Action_11dd10* mObj;
    int mOther;
    StrafeCircleHBAction(int a, Action_11dd10* b);
};
extern void* g_vftable_11dd60[];
class Ref_11dd60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_11dd60 {
  public:
    void* vptr;
};
class StrafeCircleHBAction_11dd60 : public Action_11dd60 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_11dd60* m20;
    Ref_11dd60* m24;
    ~StrafeCircleHBAction_11dd60();
};
struct Vec3_11ddb0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
class RefCounted_11ddb0 {
public:
    virtual void AddRef();
    virtual void Release();
};
struct Mount_11ddb0 {
    char pad0[0x18];
    bool FUN_00059a50(Vec3_11ddb0 *out);
};
struct Target_11ddb0 : RefCounted_11ddb0 {
    char pad04[0x3c];
    Vec3_11ddb0 pos;
};
struct Stats_11ddb0 {
    char pad0[0x10];
    Mount_11ddb0 *mount;
    char pad14[0x328 - 0x14];
    Target_11ddb0 *target;
    char pad32c[0x2064 - 0x32c];
    Vec3_11ddb0 aim;
    float f2070;
    Vec3_11ddb0 dir;
    bool FUN_00035660(Vec3_11ddb0 *out);
};
void *__fastcall FUN_000592a0(void *owner);
extern "C" Stats_11ddb0 *__fastcall FUN_00059a30(void *x);
extern "C" hulk_freg FUN_00224f10(Vec3_11ddb0 *v);
extern "C" void FUN_00224d70(float angle, Vec3_11ddb0 *v);
struct Tuning_11ddb0 {
    char pad0[0x14];
    float inner;
    float outer;
    float low;
    float high;
    float f24;
};
} // namespace fn_f5b65867
namespace hulkfight { namespace ai {
class StrafeCircleHBAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a1, int a2);
    char pad04[0x18];
    Tuning_11ddb0 *tuning;     // 0x1c
    void *owner;        // 0x20
    RefCounted_11ddb0 *held;   // 0x24
};
} }

namespace fn_f5b65867 {

// 0x0011dd10 FUN_0011dd10 (79 B): matches/0x0011dd10.cpp
// sym: ??0StrafeCircleHBAction@fn_f5b65867@@QAE@HPAVAction_11dd10@1@@Z
StrafeCircleHBAction::StrafeCircleHBAction(int a, Action_11dd10* b) : Action_11dd10() {
    int* q = &mArg;
    *q = 0;
    mObj = 0;
    mOther = 0;
    mArg = a;
    if (b)
        b->Fn();
    if (mObj)
        mObj->Release();
    mObj = b;
}


// 0x0011dd60 FUN_0011dd60 (69 B): matches/0x0011dd60.cpp
// sym: ??1StrafeCircleHBAction_11dd60@fn_f5b65867@@QAE@XZ
StrafeCircleHBAction_11dd60::~StrafeCircleHBAction_11dd60() {
    vptr = g_vftable_11dd60;
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
    ((fight::Action *)(Action_11dd60 *)this)->FUN_002326a0();
}

} // namespace fn_f5b65867

// 0x0011ddb0 hulkfight::ai::StrafeCircleHBAction::vfunc_5 (833 B): equivalent/0x0011ddb0.cpp
// sym: ?vfunc_5@StrafeCircleHBAction@ai@hulkfight@@UAE_NHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 38/38)
// hulkfight::ai::StrafeCircleHBAction::vfunc_5 @ 0x0011ddb0
namespace hulkfight { namespace ai {
bool StrafeCircleHBAction::vfunc_5(int a1, int a2)
{
    if (a1 != 0)
        return true;
    if (owner == 0)
        return false;

    Stats_11ddb0 *stats = FUN_00059a30(FUN_000592a0(owner));
    Target_11ddb0 *target = stats->target;
    if (target == 0) {
        target = (Target_11ddb0 *)held;
        if (target == 0)
            return true;
    }
    target->AddRef();
    if (held != 0)
        held->Release();
    held = target;

    // The original keeps all of these in one contiguous stack frame; the stubs fill through
    // the pointers handed to callees, so the layout matters.
    struct {
        float side;
        float height;
        Vec3_11ddb0 d;
        Vec3_11ddb0 q;
        Vec3_11ddb0 r;
        Vec3_11ddb0 p;
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

    fr.r.x = 0.0f;
    fr.r.y = 0.0f;
    fr.r.z = 0.0f;
    stats->FUN_00035660(&fr.r);
    fr.r.y = 0.0f;
    fr.r.FUN_0022d110();

    float angleD = FUN_00224f10(&fr.d);
    float angleR = FUN_00224f10(&fr.r);
    fr.side = FUN_00224fc0(angleD, angleR);
    float side = FUN_00083d90(&fr.side);
    fr.side = side;

    float theta;
    if (side < 0.0f)
        theta = angleD - 1.5707964f;
    else
        theta = angleD + 1.5707964f;

    float inner = tuning->inner;
    float outer = tuning->outer;
    if (inner > 0.0f && dist < inner) {
        double w = dist / inner * 1.5707964f;
        if (side < 0.0f)
            theta = theta - w;
        else
            theta = w + theta;
    } else if (outer > 0.0f && dist > outer) {
        double x;
        if (outer + outer > dist)
            x = (dist - outer) / outer * 1.5707964f;
        else
            x = 1.5707964f;
        if (side < 0.0f)
            theta = x + theta;
        else
            theta = theta - x;
    }

    stats->aim = (*(Vec3_11ddb0*)&DAT_004a6ac0);
    FUN_00224d70(theta, &stats->aim);

    if (fr.height < tuning->low) {
        if (dist > outer || !(outer > 0.0f))
            stats->aim.y = 1.0f;
        else
            stats->aim.y = dist / outer;
        stats->aim.FUN_0022d110();
    } else if (fr.height > tuning->high) {
        if (dist > outer || !(outer > 0.0f))
            stats->aim.y = -1.0f;
        else
            stats->aim.y = -(dist / outer);
        stats->aim.FUN_0022d110();
    }

    stats->dir = fr.d;
    stats->f2070 = tuning->f24;
    return true;
}
} }

