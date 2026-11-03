// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_0019a830 @ 0x0019a830
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class PropIsMissileCondition_19a830 {
public:
    void FUN_00192170();
    void FUN_00192180();
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
class ParamBool_19a830 : public ParamBoolBase {
public:
    ParamBool_19a830(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_19a830 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_19a830(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0019a830()
{
    if (DAT_004e1554 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamIntConstRange_19a830<hulkfight::motion::PropIsMissileCondition_19a830>("attachmentIndex", &hulkfight::motion::PropIsMissileCondition_19a830::FUN_00192170);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBool_19a830<hulkfight::motion::PropIsMissileCondition_19a830>("isMissile", &hulkfight::motion::PropIsMissileCondition_19a830::FUN_00192180);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1550), params, 2);
    }
    DAT_004e1554++;
}
