// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000bba40..0x000bbb00 (kind game, layer game, confidence medium), dominant class pure3d::TextureFont
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/content.h"
#include "gen/core.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f5ef1000 {
#define TREE_TU_END }
namespace fn_f5ef1000 {} using namespace fn_f5ef1000;
#include "game/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f5ef1000 {
typedef unsigned int u32_bba40;

} // namespace fn_f5ef1000

// 0x000bba40 content::LoadInventory::DynamicCaster<pure3d::TextureFont>::vfunc_0 (30 B): matches/0x000bba40.cpp
// sym: ?vfunc_0@?$DynamicCaster@VTextureFont@pure3d@@@LoadInventory@content@@UAEPAXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void* content::LoadInventory::DynamicCaster<pure3d::TextureFont>::vfunc_0(void* p) {
    return dynamic_cast<::pure3d::TextureFont*>((::core::IRefCount*)p);   // (sweep2, G7) the cast is the slot's result
}

