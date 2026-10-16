// Same code shape as 0x0002d750 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_aeb20;
typedef bool(__fastcall* Fn_aeb20)(CActorManager_aeb20*);

template <> void Method0<CControllerManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_aeb20 * obj = (CActorManager_aeb20 *)__p0; void * a = (void *)__p1; unsigned char * out = (unsigned char *)__p2;

    Fn_aeb20 fn = (*(Fn_aeb20 *)&this->f_1c);
    bool r = fn(obj);
    if (out)
        *out = r;
}
