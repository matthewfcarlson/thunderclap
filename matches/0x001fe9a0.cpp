// Same code shape as 0x0002c760 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_1fe9a0;
typedef float (CActorManager_1fe9a0::*Fn_1fe9a0)(const char*);
class CActorManager_1fe9a0 {
  public:
    float Get(const char* s);
};

template <> void Method1<CTriggerVolumeManager, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1fe9a0 * a = (CActorManager_1fe9a0 *)__p0; const char ** p = (const char **)__p1; float * out = (float *)__p2;

    Fn_1fe9a0 f = (*(Fn_1fe9a0 *)&this->f_1c);
    const char* s = *p;
    float x = (a->*f)(s);
    if (out)
        *out = x;
}
