// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000c96e0..0x000c9700 (kind game, layer game, confidence medium), dominant class pure3d::Geometry
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/content.h"
#include "gen/core.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f9189646 {
#define TREE_TU_END }
namespace fn_f9189646 {} using namespace fn_f9189646;
#include "game/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f9189646 {
typedef unsigned int u32_c96e0;

} // namespace fn_f9189646

// 0x000c96e0 content::LoadInventory::DynamicCaster<pure3d::Geometry>::vfunc_0 (30 B): matches/0x000c96e0.cpp
// sym: ?vfunc_0@?$DynamicCaster@VGeometry@pure3d@@@LoadInventory@content@@UAEPAXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void* content::LoadInventory::DynamicCaster<pure3d::Geometry>::vfunc_0(void* p) {
    return dynamic_cast<::pure3d::Geometry*>((::core::IRefCount*)p);   // (sweep2, G7) the cast is the slot's result
}

