// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 34/34)
// FUN_0017d210 @ 0x0017d210
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class MoveJointTrack {
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
extern ParamRegistry DAT_4e1328;
extern int DAT_4e132c;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0017d210()
{
    if (DAT_4e132c == 0) {
        void* params[16];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::MoveJointTrack>("timeBegin", &hulkfight::motion::MoveJointTrack::FUN_0016eeb0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::MoveJointTrack>("timeEnd", &hulkfight::motion::MoveJointTrack::FUN_0016eed0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamIntConstRange<hulkfight::motion::MoveJointTrack>("attachmentIndex", &hulkfight::motion::MoveJointTrack::FUN_0016eef0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamNameConstList<hulkfight::motion::MoveJointTrack>("moveJoint", &hulkfight::motion::MoveJointTrack::FUN_0016ef00);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamNameConstList<hulkfight::motion::MoveJointTrack>("startJoint", &hulkfight::motion::MoveJointTrack::FUN_0016ef10);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamVector<hulkfight::motion::MoveJointTrack>("offset", &hulkfight::motion::MoveJointTrack::FUN_0016ef40);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamVector<hulkfight::motion::MoveJointTrack>("direction", &hulkfight::motion::MoveJointTrack::FUN_0016ef80);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::MoveJointTrack>("distanceStart", &hulkfight::motion::MoveJointTrack::FUN_0016efb0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::MoveJointTrack>("distanceEnd", &hulkfight::motion::MoveJointTrack::FUN_0016efd0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::MoveJointTrack>("initVelocity", &hulkfight::motion::MoveJointTrack::FUN_0016eff0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::MoveJointTrack>("maxVelocity", &hulkfight::motion::MoveJointTrack::FUN_0016f010);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::MoveJointTrack>("acceleration", &hulkfight::motion::MoveJointTrack::FUN_0016f030);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamBool<hulkfight::motion::MoveJointTrack>("simulateMotion", &hulkfight::motion::MoveJointTrack::FUN_0016f050);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamIntConstRange<hulkfight::motion::MoveJointTrack>("priority", &hulkfight::motion::MoveJointTrack::FUN_0016f060);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::MoveJointTrack>("blendInTime", &hulkfight::motion::MoveJointTrack::FUN_0016f070);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::MoveJointTrack>("blendOutTime", &hulkfight::motion::MoveJointTrack::FUN_0016f080);
        FUN_002347b0(&DAT_4e1328, params, 16);
    }
    DAT_4e132c++;
}
