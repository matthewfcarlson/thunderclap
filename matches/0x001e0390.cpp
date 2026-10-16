// Same code shape as 0x0002c760 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_1e0390;
typedef float (CActorManager_1e0390::*Fn_1e0390)(const char*);
class CActorManager_1e0390 {
  public:
    float Get(const char* s);
};

template <> void Method1<CSPManager, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1e0390 * a = (CActorManager_1e0390 *)__p0; const char ** p = (const char **)__p1; float * out = (float *)__p2;

    Fn_1e0390 f = (*(Fn_1e0390 *)&this->f_1c);
    const char* s = *p;
    float x = (a->*f)(s);
    if (out)
        *out = x;
}
