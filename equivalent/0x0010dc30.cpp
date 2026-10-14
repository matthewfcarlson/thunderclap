// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 24/24)
// hulkfight::ai::RandomKeyWordWaitCondition::vfunc_6 @ 0x0010dc30
struct Mgr;

namespace fight {
class Params {
public:
    virtual void v0();
    Mgr *FUN_000592a0();
};
}

class CFightParams : public fight::Params {
public:
    virtual void v1();
};

struct Player {
    char pad0[0x39c];
    int counter;            // 0x39c
};

struct Mgr {
    Player *FUN_00059a30();
};

namespace hulkfight {
namespace ai {
class RandomKeyWordWaitCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, fight::Params *params, int c);
    char pad04[0x0c - 4];
    int op;                 // 0x0c
    int value;              // 0x10
};
}
}

bool hulkfight::ai::RandomKeyWordWaitCondition::vfunc_6(int a, fight::Params *params, int c)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return false;
    Player *player = params->FUN_000592a0()->FUN_00059a30();
    if (player == 0)
        return false;
    int count = player->counter;
    switch (op) {
    case 0: return count < value;
    case 1: return count <= value;
    case 2: return count == value;
    case 3: return count != value;
    case 4: return count >= value;
    case 5: return count > value;
    }
    return false;
}
