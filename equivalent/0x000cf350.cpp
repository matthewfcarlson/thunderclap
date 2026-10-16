// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method5<HUDOverlay,int,int,const_char_*,math::Vector,math::Vector,math::Vector>::vfunc_2 @ 0x000cf350
#include "gen/global.h"

struct Vec_cf350 {
    unsigned int x, y, z;
};

class HUDOverlay_cf350 {
public:
    int Act(int a1, const char *a2, Vec_cf350 v3, Vec_cf350 v4, Vec_cf350 v5);
};

typedef int (HUDOverlay_cf350::*ActFn_cf350)(int, const char *, Vec_cf350, Vec_cf350, Vec_cf350);

struct Args_cf350 {
    int a1;
    const char *a2;
    Vec_cf350 v3;
    Vec_cf350 v4;
    Vec_cf350 v5;
};

class Function_cf350 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method5<HUDOverlay, int, int, const char *,math::Vector,math::Vector,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { HUDOverlay_cf350 * obj = (HUDOverlay_cf350 *)__p0; Args_cf350 * args = (Args_cf350 *)__p1; int * out = (int *)__p2;

    ActFn_cf350 fn = (*(ActFn_cf350 *)&this->f_1c);
    int r = (obj->*fn)(args->a1, args->a2, args->v3, args->v4, args->v5);
    if (out)
        *out = r;
}
