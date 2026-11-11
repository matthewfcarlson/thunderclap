// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018c990..0x0018ca20 (kind game, layer game, confidence high), dominant class hulkfight::motion::BallAndChainShootTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fca894c8 {
#define TREE_TU_END }
namespace fn_fca894c8 {} using namespace fn_fca894c8;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fca894c8 {
class TrackFactoryTemplate_18c990 {
  public:
    TrackFactoryTemplate_18c990() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0018abd0();
typedef unsigned int U32_18c9d0;
struct Obj_18c9d0 {
    hulk_uintptr run();
};
extern int g_vftable_18c9f0;

} // namespace fn_fca894c8

// 0x0018c990 fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainShootTrack>::vfunc_1 (60 B): matches/0x0018c990.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainShootTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18c990));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18c990* t = new (mem) TrackFactoryTemplate_18c990();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0018abd0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018c9d0 fight::TrackFactoryTemplate<hulkfight::motion::BallAndChainShootTrack>::vfunc_5 (27 B): matches/0x0018c9d0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::BallAndChainShootTrack>::vfunc_5() {
    Obj_18c9d0* p = (Obj_18c9d0*)operator new(0x98);
    if (p)
        return (void*)(p->run());
    return (void*)(0);
}

namespace fn_fca894c8 {

// 0x0018c9f0 fight::TrackFactoryTemplate<hulkfight::motion::BallAndChainShootTrack>::vfunc_2 (43 B): matches/0x0018c9f0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fca894c8@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_18c9f0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fca894c8
