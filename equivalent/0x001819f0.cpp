// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// hulkfight::motion::PropIsAttachedCondition::vfunc_6 @ 0x001819f0
#include "gen/hulkfight.h"

namespace fight {
class Params_1819f0 {
public:
    virtual void v0();
};
}

class CFightParams_1819f0 : public fight::Params_1819f0 {
public:
    virtual void v1();
};

struct Fighter_1819f0 {
    char pad0[0x128];
    void *f128;
    void *FUN_00035ef0(int slot);
};

struct Anchor_1819f0 {
    Fighter_1819f0 *FUN_00059a30();
};

struct FightHandle {
    Anchor_1819f0 *FUN_000592a0();
};

namespace hulkfight {
namespace motion {
}
}
bool hulkfight::motion::PropIsAttachedCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; fight::Params_1819f0 * params = (fight::Params_1819f0 *)__p1; int c = (int)__p2;

    CFightParams_1819f0 *fp = dynamic_cast<CFightParams_1819f0 *>(params);
    if (fp == 0)
        return false;
    Fighter_1819f0 *f = ((FightHandle *)params)->FUN_000592a0()->FUN_00059a30();
    void *prop = 0;
    if (f != 0) {
        if (this->f_0c < 0)
            prop = f->f128;
        else if (this->f_0c < 8)
            prop = f->FUN_00035ef0(this->f_0c);
    }
    return (prop != 0) == (*(unsigned char *)&this->f_10);
}
