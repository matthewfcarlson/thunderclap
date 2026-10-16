// Same code shape as 0x0013e710 (propagated; names are from that function)
#include "gen/fight.h"

struct TrackFactory_15a740 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
extern "C" void* __cdecl Allocate(unsigned int);
struct Built_15a740 {
    void* init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitReactionFloatTrack>::vfunc_5() {
    void* p = Allocate(0x58);
    if (p)
        return (void*)(((Built_15a740*)p)->init());
    return (void*)(0);
}
