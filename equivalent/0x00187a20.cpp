// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_00187a20 @ 0x00187a20
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class PropIsAttachedCondition_187a20 {
public:
    void FUN_0017f520();
    void FUN_0017f530();
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
class ParamBool_187a20 : public ParamBoolBase {
public:
    ParamBool_187a20(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_187a20 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_187a20(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00187a20()
{
    if (DAT_004e1434 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamIntConstRange_187a20<hulkfight::motion::PropIsAttachedCondition_187a20>("attachmentIndex", &hulkfight::motion::PropIsAttachedCondition_187a20::FUN_0017f520);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBool_187a20<hulkfight::motion::PropIsAttachedCondition_187a20>("isAttached", &hulkfight::motion::PropIsAttachedCondition_187a20::FUN_0017f530);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1430), params, 2);
    }
    DAT_004e1434++;
}
