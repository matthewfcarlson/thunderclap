// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

struct CSmartPropThrowingAction_nv_62a00 {
    int invoke(CSmartPropThrowingTrack*, int);
};
extern CSmartPropThrowingAction* FUN_0008d690(int);

hulk_intptr CSmartPropThrowingTrack::vfunc_12(hulk_intptr param) {
    CSmartPropThrowingAction* p = FUN_0008d690(0x24);
    if (p)
        return ((CSmartPropThrowingAction_nv_62a00*)(((CSmartPropThrowingAction*)(p))))->invoke(this, param);
    return 0;
}
