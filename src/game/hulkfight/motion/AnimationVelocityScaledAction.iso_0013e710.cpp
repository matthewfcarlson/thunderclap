// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001399d0..0x0013e810 (kind game, layer game, confidence high), dominant class hulkfight::motion::AnimationVelocityScaledAction
// (tree_prelude.h: not needed)


// 0x0013e710 fight::TrackFactoryTemplate<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_5 (24 B): matches/0x0013e710.cpp [isolated: conflict: Allocate; on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$TrackFactoryTemplate@VAnimationVelocityScaledTrack@motion@hulkfight@@@fight@@UAEPAXXZ
#include "gen/fight.h"
#include "gen/hulkfight.h"

struct TrackFactory_13e710 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
extern "C" void* __cdecl Allocate(unsigned int);
struct AnimationVelocityScaledTrack_nv_13e710 {
    void* init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_5() {
    void* p = Allocate(0x58);
    if (p)
        return (void*)(((AnimationVelocityScaledTrack_nv_13e710*)(((hulkfight::motion::AnimationVelocityScaledTrack*)(((hulkfight::motion::AnimationVelocityScaledTrack*)p)))))->init());
    return (void*)(0);
}

