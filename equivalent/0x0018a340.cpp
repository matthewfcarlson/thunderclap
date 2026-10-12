// STATUS: equivalent (tools/equiv.py level 3: 1986 inputs, branch coverage 50/50)
// FUN_0018a340 @ 0x0018a340
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class PropThrowTrack {
public:
    void FUN_0017f900();
    void FUN_0017f910();
    void FUN_0017f930();
    void FUN_0017f950();
    void FUN_0017f980();
    void FUN_0017f9b0();
    void FUN_0017f9d0();
    void FUN_0017f9f0();
    void FUN_0017fa10();
    void FUN_0017fa30();
    void FUN_0017fa60();
    void FUN_0017fa90();
    void FUN_0017fac0();
    void FUN_0017faf0();
    void FUN_0017fb10();
    void FUN_0017fb30();
    void FUN_0017fb60();
    void FUN_0017fb80();
    void FUN_0017fba0();
    void FUN_0017fbc0();
    void FUN_0017fbe0();
    void FUN_0017fbf0();
    void FUN_0017fc00();
    void FUN_0017fc20();
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
class __declspec(novtable) ParamBranchBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00235170(const char* name);
    ParamBranchBase(const char* name) { FUN_00235170(name); }
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
class ParamBranch : public ParamBranchBase {
public:
    ParamBranch(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
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
extern ParamRegistry DAT_004e1498;
extern int DAT_004e149c;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0018a340()
{
    if (DAT_004e149c == 0) {
        void* params[24];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>("timeBegin", &hulkfight::motion::PropThrowTrack::FUN_0017f900);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>("timeEnd", &hulkfight::motion::PropThrowTrack::FUN_0017f910);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamIntConstRange<hulkfight::motion::PropThrowTrack>("attachmentIndex", &hulkfight::motion::PropThrowTrack::FUN_0017f930);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamBool<hulkfight::motion::PropThrowTrack>("useCameraDirection", &hulkfight::motion::PropThrowTrack::FUN_0017f950);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamVector<hulkfight::motion::PropThrowTrack>("direction", &hulkfight::motion::PropThrowTrack::FUN_0017f980);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>("distanceMin", &hulkfight::motion::PropThrowTrack::FUN_0017f9b0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>("distanceMax", &hulkfight::motion::PropThrowTrack::FUN_0017f9d0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>("velocityMin", &hulkfight::motion::PropThrowTrack::FUN_0017f9f0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>("velocityMax", &hulkfight::motion::PropThrowTrack::FUN_0017fa10);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>("spinMin", &hulkfight::motion::PropThrowTrack::FUN_0017fa30);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>("spinMax", &hulkfight::motion::PropThrowTrack::FUN_0017fa60);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>("trackingMin", &hulkfight::motion::PropThrowTrack::FUN_0017fa90);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>("trackingMax", &hulkfight::motion::PropThrowTrack::FUN_0017fac0);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamIntConstRange<hulkfight::motion::PropThrowTrack>("bounceMin", &hulkfight::motion::PropThrowTrack::FUN_0017faf0);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamIntConstRange<hulkfight::motion::PropThrowTrack>("bounceMax", &hulkfight::motion::PropThrowTrack::FUN_0017fb10);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>("yFixupAngle", &hulkfight::motion::PropThrowTrack::FUN_0017fb30);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>("forceMin", &hulkfight::motion::PropThrowTrack::FUN_0017fb60);
        mem = FUN_0008d690(0x18);
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>("forceMax", &hulkfight::motion::PropThrowTrack::FUN_0017fb80);
        mem = FUN_0008d690(0x18);
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>("damageMin", &hulkfight::motion::PropThrowTrack::FUN_0017fba0);
        mem = FUN_0008d690(0x18);
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>("damageMax", &hulkfight::motion::PropThrowTrack::FUN_0017fbc0);
        mem = FUN_0008d690(0x18);
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamIntConstRange<hulkfight::motion::PropThrowTrack>("interruptPriority", &hulkfight::motion::PropThrowTrack::FUN_0017fbe0);
        mem = FUN_0008d690(0x18);
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamBranch<hulkfight::motion::PropThrowTrack>("hitBranch", &hulkfight::motion::PropThrowTrack::FUN_0017fbf0);
        mem = FUN_0008d690(0x18);
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamName<hulkfight::motion::PropThrowTrack>("hitEffect", &hulkfight::motion::PropThrowTrack::FUN_0017fc00);
        mem = FUN_0008d690(0x18);
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamBool<hulkfight::motion::PropThrowTrack>("clearCharge", &hulkfight::motion::PropThrowTrack::FUN_0017fc20);
        FUN_002347b0(&DAT_004e1498, params, 24);
    }
    DAT_004e149c++;
}
