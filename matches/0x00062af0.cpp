// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

struct CSmartPropDropAction_nv_62af0 {
    int invoke(CSmartPropDropTrack*, int);
};
extern CSmartPropDropAction* FUN_0008d690(int);

hulk_intptr CSmartPropDropTrack::vfunc_12(hulk_intptr param) {
    CSmartPropDropAction* p = FUN_0008d690(0x24);
    if (p)
        return ((CSmartPropDropAction_nv_62af0*)(((CSmartPropDropAction*)(p))))->invoke(this, param);
    return 0;
}
