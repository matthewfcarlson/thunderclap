// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0027ca80..0x0027f2a0 (kind game, layer engine, confidence high), dominant class pure3d::prop::StateProp
// (tree_prelude.h: not needed)


// 0x0027e900 pure3d::prop::StateProp::vfunc_2 (30 B): matches/0x0027e900.cpp [isolated: conflict: pure3d::prop::StateProp::~StateProp; on include/gen/ and not mergeable]
// sym: ?vfunc_2@StateProp_27e900@fn_0027e900@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/pure3d.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (wasm10, D114) an explicit function: `pure3d::prop::StateProp::~StateProp() {}` stood for it:
// the port builds bound the `??_G`'s destructor call to that empty definition, so the body never ran (wasm
// play3 leaked a CPathAgent's move agent this way, 0x00105e30). The destructor's body 0x0027e2d0, then (flags & 1) operator delete.
namespace fn_0027e900 {
struct StateProp_27e900 {
    void FUN_0027e2d0();   // the destructor's body
    void* vfunc_2(unsigned int flags);
};
void* StateProp_27e900::vfunc_2(unsigned int flags) {
    FUN_0027e2d0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_0027e900
// the destructor itself, which other objects' code references:
pure3d::prop::StateProp::~StateProp() {}

