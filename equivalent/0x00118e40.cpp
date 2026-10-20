// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_00118e40 @ 0x00118e40
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class HasGroundPointCondition {
public:
    void FUN_00114eb0();
    void FUN_00114ed0();
};
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
};
namespace fight {
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00118e40()
{
    if (DAT_004e0c28 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool<hulkfight::ai::HasGroundPointCondition>("groundPoint", &hulkfight::ai::HasGroundPointCondition::FUN_00114eb0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBool<hulkfight::ai::HasGroundPointCondition>("useMyTargetInstead", &hulkfight::ai::HasGroundPointCondition::FUN_00114ed0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0c24), params, 2);
    }
    DAT_004e0c28++;
}
