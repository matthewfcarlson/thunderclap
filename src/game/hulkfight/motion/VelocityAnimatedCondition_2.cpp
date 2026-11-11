// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016e380..0x0016e430 (kind game, layer game, confidence high), dominant class hulkfight::motion::VelocityAnimatedCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6db3ad8 {
#define TREE_TU_END }
namespace fn_f6db3ad8 {} using namespace fn_f6db3ad8;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f6db3ad8 {
class TrackFactoryTemplate_16e380 {
  public:
    TrackFactoryTemplate_16e380() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016be50();
extern "C" char DAT_004169d8[];
struct ConditionFactoryTemplate_nv_16e3c0 {
    void Init_00234590(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_004177b4;
struct ConditionFactoryTemplate_16e400 {
    void* m_vptr;
    void base1_dtor_001666f0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f6db3ad8

// 0x0016e380 fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedCondition>::vfunc_1 (60 B): matches/0x0016e380.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VVelocityAnimatedCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16e380));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16e380* t = new (mem) TrackFactoryTemplate_16e380();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016be50();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016e3c0 fight::ConditionFactoryTemplate<hulkfight::motion::VelocityAnimatedCondition>::vfunc_5 (54 B): matches/0x0016e3c0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VVelocityAnimatedCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::VelocityAnimatedCondition>::vfunc_5() {
    fight::ConditionFactoryTemplate<hulkfight::motion::VelocityAnimatedCondition>* p = (fight::ConditionFactoryTemplate<hulkfight::motion::VelocityAnimatedCondition>*)FUN_0008d690(0x14);
    if (p) {
        ((ConditionFactoryTemplate_nv_16e3c0*)(p))->Init_00234590(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_004169d8);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f6db3ad8 {

// 0x0016e400 fight::ConditionFactoryTemplate<hulkfight::motion::VelocityAnimatedCondition>::vfunc_2 (43 B): matches/0x0016e400.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16e400@fn_f6db3ad8@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16e400::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004177b4;
    base1_dtor_001666f0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f6db3ad8
