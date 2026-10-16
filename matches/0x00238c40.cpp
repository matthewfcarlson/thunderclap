#include "gen/fight.h"

typedef unsigned int u32_238c40;
extern void PrintSomething(u32_238c40, u32_238c40, const char*, u32_238c40);
char fmt_238c40[] = "%s\n";

bool fight::PrintCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { u32_238c40 x = (u32_238c40)__p0; u32_238c40 y = (u32_238c40)__p1; u32_238c40 z = (u32_238c40)__p2;

    if ((*(u32_238c40 *)&this->f_10))
        PrintSomething(y, (*(u32_238c40 *)&this->f_0c), fmt_238c40, (*(u32_238c40 *)&this->f_10));
    return true;
}
