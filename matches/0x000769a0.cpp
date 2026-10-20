#include "compat/ptr.h"
#include "gen/fight.h"

class CGrappleInvulnerableTrack_769a0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    CGrappleInvulnerableTrack_769a0();
};
extern "C" void* __cdecl Alloc(hulk_uintptr);
extern int vtable_769a0;

template <> void* fight::TrackFactoryTemplate<CGrappleInvulnerableTrack>::vfunc_5() {
    CGrappleInvulnerableTrack_769a0* p = (CGrappleInvulnerableTrack_769a0*)Alloc(0x18);
    if (p) {
        p->CGrappleInvulnerableTrack_769a0::CGrappleInvulnerableTrack_769a0();
        *(hulk_intptr*)p = (hulk_intptr)&vtable_769a0;
        return (void*)(p);
    }
    return (void*)(0);
}
