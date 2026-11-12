// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00247410..0x00247470 (kind game, layer engine, confidence medium), dominant class om::CallbackStream
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f85ab0a5 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f85ab0a5 {} using namespace fn_f85ab0a5;
namespace fn_f85ab0a5 { extern "C" char DAT_00423f20[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/om.h"

// ---- declarations shared by the functions below
namespace fn_f85ab0a5 {
class Stream_247410 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public Stream_247410 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x00247410 om::CallbackStream::vfunc_0 (31 B): matches/0x00247410.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f85ab0a5@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_00423f20;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f85ab0a5
