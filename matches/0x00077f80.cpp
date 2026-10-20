#include "compat/ptr.h"
#include "gen/global.h"

extern void* __cdecl FUN_0008d690(hulk_uintptr);
struct Helper_77f80 {
    unsigned int call(CHeliDeathSpiralTrack*, unsigned int);
};

int CHeliDeathSpiralTrack::vfunc_12(int __p0) { unsigned int x = (unsigned int)__p0;

    void* p = FUN_0008d690(0x48);
    if (p)
        return (int)(((Helper_77f80*)p)->call(this, x));
    return (int)(0);
}
