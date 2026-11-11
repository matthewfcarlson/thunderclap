// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004c550..0x0004c660 (kind game, layer game, confidence medium), dominant class CCollisionStunTimeCondition
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fb02dbc9 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb02dbc9 {} using namespace fn_fb02dbc9;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fb02dbc9 {
extern void* hulk_at_003f6d50[];
class CCondition_4c550 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CCollisionStunTimeCondition : public CCondition_4c550 {
  public:
    CCollisionStunTimeCondition* vfunc_5(signed char flags);
};


// 0x0004c550 CCollisionStunTimeCondition::vfunc_5 (36 B): matches/0x0004c550.cpp
// sym: ?vfunc_5@CCollisionStunTimeCondition@fn_fb02dbc9@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CCollisionStunTimeCondition* CCollisionStunTimeCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fb02dbc9

// 0x0004c580 CCollisionStunTimeCondition::vfunc_7 (189 B): equivalent/0x0004c580.cpp [wrapped: conflict: CCollisionStunTimeCondition]
// sym: ?vfunc_7@CCollisionStunTimeCondition@fn_0004c580@@UAE_NPAUContext@2@@Z
namespace fn_0004c580 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CCollisionStunTimeCondition::vfunc_7 @ 0x0004c580
struct State_4c580 { char pad[0x68]; float stunTime; };
struct Context { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual State_4c580* slot3(); };
extern "C++" __declspec(nothrow) bool __cdecl FUN_00018960(float, float, float);
struct CCollisionStunTimeCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(Context*);
 char pad[8]; unsigned operation; float threshold;
};
bool CCollisionStunTimeCondition::vfunc_7(Context* context) {
 State_4c580* state = context->slot3();
 if (!state) return false;
 float time = state->stunTime;
 switch (operation) {
 case 0: return time < threshold;
 case 1: return time <= threshold;
 case 2: return FUN_00018960(time, threshold, 0.00001f);
 case 3: return !FUN_00018960(time, threshold, 0.00001f);
 case 4: return time >= threshold;
 case 5: return time > threshold;
 default: return false;
 }
}
} // namespace fn_0004c580

