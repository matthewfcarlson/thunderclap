// Same code shape as 0x0002ce30 (propagated; names are from that function)
#include "gen/global.h"

class Dummy_1ba3b0 {
  public:
    void Call(void*);
};

template <> void Method1<CRenderManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1ba3b0* d = (Dummy_1ba3b0*)a;
    (d->*(*(void (Dummy_1ba3b0::**)(void *))&this->f_1c))(*b);
}
