// Same code shape as 0x0002f6a0 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_aecb0;
typedef unsigned char(__fastcall* Fn_aecb0)(CActorManager_aecb0*);

template <> void Closure0<CControllerManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * out = (unsigned char *)__p2;

    CActorManager_aecb0* o = (*(CActorManager_aecb0 * *)&this->f_20);
    Fn_aecb0 fn = (*(Fn_aecb0 *)&this->f_1c);
    unsigned char b = fn(o);
    if (out)
        *out = b;
}
