// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// CSmartPropAttachedCondition::vfunc_7 @ 0x00049190
#include "gen/global.h"

struct Slot_49190 { int FUN_001d64a0(); };
struct Player_49190 {
    bool FUN_00035f20();
    Slot_49190* FUN_00035ef0(int i);
};
void* __fastcall FUN_000592a0(void* owner);
Player_49190* __fastcall FUN_00059a30(void* x);

bool CSmartPropAttachedCondition::vfunc_7(void* __p0) { void * actor = (void *)__p0;

    Player_49190* p = FUN_00059a30(FUN_000592a0(actor));
    if (this->f_14 == -1) {
        if (!p->FUN_00035f20())
            return false;
        if (!this->f_0c)
            return true;
        for (int i = 0; i < 8; i++) {
            Slot_49190* s = p->FUN_00035ef0(i);
            if (s && s->FUN_001d64a0() == this->f_10)
                return true;
        }
        return false;
    }
    Slot_49190* s = p->FUN_00035ef0(this->f_14);
    if (!s)
        return false;
    if (!this->f_0c)
        return true;
    return s->FUN_001d64a0() == this->f_10;
}
