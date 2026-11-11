// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00334090..0x003340b0 (kind game, layer engine, confidence medium), dominant class movie::RenderStrategy
#include "tree_prelude.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_f542a006 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f542a006 {} using namespace fn_f542a006;
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_f542a006 {
namespace pure3d {
class NonCopyable_334090 : public ::core::IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_334090* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable_334090*);


// 0x00334090 movie::RenderStrategy::vfunc_2 (31 B): matches/0x00334090.cpp
// sym: ?f2@NonCopyable_334090@pure3d@fn_f542a006@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_334090* pure3d::NonCopyable_334090::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f542a006
