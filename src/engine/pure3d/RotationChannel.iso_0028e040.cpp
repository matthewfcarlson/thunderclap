// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028dfc0..0x0028e0c0 (kind game, layer engine, confidence medium), dominant class pure3d::RotationChannel
// (tree_prelude.h: not needed)


// 0x0028e040 pure3d::Vector1DOFChannel::vfunc_0 (30 B): matches/0x0028e040.cpp [isolated: lost its match in the tree (ambiguous); on include/gen/ and not mergeable]
// sym: ?vfunc_0@Vector1DOFChannel_28e040@fn_0028e040@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/pure3d.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (wasm10, D114) an explicit function: `pure3d::Vector1DOFChannel::~Vector1DOFChannel() {}` stood for it:
// the port builds bound the `??_G`'s destructor call to that empty definition, so the body never ran (wasm
// play3 leaked a CPathAgent's move agent this way, 0x00105e30). The destructor's body 0x0028bdb0, then (flags & 1) operator delete.
namespace fn_0028e040 {
struct Vector1DOFChannel_28e040 {
    void FUN_0028bdb0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Vector1DOFChannel_28e040::vfunc_0(unsigned int flags) {
    FUN_0028bdb0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_0028e040
// the destructor itself, which other objects' code references:
pure3d::Vector1DOFChannel::~Vector1DOFChannel() {}

