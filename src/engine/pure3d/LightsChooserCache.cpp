// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0029e7b0..0x0029e7f0 (kind game, layer engine, confidence medium), dominant class pure3d::LightsChooserCache
#include "tree_prelude.h"
#include "gen/content.h"   // (nat2, D134) content::LoadObject's operator delete
#define TREE_TU_BEGIN namespace fn_ffbb471a {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ffbb471a {} using namespace fn_ffbb471a;
void __cdecl operator delete[](void* p);   // (x64t21, D115) the game's 0x0008d340
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_ffbb471a {
// (nat2, D134, D114) pure3d::LightsChooserCache's scalar deleting destructor as an explicit function: its vftable
// (0x0042d604), the block at +0x24 freed with operator delete[], the entity's destructor (0x0027afd0), then (flags & 1)
// content::LoadObject's operator delete, as the original calls (0x00263f30)
extern "C" char DAT_0042d604[];
struct LightsChooserCache_29e7b0 {
    void* vftable;
    char pad[0x20];
    void* mPtr;
    void baseDtor_0027afd0();
    void* vfunc_2(unsigned int flags);
};


// 0x0029e7b0 pure3d::LightsChooserCache::vfunc_2 (50 B): matches/0x0029e7b0.cpp
// sym: ?vfunc_2@LightsChooserCache_29e7b0@fn_ffbb471a@@QAEPAXI@Z
void* LightsChooserCache_29e7b0::vfunc_2(unsigned int flags) {
    vftable = DAT_0042d604;
    ::operator delete[](mPtr);
    baseDtor_0027afd0();
    if (flags & 1)
        ::content::LoadObject::operator delete(this);
    return this;
}

} // namespace fn_ffbb471a
