// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00056ea0..0x00056f70 (kind game, layer game, confidence high), dominant class CAxisPressCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f85e45fc {
#define TREE_TU_END }
namespace fn_f85e45fc {} using namespace fn_f85e45fc;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f85e45fc {
class TrackFactoryTemplate_56ea0 {
  public:
    TrackFactoryTemplate_56ea0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern int g_vftable_56ee0;
struct ConditionFactoryTemplate_56ee0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};
} // namespace fn_f85e45fc
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_f85e45fc {
class BaseCondition {
  public:
    BaseCondition() throw();
    virtual void v0();
    char pad[28];
};
class CAxisPressCondition_56f10 : public BaseCondition {
  public:
    CAxisPressCondition_56f10() throw() : BaseCondition() {}
    virtual void v0();
};
extern void* CAxisValueCondition_56f40_vftable[];
class CAxisValueCondition_56f40 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f85e45fc
class CAxisPressCondition : public CAxisValueCondition_56f40 {
  public:
    CAxisPressCondition* vfunc_5(signed char flags);
};


// 0x00056ea0 fight::ConditionFactoryCasterTemplate<CAxisPressCondition>::vfunc_1 (60 B): matches/0x00056ea0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCAxisPressCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CAxisPressCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_56ea0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_56ea0* t = new (mem) TrackFactoryTemplate_56ea0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00052c40();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f85e45fc {

// 0x00056ee0 fight::ConditionFactoryTemplate<CAxisPressCondition>::vfunc_2 (43 B): matches/0x00056ee0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_56ee0@fn_f85e45fc@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_56ee0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_56ee0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f85e45fc

// 0x00056f10 fight::ConditionFactoryTemplate<CAxisPressCondition>::vfunc_5 (38 B): matches/0x00056f10.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCAxisPressCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CAxisPressCondition>::vfunc_5() {
    return (void*)(new CAxisPressCondition_56f10);
}


// 0x00056f40 CAxisPressCondition::vfunc_5 (36 B): matches/0x00056f40.cpp
// sym: ?vfunc_5@CAxisPressCondition@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CAxisPressCondition* CAxisPressCondition::vfunc_5(signed char flags) {
    *(void***)this = CAxisValueCondition_56f40_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

