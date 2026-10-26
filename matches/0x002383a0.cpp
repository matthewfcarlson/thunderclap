#include "decls/data/engine/fight.h"
// data: globalArg = DAT_004e5c1c, globalFn = DAT_004caa24

#include "compat/ptr.h"
#include "gen/fight.h"

typedef float(__cdecl* Fn_2383a0)(int, int);
extern float zeroValue_2383a0;

bool fight::MaybeCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr b = (hulk_intptr)__p1; hulk_intptr c = (hulk_intptr)__p2;

    float x;
    if ((*(Fn_2383a0*)&DAT_004caa24) == 0)
        x = 0.0f;
    else
        x = (*(Fn_2383a0*)&DAT_004caa24)(b, (*(int*)&DAT_004e5c1c));
    return 100.0f * x < this->f_0c;
}
