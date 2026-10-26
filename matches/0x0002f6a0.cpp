#include "gen/global.h"

class CActorManager_2f6a0;
typedef unsigned char(__fastcall* Fn_2f6a0)(CActorManager_2f6a0*);

template <> void Closure0<CActorManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * out = (unsigned char *)__p2;

    CActorManager_2f6a0* o = (*(CActorManager_2f6a0 * *)&this->f_20);
    Fn_2f6a0 fn = (*(Fn_2f6a0 *)&this->f_1c);
    unsigned char b = fn(o);
    if (out)
        *out = b;
}
