// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00159c70..0x00159d30 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitPauseTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fceda07a {
#define TREE_TU_END }
namespace fn_fceda07a {} using namespace fn_fceda07a;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fceda07a {
class TrackFactoryTemplate_159c70 {
  public:
    TrackFactoryTemplate_159c70() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00155ea0();
extern "C" char DAT_004142a0[];
class HitPauseTrack_159cb0 {
  public:
    virtual void A();
    virtual void B();
    HitPauseTrack_159cb0();
};
extern "C" void* __cdecl operator_new(unsigned int);
extern int g_vftable_159d00;

} // namespace fn_fceda07a

// 0x00159c70 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitPauseTrack>::vfunc_1 (60 B): matches/0x00159c70.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VHitPauseTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::HitPauseTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_159c70));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_159c70* t = new (mem) TrackFactoryTemplate_159c70();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00155ea0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00159cb0 fight::TrackFactoryTemplate<hulkfight::motion::HitPauseTrack>::vfunc_5 (66 B): matches/0x00159cb0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VHitPauseTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitPauseTrack>::vfunc_5() {
    HitPauseTrack_159cb0* p = (HitPauseTrack_159cb0*)operator_new(0x18);
    if (p) {
        p->HitPauseTrack_159cb0::HitPauseTrack_159cb0();
        int* q = (int*)p;
        q[0] = ((hulk_intptr)DAT_004142a0);
        q[3] = 0;
        q[4] = 0;
        q[5] = 0;
        q[2] = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fceda07a {

// 0x00159d00 fight::TrackFactoryTemplate<hulkfight::motion::HitPauseTrack>::vfunc_2 (43 B): matches/0x00159d00.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fceda07a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_159d00;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fceda07a
