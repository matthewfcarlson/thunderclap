#include "gen/global.h"

class CActorManager_2ded0 {
  public:
    int Run(const char*, const char*);
};
struct Function_2ded0 {
    virtual void f0();
    virtual void f1();
    virtual void f2(CActorManager_2ded0*, const char**, int*);
};

template <> void Method2<CActorManager, int, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2ded0 * a = (CActorManager_2ded0 *)__p0; const char ** b = (const char **)__p1; int * out = (int *)__p2;

    int (CActorManager_2ded0::*f)(const char*, const char*) = (*(int (CActorManager_2ded0::**)(const char *, const char *))&this->f_1c);
    const char* x = b[0];
    const char* y = b[1];
    int r = (a->*f)(x, y);
    if (out)
        *out = r;
}
