// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// hulkfight::motion::HealthAction::vfunc_3 @ 0x0014ff20
#include "gen/hulkfight.h"

struct Stats_14ff20 {
    char pad0[0x1b0c];
    float offset;       // 0x1b0c
    void FUN_0003b1c0(float value, int flag);
};

struct Info_14ff20 {
    char pad0[0x10];
    float value;        // 0x10
    char negate;        // 0x14
    char useOffsetA;    // 0x15
    char useOffsetB;    // 0x16
};

class Owner;
Owner *__fastcall FUN_000592a0(Owner *owner);
Stats_14ff20 *__fastcall FUN_00059a30(Owner *ctx);

namespace hulkfight {
namespace motion {

}
}
bool hulkfight::motion::HealthAction::vfunc_3(int a, int b) {
    if ((*(Owner * *)&this->f_20) == 0)
        return false;
    Stats_14ff20 *stats = FUN_00059a30(FUN_000592a0((*(Owner * *)&this->f_20)));
    if (stats == 0)
        return false;
    int flag = (*(Info_14ff20 * *)&this->f_1c)->negate != 0;
    if ((*(Info_14ff20 * *)&this->f_1c)->useOffsetB)
        stats->FUN_0003b1c0(stats->offset - (*(Info_14ff20 * *)&this->f_1c)->value, flag);
    else if ((*(Info_14ff20 * *)&this->f_1c)->useOffsetA)
        stats->FUN_0003b1c0((*(Info_14ff20 * *)&this->f_1c)->value + stats->offset, flag);
    else
        stats->FUN_0003b1c0((*(Info_14ff20 * *)&this->f_1c)->value, flag);
    return false;
}
