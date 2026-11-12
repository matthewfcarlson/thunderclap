// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016d610..0x0016d6c0 (kind game, layer game, confidence high), dominant class hulkfight::motion::VelocityAnimatedXZCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa51ea81 {
#define TREE_TU_END }
namespace fn_fa51ea81 {} using namespace fn_fa51ea81;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fa51ea81 {
class TrackFactoryTemplate_16d610 {
  public:
    TrackFactoryTemplate_16d610() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016b160();
extern "C" void* FUN_0008d690(unsigned int);
extern int hulk_at_004166f8;
class VelocityCondition_16d650 {
  public:
    hulk_intptr vt;
    char pad[8];
    int a;
    int b;
    void Init_00234590(int);
};
extern int hulk_at_00417584;
struct ConditionFactoryTemplate_16d690 {
    void* m_vptr;
    void base1_dtor_00165c50();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fa51ea81

// 0x0016d610 fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_1 (60 B): matches/0x0016d610.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VVelocityAnimatedXZCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16d610));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16d610* t = new (mem) TrackFactoryTemplate_16d610();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016b160();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016d650 fight::ConditionFactoryTemplate<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_5 (54 B): matches/0x0016d650.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VVelocityAnimatedXZCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_5() {
    VelocityCondition_16d650* p = (VelocityCondition_16d650*)FUN_0008d690((int)sizeof(VelocityCondition_16d650));
    if (p) {
        p->Init_00234590(0);
        p->vt = (hulk_intptr)&hulk_at_004166f8;
        p->a = 0;
        p->b = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fa51ea81 {

// 0x0016d690 fight::ConditionFactoryTemplate<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_2 (43 B): matches/0x0016d690.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16d690@fn_fa51ea81@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16d690::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00417584;
    base1_dtor_00165c50();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fa51ea81
