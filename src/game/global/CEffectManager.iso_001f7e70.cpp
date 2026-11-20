// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f76c0..0x001f84d0 (kind game, layer game, confidence high), dominant class CEffectManager
// (tree_prelude.h: not needed)


// 0x001f7e70 Closure1<CEffectManager,unsigned_int,char_*>::vfunc_0 (30 B): matches/0x001f7e70.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ?vfunc_0@Closure1_1f7e70@fn_001f7e70@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure1<CEffectManager, unsigned int, char
// *>::~Closure1() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0, then
// (flags & 1) operator delete.
namespace fn_001f7e70 {
struct Closure1_1f7e70 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure1_1f7e70::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001f7e70

