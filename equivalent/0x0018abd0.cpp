// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 42/42)
// FUN_0018abd0 @ 0x0018abd0
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class BallAndChainShootTrack {
public:
    void FUN_0017fe90();
    void FUN_0017fea0();
    void FUN_0017fec0();
    void FUN_0017fef0();
    void FUN_0017ff30();
    void FUN_0017ff70();
    void FUN_0017ffa0();
    void FUN_0017ffc0();
    void FUN_0017ffe0();
    void FUN_00180000();
    void FUN_00180020();
    void FUN_00180050();
    void FUN_00180080();
    void FUN_001800b0();
    void FUN_001800c0();
    void FUN_001800f0();
    void FUN_00180110();
    void FUN_00180150();
    void FUN_00180190();
    void FUN_001801b0();
};
}
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
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
};
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234ba0(const char* name);
    ParamNameConstListBase(const char* name) { FUN_00234ba0(name); }
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
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamVector : public ParamVectorBase {
public:
    ParamVector(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};



void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0018abd0()
{
    if (DAT_004e14b4 == 0) {
        void* params[20];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>("timeBegin", &hulkfight::motion::BallAndChainShootTrack::FUN_0017fe90);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>("timeEnd", &hulkfight::motion::BallAndChainShootTrack::FUN_0017fea0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamIntConstRange<hulkfight::motion::BallAndChainShootTrack>("attachmentIndex", &hulkfight::motion::BallAndChainShootTrack::FUN_0017fec0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector<hulkfight::motion::BallAndChainShootTrack>("initPosition", &hulkfight::motion::BallAndChainShootTrack::FUN_0017fef0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamVector<hulkfight::motion::BallAndChainShootTrack>("direction", &hulkfight::motion::BallAndChainShootTrack::FUN_0017ff30);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamVector<hulkfight::motion::BallAndChainShootTrack>("propAxis", &hulkfight::motion::BallAndChainShootTrack::FUN_0017ff70);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>("distanceMin", &hulkfight::motion::BallAndChainShootTrack::FUN_0017ffa0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>("distanceMax", &hulkfight::motion::BallAndChainShootTrack::FUN_0017ffc0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>("velocityMin", &hulkfight::motion::BallAndChainShootTrack::FUN_0017ffe0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>("velocityMax", &hulkfight::motion::BallAndChainShootTrack::FUN_00180000);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>("trackingMin", &hulkfight::motion::BallAndChainShootTrack::FUN_00180020);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>("trackingMax", &hulkfight::motion::BallAndChainShootTrack::FUN_00180050);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>("yFixupAngle", &hulkfight::motion::BallAndChainShootTrack::FUN_00180080);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>("targetYOffset", &hulkfight::motion::BallAndChainShootTrack::FUN_001800b0);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamName<hulkfight::motion::BallAndChainShootTrack>("beamEffect", &hulkfight::motion::BallAndChainShootTrack::FUN_001800c0);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamVector<hulkfight::motion::BallAndChainShootTrack>("beamOffset", &hulkfight::motion::BallAndChainShootTrack::FUN_001800f0);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamNameConstList<hulkfight::motion::BallAndChainShootTrack>("beamAttachJoint", &hulkfight::motion::BallAndChainShootTrack::FUN_00180110);
        mem = FUN_0008d690(0x18);
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamVector<hulkfight::motion::BallAndChainShootTrack>("beamAttachJointOffset", &hulkfight::motion::BallAndChainShootTrack::FUN_00180150);
        mem = FUN_0008d690(0x20);
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamEnumConstList<hulkfight::motion::BallAndChainShootTrack>("damageType", ((const char**)&DAT_004ad788), (*(int*)&DAT_00412ed4), &hulkfight::motion::BallAndChainShootTrack::FUN_00180190);
        mem = FUN_0008d690(0x18);
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>("damageScale", &hulkfight::motion::BallAndChainShootTrack::FUN_001801b0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e14b0), params, 20);
    }
    DAT_004e14b4++;
}
