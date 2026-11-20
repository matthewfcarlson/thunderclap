// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000d40e0..0x000d6e00 (kind game, layer game, confidence high), dominant class MessageOverlay
// (tree_prelude.h: not needed)


// 0x000d6130 Closure3<MessageOverlay,void,const_char_*,int,math::Vector>::vfunc_0 (30 B): matches/0x000d6130.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ?vfunc_0@Closure3_d6130@fn_000d6130@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure3<MessageOverlay, void, const char *,
// int,math::Vector>::~Closure3() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body
// 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000d6130 {
struct Closure3_d6130 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure3_d6130::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000d6130

