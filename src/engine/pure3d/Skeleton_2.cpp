// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0027b540..0x0027b570 (kind game, layer engine, confidence medium), dominant class pure3d::Skeleton::Limb
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f80a3bcd {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f80a3bcd {} using namespace fn_f80a3bcd;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f80a3bcd {
typedef unsigned char byte_27b540;
class Limb_27b540 {
  public:
    virtual Limb_27b540* vfunc_0(byte_27b540);
    char pad[0x0c];
    void* field10;
};


// 0x0027b540 pure3d::Skeleton::Limb::vfunc_0 (47 B): matches/0x0027b540.cpp
// sym: ?vfunc_0@Limb_27b540@fn_f80a3bcd@@UAEPAV12@E@Z
Limb_27b540* Limb_27b540::vfunc_0(byte_27b540 param) {
    *(void**)this = (void*)((hulk_intptr)DAT_0042c1b4);
    if (field10)
        thunk(field10);
    if (param & 1)
        thunk(this);
    return this;
}

} // namespace fn_f80a3bcd
