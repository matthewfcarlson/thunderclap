// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000f1060..0x000f10c0 (kind game, layer game, confidence medium), dominant class pure3d::LightGroup
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/content.h"
#include "gen/core.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f121af0f {
#define TREE_TU_END }
namespace fn_f121af0f {} using namespace fn_f121af0f;
#include "game/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f121af0f {
typedef unsigned int u32_f1060;

} // namespace fn_f121af0f

// 0x000f1060 content::LoadInventory::DynamicCaster<pure3d::LightGroup>::vfunc_0 (30 B): matches/0x000f1060.cpp
// sym: ?vfunc_0@?$DynamicCaster@VLightGroup@pure3d@@@LoadInventory@content@@UAEPAXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void* content::LoadInventory::DynamicCaster<pure3d::LightGroup>::vfunc_0(void* p) {
    return dynamic_cast<::pure3d::LightGroup*>((::core::IRefCount*)p);   // (sweep2, G7) the cast is the slot's result
}

