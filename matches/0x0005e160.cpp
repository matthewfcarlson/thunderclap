#include "compat/ptr.h"
struct CProceduralDurationAnimationTrack {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual CProceduralDurationAnimationTrack* vfunc_5(int);
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
};
struct H {
    void f();
};
struct G_5e160 {
    void g();
};
extern void __cdecl thunk_FUN_00267090(CProceduralDurationAnimationTrack*);
extern int vftable_5e160;
CProceduralDurationAnimationTrack* CProceduralDurationAnimationTrack::vfunc_5(int param) {
    *(hulk_intptr*)this = (hulk_intptr)&vftable_5e160;
    ((H*)((char*)this + 0x38))->f();
    ((H*)((char*)this + 0x18))->f();
    ((G_5e160*)this)->g();
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}
