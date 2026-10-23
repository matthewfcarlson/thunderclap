#include "compat/ptr.h"
#include "gen/global.h"

extern "C" int __cdecl lookup(int);
struct MenuSelector_nv_efeb0 {
    int call(int, int);
};

int FEThingsBase::vfunc_59(int arg) {
    hulk_intptr p = lookup(0x3db0);
    if (p)
        return ((MenuSelector_nv_efeb0*)(((MenuSelector*)(((MenuSelector*)p)))))->call(arg, 0);
    return 0;
}
