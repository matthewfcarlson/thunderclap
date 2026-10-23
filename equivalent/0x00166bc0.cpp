// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 20/20)
// hulkfight::motion::IntentionInputCondition::vfunc_6 @ 0x00166bc0
// hulkfight::motion::IntentionInputCondition::vfunc_6 @ 0x00166bc0: checks the requested pad inputs against the controller state
#include "gen/hulkfight.h"

struct Slot_166bc0 {
    int state;
    int pad[2];
};
struct Controller_166bc0 {
    char pad00[0x1f58];
    Slot_166bc0 slots[4];
    char pad1f88[0x1ff4 - 0x1f88];
    int extra;
};
struct Holder_166bc0 {
    Controller_166bc0 *FUN_00059a30();
};

namespace fight {
class Params_166bc0 {
public:
    virtual void v0();
    Holder_166bc0 *FUN_000592a0();
};
}
class CFightParams_166bc0 : public fight::Params_166bc0 {
public:
    virtual void v1();
};

namespace hulkfight {
namespace motion {
}
}
bool hulkfight::motion::IntentionInputCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; fight::Params_166bc0 * params = (fight::Params_166bc0 *)__p1; int c = (int)__p2;

    if (dynamic_cast<CFightParams_166bc0 *>(params) == 0)
        return false;
    Controller_166bc0 *ctl = params->FUN_000592a0()->FUN_00059a30();
    bool hit = false;
    for (int i = 0; i <= 3; i++) {
        int state = ctl->slots[i].state;
        if (state == 2)
            hit = ((*(unsigned char *)&this->f_0c) == 1);
        else if (state == 1)
            hit = ((*(unsigned char *)&this->f_0d) == 1);
        if (hit)
            return true;
    }
    int extra = ctl->extra;
    if (extra == 2)
        return (*(unsigned char *)&this->f_0e) == 1;
    if (extra == 1)
        return (*(unsigned char *)&this->f_0f) == 1;
    return hit;
}
