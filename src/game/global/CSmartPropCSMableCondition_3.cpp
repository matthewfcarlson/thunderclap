// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00058870..0x00058910 (kind game, layer game, confidence high), dominant class CSmartPropCSMableCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f76de4f7 {
#define TREE_TU_END }
namespace fn_f76de4f7 {} using namespace fn_f76de4f7;
namespace fn_f76de4f7 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f76de4f7 {
class TrackFactoryTemplate_58870 {
  public:
    TrackFactoryTemplate_58870() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00053c60();
extern int hulk_at_003f9658;
struct ConditionFactoryTemplate_588e0 {
    void* m_vptr;
    void base1_dtor_00049990();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f76de4f7

// 0x00058870 fight::ConditionFactoryCasterTemplate<CSmartPropCSMableCondition>::vfunc_1 (60 B): matches/0x00058870.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCSmartPropCSMableCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CSmartPropCSMableCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_58870));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_58870* t = new (mem) TrackFactoryTemplate_58870();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00053c60();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x000588b0 fight::ConditionFactoryTemplate<CSmartPropCSMableCondition>::vfunc_5 (47 B): matches/0x000588b0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_5@ConditionFactoryTemplate@fight@fn_000588b0@@UAEPAVCSmartPropCSMableCondition@3@XZ
namespace fn_000588b0 {

class CCondition_588b0 {
  public:
    virtual void f0();
    CCondition_588b0(int) throw();
    char pad[8];
};
class CSmartPropCSMableCondition : public CCondition_588b0 {
  public:
    CSmartPropCSMableCondition() throw();
    virtual void f0();
    int value;
};
CSmartPropCSMableCondition::CSmartPropCSMableCondition() throw() : CCondition_588b0(0) {
    value = 0;
}
namespace fight {
class ConditionFactoryTemplate {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual CSmartPropCSMableCondition* vfunc_5();
};
} // namespace fight
CSmartPropCSMableCondition* fight::ConditionFactoryTemplate::vfunc_5() {
    return new CSmartPropCSMableCondition;
}
} // namespace fn_000588b0

namespace fn_f76de4f7 {

// 0x000588e0 fight::ConditionFactoryTemplate<CSmartPropCSMableCondition>::vfunc_2 (43 B): matches/0x000588e0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_588e0@fn_f76de4f7@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_588e0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9658;
    base1_dtor_00049990();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f76de4f7
