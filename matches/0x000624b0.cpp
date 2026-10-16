// Same code shape as 0x00062300 (propagated; names are from that function)
#include "gen/global.h"

struct Helper_624b0 {
    int f(CSmartPropUpdateAttachmentTrack*, int);
};
extern "C" Helper_624b0* __cdecl FUN_0008d690(int);

int CSmartPropUpdateAttachmentTrack::vfunc_12(int a) {
    Helper_624b0* p = FUN_0008d690(0x2c);
    if (p)
        return p->f(this, a);
    return 0;
}
