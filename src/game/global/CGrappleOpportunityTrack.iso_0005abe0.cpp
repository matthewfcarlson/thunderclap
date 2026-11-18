// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005a740..0x0005d190 (kind game, layer game, confidence high), merged by D32: global/CGrappleOpportunityTrack.cpp
// piece 0x0005a740..0x0005c6b0 (kind game, layer game, confidence high, dominant class CGrappleOpportunityTrack)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0005abe0 CGrappleSwapTrack::vfunc_12 (40 B): matches/0x0005abe0.cpp [isolated: conflict: FUN_0008d690; on include/gen/ and not mergeable]
// sym: ?vfunc_12@CGrappleSwapTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"
struct AllocWords_5abe0 : ::CGrappleSwapAction {   // (sweep-allocsize) gen's words and the allocation's last word (gen's size is its
    int last;                                     // last field's end, 4 short of the 0x24-byte allocation)
};
typedef char AllocWords_5abe0_size32[(sizeof(void*) != 4 || sizeof(AllocWords_5abe0) == 0x24) ? 1 : -1];

struct CGrappleSwapAction_nv_5abe0 {
    int invoke_0001dd50(CGrappleSwapTrack*, hulk_intptr);
};
extern CGrappleSwapAction* FUN_0008d690(int);

hulk_intptr CGrappleSwapTrack::vfunc_12(hulk_intptr param) {
    CGrappleSwapAction* p = FUN_0008d690(sizeof(AllocWords_5abe0));
    if (p)
        return ((CGrappleSwapAction_nv_5abe0*)(((CGrappleSwapAction*)(p))))->invoke_0001dd50(this, param);
    return 0;
}

