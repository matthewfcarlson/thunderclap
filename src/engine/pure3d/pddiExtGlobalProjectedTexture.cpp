// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00320100..0x00320130 (kind game, layer engine, confidence medium), dominant class pure3d::pddiExtGlobalProjectedTexture
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f4b3d925 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f4b3d925 {} using namespace fn_f4b3d925;
namespace fn_f4b3d925 { extern "C" char DAT_0043276c[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f4b3d925 {
class pddiExtension_320100 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public pddiExtension_320100 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x00320100 pure3d::pddiExtGlobalProjectedTexture::vfunc_0 (31 B): matches/0x00320100.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f4b3d925@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_0043276c;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f4b3d925
