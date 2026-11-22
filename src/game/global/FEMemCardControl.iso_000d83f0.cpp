// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000d7af0..0x000dc230 (kind game, layer game, confidence high), dominant class FEMemCardControl
// (tree_prelude.h: not needed)


// 0x000d83f0 FEMemCardControl::vfunc_2 (30 B): matches/0x000d83f0.cpp [isolated: conflict: FEMemCardControl::~FEMemCardControl; on include/gen/ and not mergeable]
// sym: ?vfunc_2@FEMemCardControl_d83f0@fn_000d83f0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (wasm10, D114) an explicit function: `FEMemCardControl::~FEMemCardControl() {}` stood for it:
// the port builds bound the `??_G`'s destructor call to that empty definition, so the body never ran (wasm
// play3 leaked a CPathAgent's move agent this way, 0x00105e30). The destructor's body 0x000d7db0, then (flags & 1) operator delete.
namespace fn_000d83f0 {
struct FEMemCardControl_d83f0 {
    void FUN_000d7db0();   // the destructor's body
    void* vfunc_2(unsigned int flags);
};
void* FEMemCardControl_d83f0::vfunc_2(unsigned int flags) {
    FUN_000d7db0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000d83f0
// the destructor itself, which other objects' code references:
FEMemCardControl::~FEMemCardControl() {}

