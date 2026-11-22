// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028dfc0..0x0028e0c0 (kind game, layer engine, confidence medium), dominant class pure3d::RotationChannel
// (tree_prelude.h: not needed)


// 0x0028e060 pure3d::Vector2DOFChannel::vfunc_0 (30 B): matches/0x0028e060.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ?vfunc_0@Vector2DOFChannel_28e060@fn_0028e060@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/pure3d.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (wasm10, D114) an explicit function: `pure3d::Vector2DOFChannel::~Vector2DOFChannel() {}` stood for it:
// the port builds bound the `??_G`'s destructor call to that empty definition, so the body never ran (wasm
// play3 leaked a CPathAgent's move agent this way, 0x00105e30). The destructor's body 0x0028beb0, then (flags & 1) operator delete.
namespace fn_0028e060 {
struct Vector2DOFChannel_28e060 {
    void FUN_0028beb0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Vector2DOFChannel_28e060::vfunc_0(unsigned int flags) {
    FUN_0028beb0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_0028e060
// the destructor itself, which other objects' code references:
pure3d::Vector2DOFChannel::~Vector2DOFChannel() {}

