// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c3670..0x002c3aa0 (kind game, layer engine, confidence high), dominant class pure3d::TextBible
// (tree_prelude.h: not needed)


// 0x002c3a80 pure3d::TextBible::vfunc_2 (30 B): matches/0x002c3a80.cpp [isolated: conflict: pure3d::TextBible::~TextBible; on include/gen/ and not mergeable]
// sym: ?vfunc_2@TextBible_2c3a80@fn_002c3a80@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/pure3d.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (wasm10, D114) an explicit function: `pure3d::TextBible::~TextBible() {}` stood for it:
// the port builds bound the `??_G`'s destructor call to that empty definition, so the body never ran (wasm
// play3 leaked a CPathAgent's move agent this way, 0x00105e30). The destructor's body 0x002c3a20, then (flags & 1) operator delete.
namespace fn_002c3a80 {
struct TextBible_2c3a80 {
    void FUN_002c3a20();   // the destructor's body
    void* vfunc_2(unsigned int flags);
};
void* TextBible_2c3a80::vfunc_2(unsigned int flags) {
    FUN_002c3a20();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_002c3a80
// the destructor itself, which other objects' code references:
pure3d::TextBible::~TextBible() {}

