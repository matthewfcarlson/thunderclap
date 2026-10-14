// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 12/12)
// hulkfight::scenario::Event_PropStateNameCondition::vfunc_6 @ 0x001a5cc0
namespace fight {
class Params {
public:
    virtual void v0();
};
}

struct PropInfo {
    char pad0[4];
    int type;
    char pad8[0x18 - 8];
    int nameLo;
    int nameHi;
};

class CScenarioParams : public fight::Params {
public:
    virtual void v1();
    PropInfo *FUN_001d03c0();
};

struct NameEntry {
    char pad0[8];
    int idLo;
    int idHi;
};

class NameList {
public:
    char pad0[0x1c];
    NameEntry **entries;
};

class NameTable {
public:
    NameList *FUN_001d4fc0();
};

class Prop {
public:
    char pad0[0x40];
    int stateIndex;
    char pad44[0xec - 0x44];
    NameTable *names;
};

class PropRegistry {
public:
    Prop *FUN_001dee40(int lo, int hi);
};

class Game {
public:
    char pad0[0xc];
    PropRegistry *props;
};
extern Game *DAT_004dd700;

namespace hulkfight {
namespace scenario {
class Event_PropStateNameCondition {
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

bool hulkfight::scenario::Event_PropStateNameCondition::vfunc_6(int a, fight::Params *params, int c)
{
    CScenarioParams *sp = dynamic_cast<CScenarioParams *>(params);
    if (sp == 0)
        return false;
    bool result = false;
    PropInfo *info = sp->FUN_001d03c0();
    if (info->type != 0x17)
        return false;
    Prop *prop = DAT_004dd700->props->FUN_001dee40(info->nameLo, info->nameHi);
    if (prop != 0) {
        int index = prop->stateIndex;
        if (index != -1) {
            NameEntry *entry = prop->names->FUN_001d4fc0()->entries[index];
            if (entry->idLo == wantLo && entry->idHi == wantHi) {
                result = true;
            }
        }
    }
    return result;
}
