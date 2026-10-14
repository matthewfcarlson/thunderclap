// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 20/20)
// hulkfight::motion::IntentionInputCondition::vfunc_6 @ 0x00166bc0
// hulkfight::motion::IntentionInputCondition::vfunc_6 @ 0x00166bc0: checks the requested pad inputs against the controller state
struct Slot {
    int state;
    int pad[2];
};
struct Controller {
    char pad00[0x1f58];
    Slot slots[4];
    char pad1f88[0x1ff4 - 0x1f88];
    int extra;
};
struct Holder {
    Controller *FUN_00059a30();
};

namespace fight {
class Params {
public:
    virtual void v0();
    Holder *FUN_000592a0();
};
}
class CFightParams : public fight::Params {
public:
    virtual void v1();
};

namespace hulkfight {
namespace motion {
class IntentionInputCondition {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(int a, fight::Params *params, int c);
    char pad04[8];
    unsigned char first;
    unsigned char second;
    unsigned char third;
    unsigned char fourth;
};
}
}

bool hulkfight::motion::IntentionInputCondition::vfunc_6(int a, fight::Params *params, int c)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return false;
    Controller *ctl = params->FUN_000592a0()->FUN_00059a30();
    bool hit = false;
    for (int i = 0; i <= 3; i++) {
        int state = ctl->slots[i].state;
        if (state == 2)
            hit = (first == 1);
        else if (state == 1)
            hit = (second == 1);
        if (hit)
            return true;
    }
    int extra = ctl->extra;
    if (extra == 2)
        return third == 1;
    if (extra == 1)
        return fourth == 1;
    return hit;
}
