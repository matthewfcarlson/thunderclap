// Same code shape as 0x0002c510 (propagated; names are from that function)
#include "gen/global.h"

class Function_1df870 {
  public:
    virtual void f0();
    virtual void f1();
};
class CActorManager_1df870 {
  public:
    bool (CActorManager_1df870::*m)(const char*, bool);
};
struct Pair_1df870 {
    const char* p;
    bool b;
};

template <> void Method2<CSPManager, bool, const char *, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1df870 * obj = (CActorManager_1df870 *)__p0; Pair_1df870 * p = (Pair_1df870 *)__p1; bool * out = (bool *)__p2;

    bool (CActorManager_1df870::*fn)(const char*, bool) = (*(bool (CActorManager_1df870::**)(const char *, bool))&this->f_1c);
    const char* s = p->p;
    bool b = p->b;
    bool r = (obj->*fn)(s, b);
    if (out)
        *out = r;
}
