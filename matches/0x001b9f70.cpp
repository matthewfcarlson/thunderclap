// Same code shape as 0x0002d750 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_1b9f70;
typedef unsigned char(__fastcall* Fn_1b9f70)(CActorManager_1b9f70*);

template <> void Method0<CRenderManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1b9f70 * obj = (CActorManager_1b9f70 *)__p0; void * a = (void *)__p1; unsigned char * out = (unsigned char *)__p2;

    Fn_1b9f70 fn = (*(Fn_1b9f70 *)&this->f_1c);
    unsigned char r = fn(obj);
    if (out)
        *out = r;
}
