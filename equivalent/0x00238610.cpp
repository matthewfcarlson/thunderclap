// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_00238610 @ 0x00238610
#include "decls/data/engine/fight.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace fight {
class RandomCondition_238610 {
public:
    void FUN_002381d0();
};
}

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_238610 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_238610(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00238610()
{
    if (DAT_004e5c18 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_238610<fight::RandomCondition_238610>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_238610<fight::RandomCondition_238610>("weight", &fight::RandomCondition_238610::FUN_002381d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e5c14), params, 1);
    }
    DAT_004e5c18++;
}
