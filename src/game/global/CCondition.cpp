// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004adc0..0x0004b040 (kind game, layer game, confidence medium), dominant class CCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f441c847 {
#define TREE_TU_END }
namespace fn_f441c847 {} using namespace fn_f441c847;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f441c847 {
extern int* hulk_at_004dc580;
class CCondition_4ade0 {
  public:
    virtual int vfunc_0(int);
};
class Obj_4ae90 {
  public:
    Obj_4ae90* Fnb_00059a30();
    int Fnc_00035a90();
};
} // namespace fn_f441c847
extern "C" double __cdecl __floor_default(double);
namespace fn_f441c847 {
union FloatBits_4af40 { float f; unsigned u; };


// 0x0004adc0 FUN_0004adc0 (19 B): matches/0x0004adc0.cpp
// sym: ?FUN_0004adc0@fn_f441c847@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0004adc0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dc580), ((char*)&DAT_004dc584));
}

} // namespace fn_f441c847

// 0x0004ade0 CMotionClimbAngleCondition::vfunc_0 (16 B): matches/0x0004ade0.cpp
// sym: ?vfunc_0@CMotionClimbAngleCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CMotionClimbAngleCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc580;
    return p[index];
}


// 0x0004ae50 CIsHelicopterCondition::vfunc_0 (5 B): matches/0x0004ae50.cpp [wrapped: conflict: CCondition; CIsHelicopterCondition; fight::Condition; fight::Param]
// sym: ?vfunc_0@CIsHelicopterCondition@fn_0004ae50@@UAEHH@Z
namespace fn_0004ae50 {
// Same code shape as 0x00049c80 (propagated; names are from that function)
class CCondition {
  public:
    virtual int vfunc_0();
};
namespace fight {
class Condition {
  public:
    virtual int vfunc_3();
};
class Param {
  public:
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual int vfunc_4();
};
} // namespace fight
class CIsHelicopterCondition : public CCondition, public fight::Condition, public fight::Param {
  public:
    virtual int vfunc_0(int);
};
int CIsHelicopterCondition::vfunc_0(int) {
    return 0;
}
} // namespace fn_0004ae50

namespace fn_f441c847 {

// 0x0004ae90 CIsHelicopterCondition::vfunc_7 (26 B): matches/0x0004ae90.cpp
// sym: ?vfunc_7@fn_f441c847@@YGHPAVObj_4ae90@1@@Z
// Same code shape as 0x00049cc0 (propagated; names are from that function)
int __stdcall vfunc_7(Obj_4ae90* p) {
    p = ((Obj_4ae90 *)((owners::Object_592a0 *)p)->FUN_000592a0());
    p = p->Fnb_00059a30();
    return p->Fnc_00035a90();
}


// 0x0004af40 FUN_0004af40 (195 B): equivalent/0x0004af40.cpp
// sym: ?FUN_0004af40@fn_f441c847@@YAMMMM@Z @6c797ea45342 @w978850b95974
// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 10/10)
// FUN_0004af40 @ 0x0004af40
hulk_freg __cdecl FUN_0004af40(float a, float b, float x) {
    if (!(x < a) && !(x >= b)) return x;
    FloatBits_4af40 d; d.f = a-b; d.u &= 0x7fffffff;
    if (d.f <= (*(float*)&DAT_003f6b28)) return a;
    float width = b-a;
    double n = __floor_default((double)((x-a)/width));
    hulk_freg result = (hulk_freg)(x - n*width);
    d.f = result-b; d.u &= 0x7fffffff;
    if (d.f <= (*(float*)&DAT_003f6b28)) return a;
    d.f = result-a; d.u &= 0x7fffffff;
    if (d.f <= (*(float*)&DAT_003f6b28)) return a;
    return result;
}

} // namespace fn_f441c847

// 0x0004b010 CCondition::vfunc_5 (36 B): matches/0x0004b010.cpp [wrapped: conflict: CCondition]
// sym: ?vfunc_5@CCondition@fn_0004b010@@QAEPAV12@C@Z
namespace fn_0004b010 {
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* hulk_at_003f6d50[];

class Condition_4b010 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};

class CCondition : public Condition_4b010 {
  public:
    CCondition* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis_0008d330(void* p); // thunk_FUN_00267090

CCondition* CCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}
} // namespace fn_0004b010

