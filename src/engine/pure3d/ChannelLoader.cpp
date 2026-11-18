// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028d100..0x0028d130 (kind game, layer engine, confidence medium), dominant class pure3d::ChannelLoader
#include "tree_prelude.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fc8b8506 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fc8b8506 {} using namespace fn_fc8b8506;
#include "engine/pure3d.h"


// 0x0028d100 pure3d::ChannelLoader::vfunc_2 (30 B): matches/0x0028d100.cpp
// sym: ?vfunc_2@ChannelLoader_28d100@fn_0028d100@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `pure3d::ChannelLoader::~ChannelLoader() {}` stood for it, which natively
// defines no function for the vftable slot (with the `??_G` signature, as other views call the slot). The destructor's
// body 0x0028b910, then (flags & 1) operator delete.
namespace fn_0028d100 {
struct ChannelLoader_28d100 {
    void FUN_0028b910();   // the destructor's body
    void* vfunc_2(unsigned int flags);
};
void* ChannelLoader_28d100::vfunc_2(unsigned int flags) {
    FUN_0028b910();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_0028d100
// (x64t21) the destructor itself, which other objects' code references:
pure3d::ChannelLoader::~ChannelLoader() {}

