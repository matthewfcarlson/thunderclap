// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00070500..0x00070590 (kind game, layer game, confidence high), dominant class CStunAnimationTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd242b13 {
#define TREE_TU_END }
namespace fn_fd242b13 {} using namespace fn_fd242b13;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fd242b13 {
class TrackFactoryTemplate_70500 {
  public:
    TrackFactoryTemplate_70500() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0005fef0();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Track_70540 {
    void* Init_0005de00();
};
extern int hulk_at_003fd468;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0005ddd0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fd242b13

// 0x00070500 fight::TrackFactoryCasterTemplate<CStunAnimationTrack>::vfunc_1 (60 B): matches/0x00070500.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCStunAnimationTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CStunAnimationTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_70500));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_70500* t = new (mem) TrackFactoryTemplate_70500();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0005fef0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00070540 fight::TrackFactoryTemplate<CStunAnimationTrack>::vfunc_5 (24 B): matches/0x00070540.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCStunAnimationTrack@@@fight@@UAEPAXXZ
// Same code shape as 0x00070420 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<CStunAnimationTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x48);
    if (p)
        return (void*)(((Track_70540*)p)->Init_0005de00());
    return (void*)(0);
}

namespace fn_fd242b13 {

// 0x00070560 fight::TrackFactoryTemplate<CStunAnimationTrack>::vfunc_2 (43 B): matches/0x00070560.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fd242b13@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd468;
    base1_dtor_0005ddd0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fd242b13
