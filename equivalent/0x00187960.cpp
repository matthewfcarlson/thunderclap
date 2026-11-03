// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_00187960 @ 0x00187960
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class PropGrabbableIsThrownCondition_187960 {
public:
    void FUN_0017f470();
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
class ParamBool_187960 : public ParamBoolBase {
public:
    ParamBool_187960(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00187960()
{
    if (DAT_004e141c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_187960<hulkfight::motion::PropGrabbableIsThrownCondition_187960>("isThrown", &hulkfight::motion::PropGrabbableIsThrownCondition_187960::FUN_0017f470);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1418), params, 1);
    }
    DAT_004e141c++;
}
