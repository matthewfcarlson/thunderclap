// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_0023f3a0 @ 0x0023f3a0
#include "decls/data/engine/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace fight {
class BreakPointTrack {
public:
    void FUN_0023f0d0();
    void FUN_0023f0e0();
};
}

class __declspec(novtable) ParamConditionGroupBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00235220(const char* name);
    ParamConditionGroupBase(const char* name) { FUN_00235220(name); }
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
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
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0023f3a0()
{
    if (DAT_004e5c8c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<fight::BreakPointTrack>("timeBegin", &fight::BreakPointTrack::FUN_0023f0d0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamConditionGroup<fight::BreakPointTrack>("conditionGroup", &fight::BreakPointTrack::FUN_0023f0e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e5c88), params, 2);
    }
    DAT_004e5c8c++;
}
