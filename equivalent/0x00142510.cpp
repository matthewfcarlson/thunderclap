// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 36/36)
// FUN_00142510 @ 0x00142510
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class WallRunTrack {
public:
    void FUN_0013e830();
    void FUN_0013e840();
    void FUN_0013e860();
    void FUN_0013e880();
    void FUN_0013e8a0();
    void FUN_0013e8c0();
    void FUN_0013e8e0();
    void FUN_0013e900();
    void FUN_0013e920();
    void FUN_0013e940();
    void FUN_0013e970();
    void FUN_0013e990();
    void FUN_0013e9a0();
    void FUN_0013e9b0();
    void FUN_0013e9d0();
    void FUN_0013e9f0();
    void FUN_0013ea10();
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
}

struct ParamRegistry {
};
extern ParamRegistry DAT_004e0f48;
extern int DAT_004e0f4c;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00142510()
{
    if (DAT_004e0f4c == 0) {
        void* params[17];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>("timeBegin", &hulkfight::motion::WallRunTrack::FUN_0013e830);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>("timeEnd", &hulkfight::motion::WallRunTrack::FUN_0013e840);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>("velocityInit", &hulkfight::motion::WallRunTrack::FUN_0013e860);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>("velocityInitY", &hulkfight::motion::WallRunTrack::FUN_0013e880);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>("velocityMin", &hulkfight::motion::WallRunTrack::FUN_0013e8a0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>("velocityMax", &hulkfight::motion::WallRunTrack::FUN_0013e8c0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamBool<hulkfight::motion::WallRunTrack>("useCharge", &hulkfight::motion::WallRunTrack::FUN_0013e8e0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>("gravity", &hulkfight::motion::WallRunTrack::FUN_0013e900);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>("friction", &hulkfight::motion::WallRunTrack::FUN_0013e920);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>("turningRate", &hulkfight::motion::WallRunTrack::FUN_0013e940);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>("maxAngleChange", &hulkfight::motion::WallRunTrack::FUN_0013e970);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamName<hulkfight::motion::WallRunTrack>("animLeft", &hulkfight::motion::WallRunTrack::FUN_0013e990);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamName<hulkfight::motion::WallRunTrack>("animUp", &hulkfight::motion::WallRunTrack::FUN_0013e9a0);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamName<hulkfight::motion::WallRunTrack>("animRight", &hulkfight::motion::WallRunTrack::FUN_0013e9b0);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamIntConstRange<hulkfight::motion::WallRunTrack>("priority", &hulkfight::motion::WallRunTrack::FUN_0013e9d0);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>("blendInTime", &hulkfight::motion::WallRunTrack::FUN_0013e9f0);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallRunTrack>("blendOutTime", &hulkfight::motion::WallRunTrack::FUN_0013ea10);
        FUN_002347b0(&DAT_004e0f48, params, 17);
    }
    DAT_004e0f4c++;
}
