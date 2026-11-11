// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016d360..0x0016d410 (kind game, layer game, confidence high), dominant class hulkfight::motion::TargetMotionStateCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6ea2069 {
#define TREE_TU_END }
namespace fn_f6ea2069 {} using namespace fn_f6ea2069;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f6ea2069 {
class TrackFactoryTemplate_16d360 {
  public:
    TrackFactoryTemplate_16d360() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016aee0();
extern "C" char DAT_00416678[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Temp_16d3a0 {
  public:
    virtual void V();
    char pad[8];
    int x;
    int y;
    void Init_00234590(int);
};
extern int hulk_at_00417514;
struct ConditionFactoryTemplate_16d3e0 {
    void* m_vptr;
    void base1_dtor_00165aa0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f6ea2069

// 0x0016d360 fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetMotionStateCondition>::vfunc_1 (60 B): matches/0x0016d360.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTargetMotionStateCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetMotionStateCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16d360));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16d360* t = new (mem) TrackFactoryTemplate_16d360();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016aee0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016d3a0 fight::ConditionFactoryTemplate<hulkfight::motion::TargetMotionStateCondition>::vfunc_5 (54 B): matches/0x0016d3a0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VTargetMotionStateCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::TargetMotionStateCondition>::vfunc_5() {
    Temp_16d3a0* p = (Temp_16d3a0*)FUN_0008d690((int)sizeof(Temp_16d3a0));
    if (p) {
        p->Init_00234590(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_00416678);
        p->x = 0;
        p->y = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f6ea2069 {

// 0x0016d3e0 fight::ConditionFactoryTemplate<hulkfight::motion::TargetMotionStateCondition>::vfunc_2 (43 B): matches/0x0016d3e0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16d3e0@fn_f6ea2069@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16d3e0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00417514;
    base1_dtor_00165aa0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f6ea2069
