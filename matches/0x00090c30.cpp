// Same code shape as 0x0002d750 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_90c30;
typedef bool(__fastcall* Fn_90c30)(CActorManager_90c30*);

template <> void Method0<CStatsManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_90c30 * obj = (CActorManager_90c30 *)__p0; void * a = (void *)__p1; unsigned char * out = (unsigned char *)__p2;

    Fn_90c30 fn = (*(Fn_90c30 *)&this->f_1c);
    bool r = fn(obj);
    if (out)
        *out = r;
}
