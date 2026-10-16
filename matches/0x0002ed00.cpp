// Same code shape as 0x0002e6d0 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_2ed00 {
  public:
    void Method(const char*, float);
};
struct Pair_2ed00 {
    const char* s;
    float f;
};

template <> void Closure2<CActorManager, void, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_2ed00 * p = (Pair_2ed00 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_2ed00 * *)&this->f_20)->*(*(void (CActorManager_2ed00::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
