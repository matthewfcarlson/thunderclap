// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000788e0..0x00081340 (kind game, layer game, confidence high), dominant class CAmbientsManager
// (tree_prelude.h: not needed)


// 0x0007af60 CAmbientsManager::vfunc_0 (30 B): matches/0x0007af60.cpp [isolated: conflict: CAmbientsManager::~CAmbientsManager; on include/gen/ and not mergeable]
// sym: ?vfunc_0@CAmbientsManager_7af60@fn_0007af60@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (wasm10, D114) an explicit function: `CAmbientsManager::~CAmbientsManager() {}` stood for it:
// the port builds bound the `??_G`'s destructor call to that empty definition, so the body never ran (wasm
// play3 leaked a CPathAgent's move agent this way, 0x00105e30). The destructor's body 0x00078bc0, then (flags & 1) operator delete.
namespace fn_0007af60 {
struct CAmbientsManager_7af60 {
    void FUN_00078bc0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* CAmbientsManager_7af60::vfunc_0(unsigned int flags) {
    FUN_00078bc0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_0007af60
// the destructor itself, which other objects' code references:
CAmbientsManager::~CAmbientsManager() {}

