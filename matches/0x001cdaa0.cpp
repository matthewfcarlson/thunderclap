// Same code shape as 0x0002d750 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_1cdaa0;
typedef bool(__fastcall* Fn_1cdaa0)(CActorManager_1cdaa0*);

template <> void Method0<CScenarioManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1cdaa0 * obj = (CActorManager_1cdaa0 *)__p0; void * a = (void *)__p1; unsigned char * out = (unsigned char *)__p2;

    Fn_1cdaa0 fn = (*(Fn_1cdaa0 *)&this->f_1c);
    bool r = fn(obj);
    if (out)
        *out = r;
}
