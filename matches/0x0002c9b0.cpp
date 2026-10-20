#include "gen/global.h"

class CActorManager_2c9b0 {
  public:
    int Do(const char*);
    inline int Invoke(int (CActorManager_2c9b0::*f)(const char*), const char* p) { return (this->*f)(p); }
};
class Function_2c9b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(CActorManager_2c9b0*, const char**, int*);
};

template <> void Method1<CActorManager, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2c9b0 * arg = (CActorManager_2c9b0 *)__p0; const char ** value = (const char **)__p1; int * out = (int *)__p2;

    int (CActorManager_2c9b0::*f)(const char*) = (*(int (CActorManager_2c9b0::**)(const char *))&this->f_1c);
    int r = arg->Invoke(f, *value);
    if (out)
        *out = r;
}
