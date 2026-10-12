// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 20/20)
// FUN_00137c40 @ 0x00137c40
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class FlyingBrakeTrack {
public:
    void FUN_001330f0();
    void FUN_00133100();
    void FUN_00133120();
    void FUN_00133140();
    void FUN_00133160();
    void FUN_00133180();
    void FUN_001331a0();
    void FUN_001331c0();
    void FUN_001331e0();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

struct ParamRegistry {
};
extern ParamRegistry DAT_004e0ed0;
extern int DAT_004e0ed4;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00137c40()
{
    if (DAT_004e0ed4 == 0) {
        void* params[9];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<FlyingBrakeTrack>("timeBegin", &FlyingBrakeTrack::FUN_001330f0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<FlyingBrakeTrack>("timeEnd", &FlyingBrakeTrack::FUN_00133100);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<FlyingBrakeTrack>("velocityXZ", &FlyingBrakeTrack::FUN_00133120);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<FlyingBrakeTrack>("gravity", &FlyingBrakeTrack::FUN_00133140);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<FlyingBrakeTrack>("gravityUp", &FlyingBrakeTrack::FUN_00133160);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<FlyingBrakeTrack>("terminalVelocity", &FlyingBrakeTrack::FUN_00133180);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamIntConstRange<FlyingBrakeTrack>("priority", &FlyingBrakeTrack::FUN_001331a0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<FlyingBrakeTrack>("blendInTime", &FlyingBrakeTrack::FUN_001331c0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) ParamFloatConstRange<FlyingBrakeTrack>("blendOutTime", &FlyingBrakeTrack::FUN_001331e0);
        FUN_002347b0(&DAT_004e0ed0, params, 9);
    }
    DAT_004e0ed4++;
}
