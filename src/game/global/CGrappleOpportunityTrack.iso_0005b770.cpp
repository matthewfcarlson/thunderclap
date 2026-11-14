// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0005a740..0x0005c6b0 (kind game, layer game, confidence high), dominant class CGrappleOpportunityTrack
// (tree_prelude.h: not needed)


// 0x0005b770 CGrappleLocoStrafe4Track::vfunc_5 (30 B): matches/0x0005b770.cpp [isolated: conflict: CGrappleLocoStrafe4Track::~CGrappleLocoStrafe4Track; on include/gen/ and not mergeable]
// sym: ??_GCGrappleLocoStrafe4Track@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CGrappleLocoStrafe4Track::~CGrappleLocoStrafe4Track() {}

