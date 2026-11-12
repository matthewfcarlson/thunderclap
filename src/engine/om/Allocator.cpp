// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00247680..0x002477f0 (kind game, layer engine, confidence medium), dominant class om::Allocator
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f6cf1402 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6cf1402 {} using namespace fn_f6cf1402;
namespace fn_f6cf1402 { extern "C" char DAT_00429254[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/om.h"

// ---- declarations shared by the functions below
namespace fn_f6cf1402 {
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x00247680 om::Allocator::vfunc_0 (31 B): matches/0x00247680.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f6cf1402@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_00429254;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f6cf1402
