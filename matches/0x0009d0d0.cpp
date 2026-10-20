// Same code shape as 0x0002fe60 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

class CActorManager_9d0d0 {
  public:
    float Get();
};
typedef float (CActorManager_9d0d0::*Fn_9d0d0)();

template <> void Closure0<CCameraManager, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr b = (hulk_intptr)__p1; float * out = (float *)__p2;

    CActorManager_9d0d0* m = (*(CActorManager_9d0d0 * *)&this->f_20);
    Fn_9d0d0 fn = (*(Fn_9d0d0 *)&this->f_1c);
    float v = (m->*fn)();
    if (out)
        *out = v;
}
