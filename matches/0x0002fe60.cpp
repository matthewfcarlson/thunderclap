#include "gen/global.h"

class CActorManager_2fe60 {
  public:
    float Get();
};
typedef float (CActorManager_2fe60::*Fn_2fe60)();

template <> void Closure0<CActorManager, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; int b = (int)__p1; float * out = (float *)__p2;

    CActorManager_2fe60* m = (*(CActorManager_2fe60 * *)&this->f_20);
    Fn_2fe60 fn = (*(Fn_2fe60 *)&this->f_1c);
    float v = (m->*fn)();
    if (out)
        *out = v;
}
