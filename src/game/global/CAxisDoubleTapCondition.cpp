// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004b6f0..0x0004b850 (kind game, layer game, confidence medium), dominant class CAxisDoubleTapCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f92008b6 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f92008b6 {} using namespace fn_f92008b6;
namespace fn_f92008b6 {
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f92008b6 {
extern void* hulk_at_003f6d50[];
class CAxisCondition_4b6f0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CAxisDoubleTapCondition : public CAxisCondition_4b6f0 {
  public:
    CAxisDoubleTapCondition* vfunc_5(signed char flags);
};


// 0x0004b6f0 CAxisDoubleTapCondition::vfunc_5 (36 B): matches/0x0004b6f0.cpp
// sym: ?vfunc_5@CAxisDoubleTapCondition@fn_f92008b6@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CAxisDoubleTapCondition* CAxisDoubleTapCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

} // namespace fn_f92008b6

// 0x0004b720 CAxisDoubleTapCondition::vfunc_9 (277 B): equivalent/0x0004b720.cpp [wrapped: conflict: CAxisDoubleTapCondition]
// sym: ?vfunc_9@CAxisDoubleTapCondition@fn_0004b720@@UAE_NHPAUAxisEvent@2@@Z @8fabb6338cff @wec0867692ac0
namespace fn_0004b720 {
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 21/22, incomplete)
// CAxisDoubleTapCondition::vfunc_9 @ 0x0004b720
struct AxisEvent { char pad[0x14]; int value; char pad2[0x14]; int kind; int axis; float position; };
extern hulk_freg __cdecl FUN_00224fc0(int axis, int value);
extern "C++" __declspec(nothrow) bool __cdecl FUN_00018960(float a, float b, float tolerance);
struct CAxisDoubleTapCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual bool vfunc_9(int unused, AxisEvent* event);
 char pad[12]; unsigned comparison; float threshold; float lower; float upper;
};
bool CAxisDoubleTapCondition::vfunc_9(int unused, AxisEvent* event) {
 if(event->kind != 1) return false;
 if(lower < upper) {
 if(event->position < lower || event->position > upper) return false;
 }
 float value = FUN_00224fc0(event->axis, event->value);
 float limit = threshold * 0.5f;
 union { float f; unsigned u; } magnitude;
 magnitude.f=value; magnitude.u &= 0x7fffffff;
 switch(comparison) {
 case 0: return magnitude.f < limit;
 case 1: return magnitude.f <= limit;
 case 2: return FUN_00018960(magnitude.f, limit, 0.00001f);
 case 3: return !FUN_00018960(magnitude.f, limit, 0.00001f);
 case 4: return magnitude.f >= limit;
 case 5: return magnitude.f > limit;
 default: return false;
 }
}
} // namespace fn_0004b720

