// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00021650..0x00021680 (kind game, layer game, confidence medium), dominant class pure3d::Animation
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/content.h"
#include "gen/core.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fd35c540 {
#define TREE_TU_END }
namespace fn_fd35c540 {} using namespace fn_fd35c540;
#include "game/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fd35c540 {
typedef unsigned int u32_21650;

} // namespace fn_fd35c540

// 0x00021650 content::LoadInventory::DynamicCaster<pure3d::Animation>::vfunc_0 (30 B): matches/0x00021650.cpp
// sym: ?vfunc_0@?$DynamicCaster@VAnimation@pure3d@@@LoadInventory@content@@UAEPAXPAX@Z
template <> void* content::LoadInventory::DynamicCaster<pure3d::Animation>::vfunc_0(void* p) {
    return dynamic_cast<::pure3d::Animation*>((::core::IRefCount*)p);   // (sweep2, G7) the cast is the slot's result
}

