#include "gen/fight.h"

extern void* __cdecl Alloc(int);
extern void* GrappleVftable;
class CGrappleDamageTrack_76660 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    CGrappleDamageTrack_76660();
};

template <> void* fight::TrackFactoryTemplate<CGrappleDamageTrack>::vfunc_5() {
    CGrappleDamageTrack_76660* p = (CGrappleDamageTrack_76660*)Alloc(0x18);
    if (p) {
        p->CGrappleDamageTrack_76660::CGrappleDamageTrack_76660();
        *(void**)p = &GrappleVftable;
        return (void*)(p);
    }
    return (void*)(0);
}
