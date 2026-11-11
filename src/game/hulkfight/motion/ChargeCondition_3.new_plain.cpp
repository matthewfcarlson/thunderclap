// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016c600..0x0016d360 (kind game, layer game, confidence high), dominant class hulkfight::motion::ChargeCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7af1011 {
#define TREE_TU_END }
namespace fn_f7af1011 {} using namespace fn_f7af1011;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f7af1011 {
class TrackFactoryTemplate_16d2b0 {
  public:
    TrackFactoryTemplate_16d2b0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016ade0();

} // namespace fn_f7af1011

// 0x0016d2b0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::ChargeCondition>::vfunc_1 (60 B): matches/0x0016d2b0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VChargeCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::ChargeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16d2b0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16d2b0* t = new (mem) TrackFactoryTemplate_16d2b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016ade0();
        return (void*)(t);
    }
    return (void*)(0);
}

