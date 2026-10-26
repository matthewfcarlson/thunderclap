// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

struct CSmartPropSetStateAction_nv_627a0 {
    int invoke(CSmartPropSetStateTrack*, hulk_intptr);
};
extern CSmartPropSetStateAction* FUN_0008d690(int);

hulk_intptr CSmartPropSetStateTrack::vfunc_12(hulk_intptr param) {
    CSmartPropSetStateAction* p = FUN_0008d690(0x24);
    if (p)
        return ((CSmartPropSetStateAction_nv_627a0*)(((CSmartPropSetStateAction*)(p))))->invoke(this, param);
    return 0;
}
