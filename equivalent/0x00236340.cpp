// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 6/6)
// FUN_00236340 @ 0x00236340
#include "decls/data/engine/fight.h"
#include "decls/data/engine/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace fight {
class FightNodeTimeCondition {
public:
    void FUN_002359a0();
    void FUN_002359b0();
};
}

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
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
class ParamEnumConstList : public ParamEnumConstListBase {
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
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

void FUN_00236340()
{
    if (DAT_004e5bf0 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x20);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<fight::FightNodeTimeCondition>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &fight::FightNodeTimeCondition::FUN_002359a0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<fight::FightNodeTimeCondition>("time", &fight::FightNodeTimeCondition::FUN_002359b0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e5bec), params, 2);
    }
    DAT_004e5bf0++;
}
