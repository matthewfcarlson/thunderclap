// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00320160..0x00325ee0 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dExtFramebufferEffects
// (tree_prelude.h: not needed)


// 0x003250f0 pure3d::d3dContext::vfunc_3 (30 B): matches/0x003250f0.cpp [isolated: conflict: pure3d::d3dContext::~d3dContext; on include/gen/ and not mergeable]
// sym: ?vfunc_3@d3dContext_3250f0@fn_003250f0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/pure3d.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (wasm10, D114) an explicit function: `pure3d::d3dContext::~d3dContext() {}` stood for it:
// the port builds bound the `??_G`'s destructor call to that empty definition, so the body never ran (wasm
// play3 leaked a CPathAgent's move agent this way, 0x00105e30). The destructor's body 0x00323cd0, then (flags & 1) operator delete.
namespace fn_003250f0 {
struct d3dContext_3250f0 {
    void FUN_00323cd0();   // the destructor's body
    void* vfunc_3(unsigned int flags);
};
void* d3dContext_3250f0::vfunc_3(unsigned int flags) {
    FUN_00323cd0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_003250f0
// the destructor itself, which other objects' code references:
pure3d::d3dContext::~d3dContext() {}

