// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 22/22)
// hulkfight::motion::PropStateByNameCondition::vfunc_6 @ 0x00183510
#include "gen/hulkfight.h"

struct Mgr_183510;
struct Actor_183510;
struct Player_183510;

namespace fight {
class Params_183510 {
public:
    virtual void v0();
    Mgr_183510 *FUN_000592a0();
};
}

class CFightParams_183510 : public fight::Params_183510 {
public:
    virtual void v1();
};

struct StateInfo_183510 {
    char pad0[8];
    unsigned int idLo;      // 0x08
    unsigned int idHi;      // 0x0c
};

struct StateTable_183510 {
    char pad0[0x1c];
    StateInfo_183510 **states;     // 0x1c
};

struct Actor_183510 {
    char pad0[0x40];
    int state;              // 0x40
    char pad44[0x98 - 0x44];
    StateTable_183510 *table;      // 0x98
};

struct Player_183510 {
    char pad0[0x128];
    Actor_183510 *self;            // 0x128
    Actor_183510 *FUN_00035ef0(int index);
};

struct Mgr_183510 {
    Player_183510 *FUN_00059a30();
};

namespace hulkfight {
namespace motion {
}
}
bool hulkfight::motion::PropStateByNameCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; fight::Params_183510 * params = (fight::Params_183510 *)__p1; int c = (int)__p2;

    if (dynamic_cast<CFightParams_183510 *>(params) == 0)
        return false;
    Player_183510 *player = params->FUN_000592a0()->FUN_00059a30();
    if (player == 0)
        return false;
    Actor_183510 *actor;
    if (this->f_0c < 0) {
        actor = player->self;
    } else {
        if (this->f_0c >= 8)
            return false;
        actor = player->FUN_00035ef0(this->f_0c);
    }
    if (actor == 0)
        return false;
    StateInfo_183510 *info = actor->table->states[actor->state];
    unsigned int lo = info->idLo;
    unsigned int hi = info->idHi;
    bool same = (lo == (*(unsigned int *)&this->f_18) && hi == (*(unsigned int *)&this->f_1c));
    if (this->f_10 == 0)
        return same;
    if (this->f_10 == 1)
        return !same;
    return false;
}
