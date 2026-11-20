// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00203870..0x00208b9c (kind game, layer game, confidence high), dominant class CWorldStreamManager
// (tree_prelude.h: not needed)


// 0x00206140 Closure0<CWorldStreamManager,void>::vfunc_0 (30 B): matches/0x00206140.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ?vfunc_0@Closure0_206140@fn_00206140@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure0<CWorldStreamManager, void>::~Closure0() {}`
// stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0, then (flags & 1) operator
// delete.
namespace fn_00206140 {
struct Closure0_206140 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure0_206140::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00206140

