// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016db80..0x0016dc30 (kind game, layer game, confidence high), dominant class hulkfight::motion::TargetHealthPercentCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f14fa03b {
#define TREE_TU_END }
namespace fn_f14fa03b {} using namespace fn_f14fa03b;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f14fa03b {
class TrackFactoryTemplate_16db80 {
  public:
    TrackFactoryTemplate_16db80() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016b710();
extern "C" char DAT_00416838[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class TargetHealthPercentCondition_16dbc0 {
  public:
    void Init(int);
    hulk_uintptr vt;
    int pad[2];
    int a, b;
};
extern int g_vftable_16dc00;
struct ConditionFactoryTemplate_16dc00 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f14fa03b

// 0x0016db80 fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetHealthPercentCondition>::vfunc_1 (60 B): matches/0x0016db80.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTargetHealthPercentCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetHealthPercentCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16db80));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16db80* t = new (mem) TrackFactoryTemplate_16db80();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016b710();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016dbc0 fight::ConditionFactoryTemplate<hulkfight::motion::TargetHealthPercentCondition>::vfunc_5 (54 B): matches/0x0016dbc0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VTargetHealthPercentCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::TargetHealthPercentCondition>::vfunc_5() {
    TargetHealthPercentCondition_16dbc0* p = (TargetHealthPercentCondition_16dbc0*)FUN_0008d690((int)sizeof(TargetHealthPercentCondition_16dbc0));
    if (p) {
        p->Init(0);
        p->vt = ((hulk_intptr)DAT_00416838);
        p->a = 0;
        p->b = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f14fa03b {

// 0x0016dc00 fight::ConditionFactoryTemplate<hulkfight::motion::TargetHealthPercentCondition>::vfunc_2 (43 B): matches/0x0016dc00.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16dc00@fn_f14fa03b@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16dc00::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_16dc00;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f14fa03b
