// Same code shape as 0x0002e6d0 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_2f070 {
  public:
    void Method(const char*, float);
};
struct Pair_2f070 {
    const char* s;
    float f;
};

template <> void Closure2<CActorManager, void, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_2f070 * p = (Pair_2f070 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_2f070 * *)&this->f_20)->*(*(void (CActorManager_2f070::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
