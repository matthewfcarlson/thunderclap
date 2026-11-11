// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006f300..0x0006f390 (kind game, layer game, confidence high), dominant class CExplosionTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f1773d85 {
#define TREE_TU_END }
namespace fn_f1773d85 {} using namespace fn_f1773d85;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f1773d85 {
class TrackFactoryTemplate_6f300 {
  public:
    TrackFactoryTemplate_6f300() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00078610();
typedef unsigned int u32_6f340;
struct Helper_6f340 {
    hulk_uintptr run_00077fe0();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003fcfb8;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00077fb0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f1773d85

// 0x0006f300 fight::TrackFactoryCasterTemplate<CExplosionTrack>::vfunc_1 (60 B): matches/0x0006f300.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCExplosionTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CExplosionTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6f300));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_6f300* t = new (mem) TrackFactoryTemplate_6f300();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00078610();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0006f340 fight::TrackFactoryTemplate<CExplosionTrack>::vfunc_5 (24 B): matches/0x0006f340.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCExplosionTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CExplosionTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x20);
    if (p)
        return (void*)(((Helper_6f340*)p)->run_00077fe0());
    return (void*)(0);
}

namespace fn_f1773d85 {

// 0x0006f360 fight::TrackFactoryTemplate<CExplosionTrack>::vfunc_2 (43 B): matches/0x0006f360.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f1773d85@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fcfb8;
    base1_dtor_00077fb0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f1773d85
