// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000ae9a0..0x000af110 (kind game, layer game, confidence high), dominant class CControllerManager
// (tree_prelude.h: not needed)


// 0x000aedc0 Closure1<CControllerManager,void,bool>::vfunc_0 (30 B): matches/0x000aedc0.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ?vfunc_0@Closure1_aedc0@fn_000aedc0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure1<CControllerManager, void,
// bool>::~Closure1() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0, then
// (flags & 1) operator delete.
namespace fn_000aedc0 {
struct Closure1_aedc0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure1_aedc0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000aedc0
// the destructor itself, which other objects' code references natively:
template <> Closure1<CControllerManager, void, bool>::~Closure1() {}
#if defined(HULK_PTR64)
template class Closure1<CControllerManager, void, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xaedc0)
#endif

