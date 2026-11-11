// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00113ea0..0x00113f40 (kind game, layer game, confidence high), dominant class hulkfight::ai::DefendingCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_feed8707 {
#define TREE_TU_END }
namespace fn_feed8707 {} using namespace fn_feed8707;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_feed8707 {
class TrackFactoryTemplate_113ea0 {
  public:
    TrackFactoryTemplate_113ea0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00111ca0();
extern "C" char DAT_0040d9c4[];
class DefendingCondition {
  public:
    hulk_intptr vptr;
    char pad4[8];
    unsigned char flag;
    void Init_00234590(int);
};
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int hulk_at_0040e7fc;
struct ConditionFactoryTemplate_113f10 {
    void* m_vptr;
    void base1_dtor_0010c7f0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_feed8707

// 0x00113ea0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::DefendingCondition>::vfunc_1 (60 B): matches/0x00113ea0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VDefendingCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::DefendingCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_113ea0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_113ea0* t = new (mem) TrackFactoryTemplate_113ea0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00111ca0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_feed8707 {

// 0x00113ee0 fight::ConditionFactoryTemplate<hulkfight::ai::DefendingCondition>::vfunc_5 (44 B): matches/0x00113ee0.cpp
// sym: ?FactoryVfunc5@fn_feed8707@@YAPAXXZ
void* FactoryVfunc5() {
    DefendingCondition* p = (DefendingCondition*)FUN_0008d690((int)sizeof(DefendingCondition));
    if (p) {
        p->Init_00234590(0);
        p->vptr = ((hulk_intptr)DAT_0040d9c4);
        p->flag = 1;
        return p;
    }
    return 0;
}


// 0x00113f10 fight::ConditionFactoryTemplate<hulkfight::ai::DefendingCondition>::vfunc_2 (43 B): matches/0x00113f10.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_113f10@fn_feed8707@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_113f10::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040e7fc;
    base1_dtor_0010c7f0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_feed8707
