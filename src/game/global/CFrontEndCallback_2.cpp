// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000c4ec0..0x000c4ef0 (kind game, layer game, confidence medium), dominant class CFrontEndCallback
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fa0fa6d3 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fa0fa6d3 {} using namespace fn_fa0fa6d3;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fa0fa6d3 {
class IScriptLoadCallback_c4ed0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public IScriptLoadCallback_c4ed0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x000c4ec0 CFrontEndCallback::vfunc_0 (1 B): matches/0x000c4ec0.cpp
// sym: ?FUN_000c4ec0@fn_fa0fa6d3@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000c4ec0() {}


// 0x000c4ed0 CFrontEndCallback::vfunc_1 (31 B): matches/0x000c4ed0.cpp
// sym: ?f2@NonCopyable@pure3d@fn_fa0fa6d3@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fa0fa6d3
