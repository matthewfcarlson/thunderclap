#include "gen/global.h"

class CActorManager_2d750;
typedef bool(__fastcall* Fn_2d750)(CActorManager_2d750*);

template <> void Method0<CActorManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2d750 * obj = (CActorManager_2d750 *)__p0; void * a = (void *)__p1; unsigned char * out = (unsigned char *)__p2;

    Fn_2d750 fn = (*(Fn_2d750 *)&this->f_1c);
    bool r = fn(obj);
    if (out)
        *out = r;
}
