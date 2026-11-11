// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e8be0..0x000e8c30 (kind game, layer game, confidence medium), dominant class FEDoPopDialog
#include "tree_prelude.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f917acfa {
#define TREE_TU_END }
namespace fn_f917acfa {} using namespace fn_f917acfa;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f917acfa {
class FEThing_e8c20 {
  public:
    int x;
    void* m;
};
class Target_e8c20 {
  public:
    void go();
};
class FEDoAction_e8c20 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};

} // namespace fn_f917acfa

// 0x000e8be0 FEDoPushDialog::vfunc_0 (31 B): matches/0x000e8be0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_000e8be0@@UAEPAV123@E@Z
namespace fn_000e8be0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class FEDoAction_e8be0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public FEDoAction_e8be0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_000e8be0


// 0x000e8c00 FEDoPopDialog::vfunc_0 (31 B): matches/0x000e8c00.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_000e8c00@@UAEPAV123@E@Z
namespace fn_000e8c00 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class FEDoAction_e8c00 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public FEDoAction_e8c00 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_000e8c00


// 0x000e8c20 FEDoPopDialog::vfunc_1 (11 B): matches/0x000e8c20.cpp
// sym: ?vfunc_1@FEDoPopDialog@@UAEXXZ
void FEDoPopDialog::vfunc_1() {
    ((Target_e8c20*)(*(FEThing_e8c20 * *)&this->f_10)->m)->go();
}

