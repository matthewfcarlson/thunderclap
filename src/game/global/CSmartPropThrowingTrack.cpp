// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00070350..0x000703e0 (kind game, layer game, confidence high), dominant class CSmartPropThrowingTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff61d3b1 {
#define TREE_TU_END }
namespace fn_ff61d3b1 {} using namespace fn_ff61d3b1;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ff61d3b1 {
class TrackFactoryTemplate_70350 {
  public:
    TrackFactoryTemplate_70350() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00064520();
struct Thing_70390 {
    hulk_intptr init_000629a0();
};
extern int hulk_at_003fd414;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00062970();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_ff61d3b1

// 0x00070350 fight::TrackFactoryCasterTemplate<CSmartPropThrowingTrack>::vfunc_1 (60 B): matches/0x00070350.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCSmartPropThrowingTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CSmartPropThrowingTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_70350));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_70350* t = new (mem) TrackFactoryTemplate_70350();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00064520();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00070390 fight::TrackFactoryTemplate<CSmartPropThrowingTrack>::vfunc_5 (24 B): matches/0x00070390.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCSmartPropThrowingTrack@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f4f0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<CSmartPropThrowingTrack>::vfunc_5() {
    Thing_70390* p = (Thing_70390*)operator new(0x14);
    if (p)
        return (void*)(p->init_000629a0());
    return (void*)(0);
}

namespace fn_ff61d3b1 {

// 0x000703b0 fight::TrackFactoryTemplate<CSmartPropThrowingTrack>::vfunc_2 (43 B): matches/0x000703b0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_ff61d3b1@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd414;
    base1_dtor_00062970();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ff61d3b1
