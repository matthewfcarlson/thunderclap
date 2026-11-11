// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00056dd0..0x00056ea0 (kind game, layer game, confidence high), dominant class CAxisDownCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fbb05a02 {
#define TREE_TU_END }
namespace fn_fbb05a02 {} using namespace fn_fbb05a02;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fbb05a02 {
class TrackFactoryTemplate_56dd0 {
  public:
    TrackFactoryTemplate_56dd0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern int g_vftable_56e10;
struct ConditionFactoryTemplate_56e10 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_003f9098[];
class CAxisDownCondition_56e40 {
  public:
    CAxisDownCondition_56e40();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern void* CAxisValueCondition_56e70_vftable[];
class CAxisValueCondition_56e70 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_fbb05a02
class CAxisDownCondition : public CAxisValueCondition_56e70 {
  public:
    CAxisDownCondition* vfunc_5(signed char flags);
};


// 0x00056dd0 fight::ConditionFactoryCasterTemplate<CAxisDownCondition>::vfunc_1 (60 B): matches/0x00056dd0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCAxisDownCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CAxisDownCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_56dd0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_56dd0* t = new (mem) TrackFactoryTemplate_56dd0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00052c40();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fbb05a02 {

// 0x00056e10 fight::ConditionFactoryTemplate<CAxisDownCondition>::vfunc_2 (43 B): matches/0x00056e10.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_56e10@fn_fbb05a02@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_56e10::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_56e10;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fbb05a02

// 0x00056e40 fight::ConditionFactoryTemplate<CAxisDownCondition>::vfunc_5 (38 B): matches/0x00056e40.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCAxisDownCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CAxisDownCondition>::vfunc_5() {
    CAxisDownCondition_56e40* p = (CAxisDownCondition_56e40*)FUN_0008d690(0x20);
    if (p) {
        p->CAxisDownCondition_56e40::CAxisDownCondition_56e40();
        *(void**)p = (void*)((hulk_intptr)DAT_003f9098);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00056e70 CAxisDownCondition::vfunc_5 (36 B): matches/0x00056e70.cpp
// sym: ?vfunc_5@CAxisDownCondition@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CAxisDownCondition* CAxisDownCondition::vfunc_5(signed char flags) {
    *(void***)this = CAxisValueCondition_56e70_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

