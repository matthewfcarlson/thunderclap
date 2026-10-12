// STATUS: equivalent (tools/equiv.py level 3: 2339 inputs, branch coverage 50/50)
// FUN_00191170 @ 0x00191170
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class TankLocomotionTrack {
public:
    void FUN_0018edf0();
    void FUN_0018ee00();
    void FUN_0018ee20();
    void FUN_0018ee40();
    void FUN_0018ee60();
    void FUN_0018ee80();
    void FUN_0018eea0();
    void FUN_0018eed0();
    void FUN_0018ef00();
    void FUN_0018ef20();
    void FUN_0018ef50();
    void FUN_0018ef80();
    void FUN_0018efa0();
    void FUN_0018efc0();
    void FUN_0018efe0();
    void FUN_0018f000();
    void FUN_0018f030();
    void FUN_0018f060();
    void FUN_0018f080();
    void FUN_0018f0a0();
    void FUN_0018f0c0();
    void FUN_0018f0e0();
    void FUN_0018f100();
    void FUN_0018f120();
};
}
}

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
class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
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
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
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
extern ParamRegistry DAT_004e1540;
extern int DAT_004e1544;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00191170()
{
    if (DAT_004e1544 == 0) {
        void* params[24];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("timeBegin", &hulkfight::motion::TankLocomotionTrack::FUN_0018edf0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("timeEnd", &hulkfight::motion::TankLocomotionTrack::FUN_0018ee00);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("velocityForward", &hulkfight::motion::TankLocomotionTrack::FUN_0018ee20);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("velocityReverse", &hulkfight::motion::TankLocomotionTrack::FUN_0018ee40);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("acceleration", &hulkfight::motion::TankLocomotionTrack::FUN_0018ee60);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("deceleration", &hulkfight::motion::TankLocomotionTrack::FUN_0018ee80);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("turnVelocity", &hulkfight::motion::TankLocomotionTrack::FUN_0018eea0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("turnAcceleration", &hulkfight::motion::TankLocomotionTrack::FUN_0018eed0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("treadLength", &hulkfight::motion::TankLocomotionTrack::FUN_0018ef00);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("treadWidth", &hulkfight::motion::TankLocomotionTrack::FUN_0018ef20);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamVector<hulkfight::motion::TankLocomotionTrack>("treadOffset", &hulkfight::motion::TankLocomotionTrack::FUN_0018ef50);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("springDistance", &hulkfight::motion::TankLocomotionTrack::FUN_0018ef80);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("springForce", &hulkfight::motion::TankLocomotionTrack::FUN_0018efa0);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("damperForce", &hulkfight::motion::TankLocomotionTrack::FUN_0018efc0);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("tiltForce", &hulkfight::motion::TankLocomotionTrack::FUN_0018efe0);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("frictionSlope", &hulkfight::motion::TankLocomotionTrack::FUN_0018f000);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("maxSlope", &hulkfight::motion::TankLocomotionTrack::FUN_0018f030);
        mem = FUN_0008d690(0x18);
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("gravity", &hulkfight::motion::TankLocomotionTrack::FUN_0018f060);
        mem = FUN_0008d690(0x18);
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("inAirGravity", &hulkfight::motion::TankLocomotionTrack::FUN_0018f080);
        mem = FUN_0008d690(0x18);
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("inAirMaxSpringVelocity", &hulkfight::motion::TankLocomotionTrack::FUN_0018f0a0);
        mem = FUN_0008d690(0x18);
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("maxSpringVelocity", &hulkfight::motion::TankLocomotionTrack::FUN_0018f0c0);
        mem = FUN_0008d690(0x18);
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamIntConstRange<hulkfight::motion::TankLocomotionTrack>("priority", &hulkfight::motion::TankLocomotionTrack::FUN_0018f0e0);
        mem = FUN_0008d690(0x18);
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("blendInTime", &hulkfight::motion::TankLocomotionTrack::FUN_0018f100);
        mem = FUN_0008d690(0x18);
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::TankLocomotionTrack>("blendOutTime", &hulkfight::motion::TankLocomotionTrack::FUN_0018f120);
        FUN_002347b0(&DAT_004e1540, params, 24);
    }
    DAT_004e1544++;
}
