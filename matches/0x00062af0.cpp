// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

struct CSmartPropDropAction_62af0 {
    int invoke(CSmartPropDropTrack*, int);
};
extern CSmartPropDropAction* FUN_0008d690(int);

int CSmartPropDropTrack::vfunc_12(int param) {
    CSmartPropDropAction* p = FUN_0008d690(0x24);
    if (p)
        return ((CSmartPropDropAction_62af0*)(p))->invoke(this, param);
    return 0;
}
