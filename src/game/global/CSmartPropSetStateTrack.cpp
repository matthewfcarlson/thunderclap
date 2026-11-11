// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000701a0..0x00070230 (kind game, layer game, confidence high), dominant class CSmartPropSetStateTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8efba8b {
#define TREE_TU_END }
namespace fn_f8efba8b {} using namespace fn_f8efba8b;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f8efba8b {
class TrackFactoryTemplate_701a0 {
  public:
    TrackFactoryTemplate_701a0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000641e0();
struct Thing_701e0 {
    hulk_intptr init();
};
extern int g_vftable_70200;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f8efba8b

// 0x000701a0 fight::TrackFactoryCasterTemplate<CSmartPropSetStateTrack>::vfunc_1 (60 B): matches/0x000701a0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCSmartPropSetStateTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CSmartPropSetStateTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_701a0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_701a0* t = new (mem) TrackFactoryTemplate_701a0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000641e0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x000701e0 fight::TrackFactoryTemplate<CSmartPropSetStateTrack>::vfunc_5 (24 B): matches/0x000701e0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCSmartPropSetStateTrack@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f4f0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<CSmartPropSetStateTrack>::vfunc_5() {
    Thing_701e0* p = (Thing_701e0*)operator new(0x14);
    if (p)
        return (void*)(p->init());
    return (void*)(0);
}

namespace fn_f8efba8b {

// 0x00070200 fight::TrackFactoryTemplate<CSmartPropSetStateTrack>::vfunc_2 (43 B): matches/0x00070200.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f8efba8b@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_70200;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f8efba8b
