// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0015a370..0x0015a440 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitPushbackTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ffe3b679 {
#define TREE_TU_END }
namespace fn_ffe3b679 {} using namespace fn_ffe3b679;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ffe3b679 {
class TrackFactoryTemplate_15a370 {
  public:
    TrackFactoryTemplate_15a370() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00156970();
extern "C" char DAT_004144b0[];
class HitPushbackTrack_15a3b0 {
  public:
    hulk_intptr vptr;
    int x04;
    int x08;
    int x0c;
    float x10;
    float x14;
    float x18;
    unsigned char x1c;
    char x1d[3];
    int x20;
    int x24;
    int x28;
    int x2c;
    int x30;
    void init();
};
extern "C" HitPushbackTrack_15a3b0* __cdecl FUN_0008d690(unsigned int);
extern int g_vftable_15a410;

} // namespace fn_ffe3b679

// 0x0015a370 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitPushbackTrack>::vfunc_1 (60 B): matches/0x0015a370.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VHitPushbackTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::HitPushbackTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_15a370));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_15a370* t = new (mem) TrackFactoryTemplate_15a370();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00156970();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0015a3b0 fight::TrackFactoryTemplate<hulkfight::motion::HitPushbackTrack>::vfunc_5 (86 B): matches/0x0015a3b0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VHitPushbackTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitPushbackTrack>::vfunc_5() {
    HitPushbackTrack_15a3b0* p = FUN_0008d690((int)sizeof(HitPushbackTrack_15a3b0));
    if (p) {
        p->init();
        p->x10 = -1.0f;
        p->x18 = -1.0f;
        p->x0c = 0;
        p->x1c = 0;
        p->x20 = 0;
        p->x24 = 0;
        p->x2c = 0;
        p->x30 = 0;
        p->vptr = ((hulk_intptr)DAT_004144b0);
        p->x14 = 1.0f;
        p->x28 = -5;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_ffe3b679 {

// 0x0015a410 fight::TrackFactoryTemplate<hulkfight::motion::HitPushbackTrack>::vfunc_2 (43 B): matches/0x0015a410.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_ffe3b679@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_15a410;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ffe3b679
