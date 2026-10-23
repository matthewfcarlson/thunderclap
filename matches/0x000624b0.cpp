// Same code shape as 0x00062300 (propagated; names are from that function)
#include "gen/global.h"

struct CSmartPropUpdateAttachmentAction_nv_624b0 {
    int f(CSmartPropUpdateAttachmentTrack*, int);
};
extern "C" CSmartPropUpdateAttachmentAction* __cdecl FUN_0008d690(int);

int CSmartPropUpdateAttachmentTrack::vfunc_12(int a) {
    CSmartPropUpdateAttachmentAction* p = FUN_0008d690(0x2c);
    if (p)
        return ((CSmartPropUpdateAttachmentAction_nv_624b0*)(((CSmartPropUpdateAttachmentAction*)(p))))->f(this, a);
    return 0;
}
