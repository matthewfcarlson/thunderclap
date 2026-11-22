// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005a740..0x0005d190 (kind game, layer game, confidence high), merged by D32: global/CGrappleOpportunityTrack.cpp
// piece 0x0005a740..0x0005c6b0 (kind game, layer game, confidence high, dominant class CGrappleOpportunityTrack)
// (tree_prelude.h: not needed)


// 0x0005b770 CGrappleLocoStrafe4Track::vfunc_5 (30 B): matches/0x0005b770.cpp [isolated: conflict: CGrappleLocoStrafe4Track::~CGrappleLocoStrafe4Track; on include/gen/ and not mergeable]
// sym: ?vfunc_5@CGrappleLocoStrafe4Track_5b770@fn_0005b770@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (wasm10, D114) an explicit function: `CGrappleLocoStrafe4Track::~CGrappleLocoStrafe4Track() {}` stood for it:
// the port builds bound the `??_G`'s destructor call to that empty definition, so the body never ran (wasm
// play3 leaked a CPathAgent's move agent this way, 0x00105e30). The destructor's body 0x0005a870, then (flags & 1) operator delete.
namespace fn_0005b770 {
struct CGrappleLocoStrafe4Track_5b770 {
    void FUN_0005a870();   // the destructor's body
    void* vfunc_5(unsigned int flags);
};
void* CGrappleLocoStrafe4Track_5b770::vfunc_5(unsigned int flags) {
    FUN_0005a870();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_0005b770
// the destructor itself, which other objects' code references:
CGrappleLocoStrafe4Track::~CGrappleLocoStrafe4Track() {}

