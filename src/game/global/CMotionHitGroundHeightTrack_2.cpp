// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00076fe0..0x000770a0 (kind game, layer game, confidence high), dominant class CMotionHitGroundHeightTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff714e11 {
#define TREE_TU_END }
namespace fn_ff714e11 {} using namespace fn_ff714e11;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ff714e11 {
class TrackFactoryTemplate_76fe0 {
  public:
    TrackFactoryTemplate_76fe0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00072740();
struct CMotionHitGroundHeightTrack_77020 {
    hulk_intptr vptr;
    int pad;
    int c;
    int d;
    float e;
    float f;
    void construct_00236d40();
};
extern int hulk_at_003fc1fc;
extern "C" void* FUN_0008d690(unsigned int);
extern int hulk_at_003fea14;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0006b070();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_ff714e11

// 0x00076fe0 fight::TrackFactoryCasterTemplate<CMotionHitGroundHeightTrack>::vfunc_1 (60 B): matches/0x00076fe0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCMotionHitGroundHeightTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CMotionHitGroundHeightTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_76fe0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_76fe0* t = new (mem) TrackFactoryTemplate_76fe0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00072740();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00077020 fight::TrackFactoryTemplate<CMotionHitGroundHeightTrack>::vfunc_5 (66 B): matches/0x00077020.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCMotionHitGroundHeightTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CMotionHitGroundHeightTrack>::vfunc_5() {
    CMotionHitGroundHeightTrack_77020* p = (CMotionHitGroundHeightTrack_77020*)FUN_0008d690((int)sizeof(CMotionHitGroundHeightTrack_77020));
    if (p) {
        p->construct_00236d40();
        p->vptr = (hulk_intptr)&hulk_at_003fc1fc;
        p->d = 0;
        p->e = -1.0f;
        p->f = 1.0f;
        p->c = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_ff714e11 {

// 0x00077070 fight::TrackFactoryTemplate<CMotionHitGroundHeightTrack>::vfunc_2 (43 B): matches/0x00077070.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_ff714e11@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fea14;
    base1_dtor_0006b070();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ff714e11
