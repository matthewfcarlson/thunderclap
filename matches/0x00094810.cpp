// Same code shape as 0x0002e6d0 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_94810 {
  public:
    void Method(const char*, float);
};
struct Pair_94810 {
    const char* s;
    float f;
};

template <> void Closure2<CUnlockablesManager, void, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_94810 * p = (Pair_94810 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_94810 * *)&this->f_20)->*(*(void (CActorManager_94810::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
