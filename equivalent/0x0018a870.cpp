// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 30/30)
// FUN_0018a870 @ 0x0018a870
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class BallAndChainReturnTrack {
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
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
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
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
};
namespace fight {
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234ba0(const char* name);
    ParamNameConstListBase(const char* name) { FUN_00234ba0(name); }
};
namespace fight {
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
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
extern ParamRegistry DAT_004e14a0;
extern int DAT_004e14a4;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0018a870()
{
    if (DAT_004e14a4 == 0) {
        void* params[14];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::BallAndChainReturnTrack>("timeBegin", &hulkfight::motion::BallAndChainReturnTrack::FUN_0017fc30);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::BallAndChainReturnTrack>("timeEnd", &hulkfight::motion::BallAndChainReturnTrack::FUN_0017fc40);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamIntConstRange<hulkfight::motion::BallAndChainReturnTrack>("attachmentIndex", &hulkfight::motion::BallAndChainReturnTrack::FUN_0017fc60);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::BallAndChainReturnTrack>("initVelocity", &hulkfight::motion::BallAndChainReturnTrack::FUN_0017fc80);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::BallAndChainReturnTrack>("acceleration", &hulkfight::motion::BallAndChainReturnTrack::FUN_0017fca0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::BallAndChainReturnTrack>("tracking", &hulkfight::motion::BallAndChainReturnTrack::FUN_0017fcc0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::BallAndChainReturnTrack>("targetYOffset", &hulkfight::motion::BallAndChainReturnTrack::FUN_0017fcf0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::BallAndChainReturnTrack>("minDistance", &hulkfight::motion::BallAndChainReturnTrack::FUN_0017fd10);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamVector<hulkfight::motion::BallAndChainReturnTrack>("offset", &hulkfight::motion::BallAndChainReturnTrack::FUN_0017fd40);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamVector<hulkfight::motion::BallAndChainReturnTrack>("propAxis", &hulkfight::motion::BallAndChainReturnTrack::FUN_0017fd80);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamName<hulkfight::motion::BallAndChainReturnTrack>("beamEffect", &hulkfight::motion::BallAndChainReturnTrack::FUN_0017fda0);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamVector<hulkfight::motion::BallAndChainReturnTrack>("beamOffset", &hulkfight::motion::BallAndChainReturnTrack::FUN_0017fdd0);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamNameConstList<hulkfight::motion::BallAndChainReturnTrack>("beamAttachJoint", &hulkfight::motion::BallAndChainReturnTrack::FUN_0017fdf0);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamVector<hulkfight::motion::BallAndChainReturnTrack>("beamAttachJointOffset", &hulkfight::motion::BallAndChainReturnTrack::FUN_0017fe20);
        FUN_002347b0(&DAT_004e14a0, params, 14);
    }
    DAT_004e14a4++;
}
