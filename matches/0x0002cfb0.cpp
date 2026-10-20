#include "gen/global.h"

class CActorManager_2cfb0 {
  public:
    int Act(const char*);
};
class Function_2cfb0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method1<CActorManager, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2cfb0 * obj = (CActorManager_2cfb0 *)__p0; const char ** arg = (const char **)__p1; int * out = (int *)__p2;

    int (CActorManager_2cfb0::*f)(const char*) = (*(int (CActorManager_2cfb0::**)(const char *))&this->f_1c);
    const char* a = *arg;
    int x = (obj->*f)(a);
    if (out)
        *out = x;
}
