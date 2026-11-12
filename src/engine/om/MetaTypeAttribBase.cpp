// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0024d3c0..0x0024d5a0 (kind game, layer engine, confidence medium), dominant class om::MetaTypeAttribBase
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/om.h"
#define TREE_TU_BEGIN namespace fn_fbe9f2e3 {
#define TREE_TU_END }
namespace fn_fbe9f2e3 {} using namespace fn_fbe9f2e3;
namespace fn_fbe9f2e3 { extern "C" char DAT_00429420[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/om.h"

// ---- declarations shared by the functions below
namespace pure3d {
class NonCopyable_24d3d0 : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_24d3d0* f2(unsigned char);
};
}
namespace fn_fbe9f2e3 {
void thunk_FUN_00267090(pure3d::NonCopyable_24d3d0*);

} // namespace fn_fbe9f2e3

// 0x0024d3c0 om::MetaTypeAttribBase::vfunc_3 (3 B): matches/0x0024d3c0.cpp
// sym: ?vfunc_3@MetaTypeAttribBase@om@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void om::MetaTypeAttribBase::vfunc_3(hulk_intptr a) {
    (void)a;
}


// 0x0024d3d0 om::MetaTypeAttribBase::vfunc_0 (31 B): matches/0x0024d3d0.cpp
// sym: ?f2@NonCopyable_24d3d0@pure3d@@UAEPAV12@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_24d3d0* pure3d::NonCopyable_24d3d0::f2(unsigned char param) {
    *(void**)this = (void**)DAT_00429420;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

