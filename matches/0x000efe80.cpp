#include "gen/global.h"

extern void* __cdecl GetThing(int);
struct Helper_efe80 {
    int DoThing(void*, int);
};

int FEThingsBase::vfunc_58(void* __p0) { void * p = (void *)__p0;

    void* q = GetThing(0x1da8);
    if (q)
        return ((Helper_efe80*)q)->DoThing(p, 0);
    return 0;
}
