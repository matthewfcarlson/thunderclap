// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

struct CSmartPropThrowAction_nv_62940 {
    int invoke(CSmartPropThrowTrack*, int);
};
extern CSmartPropThrowAction* FUN_0008d690(int);

int CSmartPropThrowTrack::vfunc_12(int param) {
    CSmartPropThrowAction* p = FUN_0008d690(0x24);
    if (p)
        return ((CSmartPropThrowAction_nv_62940*)(p))->invoke(this, param);
    return 0;
}
