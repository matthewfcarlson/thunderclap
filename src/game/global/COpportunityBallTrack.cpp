// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006fc60..0x0006fcf0 (kind game, layer game, confidence high), dominant class COpportunityBallTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6b38101 {
#define TREE_TU_END }
namespace fn_f6b38101 {} using namespace fn_f6b38101;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f6b38101 {
class TrackFactoryTemplate_6fc60 {
  public:
    TrackFactoryTemplate_6fc60() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0005fa10();
typedef unsigned int u32_6fca0;
struct CGrabTrack_6fca0 {
    hulk_uintptr init_0005e0c0();
};
extern int hulk_at_003fd288;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0005db80();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f6b38101

// 0x0006fc60 fight::TrackFactoryCasterTemplate<COpportunityBallTrack>::vfunc_1 (60 B): matches/0x0006fc60.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCOpportunityBallTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<COpportunityBallTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6fc60));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_6fc60* t = new (mem) TrackFactoryTemplate_6fc60();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0005fa10();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0006fca0 fight::TrackFactoryTemplate<COpportunityBallTrack>::vfunc_5 (24 B): matches/0x0006fca0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCOpportunityBallTrack@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f3d0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<COpportunityBallTrack>::vfunc_5() {
    CGrabTrack_6fca0* p = (CGrabTrack_6fca0*)operator_new(0x50);
    if (p)
        return (void*)(p->init_0005e0c0());
    return (void*)(0);
}

namespace fn_f6b38101 {

// 0x0006fcc0 fight::TrackFactoryTemplate<COpportunityBallTrack>::vfunc_2 (43 B): matches/0x0006fcc0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f6b38101@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd288;
    base1_dtor_0005db80();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f6b38101
