// Same code shape as 0x0002f6a0 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_1c00b0;
typedef bool(__fastcall* Fn_1c00b0)(CActorManager_1c00b0*);

template <> void Closure0<CSubtitleManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { bool * out = (bool *)__p2;

    CActorManager_1c00b0* o = (*(CActorManager_1c00b0 * *)&this->f_20);
    Fn_1c00b0 fn = (*(Fn_1c00b0 *)&this->f_1c);
    bool b = fn(o);
    if (out)
        *out = b;
}
