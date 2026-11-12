// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0024e920..0x0024e9e0 (kind game, layer engine, confidence medium), dominant class audio::SeqAction
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f38391a1 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f38391a1 {} using namespace fn_f38391a1;
namespace fn_f38391a1 { extern "C" char DAT_004298fc[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f38391a1 {
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x0024e920 audio::SeqAction::vfunc_0 (31 B): matches/0x0024e920.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f38391a1@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_004298fc;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f38391a1
