// Same code shape as 0x0002f6a0 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_8b010;
typedef bool(__fastcall* Fn_8b010)(CActorManager_8b010*);

template <> void Closure0<CGameFlowManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { bool * out = (bool *)__p2;

    CActorManager_8b010* o = (*(CActorManager_8b010 * *)&this->f_20);
    Fn_8b010 fn = (*(Fn_8b010 *)&this->f_1c);
    bool b = fn(o);
    if (out)
        *out = b;
}
