#include "gen/global.h"

class CActorManager_2d6d0 {
  public:
    bool Act(int);
};
class Function_2d6d0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method1<CActorManager, bool, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2d6d0 * obj = (CActorManager_2d6d0 *)__p0; int * input = (int *)__p1; bool * out = (bool *)__p2;

    bool (CActorManager_2d6d0::*f)(int) = (*(bool (CActorManager_2d6d0::**)(int))&this->f_1c);
    int n = *input;
    bool r = (obj->*f)(n);
    if (out)
        *out = r;
}
