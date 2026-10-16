#include "gen/global.h"

class CActorManager_2c760;
typedef float (CActorManager_2c760::*Fn_2c760)(const char*);
class CActorManager_2c760 {
  public:
    float Get(const char* s);
};

template <> void Method1<CActorManager, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2c760 * a = (CActorManager_2c760 *)__p0; const char ** p = (const char **)__p1; float * out = (float *)__p2;

    Fn_2c760 f = (*(Fn_2c760 *)&this->f_1c);
    const char* s = *p;
    float x = (a->*f)(s);
    if (out)
        *out = x;
}
