#include "compat/ptr.h"
#include "gen/fight.h"

typedef float(__cdecl* Fn_2383a0)(int, int);
extern Fn_2383a0 globalFn;
extern int globalArg;
extern float zeroValue_2383a0;

bool fight::MaybeCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr b = (hulk_intptr)__p1; hulk_intptr c = (hulk_intptr)__p2;

    float x;
    if (globalFn == 0)
        x = 0.0f;
    else
        x = globalFn(b, globalArg);
    return 100.0f * x < this->f_0c;
}
