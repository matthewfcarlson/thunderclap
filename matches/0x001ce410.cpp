// Same code shape as 0x0002e800 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_1ce410 {
  public:
    float Method(const char*);
};
typedef float (CActorManager_1ce410::*Fn_1ce410)(const char*);

template <> void Closure1<CScenarioManager, float, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { int ignored = (int)__p0; const char ** arg = (const char **)__p1; float * out = (float *)__p2;

    CActorManager_1ce410* obj = (*(CActorManager_1ce410 * *)&this->f_20);
    Fn_1ce410 fn = (*(Fn_1ce410 *)&this->f_1c);
    float value = (obj->*fn)(*arg);
    if (out)
        *out = value;
}
