// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0015a0d0..0x0015a180 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitPushbackAddTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f921c9e0 {
#define TREE_TU_END }
namespace fn_f921c9e0 {} using namespace fn_f921c9e0;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f921c9e0 {
class TrackFactoryTemplate_15a0d0 {
  public:
    TrackFactoryTemplate_15a0d0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00156480();
extern "C" char DAT_004143f0[];
struct HitPushbackAddTrack_15a110 {
    hulk_uintptr vt;
    char pad[4];
    int mTwo;
    int mZero;
    float mOne;
    void Init_00236d40();
};
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int hulk_at_004157f4;

} // namespace fn_f921c9e0

// 0x0015a0d0 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitPushbackAddTrack>::vfunc_1 (60 B): matches/0x0015a0d0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VHitPushbackAddTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::HitPushbackAddTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_15a0d0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_15a0d0* t = new (mem) TrackFactoryTemplate_15a0d0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00156480();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0015a110 fight::TrackFactoryTemplate<hulkfight::motion::HitPushbackAddTrack>::vfunc_5 (59 B): matches/0x0015a110.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VHitPushbackAddTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitPushbackAddTrack>::vfunc_5() {
    HitPushbackAddTrack_15a110* p = (HitPushbackAddTrack_15a110*)FUN_0008d690((int)sizeof(HitPushbackAddTrack_15a110));
    if (p) {
        p->Init_00236d40();
        p->vt = ((hulk_intptr)DAT_004143f0);
        p->mZero = 0;
        p->mOne = 1.0f;
        p->mTwo = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f921c9e0 {

// 0x0015a150 fight::TrackFactoryTemplate<hulkfight::motion::HitPushbackAddTrack>::vfunc_2 (43 B): matches/0x0015a150.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f921c9e0@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004157f4;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f921c9e0
