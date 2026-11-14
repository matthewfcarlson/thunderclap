// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004cde0..0x0004cfe0 (kind game, layer game, confidence medium), dominant class CLuaNumberCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_ff23caa7 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff23caa7 {} using namespace fn_ff23caa7;
namespace fn_ff23caa7 {
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
namespace fn_ff23caa7 { extern "C" char DAT_003f6d50[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ff23caa7 {
extern void* hulk_at_003f6d50[];
class CCondition_4cde0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CSmartPropStateCondition : public CCondition_4cde0 {
  public:
    CSmartPropStateCondition* vfunc_5(signed char flags);
};
extern void* CCondition_4ce10_vftable[];
class CCondition_4ce10 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CPropActorStateCondition : public CCondition_4ce10 {
  public:
    CPropActorStateCondition* vfunc_5(signed char flags);
};
extern void* CCondition_4ce40_vftable[];
class CCondition_4ce40 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CIsInvincibleCondition : public CCondition_4ce40 {
  public:
    CIsInvincibleCondition* vfunc_5(signed char flags);
};
extern void* CCondition_4ce70_vftable[];
class CCondition_4ce70 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CIsGrappledCondition : public CCondition_4ce70 {
  public:
    CIsGrappledCondition* vfunc_5(signed char flags);
};
extern void* CCondition_4cea0_vftable[];
class CCondition_4cea0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CGrappleSizeCondition : public CCondition_4cea0 {
  public:
    CGrappleSizeCondition* vfunc_5(signed char flags);
};
extern void* CCondition_4ced0_vftable[];
class CCondition_4ced0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CLuaNumberCondition : public CCondition_4ced0 {
  public:
    CLuaNumberCondition* vfunc_5(signed char flags);
};


// 0x0004cde0 CSmartPropStateCondition::vfunc_5 (36 B): matches/0x0004cde0.cpp
// sym: ?vfunc_5@CSmartPropStateCondition@fn_ff23caa7@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CSmartPropStateCondition* CSmartPropStateCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x0004ce10 CPropActorStateCondition::vfunc_5 (36 B): matches/0x0004ce10.cpp
// sym: ?vfunc_5@CPropActorStateCondition@fn_ff23caa7@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CPropActorStateCondition* CPropActorStateCondition::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_003f6d50);
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x0004ce40 CIsInvincibleCondition::vfunc_5 (36 B): matches/0x0004ce40.cpp
// sym: ?vfunc_5@CIsInvincibleCondition@fn_ff23caa7@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CIsInvincibleCondition* CIsInvincibleCondition::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_003f6d50);
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x0004ce70 CIsGrappledCondition::vfunc_5 (36 B): matches/0x0004ce70.cpp
// sym: ?vfunc_5@CIsGrappledCondition@fn_ff23caa7@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CIsGrappledCondition* CIsGrappledCondition::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_003f6d50);
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x0004cea0 CGrappleSizeCondition::vfunc_5 (36 B): matches/0x0004cea0.cpp
// sym: ?vfunc_5@CGrappleSizeCondition@fn_ff23caa7@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CGrappleSizeCondition* CGrappleSizeCondition::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_003f6d50);
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x0004ced0 CLuaNumberCondition::vfunc_5 (36 B): matches/0x0004ced0.cpp
// sym: ?vfunc_5@CLuaNumberCondition@fn_ff23caa7@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CLuaNumberCondition* CLuaNumberCondition::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_003f6d50);
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

} // namespace fn_ff23caa7

// 0x0004cf00 CLuaNumberCondition::vfunc_7 (200 B): equivalent/0x0004cf00.cpp [wrapped: conflict: CLuaNumberCondition]
// sym: ?vfunc_7@CLuaNumberCondition@fn_0004cf00@@UAE_NPAX@Z @048de5ccac3f @w2c8c9f97a30d
namespace fn_0004cf00 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CLuaNumberCondition::vfunc_7 @ 0x0004cf00
struct LuaState_4cf00 { hulk_freg FUN_001d2790(void* name); };
extern "C++" bool __cdecl FUN_00018960(float a,float b,float tolerance);
struct CLuaNumberCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(void*);
 char pad04[8]; unsigned operation; char name[64]; float threshold;
 LuaState_4cf00* FUN_001d4c90();
};
bool CLuaNumberCondition::vfunc_7(void*) {
 LuaState_4cf00* state=FUN_001d4c90();
 if(!state) return false;
 float value=state->FUN_001d2790(name);
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
} // namespace fn_0004cf00

