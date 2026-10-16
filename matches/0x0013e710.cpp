#include "gen/fight.h"

struct TrackFactory_13e710 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
extern "C" void* __cdecl Allocate(unsigned int);
struct Built_13e710 {
    void* init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::AnimationVelocityScaledTrack>::vfunc_5() {
    void* p = Allocate(0x58);
    if (p)
        return (void*)(((Built_13e710*)p)->init());
    return (void*)(0);
}
