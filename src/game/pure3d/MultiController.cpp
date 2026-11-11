// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000f1030..0x000f1060 (kind game, layer game, confidence medium), dominant class pure3d::MultiController
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/content.h"
#define TREE_TU_BEGIN namespace fn_ff205e2a {
#define TREE_TU_END }
namespace fn_ff205e2a {} using namespace fn_ff205e2a;
#include "game/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_ff205e2a {
typedef unsigned int u32_f1030;

} // namespace fn_ff205e2a

// 0x000f1030 content::LoadInventory::DynamicCaster<pure3d::MultiController>::vfunc_0 (30 B): matches/0x000f1030.cpp
// sym: ?vfunc_0@?$DynamicCaster@VMultiController@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::MultiController>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}

