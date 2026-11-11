// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c6c90..0x001c6cb0 (kind game, layer game, confidence medium), dominant class content::SimpleChunkHandler
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f20d0d82 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f20d0d82 {} using namespace fn_f20d0d82;
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_f20d0d82 {
class ObjectLoader_1c6c90 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public ObjectLoader_1c6c90 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x001c6c90 content::SimpleChunkHandler::vfunc_2 (31 B): matches/0x001c6c90.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f20d0d82@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f20d0d82
