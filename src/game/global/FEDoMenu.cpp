// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e8ba0..0x000e8be0 (kind game, layer game, confidence medium), dominant class FEDoMenu
#include "tree_prelude.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f811ea41 {
#define TREE_TU_END }
namespace fn_f811ea41 {} using namespace fn_f811ea41;
#include "game/global.h"


// 0x000e8ba0 FEDoFunction::vfunc_0 (30 B): matches/0x000e8ba0.cpp
// sym: ??_GFEDoFunction@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
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

