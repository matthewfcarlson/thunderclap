// Same code shape as 0x0002c760 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_1cdb20;
typedef float (CActorManager_1cdb20::*Fn_1cdb20)(const char*);
class CActorManager_1cdb20 {
  public:
    float Get(const char* s);
};

template <> void Method1<CScenarioManager, float, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1cdb20 * a = (CActorManager_1cdb20 *)__p0; const char ** p = (const char **)__p1; float * out = (float *)__p2;

    Fn_1cdb20 f = (*(Fn_1cdb20 *)&this->f_1c);
    const char* s = *p;
    float x = (a->*f)(s);
    if (out)
        *out = x;
}
