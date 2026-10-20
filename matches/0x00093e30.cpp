#include "gen/global.h"

class CUnlockablesManager_93e30 {
  public:
    bool Get(int);
};
class Function_93e30 {
  public:
    virtual void v0();
    virtual void v1();
};

template <> void Method1<CUnlockablesManager, bool, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CUnlockablesManager_93e30 * obj = (CUnlockablesManager_93e30 *)__p0; int * arg = (int *)__p1; bool * out = (bool *)__p2;

    bool (CUnlockablesManager_93e30::*f)(int) = (*(bool (CUnlockablesManager_93e30::**)(int))&this->f_1c);
    int v = *arg;
    bool r = (obj->*f)(v);
    if (out)
        *out = r;
}
