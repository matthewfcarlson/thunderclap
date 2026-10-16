// Same code shape as 0x0013e710 (propagated; names are from that function)
#include "gen/pure3d.h"

struct TrackFactory_2b4cd0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
extern "C" void* __cdecl Allocate(unsigned int);
struct Built_2b4cd0 {
    void* init();
};

void* pure3d::ShadowSkinLoader::vfunc_6() {
    void* p = Allocate(0x58);
    if (p)
        return (void*)(((Built_2b4cd0*)p)->init());
    return (void*)(0);
}
