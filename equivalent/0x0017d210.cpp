// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 34/34)
// FUN_0017d210 @ 0x0017d210
#include "gen/fight.h"
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class MoveJointTrack_17d210 {
public:
    void FUN_0016eeb0();
    void FUN_0016eed0();
    void FUN_0016eef0();
    void FUN_0016ef00();
    void FUN_0016ef10();
    void FUN_0016ef40();
    void FUN_0016ef80();
    void FUN_0016efb0();
    void FUN_0016efd0();
    void FUN_0016eff0();
    void FUN_0016f010();
    void FUN_0016f030();
    void FUN_0016f050();
    void FUN_0016f060();
    void FUN_0016f070();
    void FUN_0016f080();
};
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
namespace fight {
template <class T>
class ParamBool_17d210 : public ParamBoolBase {
public:
    ParamBool_17d210(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamFloatConstRange_17d210 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17d210(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_17d210 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_17d210(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamNameConstList_17d210 : public ParamNameConstListBase {
public:
    ParamNameConstList_17d210(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamVector_17d210 : public ParamVectorBase {
public:
    ParamVector_17d210(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern ParamRegistry DAT_4e1328;
extern int DAT_4e132c;

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0017d210()
{
    if (DAT_4e132c == 0) {
        void* params[16];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("timeBegin", &hulkfight::motion::MoveJointTrack_17d210::FUN_0016eeb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("timeEnd", &hulkfight::motion::MoveJointTrack_17d210::FUN_0016eed0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamIntConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("attachmentIndex", &hulkfight::motion::MoveJointTrack_17d210::FUN_0016eef0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamNameConstList_17d210<hulkfight::motion::MoveJointTrack_17d210>("moveJoint", &hulkfight::motion::MoveJointTrack_17d210::FUN_0016ef00);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamNameConstList_17d210<hulkfight::motion::MoveJointTrack_17d210>("startJoint", &hulkfight::motion::MoveJointTrack_17d210::FUN_0016ef10);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamVector_17d210<hulkfight::motion::MoveJointTrack_17d210>("offset", &hulkfight::motion::MoveJointTrack_17d210::FUN_0016ef40);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamVector_17d210<hulkfight::motion::MoveJointTrack_17d210>("direction", &hulkfight::motion::MoveJointTrack_17d210::FUN_0016ef80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("distanceStart", &hulkfight::motion::MoveJointTrack_17d210::FUN_0016efb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("distanceEnd", &hulkfight::motion::MoveJointTrack_17d210::FUN_0016efd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("initVelocity", &hulkfight::motion::MoveJointTrack_17d210::FUN_0016eff0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("maxVelocity", &hulkfight::motion::MoveJointTrack_17d210::FUN_0016f010);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("acceleration", &hulkfight::motion::MoveJointTrack_17d210::FUN_0016f030);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamBool_17d210<hulkfight::motion::MoveJointTrack_17d210>("simulateMotion", &hulkfight::motion::MoveJointTrack_17d210::FUN_0016f050);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamIntConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("priority", &hulkfight::motion::MoveJointTrack_17d210::FUN_0016f060);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("blendInTime", &hulkfight::motion::MoveJointTrack_17d210::FUN_0016f070);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_17d210<hulkfight::motion::MoveJointTrack_17d210>("blendOutTime", &hulkfight::motion::MoveJointTrack_17d210::FUN_0016f080);
        FUN_002347b0(&DAT_4e1328, params, 16);
    }
    DAT_4e132c++;
}
