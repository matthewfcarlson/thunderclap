// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000f0f70..0x000f0fa0 (kind game, layer game, confidence medium), dominant class pure3d::BillboardObject
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/content.h"
#define TREE_TU_BEGIN namespace fn_f46ea0cd {
#define TREE_TU_END }
namespace fn_f46ea0cd {} using namespace fn_f46ea0cd;
#include "game/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f46ea0cd {
typedef unsigned int u32_f0f70;

} // namespace fn_f46ea0cd

// 0x000f0f70 content::LoadInventory::DynamicCaster<pure3d::BillboardObject>::vfunc_0 (30 B): matches/0x000f0f70.cpp
// sym: ?vfunc_0@?$DynamicCaster@VBillboardObject@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::BillboardObject>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}

