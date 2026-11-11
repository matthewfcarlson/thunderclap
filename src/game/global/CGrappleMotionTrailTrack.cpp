// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006f750..0x0006f810 (kind game, layer game, confidence high), dominant class CGrappleMotionTrailTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7c5defd {
#define TREE_TU_END }
namespace fn_f7c5defd {} using namespace fn_f7c5defd;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f7c5defd {
class TrackFactoryTemplate_6f750 {
  public:
    TrackFactoryTemplate_6f750() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern int g_vftable_6f790;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_003fd108[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Track_6f7c0 {
    virtual void f0();
    char pad[0xcc];
};
struct Init_6f7c0 {
    void init();
};

} // namespace fn_f7c5defd

// 0x0006f750 fight::TrackFactoryCasterTemplate<CGrappleMotionTrailTrack>::vfunc_1 (60 B): matches/0x0006f750.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCGrappleMotionTrailTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CGrappleMotionTrailTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6f750));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_6f750* t = new (mem) TrackFactoryTemplate_6f750();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000612e0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f7c5defd {

// 0x0006f790 fight::TrackFactoryTemplate<CGrappleMotionTrailTrack>::vfunc_2 (43 B): matches/0x0006f790.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f7c5defd@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_6f790;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f7c5defd

// 0x0006f7c0 fight::TrackFactoryTemplate<CGrappleMotionTrailTrack>::vfunc_5 (41 B): matches/0x0006f7c0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrappleMotionTrailTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CGrappleMotionTrailTrack>::vfunc_5() {
    Track_6f7c0* p = (Track_6f7c0*)FUN_0008d690((int)sizeof(Track_6f7c0));
    if (p) {
        ((Init_6f7c0*)p)->init();
        *(void**)p = (void*)((hulk_intptr)DAT_003fd108);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x0006f7f0 CGrappleMotionTrailTrack::vfunc_5 (30 B): matches/0x0006f7f0.cpp
// sym: ??_GCGrappleMotionTrailTrack@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CGrappleMotionTrailTrack::~CGrappleMotionTrailTrack() {}

