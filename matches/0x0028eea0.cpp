#include "compat/ptr.h"
#include "gen/pure3d.h"

class Receiver_28eea0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void invoke(int, int);
};

int pure3d::ShaderFloatBroadcast::vfunc_3(void* __p0) { void * p = (void *)__p0;

    if (p) {
        Receiver_28eea0* r = *(Receiver_28eea0**)((char*)p + 16);
        r->invoke(this->f_08, this->f_0c);
    }
    return (hulk_intptr)p;
}
