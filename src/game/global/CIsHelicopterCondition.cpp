// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000525e0..0x00052680 (kind game, layer game, confidence high), dominant class CIsHelicopterCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3c7b72f {
#define TREE_TU_END }
namespace fn_f3c7b72f {} using namespace fn_f3c7b72f;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f3c7b72f {
extern "C" char DAT_003f8644[];
class ConditionFactoryCaster_525e0 {
  public:
    virtual void V0();
    virtual void* V1(void*);
};
class HelicopterCondition {
  public:
    virtual void V0();
};
extern void* __cdecl Allocate_00263ea0(unsigned int);
class InitObj_525e0 {
  public:
    void Init_002343b0();
};
class SetupObj_525e0 {
  public:
};
struct CIsGrappledCondition_52620 {
    virtual ~CIsGrappledCondition_52620();
    void init_00234590(int);
};
} // namespace fn_f3c7b72f
void* operator new(size_t);
namespace fn_f3c7b72f {
extern void* hulk_at_003f7574;
extern void* hulk_at_003f8644[];
class ConditionFactory_52650 {
  public:
    void Destroy_002343d0(); // FUN_00236d60, __thiscall, this in ecx
};
class ConditionFactoryTemplate_052650 : public ConditionFactory_52650 {
  public:
    ConditionFactoryTemplate_052650* vfunc_5(signed char flags);
};

} // namespace fn_f3c7b72f

// 0x000525e0 fight::ConditionFactoryCasterTemplate<CIsHelicopterCondition>::vfunc_1 (55 B): matches/0x000525e0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCIsHelicopterCondition@@@fight@@UAEPAXPAX@Z
template <> void* fight::ConditionFactoryCasterTemplate<CIsHelicopterCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* p = Allocate_00263ea0(0x10);
    if (p) {
        ((InitObj_525e0*)p)->Init_002343b0();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003f8644);
        ((owners::Target_27b040 *)(((SetupObj_525e0*)((char*)p + 8))))->FUN_0027b040((hulk_uintptr)arg);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00052620 fight::ConditionFactoryTemplate<CIsHelicopterCondition>::vfunc_5 (40 B): matches/0x00052620.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCIsHelicopterCondition@@@fight@@UAEPAXXZ
// Same code shape as 0x00052580 (propagated; names are from that function)
template <> void* fight::ConditionFactoryTemplate<CIsHelicopterCondition>::vfunc_5() {
    CIsGrappledCondition_52620* p = (CIsGrappledCondition_52620*)operator new(0x0c);
    if (p) {
        p->init_00234590(0);
        *(void**)p = &hulk_at_003f7574;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f3c7b72f {

// 0x00052650 fight::ConditionFactoryTemplate<CIsHelicopterCondition>::vfunc_2 (36 B): matches/0x00052650.cpp
// sym: ?vfunc_5@ConditionFactoryTemplate_052650@fn_f3c7b72f@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
ConditionFactoryTemplate_052650* ConditionFactoryTemplate_052650::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f8644;
    Destroy_002343d0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f3c7b72f
