// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004d970..0x0004da80 (kind game, layer game, confidence medium), dominant class CCharacterFloatCondition
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f995c03d {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f995c03d {} using namespace fn_f995c03d;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f995c03d {
extern void* CCondition_4d970_vftable[];
class CCondition_4d970 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CCharacterFloatCondition : public CCondition_4d970 {
  public:
    CCharacterFloatCondition* vfunc_5(signed char flags);
};


// 0x0004d970 CCharacterFloatCondition::vfunc_5 (36 B): matches/0x0004d970.cpp
// sym: ?vfunc_5@CCharacterFloatCondition@fn_f995c03d@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CCharacterFloatCondition* CCharacterFloatCondition::vfunc_5(signed char flags) {
    *(void***)this = CCondition_4d970_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f995c03d

// 0x0004d9a0 CCharacterFloatCondition::vfunc_7 (190 B): equivalent/0x0004d9a0.cpp [wrapped: conflict: CCharacterFloatCondition]
// sym: ?vfunc_7@CCharacterFloatCondition@fn_0004d9a0@@UAE_NPAUContext@2@@Z
namespace fn_0004d9a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// CCharacterFloatCondition::vfunc_7 @ 0x0004d9a0
struct Character_4d9a0 { float get(); };
struct Handle_4d9a0 { Character_4d9a0* FUN_00059a30(); };
struct Context { Handle_4d9a0* FUN_000592a0(); };
extern "C++" __declspec(nothrow) bool __cdecl FUN_00018960(float, float, float);
struct CCharacterFloatCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(Context*);
 char pad[8];
 float (Character_4d9a0::*getter)();
 unsigned comparison;
 float threshold;
};
bool CCharacterFloatCondition::vfunc_7(Context* context) {
 Character_4d9a0* character = context->FUN_000592a0()->FUN_00059a30();
 float value = (character->*getter)();
 switch(comparison) {
 case 0: return value < threshold;
 case 1: return value <= threshold;
 case 2: return FUN_00018960(value, threshold, 0.00001f);
 case 3: return !FUN_00018960(value, threshold, 0.00001f);
 case 4: return value >= threshold;
 case 5: return value > threshold;
 default: return false;
 }
}
} // namespace fn_0004d9a0

