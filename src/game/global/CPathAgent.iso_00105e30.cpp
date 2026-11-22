// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001047b0..0x00106170 (kind game, layer game, confidence high), dominant class CPathAgent
// (tree_prelude.h: not needed)


// 0x00105e30 CPathAgent::vfunc_2 (30 B): matches/0x00105e30.cpp [isolated: conflict: CPathAgent::~CPathAgent; on include/gen/ and not mergeable]
// sym: ?vfunc_2@CPathAgent_105e30@fn_00105e30@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (wasm10, D114) an explicit function: `CPathAgent::~CPathAgent() {}` stood for it, and the port builds bound the
// `??_G`'s destructor call to that empty definition, so a CPathAgent never released its move agent (+0x60) or its
// graph (+0xc8) nor freed its path (+0x64): wasm play3 leaked a CMoveAgent and a CCharacterGolem at frame 513, and
// the game heap's later layout differed (a soldier's CPathGraphAgent got another block at 2005). The destructor's
// body 0x00105060, then (flags & 1) operator delete.
namespace fn_00105e30 {
struct CPathAgent_105e30 {
    void FUN_00105060();   // the destructor's body
    void* vfunc_2(unsigned int flags);
};
void* CPathAgent_105e30::vfunc_2(unsigned int flags) {
    FUN_00105060();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00105e30
// the destructor itself, which other objects' code references:
CPathAgent::~CPathAgent() {}

