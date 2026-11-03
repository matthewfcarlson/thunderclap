// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_00052f20 @ 0x00052f20
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CAxisDoubleTapCondition_52f20 {
public:
    void FUN_00047b00();
    void FUN_00047ba0();
    void FUN_00047bb0();
    void FUN_00047bd0();
    void FUN_00047be0();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
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
class ParamFloatConstRange_52f20 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_52f20(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList_52f20 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_52f20(const char* name, const char** n, int c, void (T::*s)())
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

extern "C" void FUN_00052f20()
{
    if (DAT_004dc434 == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690(0x20);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_52f20<CAxisDoubleTapCondition_52f20>("axis", ((const char**)&DAT_0049ee74), 2, &CAxisDoubleTapCondition_52f20::FUN_00047b00);
        mem = FUN_0008d690(0x20);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_52f20<CAxisDoubleTapCondition_52f20>("compareArc", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &CAxisDoubleTapCondition_52f20::FUN_00047ba0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_52f20<CAxisDoubleTapCondition_52f20>("arc", &CAxisDoubleTapCondition_52f20::FUN_00047bb0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_52f20<CAxisDoubleTapCondition_52f20>("timeMin", &CAxisDoubleTapCondition_52f20::FUN_00047bd0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_52f20<CAxisDoubleTapCondition_52f20>("timeMax", &CAxisDoubleTapCondition_52f20::FUN_00047be0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc430), params, 5);
    }
    DAT_004dc434++;
}
