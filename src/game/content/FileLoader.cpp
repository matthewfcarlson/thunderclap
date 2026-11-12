// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001ef900..0x001ef930 (kind game, layer game, confidence medium), dominant class content::FileLoader
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f8d97dfc {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f8d97dfc {} using namespace fn_f8d97dfc;
namespace fn_f8d97dfc { extern "C" char DAT_003f6098[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_f8d97dfc {
class LoadObject_1ef900 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public LoadObject_1ef900 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x001ef900 content::FileLoader::vfunc_2 (31 B): matches/0x001ef900.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f8d97dfc@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f8d97dfc
