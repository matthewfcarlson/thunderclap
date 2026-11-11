// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c6610..0x001c6660 (kind game, layer game, confidence medium), dominant class content::ObjectLoader
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f793680e {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f793680e {} using namespace fn_f793680e;
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_f793680e {
class LoadObject_1c6610 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public LoadObject_1c6610 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x001c6610 content::ObjectLoader::vfunc_2 (31 B): matches/0x001c6610.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f793680e@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f793680e
