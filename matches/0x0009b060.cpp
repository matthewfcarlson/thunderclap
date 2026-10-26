// Same code shape as 0x0002d750 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_9b060;
typedef unsigned char(__fastcall* Fn_9b060)(CActorManager_9b060*);

template <> void Method0<CCameraManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_9b060 * obj = (CActorManager_9b060 *)__p0; void * a = (void *)__p1; unsigned char * out = (unsigned char *)__p2;

    Fn_9b060 fn = (*(Fn_9b060 *)&this->f_1c);
    unsigned char r = fn(obj);
    if (out)
        *out = r;
}
