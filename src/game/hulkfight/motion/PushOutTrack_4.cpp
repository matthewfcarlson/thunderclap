// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017f0f0..0x0017f180 (kind game, layer game, confidence high), dominant class hulkfight::motion::PushOutTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f336ca6e {
#define TREE_TU_END }
namespace fn_f336ca6e {} using namespace fn_f336ca6e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f336ca6e {
class TrackFactoryTemplate_17f0f0 {
  public:
    TrackFactoryTemplate_17f0f0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017d6a0();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Track_17f130 {
    void* Init_00170740();
};
extern int hulk_at_00419080;

} // namespace fn_f336ca6e

// 0x0017f0f0 fight::TrackFactoryCasterTemplate<hulkfight::motion::PushOutTrack>::vfunc_1 (60 B): matches/0x0017f0f0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VPushOutTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::PushOutTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17f0f0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_17f0f0* t = new (mem) TrackFactoryTemplate_17f0f0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017d6a0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017f130 fight::TrackFactoryTemplate<hulkfight::motion::PushOutTrack>::vfunc_5 (24 B): matches/0x0017f130.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VPushOutTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00070420 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PushOutTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x48);
    if (p)
        return (void*)(((Track_17f130*)p)->Init_00170740());
    return (void*)(0);
}

namespace fn_f336ca6e {

// 0x0017f150 fight::TrackFactoryTemplate<hulkfight::motion::PushOutTrack>::vfunc_2 (43 B): matches/0x0017f150.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f336ca6e@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00419080;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f336ca6e
