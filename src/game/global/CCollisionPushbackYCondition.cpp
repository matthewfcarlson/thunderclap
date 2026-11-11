// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004c2f0..0x0004c400 (kind game, layer game, confidence medium), dominant class CCollisionPushbackYCondition
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f8dc77cd {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f8dc77cd {} using namespace fn_f8dc77cd;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f8dc77cd {
extern void* CCondition_4c2f0_vftable[];
class CCondition_4c2f0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CCollisionPushbackYCondition : public CCondition_4c2f0 {
  public:
    CCollisionPushbackYCondition* vfunc_5(signed char flags);
};


// 0x0004c2f0 CCollisionPushbackYCondition::vfunc_5 (36 B): matches/0x0004c2f0.cpp
// sym: ?vfunc_5@CCollisionPushbackYCondition@fn_f8dc77cd@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CCollisionPushbackYCondition* CCollisionPushbackYCondition::vfunc_5(signed char flags) {
    *(void***)this = CCondition_4c2f0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f8dc77cd

// 0x0004c320 CCollisionPushbackYCondition::vfunc_7 (189 B): equivalent/0x0004c320.cpp [wrapped: conflict: CCollisionPushbackYCondition]
// sym: ?vfunc_7@CCollisionPushbackYCondition@fn_0004c320@@UAE_NPAUParams@2@@Z
namespace fn_0004c320 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CCollisionPushbackYCondition::vfunc_7 @ 0x0004c320
struct Obj_4c320 {
    char pad00[0x2c];
    float pushbackY;                // 0x2c
};

struct Params {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Obj_4c320 *GetObject();       // slot 3
};

extern "C++" __declspec(nothrow) bool FUN_00018960(float a, float b, float eps);

class CCollisionPushbackYCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(Params *params);
    char pad04[8];
    unsigned int op;                // 0x0c
    float threshold;                // 0x10
};

bool CCollisionPushbackYCondition::vfunc_7(Params *params)
{
    Obj_4c320 *obj = params->GetObject();
    if (!obj)
        return false;
    float value = obj->pushbackY;
    switch (op) {
    case 0:
        return value < threshold;
    case 1:
        return value <= threshold;
    case 2:
        return FUN_00018960(value, threshold, 1.0e-5f);
    case 3:
        return !FUN_00018960(value, threshold, 1.0e-5f);
    case 4:
        return value >= threshold;
    case 5:
        return value > threshold;
    }
    return false;
}
} // namespace fn_0004c320

