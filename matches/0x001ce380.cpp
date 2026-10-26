// Same code shape as 0x0002f6a0 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_1ce380;
typedef unsigned char(__fastcall* Fn_1ce380)(CActorManager_1ce380*);

template <> void Closure0<CScenarioManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * out = (unsigned char *)__p2;

    CActorManager_1ce380* o = (*(CActorManager_1ce380 * *)&this->f_20);
    Fn_1ce380 fn = (*(Fn_1ce380 *)&this->f_1c);
    unsigned char b = fn(o);
    if (out)
        *out = b;
}
