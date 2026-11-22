// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00294b00..0x00295c40 (kind game, layer engine, confidence high), dominant class pure3d::TextureFontLoader
// (tree_prelude.h: not needed)


// 0x00295600 pure3d::TextureFont::vfunc_2 (30 B): matches/0x00295600.cpp [isolated: conflict: pure3d::TextureFont::~TextureFont; on include/gen/ and not mergeable]
// sym: ?vfunc_2@TextureFont_295600@fn_00295600@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/pure3d.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (wasm10, D114) an explicit function: `pure3d::TextureFont::~TextureFont() {}` stood for it:
// the port builds bound the `??_G`'s destructor call to that empty definition, so the body never ran (wasm
// play3 leaked a CPathAgent's move agent this way, 0x00105e30). The destructor's body 0x00295520, then (flags & 1) operator delete.
namespace fn_00295600 {
struct TextureFont_295600 {
    void FUN_00295520();   // the destructor's body
    void* vfunc_2(unsigned int flags);
};
void* TextureFont_295600::vfunc_2(unsigned int flags) {
    FUN_00295520();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00295600
// the destructor itself, which other objects' code references:
pure3d::TextureFont::~TextureFont() {}

