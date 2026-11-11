// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0029e7b0..0x0029e7f0 (kind game, layer engine, confidence medium), dominant class pure3d::LightsChooserCache
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_ffbb471a {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ffbb471a {} using namespace fn_ffbb471a;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_ffbb471a {
extern "C" void destroyChooser(void*);
namespace pure3d {
class LightsChooserCache {
  public:
    virtual ~LightsChooserCache();
    void baseDtor();
    char pad[0x20];
    void* mPtr;
};
}


// 0x0029e7b0 pure3d::LightsChooserCache::vfunc_2 (50 B): matches/0x0029e7b0.cpp
// sym: ??_GLightsChooserCache@pure3d@fn_ffbb471a@@UAEPAXI@Z
namespace pure3d {
LightsChooserCache::~LightsChooserCache() {
    destroyChooser(mPtr);
    baseDtor();
}
}

} // namespace fn_ffbb471a
