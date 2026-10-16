// Same code shape as 0x0002e6d0 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_1e2720 {
  public:
    void Method(const char*, float);
};
struct Pair_1e2720 {
    const char* s;
    float f;
};

template <> void Closure2<CSPManager, void, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1e2720 * p = (Pair_1e2720 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1e2720 * *)&this->f_20)->*(*(void (CActorManager_1e2720::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
