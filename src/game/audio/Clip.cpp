// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001e9e10..0x001e9e70 (kind game, layer game, confidence medium), dominant class audio::Clip
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/content.h"
#define TREE_TU_BEGIN namespace fn_f9e96c0f {
#define TREE_TU_END }
namespace fn_f9e96c0f {} using namespace fn_f9e96c0f;
#include "game/audio.h"

// ---- declarations shared by the functions below
namespace fn_f9e96c0f {
typedef unsigned int u32_1e9e10;

} // namespace fn_f9e96c0f

// 0x001e9e10 content::LoadInventory::DynamicCaster<audio::Clip>::vfunc_0 (30 B): matches/0x001e9e10.cpp
// sym: ?vfunc_0@?$DynamicCaster@VClip@audio@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<audio::Clip>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}

