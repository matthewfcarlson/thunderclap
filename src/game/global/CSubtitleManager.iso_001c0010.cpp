// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001be0e0..0x001c1200 (kind game, layer game, confidence high), dominant class CSubtitleManager
// (tree_prelude.h: not needed)


// 0x001c0010 Closure2<CSubtitleManager,void,int,const_char_*>::vfunc_0 (30 B): matches/0x001c0010.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ?vfunc_0@Closure2_1c0010@fn_001c0010@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure2<CSubtitleManager, void, int, const char
// *>::~Closure2() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0, then
// (flags & 1) operator delete.
namespace fn_001c0010 {
struct Closure2_1c0010 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure2_1c0010::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001c0010
// the destructor itself, which other objects' code references natively:
template <> Closure2<CSubtitleManager, void, int, const char *>::~Closure2() {}
#if defined(HULK_PTR64)
template class Closure2<CSubtitleManager, void, int, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1c0010)
#endif

