// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000cc7e0..0x000d40e0 (kind game, layer game, confidence high), dominant class HUDOverlay
// (tree_prelude.h: not needed)


// 0x000cffc0 Closure4<HUDOverlay,int,int,int,math::Vector,math::Vector>::vfunc_0 (30 B): matches/0x000cffc0.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ?vfunc_0@Closure4_cffc0@fn_000cffc0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure4<HUDOverlay, int, int,
// int,math::Vector,math::Vector>::~Closure4() {}` stood for it, whose MSVC `??_G` matched only under /GX. The
// destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000cffc0 {
struct Closure4_cffc0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure4_cffc0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000cffc0

