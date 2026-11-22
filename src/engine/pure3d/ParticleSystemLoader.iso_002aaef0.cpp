// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002aa160..0x002ad790 (kind game, layer engine, confidence high), dominant class pure3d::ParticleSystemLoader
// (tree_prelude.h: not needed)


// 0x002aaef0 pure3d::DefaultParticleEmitterHandler::vfunc_2 (30 B): matches/0x002aaef0.cpp [isolated: lost its match in the tree (ambiguous); on include/gen/ and not mergeable]
// sym: ?vfunc_2@DefaultParticleEmitterHandler_2aaef0@fn_002aaef0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/pure3d.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (wasm10, D114) an explicit function: `pure3d::DefaultParticleEmitterHandler::~DefaultParticleEmitterHandler() {}` stood for it:
// the port builds bound the `??_G`'s destructor call to that empty definition, so the body never ran (wasm
// play3 leaked a CPathAgent's move agent this way, 0x00105e30). The destructor's body 0x002a3e90, then (flags & 1) operator delete.
namespace fn_002aaef0 {
struct DefaultParticleEmitterHandler_2aaef0 {
    void FUN_002a3e90();   // the destructor's body
    void* vfunc_2(unsigned int flags);
};
void* DefaultParticleEmitterHandler_2aaef0::vfunc_2(unsigned int flags) {
    FUN_002a3e90();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_002aaef0
// the destructor itself, which other objects' code references:
pure3d::DefaultParticleEmitterHandler::~DefaultParticleEmitterHandler() {}

