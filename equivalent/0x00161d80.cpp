// STATUS: equivalent (tools/equiv.py level 3: 1541 inputs, branch coverage 50/50)
// FUN_00161d80 @ 0x00161d80
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class ClimbLocomotion4Track {
public:
    void FUN_0015a8c0();
    void FUN_0015a8d0();
    void FUN_0015a8f0();
    void FUN_0015a910();
    void FUN_0015a930();
    void FUN_0015a950();
    void FUN_0015a970();
    void FUN_0015a990();
    void FUN_0015a9b0();
    void FUN_0015a9d0();
    void FUN_0015a9e0();
    void FUN_0015a9f0();
    void FUN_0015aa00();
    void FUN_0015aa10();
    void FUN_0015aa20();
    void FUN_0015aa30();
    void FUN_0015aa40();
    void FUN_0015aa50();
    void FUN_0015aa60();
    void FUN_0015aa70();
    void FUN_0015aa80();
    void FUN_0015aaa0();
    void FUN_0015aac0();
    void FUN_0015aae0();
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
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
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
extern ParamRegistry DAT_004e1178;
extern int DAT_004e117c;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00161d80()
{
    if (DAT_004e117c == 0) {
        void* params[24];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>("timeBegin", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015a8c0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>("timeEnd", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015a8d0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>("acceleration", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015a8f0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>("velocityLowNorth", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015a910);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>("velocityLowStrafe", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015a930);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>("velocityLowSouth", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015a950);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>("velocityHighNorth", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015a970);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>("velocityHighStrafe", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015a990);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>("velocityHighSouth", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015a9b0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>("phase", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015a9d0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamName<hulkfight::motion::ClimbLocomotion4Track>("locomotion", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015a9e0);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamName<hulkfight::motion::ClimbLocomotion4Track>("animIdle", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015a9f0);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamName<hulkfight::motion::ClimbLocomotion4Track>("animLowNorth", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015aa00);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamName<hulkfight::motion::ClimbLocomotion4Track>("animLowEast", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015aa10);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamName<hulkfight::motion::ClimbLocomotion4Track>("animLowSouth", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015aa20);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamName<hulkfight::motion::ClimbLocomotion4Track>("animLowWest", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015aa30);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamName<hulkfight::motion::ClimbLocomotion4Track>("animHighNorth", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015aa40);
        mem = FUN_0008d690(0x18);
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamName<hulkfight::motion::ClimbLocomotion4Track>("animHighEast", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015aa50);
        mem = FUN_0008d690(0x18);
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamName<hulkfight::motion::ClimbLocomotion4Track>("animHighSouth", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015aa60);
        mem = FUN_0008d690(0x18);
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamName<hulkfight::motion::ClimbLocomotion4Track>("animHighWest", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015aa70);
        mem = FUN_0008d690(0x18);
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamName<hulkfight::motion::ClimbLocomotion4Track>("partition", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015aa80);
        mem = FUN_0008d690(0x18);
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamIntConstRange<hulkfight::motion::ClimbLocomotion4Track>("priority", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015aaa0);
        mem = FUN_0008d690(0x18);
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>("blendInTime", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015aac0);
        mem = FUN_0008d690(0x18);
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>("blendOutTime", &hulkfight::motion::ClimbLocomotion4Track::FUN_0015aae0);
        FUN_002347b0(&DAT_004e1178, params, 24);
    }
    DAT_004e117c++;
}
