#include "gen/global.h"

class CWorldStreamManager_2054f0 {
  public:
    bool Work(int);
};
class Function_2054f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

template <> void Method1<CWorldStreamManager, bool, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CWorldStreamManager_2054f0 * obj = (CWorldStreamManager_2054f0 *)__p0; int * arg = (int *)__p1; bool * out = (bool *)__p2;

    bool (CWorldStreamManager_2054f0::*f)(int) = (*(bool (CWorldStreamManager_2054f0::**)(int))&this->f_1c);
    int value = *arg;
    bool result = (obj->*f)(value);
    if (out)
        *out = result;
}
