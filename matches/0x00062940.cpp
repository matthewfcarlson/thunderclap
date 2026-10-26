// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

struct CSmartPropThrowAction_nv_62940 {
    int invoke(CSmartPropThrowTrack*, hulk_intptr);
};
extern CSmartPropThrowAction* FUN_0008d690(int);

hulk_intptr CSmartPropThrowTrack::vfunc_12(hulk_intptr param) {
    CSmartPropThrowAction* p = FUN_0008d690(0x24);
    if (p)
        return ((CSmartPropThrowAction_nv_62940*)(((CSmartPropThrowAction*)(p))))->invoke(this, param);
    return 0;
}
