#include "gen/global.h"

extern void* __cdecl FUN_0008d690(unsigned int);
struct VScroll_nv_e49f0 {
    int make(void*, unsigned int);
};

int FEContainer::vfunc_22(int param) {
    void* p = FUN_0008d690(0x270);
    int r;
    if (p)
        r = ((VScroll_nv_e49f0*)(((VScroll*)(((VScroll*)p)))))->make(this, param);
    else
        r = 0;
    vfunc_21(r);
    return r;
}
