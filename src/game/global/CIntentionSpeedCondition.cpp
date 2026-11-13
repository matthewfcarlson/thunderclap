// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004da80..0x0004dc00 (kind game, layer game, confidence medium), dominant class CIntentionSpeedCondition
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_ff117ca4 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff117ca4 {} using namespace fn_ff117ca4;
namespace fn_ff117ca4 {
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
namespace fn_ff117ca4 { extern "C" char DAT_003f6d50[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ff117ca4 {
extern void* hulk_at_003f6d50[];
class CCondition_4da80 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CCharacterBoolCondition : public CCondition_4da80 {
  public:
    CCharacterBoolCondition* vfunc_5(signed char flags);
};
class CCondition {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
};
class CFightNodePrevCondition : public CCondition {
  public:
    char pad[12];
    CFightNodePrevCondition* vfunc_5(int);
};
class CIntentionSpeedCondition_4dab0 {
  public:
    void Fna_00234150();
    void Fnb_002345b0();
};
void thunk_FUN_00267090(void*);
extern void* CCondition_4daf0_vftable[];
class CCondition_4daf0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CIntentionSpeedCondition : public CCondition_4daf0 {
  public:
    CIntentionSpeedCondition* vfunc_5(signed char flags);
};


// 0x0004da80 CCharacterBoolCondition::vfunc_5 (36 B): matches/0x0004da80.cpp
// sym: ?vfunc_5@CCharacterBoolCondition@fn_ff117ca4@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CCharacterBoolCondition* CCharacterBoolCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x0004dab0 CFightNodePrevCondition::vfunc_5 (52 B): matches/0x0004dab0.cpp
// sym: ?vfunc_5@CFightNodePrevCondition@fn_ff117ca4@@QAEPAV12@H@Z
// Same code shape as 0x0004c020 (propagated; names are from that function)
CFightNodePrevCondition* CFightNodePrevCondition::vfunc_5(int p) {
    CFightNodePrevCondition* s = this;
    *(void (**)())s = &vt_name;
    ((CIntentionSpeedCondition_4dab0*)((char*)s + 0x10))->Fna_00234150();
    *(void (**)())s = &vt_cond;
    ((CIntentionSpeedCondition_4dab0*)s)->Fnb_002345b0();
    if (p & 1)
        thunk_FUN_00267090(s);
    return s;
}


// 0x0004daf0 CIntentionSpeedCondition::vfunc_5 (36 B): matches/0x0004daf0.cpp
// sym: ?vfunc_5@CIntentionSpeedCondition@fn_ff117ca4@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CIntentionSpeedCondition* CIntentionSpeedCondition::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_003f6d50);
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

} // namespace fn_ff117ca4

// 0x0004db20 CIntentionSpeedCondition::vfunc_7 (191 B): equivalent/0x0004db20.cpp [wrapped: conflict: CIntentionSpeedCondition]
// sym: ?vfunc_7@CIntentionSpeedCondition@fn_0004db20@@UAE_NPAUContext@2@@Z @c3f235ffd066 @w249547620292
namespace fn_0004db20 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// CIntentionSpeedCondition::vfunc_7 @ 0x0004db20
struct SpeedData { char pad[0x2070]; float speed; };
struct SpeedOwner { SpeedData* FUN_00059a30(); };
struct Context { SpeedOwner* FUN_000592a0(); };
extern "C++" __declspec(nothrow) bool __cdecl FUN_00018960(float, float, float);
struct CIntentionSpeedCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(Context*);
 char pad[8]; unsigned operation; float threshold;
};
bool CIntentionSpeedCondition::vfunc_7(Context* context) {
 float speed = context->FUN_000592a0()->FUN_00059a30()->speed;
 switch(operation) {
 case 0: return speed < threshold;
 case 1: return speed <= threshold;
 case 2: return FUN_00018960(speed, threshold, 0.00001f);
 case 3: return !FUN_00018960(speed, threshold, 0.00001f);
 case 4: return speed >= threshold;
 case 5: return speed > threshold;
 default: return false;
 }
}
} // namespace fn_0004db20

