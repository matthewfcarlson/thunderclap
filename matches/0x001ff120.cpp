// Same code shape as 0x0002c510 (propagated; names are from that function)
#include "gen/global.h"

class Function_1ff120 {
  public:
    virtual void f0();
    virtual void f1();
};
class CActorManager_1ff120 {
  public:
    bool (CActorManager_1ff120::*m)(const char*, bool);
};
struct Pair_1ff120 {
    const char* p;
    bool b;
};

template <> void Method2<CTriggerVolumeManager, bool, const char *, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1ff120 * obj = (CActorManager_1ff120 *)__p0; Pair_1ff120 * p = (Pair_1ff120 *)__p1; bool * out = (bool *)__p2;

    bool (CActorManager_1ff120::*fn)(const char*, bool) = (*(bool (CActorManager_1ff120::**)(const char *, bool))&this->f_1c);
    const char* s = p->p;
    bool b = p->b;
    bool r = (obj->*fn)(s, b);
    if (out)
        *out = r;
}
