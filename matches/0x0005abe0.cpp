// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

struct CGrappleSwapAction_nv_5abe0 {
    int invoke(CGrappleSwapTrack*, hulk_intptr);
};
extern CGrappleSwapAction* FUN_0008d690(int);

hulk_intptr CGrappleSwapTrack::vfunc_12(hulk_intptr param) {
    CGrappleSwapAction* p = FUN_0008d690(0x24);
    if (p)
        return ((CGrappleSwapAction_nv_5abe0*)(((CGrappleSwapAction*)(p))))->invoke(this, param);
    return 0;
}
