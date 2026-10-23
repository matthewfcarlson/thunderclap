// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 22/22)
// CPropActorStateCondition::vfunc_7 @ 0x00049bb0
#include "gen/global.h"

struct Counter_49bb0 {
    char pad0[0x40];
    int value;      // 0x40
};

struct Stats_49bb0 {
    char pad0[0x128];
    Counter_49bb0 *counter;
};

class Owner;
Owner *__fastcall FUN_000592a0(Owner *owner);
Stats_49bb0 *__fastcall FUN_00059a30(Owner *ctx);

bool CPropActorStateCondition::vfunc_7(void* __p0) { Owner * owner = (Owner *)__p0;

    Stats_49bb0 *stats = FUN_00059a30(FUN_000592a0(owner));
    if (stats->counter == 0)
        return false;
    int value = stats->counter->value;
    switch ((*(unsigned int *)&this->f_0c)) {
    case 0: return value < this->f_10;
    case 1: return value <= this->f_10;
    case 2: return value == this->f_10;
    case 3: return value != this->f_10;
    case 4: return value >= this->f_10;
    case 5: return value > this->f_10;
    }
    return false;
}
