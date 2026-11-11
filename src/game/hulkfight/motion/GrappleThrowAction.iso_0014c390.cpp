// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00146900..0x0014c470 (kind game, layer game, confidence high), dominant class hulkfight::motion::GrappleThrowAction
// (tree_prelude.h: not needed)


// 0x0014c390 fight::TrackFactoryTemplate<hulkfight::motion::GrappleHitReactionTrack>::vfunc_5 (24 B): matches/0x0014c390.cpp [isolated: conflict: Allocate; on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$TrackFactoryTemplate@VGrappleHitReactionTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0013e710 (propagated; names are from that function)
#include "gen/fight.h"
#include "gen/hulkfight.h"

struct TrackFactory_14c390 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
extern "C" void* __cdecl Allocate(unsigned int);
struct GrappleHitReactionTrack_nv_14c390 {
    void* init_001476d0();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::GrappleHitReactionTrack>::vfunc_5() {
    void* p = Allocate(0x58);
    if (p)
        return (void*)(((GrappleHitReactionTrack_nv_14c390*)(((hulkfight::motion::GrappleHitReactionTrack*)(((hulkfight::motion::GrappleHitReactionTrack*)p)))))->init_001476d0());
    return (void*)(0);
}

