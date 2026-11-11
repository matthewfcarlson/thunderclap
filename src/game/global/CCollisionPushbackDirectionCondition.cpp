// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004bf40..0x0004c020 (kind game, layer game, confidence medium), dominant class CCollisionPushbackDirectionCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f6628d26 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6628d26 {} using namespace fn_f6628d26;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f6628d26 {
extern void* hulk_at_003f6d50[];
class CCondition_4bf40 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CCollisionPushbackDirectionCondition : public CCondition_4bf40 {
  public:
    CCollisionPushbackDirectionCondition* vfunc_5(signed char flags);
};


// 0x0004bf40 CCollisionPushbackDirectionCondition::vfunc_5 (36 B): matches/0x0004bf40.cpp
// sym: ?vfunc_5@CCollisionPushbackDirectionCondition@fn_f6628d26@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CCollisionPushbackDirectionCondition* CCollisionPushbackDirectionCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f6628d26

// 0x0004bf70 CCollisionPushbackDirectionCondition::vfunc_7 (167 B): equivalent/0x0004bf70.cpp [wrapped: conflict: CCollisionPushbackDirectionCondition]
// sym: ?vfunc_7@CCollisionPushbackDirectionCondition@fn_0004bf70@@UAE_NPAUOwner_4bf70@2@@Z @8132bac26a40 @w5bbdd33f6732
namespace fn_0004bf70 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// CCollisionPushbackDirectionCondition::vfunc_7 @ 0x0004bf70
struct Fighter;

struct Actor_4bf70 {
    hulk_freg FUN_000354c0();
};

struct Target_4bf70 {
    char pad0[0x28];
    float x;                  // 0x28
    char pad2c[4];
    float y;                  // 0x30
};

struct Owner_4bf70 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Target_4bf70 *v3();
};

Fighter *__fastcall FUN_000592a0(Owner_4bf70 *owner);
extern "C" Actor_4bf70 *__fastcall FUN_00059a30(Fighter *f);
extern "C" hulk_freg __cdecl FUN_00224ea0(float a, float b);
extern "C" hulk_freg __cdecl FUN_00224fc0(float a, float b);

class CCollisionPushbackDirectionCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(Owner_4bf70 *owner);
    char pad04[8];
    float offset;             // 0xc
    float tolerance;          // 0x10
};

bool CCollisionPushbackDirectionCondition::vfunc_7(Owner_4bf70 *owner)
{
    Actor_4bf70 *actor = FUN_00059a30(FUN_000592a0(owner));
    Target_4bf70 *target = owner->v3();
    if (target == 0)
        return false;
    actor->FUN_000354c0();
    float dir = FUN_00224ea0(target->x, target->y);
    float cur = actor->FUN_000354c0() + offset;
    float diff = FUN_00224fc0(dir, cur);
    union {
        float f;
        unsigned int u;
    } a;
    a.f = diff;
    a.u &= 0x7fffffff;
    return tolerance * 0.5f > a.f;
}
} // namespace fn_0004bf70

