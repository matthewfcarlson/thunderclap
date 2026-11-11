// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000b3d80..0x000b3de0 (kind game, layer game, confidence medium), dominant class IControllerManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f61adc76 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f61adc76 {} using namespace fn_f61adc76;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f61adc76 {
struct Callee_b3d80 {
    void Yes(int);
};
struct Obj_b3d80 {
    char pad0[4];
    Callee_b3d80* p;
    char flag;
    void Run(hulk_intptr);
};
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x000b3d80 FUN_000b3d80 (28 B): matches/0x000b3d80.cpp
// sym: ?Run@Obj_b3d80@fn_f61adc76@@QAEXH@Z
void Obj_b3d80::Run(hulk_intptr unused) {
    if (flag)
        p->Yes(unused);
    else
        ((owners::Obj_b3b50 *)p)->FUN_000b3b50(1);
}


// 0x000b3dc0 IControllerManager::vfunc_0 (31 B): matches/0x000b3dc0.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f61adc76@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f61adc76
