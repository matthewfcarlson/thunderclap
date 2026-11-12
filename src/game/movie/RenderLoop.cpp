// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001b6f70..0x001b6f90 (kind game, layer game, confidence medium), dominant class movie::RenderLoop
#include "tree_prelude.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_f129244f {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f129244f {} using namespace fn_f129244f;
namespace fn_f129244f { extern "C" char DAT_003f6098[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_f129244f {
namespace pure3d {
class NonCopyable_1b6f70 : public ::core::IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_1b6f70* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable_1b6f70*);


// 0x001b6f70 movie::RenderLoop::vfunc_2 (31 B): matches/0x001b6f70.cpp
// sym: ?f2@NonCopyable_1b6f70@pure3d@fn_f129244f@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_1b6f70* pure3d::NonCopyable_1b6f70::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f129244f
