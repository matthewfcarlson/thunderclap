#include "gen/global.h"

class Dummy_2ce30 {
  public:
    void Call(void*);
};

template <> void Method1<CActorManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_2ce30* d = (Dummy_2ce30*)a;
    (d->*(*(void (Dummy_2ce30::**)(void *))&this->f_1c))(*b);
}
