// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014ef10..0x0014efd0 (kind game, layer game, confidence medium), dominant class hulkfight::motion::HitPauseAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fa44cb41 {
#define TREE_TU_END }
namespace fn_fa44cb41 {} using namespace fn_fa44cb41;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fa44cb41 {
struct Two_14ef10 {
    void* Fnf_00059a40();
};
struct Fighter_14ef40 {
    char pad[4];
};
Fighter_14ef40 *__fastcall FUN_000592a0(void *owner);
struct Key_14ef40 {
    char pad00[0x10];
    unsigned int lo;
    unsigned int hi;
};
struct Pausable {
    void FUN_00035b70(int zero, unsigned int lo, unsigned int hi);
};
struct Attached_14ef40 {
    char pad00[0x148];
    Pausable *pausable148;
};
struct Slot_14ef40 {
    char pad00[8];
    Pausable *direct;
    int kind;
};
struct SlotHolder {
    char pad00[8];
    Attached_14ef40 *attached;
    int kind;
};
struct Stats_14ef40 {
    char pad00[0x200];
    SlotHolder *slots[64];
    int slotCount;
};
extern "C" Stats_14ef40 *__fastcall FUN_00059a30(Fighter_14ef40 *f);
class Action_14ef40 {
public:
    virtual void vfunc_0();
};

} // namespace fn_fa44cb41

// 0x0014ef10 hulkfight::motion::GroundSlideAction::vfunc_4 (37 B): matches/0x0014ef10.cpp
// sym: ?vfunc_4@GroundSlideAction@motion@hulkfight@@UAEXXZ
// Same code shape as 0x00134160 (propagated; names are from that function)
void hulkfight::motion::GroundSlideAction::vfunc_4() {
    void* x = (*(One * *)&this->f_20)->f();
    void* y = ((Two_14ef10*)x)->Fnf_00059a40();
    if (y)
        ((Three*)y)->f((*(void * *)&this->f_24), 0);
}


// 0x0014ef40 hulkfight::motion::HitPauseAction::vfunc_3 (133 B): equivalent/0x0014ef40.cpp
// sym: ?vfunc_3@HitPauseAction@motion@hulkfight@@UAE_NHH@Z @bad14077bb22 @w6f0c129c8376
// STATUS: equivalent (tools/equiv.py level 3: 343 inputs, branch coverage 14/14)
// hulkfight::motion::HitPauseAction::vfunc_3 @ 0x0014ef40
bool hulkfight::motion::HitPauseAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    Stats_14ef40 *stats = FUN_00059a30(FUN_000592a0((*(void * *)&this->f_20)));
    int count = stats->slotCount;
    if (count > 0) {
        unsigned int lo = (*(Key_14ef40 * *)&this->f_1c)->lo;
        unsigned int hi = (*(Key_14ef40 * *)&this->f_1c)->hi;
        for (int i = 0; i < count; i++) {
            SlotHolder *holder = stats->slots[i];
            if (holder == 0)
                continue;
            Pausable *p;
            if (holder->kind == 1)
                p = (Pausable *)holder->attached;
            else if (holder->kind == 5) {
                p = 0;
                if (holder->attached != 0)
                    p = holder->attached->pausable148;
            } else
                continue;
            if (p != 0)
                p->FUN_00035b70(0, lo, hi);
        }
    }
    return false;
}

