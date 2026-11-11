// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002e1650..0x002e16f0 (kind game, layer engine, confidence medium), dominant class pure3d::OldPrimGroupLoader
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f07552bd {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f07552bd {} using namespace fn_f07552bd;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f07552bd {
extern void* hulk_at_0042fb94[];
} // namespace fn_f07552bd
void operator delete(void*);
namespace fn_f07552bd {
class Ref_2e1650 {
  public:
    virtual void F0();
    virtual void Release();
};
class RenderObjectLoader_2e1650 {
  public:
    void* vptr;
    void Fin_002a3e90();
};
class OldPrimGroupLoader_2e1650 : public RenderObjectLoader_2e1650 {
  public:
    char pad[4];
    Ref_2e1650* m;
    OldPrimGroupLoader_2e1650* f2(unsigned char flags);
};


// 0x002e1650 pure3d::OldPrimGroupLoader::vfunc_2 (57 B): matches/0x002e1650.cpp
// sym: ?f2@OldPrimGroupLoader_2e1650@fn_f07552bd@@QAEPAV12@E@Z
OldPrimGroupLoader_2e1650* OldPrimGroupLoader_2e1650::f2(unsigned char flags) {
    vptr = hulk_at_0042fb94;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_002a3e90();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f07552bd
