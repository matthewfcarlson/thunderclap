// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_0018df00 @ 0x0018df00
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
namespace motion {
class TimerCondition {
public:
    void FUN_0018cab0();
    void FUN_0018cac0();
    void FUN_0018cad0();
    void FUN_0018caf0();
    void FUN_0018cb10();
};
}
}

class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
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
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
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
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
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

void FUN_0018df00()
{
    if (DAT_004e150c == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamIntConstRange<hulkfight::motion::TimerCondition>("timer", &hulkfight::motion::TimerCondition::FUN_0018cab0);
        mem = FUN_0008d690(0x20);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList<hulkfight::motion::TimerCondition>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::motion::TimerCondition::FUN_0018cac0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TimerCondition>("value", &hulkfight::motion::TimerCondition::FUN_0018cad0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamBool<hulkfight::motion::TimerCondition>("useKeyWordWait", &hulkfight::motion::TimerCondition::FUN_0018caf0);
        mem = FUN_0008d690(0x20);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamEnumConstList<hulkfight::motion::TimerCondition>("keyWord", ((const char**)&DAT_004bebb4), 15, &hulkfight::motion::TimerCondition::FUN_0018cb10);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1508), params, 5);
    }
    DAT_004e150c++;
}
