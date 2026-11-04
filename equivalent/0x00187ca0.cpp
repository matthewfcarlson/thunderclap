// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_00187ca0 @ 0x00187ca0
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class PropCollidedWithWorldCondition_187ca0 {
public:
    void FUN_0017f660();
    void FUN_0017f670();
};
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
namespace fight {
template <class T>
class ParamBool_187ca0 : public ParamBoolBase {
public:
    ParamBool_187ca0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_187ca0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_187ca0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00187ca0()
{
    if (DAT_004e1454 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_187ca0<hulkfight::motion::PropCollidedWithWorldCondition_187ca0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamIntConstRange_187ca0<hulkfight::motion::PropCollidedWithWorldCondition_187ca0>("attachmentIndex", &hulkfight::motion::PropCollidedWithWorldCondition_187ca0::FUN_0017f660);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_187ca0<hulkfight::motion::PropCollidedWithWorldCondition_187ca0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBool_187ca0<hulkfight::motion::PropCollidedWithWorldCondition_187ca0>("collided", &hulkfight::motion::PropCollidedWithWorldCondition_187ca0::FUN_0017f670);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1450), params, 2);
    }
    DAT_004e1454++;
}
