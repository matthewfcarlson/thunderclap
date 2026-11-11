// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002e1610..0x002e1650 (kind game, layer engine, confidence medium), dominant class pure3d::PrimGroupLoader
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fa73f5c5 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fa73f5c5 {} using namespace fn_fa73f5c5;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fa73f5c5 {
extern void* g_vftable_2e1610[];
} // namespace fn_fa73f5c5
void operator delete(void*);
namespace fn_fa73f5c5 {
class Ref_2e1610 {
  public:
    virtual void F0();
    virtual void Release();
};
class RenderObjectLoader_2e1610 {
  public:
    void* vptr;
    void Fin();
};
class PrimGroupLoader_2e1610 : public RenderObjectLoader_2e1610 {
  public:
    char pad[4];
    Ref_2e1610* m;
    PrimGroupLoader_2e1610* f2(unsigned char flags);
};


// 0x002e1610 pure3d::PrimGroupLoader::vfunc_2 (57 B): matches/0x002e1610.cpp
// sym: ?f2@PrimGroupLoader_2e1610@fn_fa73f5c5@@QAEPAV12@E@Z
PrimGroupLoader_2e1610* PrimGroupLoader_2e1610::f2(unsigned char flags) {
    vptr = g_vftable_2e1610;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_fa73f5c5
