#include "gen/global.h"

class CActorManager_2ca30 {
  public:
    const char* Run(const char*);
};
class Function_2ca30 {
  public:
    virtual void v0();
    virtual void v1();
};

template <> void Method1<CActorManager, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2ca30 * obj = (CActorManager_2ca30 *)__p0; const char ** arg = (const char **)__p1; const char ** out = (const char **)__p2;

    const char* (CActorManager_2ca30::*f)(const char*) = (*(const char *(CActorManager_2ca30::**)(const char *))&this->f_1c);
    const char* p = *arg;
    const char* r = (obj->*f)(p);
    if (out)
        *out = r;
}
