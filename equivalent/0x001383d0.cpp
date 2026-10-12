// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 30/30)
// FUN_001383d0 @ 0x001383d0
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class FallTrack {
public:
    void FUN_001334b0();
    void FUN_001334c0();
    void FUN_001334e0();
    void FUN_00133510();
    void FUN_00133530();
    void FUN_00133560();
    void FUN_00133580();
    void FUN_001335b0();
    void FUN_001335e0();
    void FUN_00133600();
    void FUN_00133620();
    void FUN_00133640();
    void FUN_00133660();
    void FUN_00133680();
};
}}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
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
}

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
extern ParamRegistry DAT_004e0ef0;
extern int DAT_004e0ef4;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001383d0()
{
    if (DAT_004e0ef4 == 0) {
        void* params[14];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FallTrack>("timeBegin", &hulkfight::motion::FallTrack::FUN_001334b0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FallTrack>("timeEnd", &hulkfight::motion::FallTrack::FUN_001334c0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FallTrack>("turningVelocityMin", &hulkfight::motion::FallTrack::FUN_001334e0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FallTrack>("turningVelocityMinForwardSpeedCap", &hulkfight::motion::FallTrack::FUN_00133510);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FallTrack>("turningVelocityMax", &hulkfight::motion::FallTrack::FUN_00133530);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FallTrack>("turningVelocityMaxForwardSpeedCap", &hulkfight::motion::FallTrack::FUN_00133560);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamBool<hulkfight::motion::FallTrack>("useInitialVelocity", &hulkfight::motion::FallTrack::FUN_00133580);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamVector<hulkfight::motion::FallTrack>("initialVelocity", &hulkfight::motion::FallTrack::FUN_001335b0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FallTrack>("gravity", &hulkfight::motion::FallTrack::FUN_001335e0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FallTrack>("maxVelocity", &hulkfight::motion::FallTrack::FUN_00133600);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamBool<hulkfight::motion::FallTrack>("limitTurning", &hulkfight::motion::FallTrack::FUN_00133620);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamIntConstRange<hulkfight::motion::FallTrack>("priority", &hulkfight::motion::FallTrack::FUN_00133640);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FallTrack>("blendInTime", &hulkfight::motion::FallTrack::FUN_00133660);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FallTrack>("blendOutTime", &hulkfight::motion::FallTrack::FUN_00133680);
        FUN_002347b0(&DAT_004e0ef0, params, 14);
    }
    DAT_004e0ef4++;
}
