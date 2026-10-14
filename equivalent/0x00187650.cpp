// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_00187650 @ 0x00187650
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class PropMissionCriticalCondition {
public:
    void FUN_0017f2b0();
    void FUN_0017f2d0();
};
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
};
class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
namespace fight {
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern ParamRegistry DAT_004e1400;
extern int DAT_004e1404;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00187650()
{
    if (DAT_004e1404 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamIntConstRange<hulkfight::motion::PropMissionCriticalCondition>("attachmentIndex", &hulkfight::motion::PropMissionCriticalCondition::FUN_0017f2b0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBool<hulkfight::motion::PropMissionCriticalCondition>("missionCritical", &hulkfight::motion::PropMissionCriticalCondition::FUN_0017f2d0);
        FUN_002347b0(&DAT_004e1400, params, 2);
    }
    DAT_004e1404++;
}
