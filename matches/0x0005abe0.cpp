// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

struct CGrappleSwapAction_nv_5abe0 {
    int invoke(CGrappleSwapTrack*, int);
};
extern CGrappleSwapAction* FUN_0008d690(int);

int CGrappleSwapTrack::vfunc_12(int param) {
    CGrappleSwapAction* p = FUN_0008d690(0x24);
    if (p)
        return ((CGrappleSwapAction_nv_5abe0*)(((CGrappleSwapAction*)(p))))->invoke(this, param);
    return 0;
}
