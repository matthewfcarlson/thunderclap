// Same code shape as 0x0002e6d0 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_1c0030 {
  public:
    void Method(const char*, float);
};
struct Pair_1c0030 {
    const char* s;
    float f;
};

template <> void Closure2<CSubtitleManager, void, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1c0030 * p = (Pair_1c0030 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1c0030 * *)&this->f_20)->*(*(void (CActorManager_1c0030::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
