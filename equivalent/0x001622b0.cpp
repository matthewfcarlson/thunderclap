// STATUS: equivalent (tools/equiv.py level 3: 1835 inputs, branch coverage 54/54)
// FUN_001622b0 @ 0x001622b0
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class LocomotionStrafe4Track_1622b0 {
public:
    void FUN_0015aaf0();
    void FUN_0015ab00();
    void FUN_0015ab20();
    void FUN_0015ab40();
    void FUN_0015ab70();
    void FUN_0015ab90();
    void FUN_0015abb0();
    void FUN_0015abd0();
    void FUN_0015abf0();
    void FUN_0015ac10();
    void FUN_0015ac30();
    void FUN_0015ac50();
    void FUN_0015ac60();
    void FUN_0015ac70();
    void FUN_0015ac80();
    void FUN_0015ac90();
    void FUN_0015aca0();
    void FUN_0015acb0();
    void FUN_0015acc0();
    void FUN_0015acd0();
    void FUN_0015ace0();
    void FUN_0015acf0();
    void FUN_0015ad00();
    void FUN_0015ad20();
    void FUN_0015ad40();
    void FUN_0015ad60();
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
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
namespace fight {
template <class T>
class ParamBool_1622b0 : public ParamBoolBase {
public:
    ParamBool_1622b0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamFloatConstRange_1622b0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1622b0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_1622b0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_1622b0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName_1622b0 : public ParamNameBase {
public:
    ParamName_1622b0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_001622b0()
{
    if (DAT_004e1184 == 0) {
        void* params[26];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("timeBegin", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015aaf0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("timeEnd", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ab00);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("acceleration", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ab20);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("turningVelocity", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ab40);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamBool_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("steering", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ab70);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("velocityWalkNorth", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ab90);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("velocityWalkStrafe", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015abb0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("velocityWalkSouth", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015abd0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("velocityRunNorth", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015abf0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("velocityRunStrafe", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ac10);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("velocityRunSouth", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ac30);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("phase", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ac50);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("locomotion", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ac60);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("animIdle", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ac70);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("animWalkNorth", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ac80);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("animWalkEast", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ac90);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("animWalkSouth", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015aca0);
        mem = FUN_0008d690(0x18);
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("animWalkWest", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015acb0);
        mem = FUN_0008d690(0x18);
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("animRunNorth", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015acc0);
        mem = FUN_0008d690(0x18);
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("animRunEast", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015acd0);
        mem = FUN_0008d690(0x18);
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("animRunSouth", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ace0);
        mem = FUN_0008d690(0x18);
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("animRunWest", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015acf0);
        mem = FUN_0008d690(0x18);
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("partition", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ad00);
        mem = FUN_0008d690(0x18);
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamIntConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("priority", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ad20);
        mem = FUN_0008d690(0x18);
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("blendInTime", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ad40);
        mem = FUN_0008d690(0x18);
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("blendOutTime", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ad60);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1180), params, 26);
    }
    DAT_004e1184++;
}
