// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x003137d0..0x003137f0 (kind game, layer engine, confidence medium), dominant class physics::SubCollisionDetector
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fa470ba2 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fa470ba2 {} using namespace fn_fa470ba2;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_fa470ba2 {
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x003137d0 physics::SubCollisionDetector::vfunc_0 (31 B): matches/0x003137d0.cpp
// sym: ?f2@NonCopyable@pure3d@fn_fa470ba2@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fa470ba2
