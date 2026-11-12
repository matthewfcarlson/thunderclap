// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c1440..0x001c1460 (kind game, layer game, confidence medium), dominant class pure3d::ShaderCallback
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_ff5e343a {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff5e343a {} using namespace fn_ff5e343a;
namespace fn_ff5e343a { extern "C" char DAT_003f6098[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_ff5e343a {
class NonCopyable_1c1440 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public NonCopyable_1c1440 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x001c1440 pure3d::ShaderCallback::vfunc_2 (31 B): matches/0x001c1440.cpp
// sym: ?f2@NonCopyable@pure3d@fn_ff5e343a@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_ff5e343a
