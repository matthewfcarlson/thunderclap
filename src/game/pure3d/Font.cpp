// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000f8690..0x000f86f0 (kind game, layer game, confidence medium), dominant class pure3d::Font
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/content.h"
#define TREE_TU_BEGIN namespace fn_ffda38de {
#define TREE_TU_END }
namespace fn_ffda38de {} using namespace fn_ffda38de;
#include "game/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_ffda38de {
typedef unsigned int u32_f8690;

} // namespace fn_ffda38de

// 0x000f8690 content::LoadInventory::DynamicCaster<pure3d::Font>::vfunc_0 (30 B): matches/0x000f8690.cpp
// sym: ?vfunc_0@?$DynamicCaster@VFont@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::Font>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}

