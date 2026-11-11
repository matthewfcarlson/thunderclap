// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006f4b0..0x0006f540 (kind game, layer game, confidence high), dominant class CGrappleDetachTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc60230d {
#define TREE_TU_END }
namespace fn_fc60230d {} using namespace fn_fc60230d;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fc60230d {
class TrackFactoryTemplate_6f4b0 {
  public:
    TrackFactoryTemplate_6f4b0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0005c280();
struct Thing_6f4f0 {
    hulk_intptr init_0005ac40();
};
extern int hulk_at_003fd00c;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0005ac10();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fc60230d

// 0x0006f4b0 fight::TrackFactoryCasterTemplate<CGrappleDetachTrack>::vfunc_1 (60 B): matches/0x0006f4b0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCGrappleDetachTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CGrappleDetachTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6f4b0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_6f4b0* t = new (mem) TrackFactoryTemplate_6f4b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0005c280();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0006f4f0 fight::TrackFactoryTemplate<CGrappleDetachTrack>::vfunc_5 (24 B): matches/0x0006f4f0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrappleDetachTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CGrappleDetachTrack>::vfunc_5() {
    Thing_6f4f0* p = (Thing_6f4f0*)operator new(0x14);
    if (p)
        return (void*)(p->init_0005ac40());
    return (void*)(0);
}

namespace fn_fc60230d {

// 0x0006f510 fight::TrackFactoryTemplate<CGrappleDetachTrack>::vfunc_2 (43 B): matches/0x0006f510.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fc60230d@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd00c;
    base1_dtor_0005ac10();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc60230d
