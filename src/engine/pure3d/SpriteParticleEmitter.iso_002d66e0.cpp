// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002d3dc0..0x002d6720 (kind game, layer engine, confidence high), dominant class pure3d::SpriteParticleEmitter
// (tree_prelude.h: not needed)


// 0x002d66e0 pure3d::SpriteParticleEmitter::vfunc_2 (30 B): matches/0x002d66e0.cpp [isolated: conflict: pure3d::SpriteParticleEmitter::~SpriteParticleEmitter; on include/gen/ and not mergeable]
// sym: ??_GSpriteParticleEmitter@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/pure3d.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::SpriteParticleEmitter::~SpriteParticleEmitter() {}

