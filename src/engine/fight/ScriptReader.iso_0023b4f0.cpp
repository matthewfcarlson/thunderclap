// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023a3f0..0x0023b540 (kind game, layer engine, confidence high), dominant class fight::ScriptReader
// (tree_prelude.h: not needed)


// 0x0023b4f0 fight::ScriptReader::vfunc_2 (30 B): matches/0x0023b4f0.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ?vfunc_2@ScriptReader_23b4f0@fn_0023b4f0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/fight.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (wasm10, D114) an explicit function: `fight::ScriptReader::~ScriptReader() {}` stood for it:
// the port builds bound the `??_G`'s destructor call to that empty definition, so the body never ran (wasm
// play3 leaked a CPathAgent's move agent this way, 0x00105e30). The destructor's body 0x0023b3b0, then (flags & 1) operator delete.
namespace fn_0023b4f0 {
struct ScriptReader_23b4f0 {
    void FUN_0023b3b0();   // the destructor's body
    void* vfunc_2(unsigned int flags);
};
void* ScriptReader_23b4f0::vfunc_2(unsigned int flags) {
    FUN_0023b3b0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_0023b4f0
// the destructor itself, which other objects' code references:
fight::ScriptReader::~ScriptReader() {}

