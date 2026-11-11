// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012adf0..0x0012ae90 (kind game, layer game, confidence high), dominant class hulkfight::ai::CanSeeTargetCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff34bed0 {
#define TREE_TU_END }
namespace fn_ff34bed0 {} using namespace fn_ff34bed0;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ff34bed0 {
class TrackFactoryTemplate_12adf0 {
  public:
    TrackFactoryTemplate_12adf0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001291d0();
extern "C" char DAT_0040ff54[];
class CanSeeTargetCondition_12ae30 {
  public:
    hulk_intptr vt;
    char pad[8];
    u8 a;
    u8 b;
    void Init_00234590(int);
};
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int hulk_at_00410b2c;
struct ConditionFactoryTemplate_12ae60 {
    void* m_vptr;
    void base1_dtor_00124280();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_ff34bed0

// 0x0012adf0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::CanSeeTargetCondition>::vfunc_1 (60 B): matches/0x0012adf0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCanSeeTargetCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::CanSeeTargetCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12adf0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_12adf0* t = new (mem) TrackFactoryTemplate_12adf0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001291d0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0012ae30 fight::ConditionFactoryTemplate<hulkfight::ai::CanSeeTargetCondition>::vfunc_5 (48 B): matches/0x0012ae30.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCanSeeTargetCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::CanSeeTargetCondition>::vfunc_5() {
    CanSeeTargetCondition_12ae30* p = (CanSeeTargetCondition_12ae30*)FUN_0008d690((int)sizeof(CanSeeTargetCondition_12ae30));
    if (p) {
        p->Init_00234590(0);
        p->a = 1;
        p->b = 1;
        p->vt = ((hulk_intptr)DAT_0040ff54);
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_ff34bed0 {

// 0x0012ae60 fight::ConditionFactoryTemplate<hulkfight::ai::CanSeeTargetCondition>::vfunc_2 (43 B): matches/0x0012ae60.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12ae60@fn_ff34bed0@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12ae60::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00410b2c;
    base1_dtor_00124280();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ff34bed0
