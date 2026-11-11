// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0011e100..0x0011e4a0 (kind game, layer game, confidence medium), dominant class hulkfight::ai::StrafeLateralHBAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f2baa6cd {
#define TREE_TU_END }
namespace fn_f2baa6cd {} using namespace fn_f2baa6cd;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f2baa6cd {
struct Ref_11e100 {
    virtual void AddRef();
    virtual void Release();
};
struct Action_11e100 {
    Action_11e100() throw();
    virtual void V0();
    char pad04[0x18];
};
struct StrafeLateralHBAction_11e100 : Action_11e100 {
    int m1c;
    Ref_11e100* m20;
    int m24;
    StrafeLateralHBAction_11e100(int a, Ref_11e100* r);
    virtual void V0();
};
extern void* hulk_at_0040f614[];
class Ref_11e150 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_11e150 {
  public:
    void* vptr;
};
class StrafeLateralHBAction_11e150 : public Action_11e150 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_11e150* m20;
    Ref_11e150* m24;
    ~StrafeLateralHBAction_11e150();
};
struct Vec3_11e1a0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
class RefCounted_11e1a0 {
public:
    virtual void AddRef();
    virtual void Release();
};
struct Mount_11e1a0 {
    char pad0[0x18];
    bool FUN_00059a50(Vec3_11e1a0 *out);
};
struct Target_11e1a0 : RefCounted_11e1a0 {
    char pad04[0x3c];
    Vec3_11e1a0 pos;
};
struct Stats_11e1a0 {
    char pad0[0x10];
    Mount_11e1a0 *mount;
    char pad14[0x328 - 0x14];
    Target_11e1a0 *target;
    char pad32c[0x2064 - 0x32c];
    Vec3_11e1a0 aim;
    float f2070;
    Vec3_11e1a0 dir;
    bool FUN_00035660(Vec3_11e1a0 *out);
};
void *__fastcall FUN_000592a0(void *owner);
extern "C" Stats_11e1a0 *__fastcall FUN_00059a30(void *x);
extern "C" hulk_freg FUN_00224f10(Vec3_11e1a0 *v);
extern "C" void FUN_00224d70(float angle, Vec3_11e1a0 *v);
struct Tuning_11e1a0 {
    char pad0[0x1c];
    float low;
    float high;
    float f24;
};
} // namespace fn_f2baa6cd
namespace hulkfight { namespace ai {
class StrafeLateralHBAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a1, int a2);
    char pad04[0x18];
    Tuning_11e1a0 *tuning;     // 0x1c
    void *owner;        // 0x20
    RefCounted_11e1a0 *held;   // 0x24
};
} }

namespace fn_f2baa6cd {

// 0x0011e100 FUN_0011e100 (79 B): matches/0x0011e100.cpp
// sym: ??0StrafeLateralHBAction_11e100@fn_f2baa6cd@@QAE@HPAURef_11e100@1@@Z
StrafeLateralHBAction_11e100::StrafeLateralHBAction_11e100(int a, Ref_11e100* r) {
    int* q = &m1c;
    *q = 0;
    m20 = 0;
    m24 = 0;
    m1c = a;
    if (r)
        r->AddRef();
    if (m20)
        m20->Release();
    m20 = r;
}


// 0x0011e150 FUN_0011e150 (69 B): matches/0x0011e150.cpp
// sym: ??1StrafeLateralHBAction_11e150@fn_f2baa6cd@@QAE@XZ
StrafeLateralHBAction_11e150::~StrafeLateralHBAction_11e150() {
    vptr = hulk_at_0040f614;
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
    ((fight::Action *)(Action_11e150 *)this)->FUN_002326a0();
}

} // namespace fn_f2baa6cd

// 0x0011e1a0 hulkfight::ai::StrafeLateralHBAction::vfunc_5 (754 B): equivalent/0x0011e1a0.cpp
// sym: ?vfunc_5@StrafeLateralHBAction@ai@hulkfight@@UAE_NHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 85 inputs, branch coverage 27/30, incomplete)
// hulkfight::ai::StrafeLateralHBAction::vfunc_5 @ 0x0011e1a0
namespace hulkfight { namespace ai {
bool StrafeLateralHBAction::vfunc_5(int a1, int a2)
{
    if (a1 != 0)
        return true;
    if (owner == 0)
        return false;

    Stats_11e1a0 *stats = FUN_00059a30(FUN_000592a0(owner));
    Target_11e1a0 *target = stats->target;
    if (target == 0) {
        target = (Target_11e1a0 *)held;
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
        Vec3_11e1a0 d;
        Vec3_11e1a0 q;
        Vec3_11e1a0 r;
        Vec3_11e1a0 p;
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

    if (dist < 7.0f) {
        double w = (double)dist * 0.14285715f * 1.5707964f;
        if (side < 0.0f)
            theta = theta - w;
        else
            theta = w + theta;
    } else if (dist > 20.0f) {
        double x;
        if (dist < 40.0f)
            x = ((double)dist - 20.0f) * 0.05f * 1.5707964f;
        else
            x = 1.5707964f;
        if (side < 0.0f)
            theta = x + theta;
        else
            theta = theta - x;
    }

    stats->aim = (*(Vec3_11e1a0*)&DAT_004a6ac0);
    FUN_00224d70(theta, &stats->aim);

    if (fr.height < tuning->low) {
        if (dist > 20.0f)
            stats->aim.y = 1.0f;
        else
            stats->aim.y = dist * 0.05f;
        stats->aim.FUN_0022d110();
    } else if (fr.height > tuning->high) {
        if (dist > 20.0f)
            stats->aim.y = -1.0f;
        else
            stats->aim.y = dist * -0.05f;
        stats->aim.FUN_0022d110();
    }

    stats->dir = fr.d;
    stats->f2070 = tuning->f24;
    return true;
}
} }

