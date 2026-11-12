// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006f1e0..0x0006f270 (kind game, layer game, confidence high), dominant class CEffectTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f59379d5 {
#define TREE_TU_END }
namespace fn_f59379d5 {} using namespace fn_f59379d5;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f59379d5 {
class TrackFactoryTemplate_6f1e0 {
  public:
    TrackFactoryTemplate_6f1e0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
typedef unsigned int u32_6f220;
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct InitObj_6f220 {
    hulk_uintptr Init_00060660();
};
extern int hulk_at_003fcf80;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00060630();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f59379d5

// 0x0006f1e0 fight::TrackFactoryCasterTemplate<CEffectTrack>::vfunc_1 (60 B): matches/0x0006f1e0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCEffectTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CEffectTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6f1e0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_6f1e0* t = new (mem) TrackFactoryTemplate_6f1e0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00061850();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0006f220 fight::TrackFactoryTemplate<CEffectTrack>::vfunc_5 (24 B): matches/0x0006f220.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCEffectTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CEffectTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x60);
    if (p)
        return (void*)(((InitObj_6f220*)p)->Init_00060660());
    return (void*)(0);
}

namespace fn_f59379d5 {

// 0x0006f240 fight::TrackFactoryTemplate<CEffectTrack>::vfunc_2 (43 B): matches/0x0006f240.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f59379d5@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fcf80;
    base1_dtor_00060630();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f59379d5
