// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// hulkfight::motion::IntentionButtonDownAnyCondition::vfunc_6 @ 0x00166b40
#include "gen/hulkfight.h"

namespace fight { class Params_166b40; }
class CFightParams_166b40;

class Holder_166b40 {
public:
    char pad0[0x1f58];
    struct Slot { int state; int a; int b; } slots[11];
};
class Inner_166b40 {
public:
    Holder_166b40* FUN_00059a30();
};
namespace fight {
class Params_166b40 {
public:
    virtual void p0();
    Inner_166b40* FUN_000592a0();
};
}
class CFightParams_166b40 : public fight::Params_166b40 {
public:
    virtual void c0();
};

namespace hulkfight { namespace motion {

}}
bool hulkfight::motion::IntentionButtonDownAnyCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int unused1 = (int)__p0; fight::Params_166b40 * params = (fight::Params_166b40 *)__p1; int unused2 = (int)__p2;

    if (!dynamic_cast<CFightParams_166b40*>(params))
        return false;
    Holder_166b40* h = params->FUN_000592a0()->FUN_00059a30();
    char down = 0;
    for (int i = 0; i < 11; i++) {
        if (h->slots[i].state == 2 || h->slots[i].state == 1) {
            down = 1;
            break;
        }
    }
    return down == this->f_0c;
}
