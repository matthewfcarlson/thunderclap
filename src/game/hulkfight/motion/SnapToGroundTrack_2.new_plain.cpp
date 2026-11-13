// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017bc70..0x0017e1a0 (kind game, layer game, confidence high), dominant class hulkfight::motion::SnapToGroundTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f31995d4 {
#define TREE_TU_END }
namespace fn_f31995d4 {} using namespace fn_f31995d4;
namespace fn_f31995d4 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f31995d4 {
class TrackFactoryTemplate_17e030 {
  public:
    TrackFactoryTemplate_17e030() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
class TrackFactoryTemplate_17e0f0 {
  public:
    TrackFactoryTemplate_17e0f0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};

} // namespace fn_f31995d4

// 0x0017e030 fight::TrackFactoryCasterTemplate<hulkfight::motion::ChargeTrack>::vfunc_1 (60 B): matches/0x0017e030.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VChargeTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::ChargeTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17e030));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_17e030* t = new (mem) TrackFactoryTemplate_17e030();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017e0f0 fight::TrackFactoryCasterTemplate<hulkfight::motion::SnapToGroundTrack>::vfunc_1 (60 B): matches/0x0017e0f0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VSnapToGroundTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::SnapToGroundTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17e0f0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_17e0f0* t = new (mem) TrackFactoryTemplate_17e0f0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}

