#include "gen/pure3d.h"

struct Params_31b960 {
    int p0, p1, p2, p3, p4, p5, p6, p7;
};
void* Alloc(unsigned n);
inline void* operator new(unsigned, void* p) {
    return p;
}
class Impl_31b960 {
  public:
    Impl_31b960(int ctx);
    void Setup(int a, int b, int c, int d, int e, int f);
    virtual void v0();
    virtual void v1();
    virtual int v2();
    virtual void v3(int del);
};

void* pure3d::d3dDevice::vfunc_10(void* __p0) { Params_31b960 * p = (Params_31b960 *)__p0;

    void* m = Alloc(0x40);
    Impl_31b960* o;
    if (m)
        o = new (m) Impl_31b960(this->f_0c);
    else
        o = 0;
    o->Setup(p->p0, p->p1, 0, p->p4, p->p5, p->p7);
    this->f_08 = o->v2();
    if (this->f_08 != 1) {
        o->v3(1);
        return (void*)(0);
    }
    return (void*)(o);
}
