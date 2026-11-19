// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001cc5e0..0x001d0360 (kind game, layer game, confidence high), dominant class CScenarioManager
// (tree_prelude.h: not needed)


// 0x001ce8b0 Closure1<CScenarioManager,eMissionObjectiveState,int>::vfunc_0 (30 B): matches/0x001ce8b0.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ?vfunc_0@Closure1_1ce8b0@fn_001ce8b0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure1<CScenarioManager,eMissionObjectiveState,
// int>::~Closure1() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0, then
// (flags & 1) operator delete.
namespace fn_001ce8b0 {
struct Closure1_1ce8b0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure1_1ce8b0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ce8b0
// the destructor itself, which other objects' code references natively:
template <> Closure1<CScenarioManager,eMissionObjectiveState, int>::~Closure1() {}
#if defined(HULK_PTR64)
template class Closure1<CScenarioManager,eMissionObjectiveState, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ce8b0)
#endif

