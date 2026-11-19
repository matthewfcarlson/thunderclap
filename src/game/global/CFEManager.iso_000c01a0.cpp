// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000be230..0x000c4ec0 (kind game, layer game, confidence high), dominant class CFEManager
// (tree_prelude.h: not needed)


// 0x000c01a0 Closure6<CFEManager,void,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x000c01a0.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ?vfunc_0@Closure6_c01a0@fn_000c01a0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure6<CFEManager, void, const char *, const char
// *, const char *, const char *, const char *, const char *>::~Closure6() {}` stood for it, whose MSVC `??_G` matched
// only under /GX. The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000c01a0 {
struct Closure6_c01a0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure6_c01a0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000c01a0
// the destructor itself, which other objects' code references natively:
template <> Closure6<CFEManager, void, const char *, const char *, const char *, const char *, const char *, const char *>::~Closure6() {}
#if defined(HULK_PTR64)
template class Closure6<CFEManager, void, const char *, const char *, const char *, const char *, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xc01a0)
#endif

