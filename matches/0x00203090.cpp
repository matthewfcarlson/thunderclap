// Same code shape as 0x0002fe60 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_203090 {
  public:
    float Get();
};
typedef float (CActorManager_203090::*Fn_203090)();

template <> void Closure0<CWorldCollisionManager, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; int b = (int)__p1; float * out = (float *)__p2;

    CActorManager_203090* m = (*(CActorManager_203090 * *)&this->f_20);
    Fn_203090 fn = (*(Fn_203090 *)&this->f_1c);
    float v = (m->*fn)();
    if (out)
        *out = v;
}
