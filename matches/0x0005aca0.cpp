// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

struct CGrappleDetachAction_nv_5aca0 {
    int invoke(CGrappleDetachTrack*, int);
};
extern CGrappleDetachAction* FUN_0008d690(int);

int CGrappleDetachTrack::vfunc_12(int param) {
    CGrappleDetachAction* p = FUN_0008d690(0x24);
    if (p)
        return ((CGrappleDetachAction_nv_5aca0*)(((CGrappleDetachAction*)(p))))->invoke(this, param);
    return 0;
}
