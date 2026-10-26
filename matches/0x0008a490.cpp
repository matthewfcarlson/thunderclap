// Same code shape as 0x0002d750 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_8a490;
typedef unsigned char(__fastcall* Fn_8a490)(CActorManager_8a490*);

template <> void Method0<CGameFlowManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_8a490 * obj = (CActorManager_8a490 *)__p0; void * a = (void *)__p1; unsigned char * out = (unsigned char *)__p2;

    Fn_8a490 fn = (*(Fn_8a490 *)&this->f_1c);
    unsigned char r = fn(obj);
    if (out)
        *out = r;
}
