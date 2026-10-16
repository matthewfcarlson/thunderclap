// STATUS: equivalent (tools/equiv.py level 3: 343 inputs, branch coverage 14/14)
// hulkfight::motion::HitPauseAction::vfunc_3 @ 0x0014ef40
#include "gen/hulkfight.h"

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
Stats_14ef40 *__fastcall FUN_00059a30(Fighter_14ef40 *f);

class Action_14ef40 {
public:
    virtual void vfunc_0();
};

namespace hulkfight {
namespace motion {

}
}
bool hulkfight::motion::HitPauseAction::vfunc_3(int a, int b) {
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
