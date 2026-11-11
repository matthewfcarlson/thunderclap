// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018c0e0..0x0018c170 (kind game, layer game, confidence high), dominant class hulkfight::motion::BallAndChainSpinTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f733270e {
#define TREE_TU_END }
namespace fn_f733270e {} using namespace fn_f733270e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f733270e {
class TrackFactoryTemplate_18c0e0 {
  public:
    TrackFactoryTemplate_18c0e0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00188220();
extern "C" void* __cdecl operator_new(unsigned int);
extern int hulk_at_0041a828;

} // namespace fn_f733270e

// 0x0018c0e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainSpinTrack>::vfunc_1 (60 B): matches/0x0018c0e0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VBallAndChainSpinTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainSpinTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18c0e0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18c0e0* t = new (mem) TrackFactoryTemplate_18c0e0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00188220();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018c120 fight::TrackFactoryTemplate<hulkfight::motion::BallAndChainSpinTrack>::vfunc_5 (24 B): matches/0x0018c120.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VBallAndChainSpinTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x000704b0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::BallAndChainSpinTrack>::vfunc_5() {
    void* p = operator_new(0x34);
    if (p)
        return (void*)(Construct(p));
    return (void*)(0);
}

namespace fn_f733270e {

// 0x0018c140 fight::TrackFactoryTemplate<hulkfight::motion::BallAndChainSpinTrack>::vfunc_2 (43 B): matches/0x0018c140.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f733270e@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a828;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f733270e
