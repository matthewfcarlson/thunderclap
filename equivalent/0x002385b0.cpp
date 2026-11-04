// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_002385b0 @ 0x002385b0
#include "decls/data/engine/fight.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace fight {
class MaybeCondition_2385b0 {
public:
    void FUN_002381c0();
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
class ParamFloatConstRange_2385b0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_2385b0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_002385b0()
{
    if (DAT_004e5c10 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_2385b0<fight::MaybeCondition_2385b0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_2385b0<fight::MaybeCondition_2385b0>("percent", &fight::MaybeCondition_2385b0::FUN_002381c0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e5c0c), params, 1);
    }
    DAT_004e5c10++;
}
