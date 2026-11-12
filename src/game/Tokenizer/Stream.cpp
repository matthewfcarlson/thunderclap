// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001fa960..0x001fa9c0 (kind game, layer game, confidence medium), dominant class Tokenizer::Stream
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fa7a8bfd {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fa7a8bfd {} using namespace fn_fa7a8bfd;
namespace fn_fa7a8bfd { extern "C" char DAT_00424fd8[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_fa7a8bfd {
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


// 0x001fa960 Tokenizer::Stream::vfunc_0 (31 B): matches/0x001fa960.cpp
// sym: ?f2@NonCopyable@pure3d@fn_fa7a8bfd@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_00424fd8;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fa7a8bfd
