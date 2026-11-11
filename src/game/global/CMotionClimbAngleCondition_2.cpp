// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000583b0..0x00058460 (kind game, layer game, confidence high), dominant class CMotionClimbAngleCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fbf65e06 {
#define TREE_TU_END }
namespace fn_fbf65e06 {} using namespace fn_fbf65e06;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fbf65e06 {
class TrackFactoryTemplate_583b0 {
  public:
    TrackFactoryTemplate_583b0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000548b0();
extern "C" char DAT_003f7550[];
class CMotionClimbAngleCondition_583f0 {
  public:
    void Init(int);
    int w[6];
};
extern int g_vftable_58430;
struct ConditionFactoryTemplate_58430 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fbf65e06

// 0x000583b0 fight::ConditionFactoryCasterTemplate<CMotionClimbAngleCondition>::vfunc_1 (60 B): matches/0x000583b0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCMotionClimbAngleCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CMotionClimbAngleCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_583b0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_583b0* t = new (mem) TrackFactoryTemplate_583b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000548b0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x000583f0 fight::ConditionFactoryTemplate<CMotionClimbAngleCondition>::vfunc_5 (61 B): matches/0x000583f0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCMotionClimbAngleCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CMotionClimbAngleCondition>::vfunc_5() {
    CMotionClimbAngleCondition_583f0* p = (CMotionClimbAngleCondition_583f0*)operator new(sizeof(CMotionClimbAngleCondition_583f0));
    if (p) {
        p->Init(0);
        p->w[0] = ((hulk_intptr)DAT_003f7550);
        p->w[3] = 0;
        p->w[4] = 0x3fc90fdb;
        p->w[5] = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fbf65e06 {

// 0x00058430 fight::ConditionFactoryTemplate<CMotionClimbAngleCondition>::vfunc_2 (43 B): matches/0x00058430.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_58430@fn_fbf65e06@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_58430::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_58430;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fbf65e06
