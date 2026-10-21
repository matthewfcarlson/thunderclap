// STATUS: equivalent (tools/equiv.py level 3: 20030 inputs, branch coverage 15/16, incomplete)
// hulkfight::motion::GrapplePropDamageAction::vfunc_3 @ 0x00182380
#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct Pad_182380 {
    void FUN_001d6ec0(int a, int b, int c);
};

struct Fighter_182380 {
    char pad0[0x128];
    Pad_182380 *selfPad;
    int val;
    Pad_182380 *FUN_00035ef0(int idx);
};

struct Stats_182380 {
    char pad0[0x12c];
    int padValue;
    char pad130[0x334 - 0x130];
    Fighter_182380 *fighterA;
    Fighter_182380 *fighterB;
    char pad33c[0x1e58 - 0x33c];
    float blend;
};

struct Info_182380 {
    char pad0[0x10];
    int padIndex;
    float from;
    float to;
};

class Owner;
Owner *__fastcall FUN_000592a0(Owner *owner);
Stats_182380 *__fastcall FUN_00059a30(Owner *ctx);

namespace hulkfight {
namespace motion {

}
}
bool hulkfight::motion::GrapplePropDamageAction::vfunc_3(int a, int b) {
    if ((*(Owner * *)&this->f_20) == 0)
        return false;
    Stats_182380 *stats = FUN_00059a30(FUN_000592a0((*(Owner * *)&this->f_20)));
    Fighter_182380 *fighter = stats->fighterB;
    if (fighter == 0) {
        fighter = stats->fighterA;
        if (fighter == 0)
            return false;
    }
    int idx = (*(Info_182380 * *)&this->f_1c)->padIndex;
    Pad_182380 *pad;
    if (idx < 0) {
        pad = fighter->selfPad;
    } else if (idx >= 8) {
        return false;
    } else {
        pad = fighter->FUN_00035ef0(idx);
    }
    if (pad == 0)
        return false;
    hulk_freg v = (*(Info_182380 * *)&this->f_1c)->from;
    if (v < (*(Info_182380 * *)&this->f_1c)->to)
        v += ((*(Info_182380 * *)&this->f_1c)->to - v) * stats->blend;
    pad->FUN_001d6ec0((int)v, stats->padValue, 0);
    return false;
}
