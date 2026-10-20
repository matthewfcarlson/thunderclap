// Same code shape as 0x0002e800 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

class CActorManager_1ffad0 {
  public:
    float Method(const char*);
};
typedef float (CActorManager_1ffad0::*Fn_1ffad0)(const char*);

template <> void Closure1<CTriggerVolumeManager, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr ignored = (hulk_intptr)__p0; const char ** arg = (const char **)__p1; float * out = (float *)__p2;

    CActorManager_1ffad0* obj = (*(CActorManager_1ffad0 * *)&this->f_20);
    Fn_1ffad0 fn = (*(Fn_1ffad0 *)&this->f_1c);
    float value = (obj->*fn)(*arg);
    if (out)
        *out = value;
}
