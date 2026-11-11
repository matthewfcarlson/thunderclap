// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000702c0..0x00070350 (kind game, layer game, confidence high), dominant class CSmartPropThrowTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f908f418 {
#define TREE_TU_END }
namespace fn_f908f418 {} using namespace fn_f908f418;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f908f418 {
class TrackFactoryTemplate_702c0 {
  public:
    TrackFactoryTemplate_702c0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000642e0();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Thing_70300 {
    hulk_uintptr go_000628b0();
};
extern int hulk_at_003fd3f8;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00062880();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f908f418

// 0x000702c0 fight::TrackFactoryCasterTemplate<CSmartPropThrowTrack>::vfunc_1 (60 B): matches/0x000702c0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCSmartPropThrowTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CSmartPropThrowTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_702c0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_702c0* t = new (mem) TrackFactoryTemplate_702c0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000642e0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00070300 fight::TrackFactoryTemplate<CSmartPropThrowTrack>::vfunc_5 (24 B): matches/0x00070300.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCSmartPropThrowTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CSmartPropThrowTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x44);
    if (p)
        return (void*)(((Thing_70300*)p)->go_000628b0());
    return (void*)(0);
}

namespace fn_f908f418 {

// 0x00070320 fight::TrackFactoryTemplate<CSmartPropThrowTrack>::vfunc_2 (43 B): matches/0x00070320.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f908f418@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd3f8;
    base1_dtor_00062880();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f908f418
