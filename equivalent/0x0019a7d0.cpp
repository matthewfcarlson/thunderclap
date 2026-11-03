// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_0019a7d0 @ 0x0019a7d0
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class PropGrabbableIsMissileCondition_19a7d0 {
public:
    void FUN_00192160();
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
class ParamBool_19a7d0 : public ParamBoolBase {
public:
    ParamBool_19a7d0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0019a7d0()
{
    if (DAT_004e154c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_19a7d0<hulkfight::motion::PropGrabbableIsMissileCondition_19a7d0>("isMissile", &hulkfight::motion::PropGrabbableIsMissileCondition_19a7d0::FUN_00192160);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1548), params, 1);
    }
    DAT_004e154c++;
}
