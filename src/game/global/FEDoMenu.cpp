// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e8ba0..0x000e8be0 (kind game, layer game, confidence medium), dominant class FEDoMenu
#include "tree_prelude.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f811ea41 {
#define TREE_TU_END }
namespace fn_f811ea41 {} using namespace fn_f811ea41;
#include "game/global.h"


// 0x000e8ba0 FEDoFunction::vfunc_0 (30 B): matches/0x000e8ba0.cpp
// sym: ?vfunc_0@FEDoFunction_e8ba0@fn_000e8ba0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `FEDoFunction::~FEDoFunction() {}` stood for it, which natively defines no
// function for the vftable slot (with the `??_G` signature, as other views call the slot). The destructor's body
// 0x000e1a60, then (flags & 1) operator delete.
namespace fn_000e8ba0 {
struct FEDoFunction_e8ba0 {
    void FUN_000e1a60();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* FEDoFunction_e8ba0::vfunc_0(unsigned int flags) {
    FUN_000e1a60();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000e8ba0
// (x64t21) the destructor itself, which other objects' code references:
FEDoFunction::~FEDoFunction() {}


// 0x000e8bc0 FEDoMenu::vfunc_0 (31 B): matches/0x000e8bc0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_000e8bc0@@UAEPAV123@E@Z
namespace fn_000e8bc0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class FEDoAction_e8bc0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_0040bfa0[];
namespace pure3d {
class NonCopyable : public FEDoAction_e8bc0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_0040bfa0;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_000e8bc0

