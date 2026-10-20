// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_0023c9f0 @ 0x0023c9f0
#include "decls/data/engine/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace fight {
class SubConditionGroupCondition {
public:
    void FUN_0023c8a0();
};
}

class __declspec(novtable) ParamConditionGroupBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00235220(const char* name);
    ParamConditionGroupBase(const char* name) { FUN_00235220(name); }
};
namespace fight {
template <class T>
class ParamConditionGroup : public ParamConditionGroupBase {
public:
    ParamConditionGroup(const char* name, void (T::*s)()) : ParamConditionGroupBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0023c9f0()
{
    if (DAT_004e5c48 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamConditionGroup<fight::SubConditionGroupCondition>("conditionGroup", &fight::SubConditionGroupCondition::FUN_0023c8a0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e5c44), params, 1);
    }
    DAT_004e5c48++;
}
