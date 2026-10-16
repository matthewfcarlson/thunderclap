// Same code shape as 0x0002f6a0 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_1b82a0;
typedef bool(__fastcall* Fn_1b82a0)(CActorManager_1b82a0*);

template <> void Closure0<CFMVManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { bool * out = (bool *)__p2;

    CActorManager_1b82a0* o = (*(CActorManager_1b82a0 * *)&this->f_20);
    Fn_1b82a0 fn = (*(Fn_1b82a0 *)&this->f_1c);
    bool b = fn(o);
    if (out)
        *out = b;
}
