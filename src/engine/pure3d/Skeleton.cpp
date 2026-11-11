// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0027b510..0x0027b540 (kind game, layer engine, confidence medium), dominant class pure3d::Skeleton::Partition
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f975067c {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f975067c {} using namespace fn_f975067c;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f975067c {
typedef unsigned char byte_27b510;
class Partition {
  public:
    virtual Partition* vfunc_0(byte_27b510);
    char pad[0x0c];
    void* field10;
};


// 0x0027b510 pure3d::Skeleton::Partition::vfunc_0 (47 B): matches/0x0027b510.cpp
// sym: ?vfunc_0@Partition@fn_f975067c@@UAEPAV12@E@Z
Partition* Partition::vfunc_0(byte_27b510 param) {
    *(void**)this = (void*)((hulk_intptr)DAT_0042c1b4);
    if (field10)
        thunk(field10);
    if (param & 1)
        thunk(this);
    return this;
}

} // namespace fn_f975067c
