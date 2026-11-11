// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006f270..0x0006f300 (kind game, layer game, confidence high), dominant class CEffectStopTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5467fe9 {
#define TREE_TU_END }
namespace fn_f5467fe9 {} using namespace fn_f5467fe9;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f5467fe9 {
class TrackFactoryTemplate_6f270 {
  public:
    TrackFactoryTemplate_6f270() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
class Effect_6f2b0 {
  public:
    hulk_intptr Init_000608d0();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003fcf9c;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_000608a0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f5467fe9

// 0x0006f270 fight::TrackFactoryCasterTemplate<CEffectStopTrack>::vfunc_1 (60 B): matches/0x0006f270.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCEffectStopTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CEffectStopTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6f270));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_6f270* t = new (mem) TrackFactoryTemplate_6f270();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000610c0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0006f2b0 fight::TrackFactoryTemplate<CEffectStopTrack>::vfunc_5 (24 B): matches/0x0006f2b0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCEffectStopTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CEffectStopTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x18);
    if (p)
        return (void*)(((Effect_6f2b0*)p)->Init_000608d0());
    return (void*)(0);
}

namespace fn_f5467fe9 {

// 0x0006f2d0 fight::TrackFactoryTemplate<CEffectStopTrack>::vfunc_2 (43 B): matches/0x0006f2d0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f5467fe9@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fcf9c;
    base1_dtor_000608a0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f5467fe9
