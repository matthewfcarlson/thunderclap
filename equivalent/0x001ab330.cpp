// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 10/10)
// hulkfight::scenario::Event_TriggerVolumeNameCondition::vfunc_6 @ 0x001ab330
namespace fight {
class Params {
public:
    virtual void v0();
};
}

struct Id64 {
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

class CScenarioParams : public fight::Params {
public:
    virtual void v1();
    VolumeInfo *FUN_001d03c0();
};

namespace hulkfight {
namespace scenario {
class Event_TriggerVolumeNameCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, fight::Params *params, int c);
    char pad04[0xc];
    unsigned int wantLo;    // 0x10
    unsigned int wantHi;    // 0x14
};
}
}

bool hulkfight::scenario::Event_TriggerVolumeNameCondition::vfunc_6(int a, fight::Params *params, int c)
{
    Id64 name;
    name.FUN_0027af00();

    CScenarioParams *sp = dynamic_cast<CScenarioParams *>(params);
    if (sp != 0) {
        VolumeInfo *info = sp->FUN_001d03c0();
        if (info->type == 0x1d || info->type == 0x1e) {
            name.FUN_0027b040(info->name);
            if (name.lo == wantLo && name.hi == wantHi) {
                name.FUN_0027af50();
                return true;
            }
        }
    }
    name.FUN_0027af50();
    return false;
}
