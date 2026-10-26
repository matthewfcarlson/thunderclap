#include "compat/ptr.h"
#include "gen/global.h"

extern "C" void* __cdecl FUN_0008d690(int);
struct Worker_6a010 {
    int go(unsigned int, unsigned int);
};

hulk_intptr CComboTimerTrack::vfunc_12(hulk_intptr __p0) { unsigned int param = (unsigned int)__p0;

    void* p = FUN_0008d690(0x24);
    if (p)
        return ((Worker_6a010*)p)->go(param, this->f_14);
    return 0;
}
