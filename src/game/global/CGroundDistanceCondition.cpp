// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004bc70..0x0004be00 (kind game, layer game, confidence medium), dominant class CGroundDistanceCondition
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f0912206 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f0912206 {} using namespace fn_f0912206;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f0912206 {
extern void* hulk_at_003f6d50[];
class CCondition_4bc70 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CGroundDistanceCondition : public CCondition_4bc70 {
  public:
    CGroundDistanceCondition* vfunc_5(signed char flags);
};


// 0x0004bc70 CGroundDistanceCondition::vfunc_5 (36 B): matches/0x0004bc70.cpp
// sym: ?vfunc_5@CGroundDistanceCondition@fn_f0912206@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CGroundDistanceCondition* CGroundDistanceCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f0912206

// 0x0004bca0 CGroundDistanceCondition::vfunc_7 (324 B): equivalent/0x0004bca0.cpp [wrapped: conflict: CGroundDistanceCondition]
// sym: ?vfunc_7@CGroundDistanceCondition@fn_0004bca0@@UAEDPAX@Z @2114c0973ad1 @wbde10e678187
namespace fn_0004bca0 {
// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 14/16, incomplete)
// CGroundDistanceCondition::vfunc_7 @ 0x0004bca0
struct Vec3_4bca0 { float x, y, z; };

struct Fighter_4bca0 {
    char pad0[0x18];
    struct Body_4bca0 *body;
    char FUN_00059a50(Vec3_4bca0 *out);
};
struct Body_4bca0 { char pad[0x40]; Vec3_4bca0 pos; };

struct Actor_4bca0 {
    char pad[0x1a39];
    char grounded;
    char pad1a3a[0x1a48 - 0x1a3a];
    Vec3_4bca0 groundPos;
};

Fighter_4bca0 *__fastcall FUN_000592a0(void *owner);
extern "C" Actor_4bca0 *__fastcall FUN_00059a30(Fighter_4bca0 *f);
extern "C++" __declspec(nothrow) int __cdecl FUN_00018960(float a, float b, float c);

class CGroundDistanceCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual char vfunc_7(void *owner);
    char pad04[8];
    int mode;
    float threshold;
};

char CGroundDistanceCondition::vfunc_7(void *owner)
{
    Fighter_4bca0 *fighter = FUN_000592a0(owner);
    Actor_4bca0 *actor = FUN_00059a30(fighter);
    Vec3_4bca0 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    fighter->FUN_00059a50(&pos);
    Vec3_4bca0 ground = actor->groundPos;
    float floorY;
    if (actor->grounded)
        floorY = ground.y;
    else
        floorY = -10000.0f;
    float dist = pos.y - floorY;
    switch (mode) {
    case 0: return dist < threshold;
    case 1: return dist <= threshold;
    case 2: return (char)FUN_00018960(dist, threshold, 1e-5f);
    case 3: return (char)FUN_00018960(dist, threshold, 1e-5f) == 0;
    case 4: return dist >= threshold;
    case 5: return dist > threshold;
    }
    return 0;
}
} // namespace fn_0004bca0

