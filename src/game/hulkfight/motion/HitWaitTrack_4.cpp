// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00159d30..0x00159de0 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitWaitTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fdcd66b6 {
#define TREE_TU_END }
namespace fn_fdcd66b6 {} using namespace fn_fdcd66b6;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fdcd66b6 {
class TrackFactoryTemplate_159d30 {
  public:
    TrackFactoryTemplate_159d30() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00155f80();
class HitWaitTrack_159d70 {
  public:
    virtual void V();
    int pad[2];
    int a;
    int b;
    HitWaitTrack_159d70();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_00414300;
extern int hulk_at_00415768;

} // namespace fn_fdcd66b6

// 0x00159d30 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitWaitTrack>::vfunc_1 (60 B): matches/0x00159d30.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VHitWaitTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::HitWaitTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_159d30));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_159d30* t = new (mem) TrackFactoryTemplate_159d30();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00155f80();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00159d70 fight::TrackFactoryTemplate<hulkfight::motion::HitWaitTrack>::vfunc_5 (52 B): matches/0x00159d70.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VHitWaitTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitWaitTrack>::vfunc_5() {
    HitWaitTrack_159d70* p = (HitWaitTrack_159d70*)FUN_0008d690((int)sizeof(HitWaitTrack_159d70));
    if (p) {
        p->HitWaitTrack_159d70::HitWaitTrack_159d70();
        *(hulk_intptr*)p = (hulk_intptr)&hulk_at_00414300;
        p->a = 0;
        p->b = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fdcd66b6 {

// 0x00159db0 fight::TrackFactoryTemplate<hulkfight::motion::HitWaitTrack>::vfunc_2 (43 B): matches/0x00159db0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fdcd66b6@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00415768;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fdcd66b6
