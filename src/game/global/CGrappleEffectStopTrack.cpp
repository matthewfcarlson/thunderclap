// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0006f600..0x0006f6c0 (kind game, layer game, confidence high), dominant class CGrappleEffectStopTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd348dcb {
#define TREE_TU_END }
namespace fn_fd348dcb {} using namespace fn_fd348dcb;
namespace fn_fd348dcb {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fd348dcb {
class TrackFactoryTemplate_6f600 {
  public:
    TrackFactoryTemplate_6f600() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003fd078;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_000608a0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_003fd094[];
class StopTrack_6f670 {
  public:
    void Init_000608d0();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

} // namespace fn_fd348dcb

// 0x0006f600 fight::TrackFactoryCasterTemplate<CGrappleEffectStopTrack>::vfunc_1 (60 B): matches/0x0006f600.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCGrappleEffectStopTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CGrappleEffectStopTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6f600));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_6f600* t = new (mem) TrackFactoryTemplate_6f600();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000610c0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fd348dcb {

// 0x0006f640 fight::TrackFactoryTemplate<CGrappleEffectStopTrack>::vfunc_2 (43 B): matches/0x0006f640.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fd348dcb@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd078;
    base1_dtor_000608a0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fd348dcb

// 0x0006f670 fight::TrackFactoryTemplate<CGrappleEffectStopTrack>::vfunc_5 (38 B): matches/0x0006f670.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrappleEffectStopTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CGrappleEffectStopTrack>::vfunc_5() {
    StopTrack_6f670* p = (StopTrack_6f670*)FUN_0008d690(0x18);
    if (p) {
        p->Init_000608d0();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_003fd094);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x0006f6a0 CGrappleEffectStopTrack::vfunc_5 (30 B): matches/0x0006f6a0.cpp
// sym: ??_GCGrappleEffectStopTrack@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CGrappleEffectStopTrack::~CGrappleEffectStopTrack() {}

