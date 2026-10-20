#include "gen/global.h"

class CActorManager_2e200 {
  public:
    float Method(const char*, const char*);
};
struct Args {
    const char* a;
    const char* b;
};
typedef float (CActorManager_2e200::*MemFn)(const char*, const char*);
class Function_2e200 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

template <> void Method2<CActorManager, float, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2e200 * obj = (CActorManager_2e200 *)__p0; Args * args = (Args *)__p1; float * out = (float *)__p2;

    MemFn f = (*(MemFn *)&this->f_1c);
    const char* a = args->a;
    const char* b = args->b;
    float r = (obj->*f)(a, b);
    if (out)
        *out = r;
}
