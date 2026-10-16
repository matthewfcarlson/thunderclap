// Same code shape as 0x0002ce30 (propagated; names are from that function)
#include "gen/global.h"

class Dummy_90a30 {
  public:
    void Call(void*);
};

template <> void Method1<CStatsManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_90a30* d = (Dummy_90a30*)a;
    (d->*(*(void (Dummy_90a30::**)(void *))&this->f_1c))(*b);
}
