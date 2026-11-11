// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017f210..0x0017f2b0 (kind game, layer game, confidence high), dominant class hulkfight::motion::FootPivotTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa9b8fa8 {
#define TREE_TU_END }
namespace fn_fa9b8fa8 {} using namespace fn_fa9b8fa8;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fa9b8fa8 {
class TrackFactoryTemplate_17f210 {
  public:
    TrackFactoryTemplate_17f210() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017ddf0();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Track_17f250 {
    void* Init_00170f90();
};
extern int hulk_at_004190b8;

} // namespace fn_fa9b8fa8

// 0x0017f210 fight::TrackFactoryCasterTemplate<hulkfight::motion::FootPivotTrack>::vfunc_1 (60 B): matches/0x0017f210.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VFootPivotTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::FootPivotTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17f210));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_17f210* t = new (mem) TrackFactoryTemplate_17f210();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017ddf0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017f250 fight::TrackFactoryTemplate<hulkfight::motion::FootPivotTrack>::vfunc_5 (24 B): matches/0x0017f250.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VFootPivotTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00070420 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::FootPivotTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x48);
    if (p)
        return (void*)(((Track_17f250*)p)->Init_00170f90());
    return (void*)(0);
}

namespace fn_fa9b8fa8 {

// 0x0017f270 fight::TrackFactoryTemplate<hulkfight::motion::FootPivotTrack>::vfunc_2 (43 B): matches/0x0017f270.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fa9b8fa8@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004190b8;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fa9b8fa8
