#include "gen/core.h"

struct Dispatch_277500 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h(void*, int, int, int, int, int);
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
};

void core::CementLibrary::vfunc_8(void* __p0, int a, int b, int c, int d, int e) { int ** p = (int **)__p0;

    Dispatch_277500* dsp = (Dispatch_277500*)this;
    dsp->h(p, a, b, c, d, e);
    Dispatch_277500* v = (Dispatch_277500*)*p;
    if (v)
        v->v();
}
