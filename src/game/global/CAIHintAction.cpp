// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000179b0..0x00017a80 (kind game, layer game, confidence medium), dominant class CAIHintAction
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f89f20ea {
#define TREE_TU_END }
namespace fn_f89f20ea {} using namespace fn_f89f20ea;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f89f20ea {
struct Manager_179b0;
struct Ctx_179b0 {
};
struct Manager_179b0 {
    Manager_179b0* Fng_00059a30();
};
class X_179b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int);
};
class H {
  public:
    void* Fng_00059a30();
    unsigned int Fnh_0003ea10(int);
};
struct Obj_17a00 {
};
struct Obj2_17a00 {
    void* Fng_00059a30();
};
struct Obj3_17a00 {
    void Fnh_0027af70(void*);
};
class CAction_17a00 {
  public:
    char pad[0x1c];
    Obj_17a00* one;
    Obj_17a00* two;
};
struct A_17a30 {
    char pad[8];
    A_17a30(const float& f);
    void done_0027af50();
};
struct Obj_17a30 {
    void use_0027af70(A_17a30* a);
};
struct T_17a30 {
};
struct Base_17a30 {
    char pad[0x1b50];
};
struct U_17a30 {
    Base_17a30* second_00059a30();
};

} // namespace fn_f89f20ea

// 0x000179b0 CAlertStatusAction::vfunc_6 (43 B): matches/0x000179b0.cpp
// sym: ?vfunc_6@CAlertStatusAction@@UAE_NH@Z
bool CAlertStatusAction::vfunc_6(int ) {
    Manager_179b0* p = ((Manager_179b0 *)((owners::Object_592a0 *)((*(Ctx_179b0 * *)&this->f_1c)))->FUN_000592a0());
    p = p->Fng_00059a30();
    X_179b0* x = *(X_179b0**)((char*)p + 0x1ca0);
    if (x)
        x->f8(this->f_20);
    return false;
}


// 0x000179e0 CDeathAction::vfunc_6 (29 B): matches/0x000179e0.cpp
// sym: ?vfunc_6@CDeathAction@@UAE_NH@Z
bool CDeathAction::vfunc_6(int ) {
    H* a = (*(H * *)&this->f_1c);
    void* b = ((void *)((owners::Object_592a0 *)a)->FUN_000592a0());
    H* c = (H*)b;
    void* d = c->Fng_00059a30();
    H* e = (H*)d;
    e->Fnh_0003ea10(1);
    return false;
}


// 0x00017a00 CAIHintAction::vfunc_6 (42 B): matches/0x00017a00.cpp
// sym: ?vfunc_6@CAIHintAction@@UAE_NH@Z
bool CAIHintAction::vfunc_6(int x) {
    Obj_17a00* o = (*(Obj_17a00 * *)&this->f_1c);
    void* a = ((void *)((owners::Object_592a0 *)o)->FUN_000592a0());
    void* b = ((Obj2_17a00*)a)->Fng_00059a30();
    ((Obj3_17a00*)((char*)b + 0x1b50))->Fnh_0027af70((char*)(*(Obj_17a00 * *)&this->f_20) + 0x18);
    return true;
}


// 0x00017a30 CAIHintAction::vfunc_4 (65 B): matches/0x00017a30.cpp
// sym: ?vfunc_4@CAIHintAction@@UAEXXZ
// data: kZeroF = DAT_003f335c
void CAIHintAction::vfunc_4() {
    T_17a30* a = (T_17a30*)(*(void * *)&this->f_1c);
    U_17a30* b = (U_17a30*)((void *)((owners::Object_592a0 *)a)->FUN_000592a0());
    Base_17a30* o = b->second_00059a30();
    A_17a30 local((*(float*)&DAT_003f335c));
    ((Obj_17a30*)((char*)o + 0x1b50))->use_0027af70(&local);
    local.done_0027af50();
}

