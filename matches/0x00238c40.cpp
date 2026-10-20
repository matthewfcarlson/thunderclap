#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_238c40;
extern void PrintSomething(hulk_uintptr, u32_238c40, const char*, u32_238c40);
char fmt_238c40[] = "%s\n";

bool fight::PrintCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { hulk_uintptr x = (hulk_uintptr)__p0; hulk_uintptr y = (hulk_uintptr)__p1; hulk_uintptr z = (hulk_uintptr)__p2;

    if ((*(u32_238c40 *)&this->f_10))
        PrintSomething(y, (*(u32_238c40 *)&this->f_0c), fmt_238c40, (*(u32_238c40 *)&this->f_10));
    return true;
}
