// Same code shape as 0x0002ce30 (propagated; names are from that function)
#include "gen/global.h"

class Dummy_46360 {
  public:
    void Call(void*);
};

template <> void Method1<CCharacterTemplateManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_46360* d = (Dummy_46360*)a;
    (d->*(*(void (Dummy_46360::**)(void *))&this->f_1c))(*b);
}
