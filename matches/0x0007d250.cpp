// Same code shape as 0x0002ce30 (propagated; names are from that function)
#include "gen/global.h"

class Dummy_7d250 {
  public:
    void Call(void*);
};

template <> void Method1<CAmbientsManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_7d250* d = (Dummy_7d250*)a;
    (d->*(*(void (Dummy_7d250::**)(void *))&this->f_1c))(*b);
}
