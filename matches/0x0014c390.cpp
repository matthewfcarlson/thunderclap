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
    void* init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::GrappleHitReactionTrack>::vfunc_5() {
    void* p = Allocate(0x58);
    if (p)
        return (void*)(((GrappleHitReactionTrack_nv_14c390*)(((hulkfight::motion::GrappleHitReactionTrack*)p)))->init());
    return (void*)(0);
}
