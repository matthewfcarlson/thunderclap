// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00284a10..0x002878b0 (kind game, layer engine, confidence high), dominant class pure3d::DefaultFrameControllerHandler
// (tree_prelude.h: not needed)


// 0x00286500 pure3d::BlendFrameController::vfunc_2 (30 B): matches/0x00286500.cpp [isolated: conflict: pure3d::BlendFrameController::~BlendFrameController; on include/gen/ and not mergeable]
// sym: ?vfunc_2@BlendFrameController_286500@fn_00286500@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/pure3d.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (wasm10, D114) an explicit function: `pure3d::BlendFrameController::~BlendFrameController() {}` stood for it:
// the port builds bound the `??_G`'s destructor call to that empty definition, so the body never ran (wasm
// play3 leaked a CPathAgent's move agent this way, 0x00105e30). The destructor's body 0x00285f50, then (flags & 1) operator delete.
namespace fn_00286500 {
struct BlendFrameController_286500 {
    void FUN_00285f50();   // the destructor's body
    void* vfunc_2(unsigned int flags);
};
void* BlendFrameController_286500::vfunc_2(unsigned int flags) {
    FUN_00285f50();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00286500
// the destructor itself, which other objects' code references:
pure3d::BlendFrameController::~BlendFrameController() {}

