// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e8c30..0x000e8c50 (kind game, layer game, confidence medium), dominant class FEDoBackMenu
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f39aad4b {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f39aad4b {} using namespace fn_f39aad4b;
namespace fn_f39aad4b { extern "C" char DAT_0040bfa0[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f39aad4b {
class FEDoAction_e8c30 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public FEDoAction_e8c30 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x000e8c30 FEDoBackMenu::vfunc_0 (31 B): matches/0x000e8c30.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f39aad4b@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_0040bfa0;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f39aad4b
