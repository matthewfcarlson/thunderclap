// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004b3f0..0x0004b4f0 (kind game, layer game, confidence medium), dominant class CAxisSpeedCondition
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f98a4a34 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f98a4a34 {} using namespace fn_f98a4a34;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f98a4a34 {
extern void* hulk_at_003f6d50[];
class CAxisCondition_4b3f0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CAxisSpeedCondition : public CAxisCondition_4b3f0 {
  public:
    CAxisSpeedCondition* vfunc_5(signed char flags);
};


// 0x0004b3f0 CAxisSpeedCondition::vfunc_5 (36 B): matches/0x0004b3f0.cpp
// sym: ?vfunc_5@CAxisSpeedCondition@fn_f98a4a34@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CAxisSpeedCondition* CAxisSpeedCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f98a4a34

// 0x0004b420 CAxisSpeedCondition::vfunc_9 (173 B): equivalent/0x0004b420.cpp [wrapped: conflict: CAxisSpeedCondition]
// sym: ?vfunc_9@CAxisSpeedCondition@fn_0004b420@@UAE_NPAXPAUAxisInput_4b420@2@@Z @0928de1d200d @wa37ad06799c0
namespace fn_0004b420 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// CAxisSpeedCondition::vfunc_9 @ 0x0004b420
extern "C++" __declspec(nothrow) bool __cdecl FUN_00018960(float, float, float);
struct AxisInput_4b420 { char pad[0x20]; float speed; };
struct CAxisSpeedCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual bool vfunc_9(void*, AxisInput_4b420*);
 char pad[0xc]; unsigned operation; float threshold;
};
bool CAxisSpeedCondition::vfunc_9(void*, AxisInput_4b420* input) {
 float value = input->speed * 57.2957763671875f;
 switch(operation) {
 case 0: return value < threshold;
 case 1: return value <= threshold;
 case 2: return FUN_00018960(value,threshold,0.00001f);
 case 3: return !FUN_00018960(value,threshold,0.00001f);
 case 4: return value >= threshold;
 case 5: return value > threshold;
 default: return false;
 }
}
} // namespace fn_0004b420

