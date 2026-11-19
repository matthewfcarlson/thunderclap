// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00203870..0x00208b9c (kind game, layer game, confidence high), dominant class CWorldStreamManager
// (tree_prelude.h: not needed)


// 0x00206040 Closure1<CWorldStreamManager,bool,int>::vfunc_0 (30 B): matches/0x00206040.cpp [isolated: lost its match in the tree (ambiguous); on include/gen/ and not mergeable]
// sym: ?vfunc_0@Closure1_206040@fn_00206040@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure1<CWorldStreamManager, bool,
// int>::~Closure1() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0, then
// (flags & 1) operator delete.
namespace fn_00206040 {
struct Closure1_206040 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure1_206040::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00206040
// the destructor itself, which other objects' code references natively:
template <> Closure1<CWorldStreamManager, bool, int>::~Closure1() {}
#if defined(HULK_PTR64)
template class Closure1<CWorldStreamManager, bool, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x206040)
#endif

