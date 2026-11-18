// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00310130..0x003101f0 (kind game, layer engine, confidence medium), dominant class physics::PoseEngine
#include "tree_prelude.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_f585e10a {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f585e10a {} using namespace fn_f585e10a;
#include "engine/physics.h"


// 0x00310130 physics::PoseEngine::vfunc_2 (30 B): matches/0x00310130.cpp
// sym: ?vfunc_2@PoseEngine_310130@fn_00310130@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `physics::PoseEngine::~PoseEngine() {}` stood for it, which natively defines no
// function for the vftable slot (with the `??_G` signature, as other views call the slot). The destructor's body
// 0x0030fc90, then (flags & 1) operator delete.
namespace fn_00310130 {
struct PoseEngine_310130 {
    void FUN_0030fc90();   // the destructor's body
    void* vfunc_2(unsigned int flags);
};
void* PoseEngine_310130::vfunc_2(unsigned int flags) {
    FUN_0030fc90();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00310130
// (x64t21) the destructor itself, which other objects' code references:
physics::PoseEngine::~PoseEngine() {}

