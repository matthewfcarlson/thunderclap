// Same code shape as 0x0002ceb0 (propagated; names are from that function)
#include "gen/global.h"

class Function_d71d0 {
  public:
    virtual void f0();
    virtual void f1();
};

template <> void Method0<CSimOverlayManager, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * b = (void *)__p1; unsigned int * out = (unsigned int *)__p2;

    unsigned(__fastcall * p)(void*) = *(unsigned(__fastcall**)(void*))((char*)this + 0x1c);
    unsigned v = p(a);
    if (out)
        *out = v;
}
