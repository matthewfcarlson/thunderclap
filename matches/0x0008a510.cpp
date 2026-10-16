// Same code shape as 0x0002ce30 (propagated; names are from that function)
#include "gen/global.h"

class Dummy_8a510 {
  public:
    void Call(void*);
};

template <> void Method1<CGameFlowManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_8a510* d = (Dummy_8a510*)a;
    (d->*(*(void (Dummy_8a510::**)(void *))&this->f_1c))(*b);
}
