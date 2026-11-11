// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00016440..0x000164e0 (kind game, layer game, confidence medium), dominant class CSmartPropDropAction
#include "tree_prelude.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7925198 {
#define TREE_TU_END }
namespace fn_f7925198 {} using namespace fn_f7925198;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f7925198 {
struct Obj2_16440;
struct Obj1_16440 {
};
struct Obj2_16440 {
    Obj2_16440* second_00059a30();
};
class CAction_16460 {
    char pad[0x1c];
};
struct HelperA_16460 {
    char pad[0x1c];
    char* Fng_00059a30();
};

} // namespace fn_f7925198

// 0x00016440 CSmartPropThrowingAction::vfunc_6 (27 B): matches/0x00016440.cpp
// sym: ?vfunc_6@CSmartPropThrowingAction@@UAE_NH@Z
bool CSmartPropThrowingAction::vfunc_6(int x) {
    Obj2_16440* p = ((Obj2_16440 *)((owners::Object_592a0 *)((*(Obj1_16440 * *)&this->f_1c)))->FUN_000592a0());
    Obj2_16440* q = p->second_00059a30();
    *((char*)q + 0x1f51) = 1;
    return true;
}


// 0x00016460 CSmartPropThrowingAction::vfunc_4 (23 B): matches/0x00016460.cpp
// sym: ?vfunc_4@CSmartPropThrowingAction@@UAEXXZ
void CSmartPropThrowingAction::vfunc_4() {
    HelperA_16460* p = *(HelperA_16460**)((char*)this + 0x1c);
    p = ((HelperA_16460 *)((owners::Object_592a0 *)p)->FUN_000592a0());
    char* q = p->Fng_00059a30();
    q[0x1f51] = 0;
}


// 0x00016480 CSmartPropDropAction::vfunc_6 (91 B): equivalent/0x00016480.cpp [wrapped: conflict: CSmartPropDropAction]
// sym: ?vfunc_6@CSmartPropDropAction@fn_00016480@@QAEEH@Z
namespace fn_00016480 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// CSmartPropDropAction::vfunc_6 @ 0x00016480
struct CObjectFirst { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual int f14(); }; struct CObjectSecond { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual int f14(int); }; struct CReceiver { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(int); }; struct CContainer { CReceiver* FUN_00035ef0(int); void FUN_00040170(); }; struct CIntermediate { CContainer* FUN_00059a30(); }; struct CSource { CIntermediate* FUN_000592a0(); }; struct CSmartPropDropAction { char pad[0x1c]; CSource* source; CObjectFirst* object; unsigned char vfunc_6(int unused); }; unsigned char CSmartPropDropAction::vfunc_6(int unused) { CContainer* container = source->FUN_000592a0()->FUN_00059a30(); if (object->f14() >= 0) { if (container->FUN_00035ef0(0)) { CReceiver* receiver = container->FUN_00035ef0(0); receiver->f16(((CObjectSecond*)object)->f14(1)); } } container->FUN_00040170(); return 0; }
} // namespace fn_00016480

