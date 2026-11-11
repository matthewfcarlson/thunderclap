// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00049140..0x00049230 (kind game, layer game, confidence medium), dominant class CSmartPropAttachedCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3159823 {
#define TREE_TU_END }
namespace fn_f3159823 {} using namespace fn_f3159823;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f3159823 {
extern int* hulk_at_004dc4a0;
class CCondition_49140 {
  public:
    virtual int vfunc_0(int);
};
struct Slot_49190 { int FUN_001d64a0(); };
struct Player_49190 {
};
void* __fastcall FUN_000592a0(void* owner);
extern "C" Player_49190* __fastcall FUN_00059a30(void* x);

} // namespace fn_f3159823

// 0x00049140 CSmartPropAttachedCondition::vfunc_0 (16 B): matches/0x00049140.cpp
// sym: ?vfunc_0@CSmartPropAttachedCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSmartPropAttachedCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc4a0;
    return p[index];
}


// 0x00049190 CSmartPropAttachedCondition::vfunc_7 (152 B): equivalent/0x00049190.cpp
// sym: ?vfunc_7@CSmartPropAttachedCondition@@UAE_NPAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// CSmartPropAttachedCondition::vfunc_7 @ 0x00049190
bool CSmartPropAttachedCondition::vfunc_7(void* __p0) { void * actor = (void *)__p0;

    Player_49190* p = FUN_00059a30(FUN_000592a0(actor));
    if (this->f_14 == -1) {
        if (!((owners::C_35f20 *)p)->FUN_00035f20())
            return false;
        if (!this->f_0c)
            return true;
        for (int i = 0; i < 8; i++) {
            Slot_49190* s = ((Slot_49190 *)((owners::C_35ef0 *)p)->FUN_00035ef0((hulk_intptr)i));
            if (s && s->FUN_001d64a0() == this->f_10)
                return true;
        }
        return false;
    }
    Slot_49190* s = ((Slot_49190 *)((owners::C_35ef0 *)p)->FUN_00035ef0((hulk_intptr)(this->f_14)));
    if (!s)
        return false;
    if (!this->f_0c)
        return true;
    return s->FUN_001d64a0() == this->f_10;
}

