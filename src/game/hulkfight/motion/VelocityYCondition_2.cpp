// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016d560..0x0016d610 (kind game, layer game, confidence high), dominant class hulkfight::motion::VelocityYCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ffa13669 {
#define TREE_TU_END }
namespace fn_ffa13669 {} using namespace fn_ffa13669;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ffa13669 {
class TrackFactoryTemplate_16d560 {
  public:
    TrackFactoryTemplate_16d560() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016b0b0();
extern "C" char DAT_004166d8[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class VelocityYCondition_16d5a0 {
  public:
    virtual void dummy();
    int pad1;
    int pad2;
    int b;
    int c;
    VelocityYCondition_16d5a0(int);
};
extern int g_vftable_16d5e0;
struct ConditionFactoryTemplate_16d5e0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_ffa13669

// 0x0016d560 fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityYCondition>::vfunc_1 (60 B): matches/0x0016d560.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VVelocityYCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityYCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16d560));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16d560* t = new (mem) TrackFactoryTemplate_16d560();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016b0b0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016d5a0 fight::ConditionFactoryTemplate<hulkfight::motion::VelocityYCondition>::vfunc_5 (54 B): matches/0x0016d5a0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VVelocityYCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::VelocityYCondition>::vfunc_5() {
    VelocityYCondition_16d5a0* p = (VelocityYCondition_16d5a0*)FUN_0008d690((int)sizeof(VelocityYCondition_16d5a0));
    if (p) {
        p->VelocityYCondition_16d5a0::VelocityYCondition_16d5a0(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_004166d8);
        p->b = 0;
        p->c = 0;
        return (void*)(p);
    } else {
        return (void*)((VelocityYCondition_16d5a0*)0);
    }
}

namespace fn_ffa13669 {

// 0x0016d5e0 fight::ConditionFactoryTemplate<hulkfight::motion::VelocityYCondition>::vfunc_2 (43 B): matches/0x0016d5e0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16d5e0@fn_ffa13669@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16d5e0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_16d5e0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ffa13669
