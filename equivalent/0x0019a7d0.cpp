// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_0019a7d0 @ 0x0019a7d0
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
namespace motion {
class PropGrabbableIsMissileCondition {
public:
    void FUN_00192160();
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

void FUN_0019a7d0()
{
    if (DAT_004e154c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool<hulkfight::motion::PropGrabbableIsMissileCondition>("isMissile", &hulkfight::motion::PropGrabbableIsMissileCondition::FUN_00192160);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1548), params, 1);
    }
    DAT_004e154c++;
}
