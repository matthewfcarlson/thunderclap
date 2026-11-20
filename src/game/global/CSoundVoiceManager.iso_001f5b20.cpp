// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f2e40..0x001f6bc0 (kind game, layer game, confidence high), dominant class CSoundVoiceManager
// (tree_prelude.h: not needed)


// 0x001f5b20 Closure4<CSoundVoiceManager,void,char_*,char_*,char_*,int>::vfunc_0 (30 B): matches/0x001f5b20.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ?vfunc_0@Closure4_1f5b20@fn_001f5b20@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure4<CSoundVoiceManager, void, char *, char *,
// char *, int>::~Closure4() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body
// 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001f5b20 {
struct Closure4_1f5b20 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure4_1f5b20::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001f5b20

