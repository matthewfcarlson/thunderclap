// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00159bb0..0x00159c70 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitThrowTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f81168ff {
#define TREE_TU_END }
namespace fn_f81168ff {} using namespace fn_f81168ff;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f81168ff {
class TrackFactoryTemplate_159bb0 {
  public:
    TrackFactoryTemplate_159bb0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00155cd0();
extern "C" char DAT_00414240[];
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
struct HitThrowTrack_159bf0 {
    hulk_intptr vt;
    char p04[8];
    int f0c;
    float f10;
    unsigned char f14;
    char p15[3];
    int f18;
    float f1c;
    int f20;
    int f24;
    int f28;
    void InitTrack_00236d40();
};
extern int hulk_at_00415730;

} // namespace fn_f81168ff

// 0x00159bb0 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitThrowTrack>::vfunc_1 (60 B): matches/0x00159bb0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VHitThrowTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::HitThrowTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_159bb0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_159bb0* t = new (mem) TrackFactoryTemplate_159bb0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00155cd0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00159bf0 fight::TrackFactoryTemplate<hulkfight::motion::HitThrowTrack>::vfunc_5 (80 B): matches/0x00159bf0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VHitThrowTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitThrowTrack>::vfunc_5() {
    HitThrowTrack_159bf0* p = (HitThrowTrack_159bf0*)FUN_0008d690((int)sizeof(HitThrowTrack_159bf0));
    if (p) {
        p->InitTrack_00236d40();
        p->f0c = 0;
        p->f18 = 0;
        p->f24 = 0;
        p->f28 = 0;
        p->vt = ((hulk_intptr)DAT_00414240);
        p->f10 = -1.0f;
        p->f14 = 1;
        p->f1c = 30.0f;
        p->f20 = -5;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f81168ff {

// 0x00159c40 fight::TrackFactoryTemplate<hulkfight::motion::HitThrowTrack>::vfunc_2 (43 B): matches/0x00159c40.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f81168ff@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00415730;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f81168ff
