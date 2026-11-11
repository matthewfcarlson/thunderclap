// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0015a790..0x0015a820 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitReactionTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0f2ff97 {
#define TREE_TU_END }
namespace fn_f0f2ff97 {} using namespace fn_f0f2ff97;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f0f2ff97 {
class TrackFactoryTemplate_15a790 {
  public:
    TrackFactoryTemplate_15a790() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00158700();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Track_15a7d0 {
    void* Init_0014de00();
};
extern int hulk_at_0041590c;

} // namespace fn_f0f2ff97

// 0x0015a790 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitReactionTrack>::vfunc_1 (60 B): matches/0x0015a790.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VHitReactionTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::HitReactionTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_15a790));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_15a790* t = new (mem) TrackFactoryTemplate_15a790();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00158700();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0015a7d0 fight::TrackFactoryTemplate<hulkfight::motion::HitReactionTrack>::vfunc_5 (24 B): matches/0x0015a7d0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VHitReactionTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00070420 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitReactionTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x48);
    if (p)
        return (void*)(((Track_15a7d0*)p)->Init_0014de00());
    return (void*)(0);
}

namespace fn_f0f2ff97 {

// 0x0015a7f0 fight::TrackFactoryTemplate<hulkfight::motion::HitReactionTrack>::vfunc_2 (43 B): matches/0x0015a7f0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f0f2ff97@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041590c;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f0f2ff97
