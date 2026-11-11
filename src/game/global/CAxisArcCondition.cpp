// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004b600..0x0004b6f0 (kind game, layer game, confidence medium), dominant class CAxisArcCondition
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f9802d26 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9802d26 {} using namespace fn_f9802d26;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f9802d26 {
extern void* CAxisTimeCondition_4b600_vftable[];
class CAxisTimeCondition_4b600 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CAxisArcCondition : public CAxisTimeCondition_4b600 {
  public:
    CAxisArcCondition* vfunc_5(signed char flags);
};


// 0x0004b600 CAxisArcCondition::vfunc_5 (36 B): matches/0x0004b600.cpp
// sym: ?vfunc_5@CAxisArcCondition@fn_f9802d26@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CAxisArcCondition* CAxisArcCondition::vfunc_5(signed char flags) {
    *(void***)this = CAxisTimeCondition_4b600_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f9802d26

// 0x0004b630 CAxisArcCondition::vfunc_10 (160 B): equivalent/0x0004b630.cpp [wrapped: conflict: CAxisArcCondition]
// sym: ?vfunc_10@CAxisArcCondition@fn_0004b630@@UAE_NPAUAxisInput_4b630@2@PAH@Z
namespace fn_0004b630 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CAxisArcCondition::vfunc_10 @ 0x0004b630
// CAxisArcCondition::vfunc_10 @ 0x0004b630: compares the axis value against the stored limit with the configured test
extern "C++" __declspec(nothrow) bool FUN_00018960(float a, float b, float epsilon);

struct AxisInput_4b630 {
    char pad00[0x18];
    float value;
    int state;
};

class CAxisArcCondition {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual bool vfunc_10(AxisInput_4b630 *input, int *outState);
    char pad04[0x14];
    unsigned int mode;
    float limit;
};

bool CAxisArcCondition::vfunc_10(AxisInput_4b630 *input, int *outState)
{
    *outState = input->state;
    switch (mode) {
    case 0:
        return input->value < limit;
    case 1:
        return input->value <= limit;
    case 2:
        return FUN_00018960(input->value, limit, 1.0e-5f);
    case 3:
        return !FUN_00018960(input->value, limit, 1.0e-5f);
    case 4:
        return input->value >= limit;
    case 5:
        return input->value > limit;
    default:
        return false;
    }
}
} // namespace fn_0004b630

