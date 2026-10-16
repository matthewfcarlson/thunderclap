// Same code shape as 0x0002e6d0 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_1ce610 {
  public:
    void Method(const char*, float);
};
struct Pair_1ce610 {
    const char* s;
    float f;
};

template <> void Closure2<CScenarioManager, void, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1ce610 * p = (Pair_1ce610 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1ce610 * *)&this->f_20)->*(*(void (CActorManager_1ce610::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
