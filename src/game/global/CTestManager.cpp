// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00091af0..0x00091bc0 (kind game, layer game, confidence high), dominant class CTestManager
#include "tree_prelude.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f9da7962 {
#define TREE_TU_END }
namespace fn_f9da7962 {} using namespace fn_f9da7962;
#include "game/global.h"


// 0x00091af0 CTestManager::vfunc_0 (3 B): matches/0x00091af0.cpp
// sym: ?vfunc_0@CTestManager@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void CTestManager::vfunc_0(int a, int b) {}


// 0x00091b00 CTestManager::vfunc_2 (3 B): matches/0x00091b00.cpp
// sym: ?vfunc_2@CTestManager@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void CTestManager::vfunc_2(int a) {
    (void)a;
}


// 0x00091b90 CTestManager::vfunc_1 (31 B): matches/0x00091b90.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00091b90@@UAEPAV123@E@Z
namespace fn_00091b90 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class IMessageScriptCallback_91b90 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public IMessageScriptCallback_91b90 {
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
} // namespace fn_00091b90

