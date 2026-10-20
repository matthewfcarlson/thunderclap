#include "compat/ptr.h"
#include "gen/global.h"

class CActorManager_2e800 {
  public:
    float Method(const char*);
};
typedef float (CActorManager_2e800::*Fn_2e800)(const char*);

template <> void Closure1<CActorManager, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr ignored = (hulk_intptr)__p0; const char ** arg = (const char **)__p1; float * out = (float *)__p2;

    CActorManager_2e800* obj = (*(CActorManager_2e800 * *)&this->f_20);
    Fn_2e800 fn = (*(Fn_2e800 *)&this->f_1c);
    float value = (obj->*fn)(*arg);
    if (out)
        *out = value;
}
