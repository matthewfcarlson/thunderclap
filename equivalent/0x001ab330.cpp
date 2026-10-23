// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 10/10)
// hulkfight::scenario::Event_TriggerVolumeNameCondition::vfunc_6 @ 0x001ab330
#include "gen/hulkfight.h"

namespace fight {
class Params_1ab330 {
public:
    virtual void v0();
};
}

struct Id64_1ab330 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af00();
    void FUN_0027af50();
    void FUN_0027b040(const char *name);
};

struct VolumeInfo {
    char pad00[4];
    int type;               // 0x4
    char pad08[0xc];
    char name[1];           // 0x14
};

class CScenarioParams_1ab330 : public fight::Params_1ab330 {
public:
    virtual void v1();
    VolumeInfo *FUN_001d03c0();
};

namespace hulkfight {
namespace scenario {
}
}
bool hulkfight::scenario::Event_TriggerVolumeNameCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; fight::Params_1ab330 * params = (fight::Params_1ab330 *)__p1; int c = (int)__p2;

    Id64_1ab330 name;
    name.FUN_0027af00();

    CScenarioParams_1ab330 *sp = dynamic_cast<CScenarioParams_1ab330 *>(params);
    if (sp != 0) {
        VolumeInfo *info = sp->FUN_001d03c0();
        if (info->type == 0x1d || info->type == 0x1e) {
            name.FUN_0027b040(info->name);
            if (name.lo == (*(unsigned int *)&this->f_10) && name.hi == (*(unsigned int *)&this->f_14)) {
                name.FUN_0027af50();
                return true;
            }
        }
    }
    name.FUN_0027af50();
    return false;
}
