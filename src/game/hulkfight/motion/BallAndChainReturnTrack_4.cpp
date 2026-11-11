// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018c900..0x0018c990 (kind game, layer game, confidence high), dominant class hulkfight::motion::BallAndChainReturnTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3f355e9 {
#define TREE_TU_END }
namespace fn_f3f355e9 {} using namespace fn_f3f355e9;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f3f355e9 {
class TrackFactoryTemplate_18c900 {
  public:
    TrackFactoryTemplate_18c900() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0018a870();
typedef unsigned int u32_18c940;
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct CKeyPoseTrack_18c940 {
    hulk_uintptr init();
};
extern int g_vftable_18c960;

} // namespace fn_f3f355e9

// 0x0018c900 fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainReturnTrack>::vfunc_1 (60 B): matches/0x0018c900.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainReturnTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18c900));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18c900* t = new (mem) TrackFactoryTemplate_18c900();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0018a870();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018c940 fight::TrackFactoryTemplate<hulkfight::motion::BallAndChainReturnTrack>::vfunc_5 (24 B): matches/0x0018c940.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00077d00 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::BallAndChainReturnTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x78);
    if (p)
        return (void*)(((CKeyPoseTrack_18c940*)p)->init());
    return (void*)(0);
}

namespace fn_f3f355e9 {

// 0x0018c960 fight::TrackFactoryTemplate<hulkfight::motion::BallAndChainReturnTrack>::vfunc_2 (43 B): matches/0x0018c960.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f3f355e9@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_18c960;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f3f355e9
