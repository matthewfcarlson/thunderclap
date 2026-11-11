// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00017570..0x000175c0 (kind game, layer game, confidence medium), dominant class CUninterruptibleAction
#include "tree_prelude.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe7f115d {
#define TREE_TU_END }
namespace fn_fe7f115d {} using namespace fn_fe7f115d;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fe7f115d {
struct ObjA_17570 {
};
struct ObjB_17570 {
    ObjB_17570* Fng_00059a30();
};
struct ObjC_17570 {
    void Fnh_00036140(int);
};

} // namespace fn_fe7f115d

// 0x00017570 CUninterruptibleAction::vfunc_6 (29 B): matches/0x00017570.cpp
// sym: ?vfunc_6@CUninterruptibleAction@@UAE_NH@Z
// Same code shape as 0x00016580 (propagated; names are from that function)
bool CUninterruptibleAction::vfunc_6(int ) {
    ObjA_17570* a = ((ObjA_17570 *)((owners::Object_592a0 *)((*(ObjA_17570 * *)&this->f_1c)))->FUN_000592a0());
    ObjB_17570* b = ((ObjB_17570*)a)->Fng_00059a30();
    ((ObjC_17570*)b)->Fnh_00036140(1);
    return true;
}


// 0x00017590 CUninterruptibleAction::vfunc_4 (44 B): matches/0x00017590.cpp [wrapped: conflict: CUninterruptibleAction]
// sym: ?vfunc_4@CUninterruptibleAction@fn_00017590@@QAEXXZ
namespace fn_00017590 {
// Same code shape as 0x000165a0 (propagated; names are from that function)
typedef unsigned int u32_17590;
struct A_17590 {
    A_17590* f2_00059a30();
    void f3_00036140(int);
    void f4_00036120(u32_17590);
};
struct X_17590 {
    A_17590* f1_000592a0();
};
struct CUninterruptibleAction {
    char pad[0x1c];
    X_17590* mAt1c;
    u32_17590 mAt20;
    void vfunc_4();
};
void CUninterruptibleAction::vfunc_4() {
    A_17590* a = mAt1c->f1_000592a0();
    A_17590* b = a->f2_00059a30();
    b->f3_00036140(0);
    b->f4_00036120(mAt20);
}
} // namespace fn_00017590

