// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001e9de0..0x001e9e10 (kind game, layer game, confidence medium), dominant class audio::ListenerEffectXBox
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/content.h"
#include "gen/core.h"
#include "gen/audio.h"
#define TREE_TU_BEGIN namespace fn_fa42030b {
#define TREE_TU_END }
namespace fn_fa42030b {} using namespace fn_fa42030b;
#include "game/audio.h"

// ---- declarations shared by the functions below
namespace fn_fa42030b {
typedef unsigned int u32_1e9de0;

} // namespace fn_fa42030b

// 0x001e9de0 content::LoadInventory::DynamicCaster<audio::ListenerEffectXBox>::vfunc_0 (30 B): matches/0x001e9de0.cpp
// sym: ?vfunc_0@?$DynamicCaster@VListenerEffectXBox@audio@@@LoadInventory@content@@UAEPAXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void* content::LoadInventory::DynamicCaster<audio::ListenerEffectXBox>::vfunc_0(void* p) {
    return dynamic_cast<::audio::ListenerEffectXBox*>((::core::IRefCount*)p);   // (sweep2, G7) the cast is the slot's result
}

