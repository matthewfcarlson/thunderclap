// STATUS: equivalent (tools/equiv.py level 3: 3040 inputs, branch coverage 15/16, incomplete)
// hulkfight::scenario::Event_PropTypeCondition::vfunc_6 @ 0x001a4b10
namespace fight {
class Params {
public:
    virtual void v0();
};
}

struct PropInfo_1a4b10 {
    char pad0[4];
    int type;
    char pad8[0x20 - 8];
    int typeLo;
    int typeHi;
};

class CScenarioParams : public fight::Params {
public:
    virtual void v1();
    PropInfo_1a4b10 *FUN_001d03c0();
};

namespace hulkfight {
namespace scenario {
class Event_PropTypeCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, fight::Params *params, int c);
    char pad04[0x10 - 4];
    int wantLo;
    int wantHi;
};
}
}

bool hulkfight::scenario::Event_PropTypeCondition::vfunc_6(int a, fight::Params *params, int c)
{
    CScenarioParams *sp = dynamic_cast<CScenarioParams *>(params);
    if (sp == 0)
        return false;
    PropInfo_1a4b10 *info = sp->FUN_001d03c0();
    if (info->type < 0x12 || info->type > 0x17)
        return false;
    return info->typeLo == wantLo && info->typeHi == wantHi;
}
