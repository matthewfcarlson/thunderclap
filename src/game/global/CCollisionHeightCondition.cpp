// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004c020..0x0004c1c0 (kind game, layer game, confidence medium), dominant class CCollisionHeightCondition
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f685d77c {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f685d77c {} using namespace fn_f685d77c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f685d77c {
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
class CNameFlagConditionBase : public CCondition {
  public:
    char pad[12];
    CNameFlagConditionBase* vfunc_5(int);
};
class CCollisionHeightCondition_4c020 {
  public:
    void Fna_0027af50();
    void Fnb_002345b0();
};
void thunk_FUN_00267090(void*);
extern void* hulk_at_003f6d50[];
class CCondition_4c060 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CCollisionInterruptCondition : public CCondition_4c060 {
  public:
    CCollisionInterruptCondition* vfunc_5(signed char flags);
};
extern void* CCondition_4c090_vftable[];
class CCondition_4c090 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CCollisionHeightCondition : public CCondition_4c090 {
  public:
    CCollisionHeightCondition* vfunc_5(signed char flags);
};


// 0x0004c020 CNameFlagConditionBase::vfunc_5 (52 B): matches/0x0004c020.cpp
// sym: ?vfunc_5@CNameFlagConditionBase@fn_f685d77c@@QAEPAV12@H@Z
CNameFlagConditionBase* CNameFlagConditionBase::vfunc_5(int p) {
    CNameFlagConditionBase* s = this;
    *(void (**)())s = &vt_name;
    ((CCollisionHeightCondition_4c020*)((char*)s + 0x10))->Fna_0027af50();
    *(void (**)())s = &vt_cond;
    ((CCollisionHeightCondition_4c020*)s)->Fnb_002345b0();
    if (p & 1)
        thunk_FUN_00267090(s);
    return s;
}


// 0x0004c060 CCollisionInterruptCondition::vfunc_5 (36 B): matches/0x0004c060.cpp
// sym: ?vfunc_5@CCollisionInterruptCondition@fn_f685d77c@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CCollisionInterruptCondition* CCollisionInterruptCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0004c090 CCollisionHeightCondition::vfunc_5 (36 B): matches/0x0004c090.cpp
// sym: ?vfunc_5@CCollisionHeightCondition@fn_f685d77c@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CCollisionHeightCondition* CCollisionHeightCondition::vfunc_5(signed char flags) {
    *(void***)this = CCondition_4c090_vftable;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f685d77c

// 0x0004c0c0 CCollisionHeightCondition::vfunc_7 (217 B): equivalent/0x0004c0c0.cpp [wrapped: conflict: CCollisionHeightCondition]
// sym: ?vfunc_7@CCollisionHeightCondition@fn_0004c0c0@@UAE_NPAUContext@2@@Z @b34884153e45 @w4e52be5dbf0e
namespace fn_0004c0c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CCollisionHeightCondition::vfunc_7 @ 0x0004c0c0
struct CollisionData {
 char pad0[0x2c]; float velocity;
 char pad30[0x2c]; float time;
 char pad60[4]; float acceleration;
};
struct Context {
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual CollisionData* slot3();
};
extern "C++" __declspec(nothrow) bool __cdecl FUN_00018960(float, float, float);
struct CCollisionHeightCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
 virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
 virtual bool vfunc_7(Context*);
 char pad4[8]; unsigned comparison; float threshold;
};
bool CCollisionHeightCondition::vfunc_7(Context* context) {
 CollisionData* data = context->slot3();
 if (!data) return false;
 float height = data->time * data->velocity * 0.5f - data->time * data->acceleration * data->time * 0.125f;
 switch (comparison) {
 case 0: return height < threshold;
 case 1: return height <= threshold;
 case 2: return FUN_00018960(height, threshold, 0.00001f);
 case 3: return !FUN_00018960(height, threshold, 0.00001f);
 case 4: return height >= threshold;
 case 5: return height > threshold;
 default: return false;
 }
}
} // namespace fn_0004c0c0

