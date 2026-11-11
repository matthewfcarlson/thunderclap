// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010b2a0..0x0010c0d0 (kind game, layer game, confidence high), dominant class hulkfight::ai::FaceTargetAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0010bde0 hulkfight::ai::FaceMotionTrack::vfunc_10 (70 B): matches/0x0010bde0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@FaceMotionTrack@ai@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_10bde0 {
  public:
    int x;
};
extern Params_10bde0 TypeA_10bde0;
extern Params_10bde0 TypeB_10bde0;
int __cdecl Check(void*, int, Params_10bde0*, Params_10bde0*, int);
struct FaceMotionAction_nv_10bde0 {
    int Init(hulkfight::ai::FaceMotionTrack*, hulk_intptr);
};
hulkfight::ai::FaceMotionAction* __cdecl Alloc(int);

hulk_intptr hulkfight::ai::FaceMotionTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_10bde0, &TypeB_10bde0, 0);
    if (result) {
        hulkfight::ai::FaceMotionAction* p = Alloc(0x24);
        if (p)
            return ((FaceMotionAction_nv_10bde0*)(((hulkfight::ai::FaceMotionAction*)(p))))->Init(this, c);
    }
    return 0;
}

