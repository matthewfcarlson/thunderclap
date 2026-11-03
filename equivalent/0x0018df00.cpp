// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_0018df00 @ 0x0018df00
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class TimerCondition_18df00 {
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
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
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
class ParamIntConstRange_18df00 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_18df00(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamFloatConstRange_18df00 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_18df00(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamBool_18df00 : public ParamBoolBase {
public:
    ParamBool_18df00(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList_18df00 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_18df00(const char* name, const char** n, int c, void (T::*s)())
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
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0018df00()
{
    if (DAT_004e150c == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamIntConstRange_18df00<hulkfight::motion::TimerCondition_18df00>("timer", &hulkfight::motion::TimerCondition_18df00::FUN_0018cab0);
        mem = FUN_0008d690(0x20);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_18df00<hulkfight::motion::TimerCondition_18df00>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::motion::TimerCondition_18df00::FUN_0018cac0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_18df00<hulkfight::motion::TimerCondition_18df00>("value", &hulkfight::motion::TimerCondition_18df00::FUN_0018cad0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamBool_18df00<hulkfight::motion::TimerCondition_18df00>("useKeyWordWait", &hulkfight::motion::TimerCondition_18df00::FUN_0018caf0);
        mem = FUN_0008d690(0x20);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamEnumConstList_18df00<hulkfight::motion::TimerCondition_18df00>("keyWord", ((const char**)&DAT_004bebb4), 15, &hulkfight::motion::TimerCondition_18df00::FUN_0018cb10);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1508), params, 5);
    }
    DAT_004e150c++;
}
