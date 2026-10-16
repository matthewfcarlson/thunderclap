// Same code shape as 0x0002e6d0 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_1d4150 {
  public:
    void Method(const char*, float);
};
struct Pair_1d4150 {
    const char* s;
    float f;
};

template <> void Closure2<ScriptHandler, void, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1d4150 * p = (Pair_1d4150 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1d4150 * *)&this->f_20)->*(*(void (CActorManager_1d4150::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
