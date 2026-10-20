// Same code shape as 0x000e49f0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern void* __cdecl FUN_0008d690(hulk_uintptr);
struct VScroll_nv_e4f70 {
    int make(void*, unsigned int);
};

int FEScreenBase::vfunc_22(int param) {
    void* p = FUN_0008d690(0x270);
    int r;
    if (p)
        r = ((VScroll_nv_e4f70*)(((VScroll*)p)))->make(this, param);
    else
        r = 0;
    vfunc_21(r);
    return r;
}
