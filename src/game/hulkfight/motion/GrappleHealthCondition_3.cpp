// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016dc30..0x0016dce0 (kind game, layer game, confidence high), dominant class hulkfight::motion::GrappleHealthCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc21461e {
#define TREE_TU_END }
namespace fn_fc21461e {} using namespace fn_fc21461e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fc21461e {
class TrackFactoryTemplate_16dc30 {
  public:
    TrackFactoryTemplate_16dc30() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016b7c0();
extern int g_vftable_16dcb0;
struct ConditionFactoryTemplate_16dcb0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fc21461e

// 0x0016dc30 fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleHealthCondition>::vfunc_1 (60 B): matches/0x0016dc30.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VGrappleHealthCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleHealthCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16dc30));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16dc30* t = new (mem) TrackFactoryTemplate_16dc30();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016b7c0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fc21461e {

// 0x0016dcb0 fight::ConditionFactoryTemplate<hulkfight::motion::GrappleHealthCondition>::vfunc_2 (43 B): matches/0x0016dcb0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16dcb0@fn_fc21461e@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16dcb0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_16dcb0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc21461e
