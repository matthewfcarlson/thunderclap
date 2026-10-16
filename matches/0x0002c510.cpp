#include "gen/global.h"

class Function_2c510 {
  public:
    virtual void f0();
    virtual void f1();
};
class CActorManager_2c510 {
  public:
    bool (CActorManager_2c510::*m)(const char*, bool);
};
struct Pair_2c510 {
    const char* p;
    bool b;
};

template <> void Method2<CActorManager, bool, const char *, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2c510 * obj = (CActorManager_2c510 *)__p0; Pair_2c510 * p = (Pair_2c510 *)__p1; bool * out = (bool *)__p2;

    bool (CActorManager_2c510::*fn)(const char*, bool) = (*(bool (CActorManager_2c510::**)(const char *, bool))&this->f_1c);
    const char* s = p->p;
    bool b = p->b;
    bool r = (obj->*fn)(s, b);
    if (out)
        *out = r;
}
