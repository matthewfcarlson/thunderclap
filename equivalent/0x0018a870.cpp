// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 30/30)
// FUN_0018a870 @ 0x0018a870
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class BallAndChainReturnTrack_18a870 {
public:
    void FUN_0017fc30();
    void FUN_0017fc40();
    void FUN_0017fc60();
    void FUN_0017fc80();
    void FUN_0017fca0();
    void FUN_0017fcc0();
    void FUN_0017fcf0();
    void FUN_0017fd10();
    void FUN_0017fd40();
    void FUN_0017fd80();
    void FUN_0017fda0();
    void FUN_0017fdd0();
    void FUN_0017fdf0();
    void FUN_0017fe20();
};
}}

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_18a870 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_18a870(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
namespace fight {
template <class T>
class ParamIntConstRange_18a870 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_18a870(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
namespace fight {
template <class T>
class ParamName_18a870 : public ParamNameBase {
public:
    ParamName_18a870(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
namespace fight {
template <class T>
class ParamNameConstList_18a870 : public ParamNameConstListBase {
public:
    ParamNameConstList_18a870(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
namespace fight {
template <class T>
class ParamVector_18a870 : public ParamVectorBase {
public:
    ParamVector_18a870(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0018a870()
{
    if (DAT_004e14a4 == 0) {
        void* params[14];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("timeBegin", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fc30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("timeEnd", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fc40);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamIntConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("attachmentIndex", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fc60);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("initVelocity", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fc80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("acceleration", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fca0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("tracking", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fcc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("targetYOffset", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fcf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("minDistance", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fd10);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamVector_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("offset", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fd40);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamVector_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("propAxis", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fd80);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamName_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("beamEffect", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fda0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamVector_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("beamOffset", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fdd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamNameConstList_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("beamAttachJoint", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fdf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamVector_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("beamAttachJointOffset", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fe20);
        FUN_002347b0(((ParamRegistry*)&DAT_004e14a0), params, 14);
    }
    DAT_004e14a4++;
}
