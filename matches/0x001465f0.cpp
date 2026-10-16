// Same code shape as 0x0013e710 (propagated; names are from that function)
#include "gen/fight.h"

struct TrackFactory_1465f0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
extern "C" void* __cdecl Allocate(unsigned int);
struct Built_1465f0 {
    void* init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::WorldConeDamageTrack>::vfunc_5() {
    void* p = Allocate(0x58);
    if (p)
        return (void*)(((Built_1465f0*)p)->init());
    return (void*)(0);
}
