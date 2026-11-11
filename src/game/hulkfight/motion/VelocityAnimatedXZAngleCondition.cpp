// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016e030..0x0016e0e0 (kind game, layer game, confidence high), dominant class hulkfight::motion::VelocityAnimatedXZAngleCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ffe86028 {
#define TREE_TU_END }
namespace fn_ffe86028 {} using namespace fn_ffe86028;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ffe86028 {
class TrackFactoryTemplate_16e030 {
  public:
    TrackFactoryTemplate_16e030() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016bb80();
extern "C" char DAT_00416938[];
extern "C" void* __cdecl operator_new(unsigned int);
class Obj {
  public:
    Obj(int);
    hulk_uintptr vf;
    int a;
    int b;
    int c;
    unsigned int d;
};
extern int hulk_at_00417728;
struct ConditionFactoryTemplate_16e0b0 {
    void* m_vptr;
    void base1_dtor_001664e0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_ffe86028

// 0x0016e030 fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedXZAngleCondition>::vfunc_1 (60 B): matches/0x0016e030.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VVelocityAnimatedXZAngleCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedXZAngleCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16e030));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16e030* t = new (mem) TrackFactoryTemplate_16e030();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016bb80();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016e070 fight::ConditionFactoryTemplate<hulkfight::motion::VelocityAnimatedXZAngleCondition>::vfunc_5 (54 B): matches/0x0016e070.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VVelocityAnimatedXZAngleCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::VelocityAnimatedXZAngleCondition>::vfunc_5() {
    Obj* p = (Obj*)operator_new(0x14);
    if (p) {
        p->Obj::Obj(0);
        p->vf = ((hulk_intptr)DAT_00416938);
        p->c = 0;
        p->d = 0x3fc90fdb;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_ffe86028 {

// 0x0016e0b0 fight::ConditionFactoryTemplate<hulkfight::motion::VelocityAnimatedXZAngleCondition>::vfunc_2 (43 B): matches/0x0016e0b0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16e0b0@fn_ffe86028@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16e0b0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00417728;
    base1_dtor_001664e0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ffe86028
