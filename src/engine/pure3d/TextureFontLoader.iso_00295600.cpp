// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00294b00..0x00295c40 (kind game, layer engine, confidence high), dominant class pure3d::TextureFontLoader
// (tree_prelude.h: not needed)


// 0x00295600 pure3d::TextureFont::vfunc_2 (30 B): matches/0x00295600.cpp [isolated: conflict: pure3d::TextureFont::~TextureFont; on include/gen/ and not mergeable]
// sym: ??_GTextureFont@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/pure3d.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::TextureFont::~TextureFont() {}

