// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004b2b0..0x0004b3f0 (kind game, layer game, confidence medium), dominant class CAxisTimeCondition
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f022e3e8 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f022e3e8 {} using namespace fn_f022e3e8;
namespace fn_f022e3e8 {
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
namespace fn_f022e3e8 { extern "C" char DAT_003f6d50[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f022e3e8 {
extern void* hulk_at_003f6d50[];
class CControllerCondition_4b2b0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CAxisCondition : public CControllerCondition_4b2b0 {
  public:
    CAxisCondition* vfunc_5(signed char flags);
};
extern void* CAxisCondition_4b2e0_vftable[];
class CAxisCondition_4b2e0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CAxisTimeCondition : public CAxisCondition_4b2e0 {
  public:
    CAxisTimeCondition* vfunc_5(signed char flags);
};


// 0x0004b2b0 CAxisCondition::vfunc_5 (36 B): matches/0x0004b2b0.cpp
// sym: ?vfunc_5@CAxisCondition@fn_f022e3e8@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CAxisCondition* CAxisCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x0004b2e0 CAxisTimeCondition::vfunc_5 (36 B): matches/0x0004b2e0.cpp
// sym: ?vfunc_5@CAxisTimeCondition@fn_f022e3e8@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CAxisTimeCondition* CAxisTimeCondition::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_003f6d50);
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

} // namespace fn_f022e3e8

// 0x0004b310 CAxisTimeCondition::vfunc_9 (197 B): equivalent/0x0004b310.cpp [wrapped: conflict: CAxisTimeCondition]
// sym: ?vfunc_9@CAxisTimeCondition@fn_0004b310@@UAE_NHPAUAxisInput_4b310@2@@Z @d5ceca3c2941 @w83b705e90fdc
namespace fn_0004b310 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CAxisTimeCondition::vfunc_9 @ 0x0004b310
extern "C++" __declspec(nothrow) bool __cdecl FUN_00018960(float, float, float);
struct AxisInput_4b310 { int unknown; float time; };
struct CAxisTimeCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual bool vfunc_9(int, AxisInput_4b310*); virtual bool FUN_00344f51(AxisInput_4b310*, float*);
 char pad[12]; unsigned comparison; float threshold;
};
bool CAxisTimeCondition::vfunc_9(int unused, AxisInput_4b310* input) {
 float value=input->time;
 if(!FUN_00344f51(input,&value)) return false;
 switch(comparison) {
 case 0: return value < threshold;
 case 1: return value <= threshold;
 case 2: return FUN_00018960(value,threshold,0.00001f);
 case 3: return !FUN_00018960(value,threshold,0.00001f);
 case 4: return value >= threshold;
 case 5: return value > threshold;
 default: return false;
 }
}
} // namespace fn_0004b310

