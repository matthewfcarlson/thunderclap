// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_001a6f30 @ 0x001a6f30
#include "decls/data/game/hulkfight/scenario.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace scenario {
class NodeIsNotRunningCondition_1a6f30 {
public:
    void FUN_001a1ed0();
};
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
namespace fight {
template <class T>
class ParamBool_1a6f30 : public ParamBoolBase {
public:
    ParamBool_1a6f30(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001a6f30()
{
    if (DAT_004e170c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_1a6f30<hulkfight::scenario::NodeIsNotRunningCondition_1a6f30>("nodeIsNotRunning", &hulkfight::scenario::NodeIsNotRunningCondition_1a6f30::FUN_001a1ed0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1708), params, 1);
    }
    DAT_004e170c++;
}
