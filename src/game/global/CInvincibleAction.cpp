// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00016540..0x000165d0 (kind game, layer game, confidence medium), dominant class CInvincibleAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe912186 {
#define TREE_TU_END }
namespace fn_fe912186 {} using namespace fn_fe912186;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fe912186 {
struct A_16540 {
    A_16540* get();
    int remove(void*, int);
};
struct B_16540 {
    A_16540* get();
};
struct Manager_16540 {
    char pad[0xc];
    A_16540* obj;
};
extern Manager_16540* volatile gManager_16540;
struct ObjA_16580 {
};
struct ObjB_16580 {
    ObjB_16580* g();
};
struct ObjC_16580 {
    void h(int);
};

} // namespace fn_fe912186

// 0x00016540 CSmartPropRemoveInstanceAction::vfunc_6 (56 B): matches/0x00016540.cpp
// sym: ?vfunc_6@CSmartPropRemoveInstanceAction@@UAE_NH@Z
bool CSmartPropRemoveInstanceAction::vfunc_6(int ) {
    A_16540* a = (*(B_16540 * *)&this->f_1c)->get();
    a = a->get();
    hulk_intptr x = ((int)((owners::C_35ef0 *)a)->FUN_00035ef0((hulk_intptr)((*(void * *)&this->f_20))));
    if (x)
        gManager_16540->obj->remove((void*)x, 1);
    return false;
}


// 0x00016580 CInvincibleAction::vfunc_6 (29 B): matches/0x00016580.cpp
// sym: ?vfunc_6@CInvincibleAction@@UAE_NH@Z
bool CInvincibleAction::vfunc_6(int ) {
    ObjA_16580* a = ((ObjA_16580 *)((owners::Object_592a0 *)((*(ObjA_16580 * *)&this->f_1c)))->FUN_000592a0());
    ObjB_16580* b = ((ObjB_16580*)a)->g();
    ((ObjC_16580*)b)->h(1);
    return true;
}


// 0x000165a0 CInvincibleAction::vfunc_4 (44 B): matches/0x000165a0.cpp [wrapped: conflict: CInvincibleAction]
// sym: ?vfunc_4@CInvincibleAction@fn_000165a0@@QAEXXZ
namespace fn_000165a0 {
typedef unsigned int u32_165a0;
struct A_165a0 {
    A_165a0* f2();
    void f3(int);
    void f4(u32_165a0);
};
struct X_165a0 {
    A_165a0* f1();
};
struct CInvincibleAction {
    char pad[0x1c];
    X_165a0* mAt1c;
    u32_165a0 mAt20;
    void vfunc_4();
};
void CInvincibleAction::vfunc_4() {
    A_165a0* a = mAt1c->f1();
    A_165a0* b = a->f2();
    b->f3(0);
    b->f4(mAt20);
}
} // namespace fn_000165a0

