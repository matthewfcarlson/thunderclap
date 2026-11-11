// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00052540..0x000525e0 (kind game, layer game, confidence high), dominant class CIsGrappledCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f886958e {
#define TREE_TU_END }
namespace fn_f886958e {} using namespace fn_f886958e;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f886958e {
extern "C" char DAT_003f8628[];
typedef unsigned int u32_52540;
extern "C" void* __cdecl thunk_FUN_0008d690(unsigned int);
class Helper_52540 {
  public:
    void Init_002343b0();
};
class Init2 {
  public:
    void Init_0027b040(hulk_uintptr);
};
struct CIsGrappledCondition_52580 {
    virtual ~CIsGrappledCondition_52580();
    void init_00234590(int);
};
} // namespace fn_f886958e
void* operator new(size_t);
namespace fn_f886958e {
extern void* hulk_at_003f72bc;
extern void* hulk_at_003f8628[];
class ConditionFactory_525b0 {
  public:
    void Destroy_002343d0(); // FUN_00236d60, __thiscall, this in ecx
};
class ConditionFactoryTemplate_0525b0 : public ConditionFactory_525b0 {
  public:
    ConditionFactoryTemplate_0525b0* vfunc_5(signed char flags);
};

} // namespace fn_f886958e

// 0x00052540 fight::ConditionFactoryCasterTemplate<CIsGrappledCondition>::vfunc_1 (55 B): matches/0x00052540.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCIsGrappledCondition@@@fight@@UAEPAXPAX@Z
template <> void* fight::ConditionFactoryCasterTemplate<CIsGrappledCondition>::vfunc_1(void* __p0) { hulk_uintptr arg = (hulk_uintptr)__p0;

    void* p = thunk_FUN_0008d690(0x10);
    if (p) {
        ((Helper_52540*)p)->Init_002343b0();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003f8628);
        ((Init2*)((char*)p + 8))->Init_0027b040(arg);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00052580 fight::ConditionFactoryTemplate<CIsGrappledCondition>::vfunc_5 (40 B): matches/0x00052580.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCIsGrappledCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CIsGrappledCondition>::vfunc_5() {
    CIsGrappledCondition_52580* p = (CIsGrappledCondition_52580*)operator new(0x0c);
    if (p) {
        p->init_00234590(0);
        *(void**)p = &hulk_at_003f72bc;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f886958e {

// 0x000525b0 fight::ConditionFactoryTemplate<CIsGrappledCondition>::vfunc_2 (36 B): matches/0x000525b0.cpp
// sym: ?vfunc_5@ConditionFactoryTemplate_0525b0@fn_f886958e@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
ConditionFactoryTemplate_0525b0* ConditionFactoryTemplate_0525b0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f8628;
    Destroy_002343d0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f886958e
