// Same code shape as 0x00062300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

struct CSmartPropUpdateAttachmentAction_nv_624b0 {
    int f(CSmartPropUpdateAttachmentTrack*, int);
};
extern "C" CSmartPropUpdateAttachmentAction* __cdecl FUN_0008d690(int);

hulk_intptr CSmartPropUpdateAttachmentTrack::vfunc_12(hulk_intptr a) {
    CSmartPropUpdateAttachmentAction* p = FUN_0008d690(0x2c);
    if (p)
        return ((CSmartPropUpdateAttachmentAction_nv_624b0*)(((CSmartPropUpdateAttachmentAction*)(p))))->f(this, a);
    return 0;
}
