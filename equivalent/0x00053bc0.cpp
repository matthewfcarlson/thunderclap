// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_00053bc0 @ 0x00053bc0
#include "decls/data/game/global.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CSmartPropAngleCondition_53bc0 {
public:
    void FUN_00047ec0();
    void FUN_0004c790();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_53bc0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_53bc0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00053bc0()
{
    if (DAT_004dc4cc == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_53bc0<::CSmartPropAngleCondition_53bc0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_53bc0<::CSmartPropAngleCondition_53bc0>("angle", &::CSmartPropAngleCondition_53bc0::FUN_00047ec0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_53bc0<::CSmartPropAngleCondition_53bc0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_53bc0<::CSmartPropAngleCondition_53bc0>("arc", &::CSmartPropAngleCondition_53bc0::FUN_0004c790);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc4c8), params, 2);
    }
    DAT_004dc4cc++;
}
