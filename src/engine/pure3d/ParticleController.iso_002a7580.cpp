// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a6fb0..0x002a7730 (kind game, layer engine, confidence high), dominant class pure3d::ParticleController
// (tree_prelude.h: not needed)


// 0x002a7580 pure3d::ParticleController::vfunc_2 (30 B): matches/0x002a7580.cpp [isolated: conflict: pure3d::ParticleController::~ParticleController; on include/gen/ and not mergeable]
// sym: ?vfunc_2@ParticleController_2a7580@fn_002a7580@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/pure3d.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (wasm10, D114) an explicit function: `pure3d::ParticleController::~ParticleController() {}` stood for it:
// the port builds bound the `??_G`'s destructor call to that empty definition, so the body never ran (wasm
// play3 leaked a CPathAgent's move agent this way, 0x00105e30). The destructor's body 0x002a74e0, then (flags & 1) operator delete.
namespace fn_002a7580 {
struct ParticleController_2a7580 {
    void FUN_002a74e0();   // the destructor's body
    void* vfunc_2(unsigned int flags);
};
void* ParticleController_2a7580::vfunc_2(unsigned int flags) {
    FUN_002a74e0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_002a7580
// the destructor itself, which other objects' code references:
pure3d::ParticleController::~ParticleController() {}

