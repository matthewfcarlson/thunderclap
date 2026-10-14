// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 22/22)
// hulkfight::motion::GrapplePropStateByNameCondition::vfunc_6 @ 0x001835c0
struct Mgr_1835c0;
struct Actor_1835c0;
struct Player_1835c0;

namespace fight {
class Params {
public:
    virtual void v0();
    Mgr_1835c0 *FUN_000592a0();
};
}

class CFightParams : public fight::Params {
public:
    virtual void v1();
};

struct StateInfo_1835c0 {
    char pad0[8];
    unsigned int idLo;      // 0x08
    unsigned int idHi;      // 0x0c
};

struct StateTable_1835c0 {
    char pad0[0x1c];
    StateInfo_1835c0 **states;     // 0x1c
};

struct Actor_1835c0 {
    char pad0[0x40];
    int state;              // 0x40
    char pad44[0x98 - 0x44];
    StateTable_1835c0 *table;      // 0x98
};

struct Roster_1835c0 {
    char pad0[0x128];
    Actor_1835c0 *self;            // 0x128
    Actor_1835c0 *FUN_00035ef0(int index);
};

struct Player_1835c0 {
    char pad0[0x338];
    Roster_1835c0 *roster;         // 0x338
};

struct Mgr_1835c0 {
    Player_1835c0 *FUN_00059a30();
};

namespace hulkfight {
namespace motion {
class GrapplePropStateByNameCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, fight::Params *params, int c);
    char pad04[0x0c - 4];
    int playerIndex;        // 0x0c
    int mode;               // 0x10
    char pad14[4];
    unsigned int wantLo;    // 0x18
    unsigned int wantHi;    // 0x1c
};
}
}

bool hulkfight::motion::GrapplePropStateByNameCondition::vfunc_6(int a, fight::Params *params, int c)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return false;
    Player_1835c0 *player = params->FUN_000592a0()->FUN_00059a30();
    Roster_1835c0 *roster = player->roster;
    if (roster == 0)
        return false;
    Actor_1835c0 *actor;
    if (playerIndex < 0) {
        actor = roster->self;
    } else {
        if (playerIndex >= 8)
            return false;
        actor = roster->FUN_00035ef0(playerIndex);
    }
    if (actor == 0)
        return false;
    StateInfo_1835c0 *info = actor->table->states[actor->state];
    unsigned int lo = info->idLo;
    unsigned int hi = info->idHi;
    bool same = (lo == wantLo && hi == wantHi);
    if (mode == 0)
        return same;
    if (mode == 1)
        return !same;
    return false;
}
