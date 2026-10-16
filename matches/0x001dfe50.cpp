// Same code shape as 0x0002ce30 (propagated; names are from that function)
#include "gen/global.h"

class Dummy_1dfe50 {
  public:
    void Call(void*);
};

template <> void Method1<CSPManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1dfe50* d = (Dummy_1dfe50*)a;
    (d->*(*(void (Dummy_1dfe50::**)(void *))&this->f_1c))(*b);
}
