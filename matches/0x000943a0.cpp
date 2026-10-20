#include "gen/global.h"

class CUnlockablesManager_943a0 {
  public:
    int Run(const char*);
};
class Function_943a0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};

template <> void Method1<CUnlockablesManager, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CUnlockablesManager_943a0 * obj = (CUnlockablesManager_943a0 *)__p0; const char ** arg = (const char **)__p1; int * out = (int *)__p2;

    int (CUnlockablesManager_943a0::*f)(const char*) = (*(int (CUnlockablesManager_943a0::**)(const char *))&this->f_1c);
    const char* p = *arg;
    int v = (obj->*f)(p);
    if (out)
        *out = v;
}
