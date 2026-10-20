// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 12/12)
// FUN_000528d0 @ 0x000528d0
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/ai.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CButtonValueCondition {
public:
    void FUN_00047ab0();
    void FUN_00047ac0();
    void FUN_00047ad0();
    void FUN_00047ae0();
    void FUN_00047af0();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
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
}

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_000528d0()
{
    if (DAT_004dc40c == 0) {
        void* params[5];
        void* mem;
        mem = FUN_0008d690(0x20);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<CButtonValueCondition>("button", ((const char**)&DAT_0049ee30), 13, &CButtonValueCondition::FUN_00047ab0);
        mem = FUN_0008d690(0x20);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList<CButtonValueCondition>("compareTime", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &CButtonValueCondition::FUN_00047ac0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<CButtonValueCondition>("time", &CButtonValueCondition::FUN_00047ad0);
        mem = FUN_0008d690(0x20);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamEnumConstList<CButtonValueCondition>("compareValue", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &CButtonValueCondition::FUN_00047ae0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<CButtonValueCondition>("value", &CButtonValueCondition::FUN_00047af0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc408), params, 5);
    }
    DAT_004dc40c++;
}
