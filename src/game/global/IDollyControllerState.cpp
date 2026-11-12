// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000dd6c0..0x000dd710 (kind game, layer game, confidence medium), dominant class IDollyControllerState
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f777e219 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f777e219 {} using namespace fn_f777e219;
namespace fn_f777e219 { extern "C" char DAT_0040bc80[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f777e219 {
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x000dd6c0 IDollyControllerState::vfunc_0 (31 B): matches/0x000dd6c0.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f777e219@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_0040bc80;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f777e219
