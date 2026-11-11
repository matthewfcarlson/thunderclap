// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006fff0..0x00070080 (kind game, layer game, confidence high), dominant class CSmartPropDropTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f2bb1205 {
#define TREE_TU_END }
namespace fn_f2bb1205 {} using namespace fn_f2bb1205;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f2bb1205 {
class TrackFactoryTemplate_6fff0 {
  public:
    TrackFactoryTemplate_6fff0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
struct Thing_70030 {
    hulk_intptr init_00062a80();
};
extern int hulk_at_003fd36c;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00062a50();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f2bb1205

// 0x0006fff0 fight::TrackFactoryCasterTemplate<CSmartPropDropTrack>::vfunc_1 (60 B): matches/0x0006fff0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCSmartPropDropTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CSmartPropDropTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6fff0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_6fff0* t = new (mem) TrackFactoryTemplate_6fff0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000645c0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00070030 fight::TrackFactoryTemplate<CSmartPropDropTrack>::vfunc_5 (24 B): matches/0x00070030.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCSmartPropDropTrack@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f4f0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<CSmartPropDropTrack>::vfunc_5() {
    Thing_70030* p = (Thing_70030*)operator new(0x14);
    if (p)
        return (void*)(p->init_00062a80());
    return (void*)(0);
}

namespace fn_f2bb1205 {

// 0x00070050 fight::TrackFactoryTemplate<CSmartPropDropTrack>::vfunc_2 (43 B): matches/0x00070050.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f2bb1205@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd36c;
    base1_dtor_00062a50();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f2bb1205
