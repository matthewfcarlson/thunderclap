// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 14/14)
// hulkfight::motion::TargetMotionStateCondition::vfunc_6 @ 0x00167290
#include "gen/hulkfight.h"

struct Stats_167290;

struct Ctx_167290 {
    Stats_167290 *FUN_00059a30();
};

class Owner_167290 {
public:
    Ctx_167290 *FUN_000592a0();
};

struct Target_167290 {
    char pad0[0x140];
    unsigned int f140;
};

struct Stats_167290 {
    char pad0[0x328];
    struct Slot {
        char pad0[8];
        Target_167290 *f8;
        int fc;
    } *f328;
};

bool hulkfight::motion::TargetMotionStateCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a1 = (int)__p0; Owner_167290 * owner = (Owner_167290 *)__p1; int a3 = (int)__p2;

    Stats_167290 *st = owner->FUN_000592a0()->FUN_00059a30();
    Stats_167290::Slot *slot = st->f328;
    if (slot == 0 || slot->f8 == 0 || slot->fc != 1)
        return (bool)(1);
    unsigned int want = (*(unsigned int *)&this->f_10);
    unsigned int cur = slot->f8->f140;
    if (this->f_0c == 0)
        return (bool)(cur == want);
    if (this->f_0c == 1)
        return (bool)(cur != want);
    return (bool)(0);
}
