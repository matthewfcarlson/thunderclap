// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000f9820..0x000f9870 (kind game, layer game, confidence medium), dominant class DollyScript::CScriptToken
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f78bdd87 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f78bdd87 {} using namespace fn_f78bdd87;
#include "game/DollyScript.h"

// ---- declarations shared by the functions below
namespace fn_f78bdd87 {
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x000f9820 DollyScript::CScriptToken::vfunc_0 (31 B): matches/0x000f9820.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f78bdd87@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f78bdd87
