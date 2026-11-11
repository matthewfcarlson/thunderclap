// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006fd80..0x0006fe40 (kind game, layer game, confidence high), dominant class CPushBackAnimationTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f59455c9 {
#define TREE_TU_END }
namespace fn_f59455c9 {} using namespace fn_f59455c9;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f59455c9 {
class TrackFactoryTemplate_6fd80 {
  public:
    TrackFactoryTemplate_6fd80() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003fd2c0;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0005dc80();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};
struct CHitAnimationTrack_6fdf0 {
    unsigned int* vf;
    void init_0005dcb0();
};
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);

} // namespace fn_f59455c9

// 0x0006fd80 fight::TrackFactoryCasterTemplate<CPushBackAnimationTrack>::vfunc_1 (60 B): matches/0x0006fd80.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCPushBackAnimationTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CPushBackAnimationTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6fd80));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_6fd80* t = new (mem) TrackFactoryTemplate_6fd80();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0005fbe0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f59455c9 {

// 0x0006fdc0 fight::TrackFactoryTemplate<CPushBackAnimationTrack>::vfunc_2 (43 B): matches/0x0006fdc0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f59455c9@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd2c0;
    base1_dtor_0005dc80();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f59455c9

// 0x0006fdf0 fight::TrackFactoryTemplate<CPushBackAnimationTrack>::vfunc_5 (38 B): matches/0x0006fdf0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCPushBackAnimationTrack@@@fight@@UAEPAXXZ
// Same code shape as 0x0006fb80 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<CPushBackAnimationTrack>::vfunc_5() {
    CHitAnimationTrack_6fdf0* p = (CHitAnimationTrack_6fdf0*)FUN_0008d690(0x50);
    if (p) {
        p->init_0005dcb0();
        p->vf = (unsigned int*)&hit_vftable;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x0006fe20 CPushBackAnimationTrack::vfunc_5 (30 B): matches/0x0006fe20.cpp
// sym: ??_GCPushBackAnimationTrack@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CPushBackAnimationTrack::~CPushBackAnimationTrack() {}

