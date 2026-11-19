// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000f1000..0x000f1030 (kind game, layer game, confidence medium), dominant class pure3d::scenegraph::Scenegraph
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/content.h"
#include "gen/core.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fc5edcb9 {
#define TREE_TU_END }
namespace fn_fc5edcb9 {} using namespace fn_fc5edcb9;
#include "common.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_fc5edcb9 {
typedef unsigned int u32_f1000;

} // namespace fn_fc5edcb9

// 0x000f1000 content::LoadInventory::DynamicCaster<pure3d::scenegraph::Scenegraph>::vfunc_0 (30 B): matches/0x000f1000.cpp
// sym: ?vfunc_0@?$DynamicCaster@VScenegraph@scenegraph@pure3d@@@LoadInventory@content@@UAEPAXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void* content::LoadInventory::DynamicCaster<pure3d::scenegraph::Scenegraph>::vfunc_0(void* p) {
    return dynamic_cast<::pure3d::scenegraph::Scenegraph*>((::core::IRefCount*)p);   // (sweep2, G7) the cast is the slot's result
}

