// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00247310..0x00247360 (kind game, layer engine, confidence medium), dominant class om::OmPrintfStream
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f67ef385 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f67ef385 {} using namespace fn_f67ef385;
#include "engine/om.h"

// ---- declarations shared by the functions below
namespace fn_f67ef385 {
class Stream_247310 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public Stream_247310 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x00247310 om::OmPrintfStream::vfunc_0 (31 B): matches/0x00247310.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f67ef385@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f67ef385
