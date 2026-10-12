// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 24/24)
// FUN_00121830 @ 0x00121830
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class StrafeCircleTrack {
public:
    void FUN_0011bea0();
    void FUN_0011beb0();
    void FUN_0011bed0();
    void FUN_0011bef0();
    void FUN_0011bf10();
    void FUN_0011bf30();
    void FUN_0011bf50();
    void FUN_0011bf70();
    void FUN_0011bf90();
    void FUN_0011bfb0();
    void FUN_0011bfc0();
};

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

struct ParamRegistry {
};
extern ParamRegistry DAT_004e0cd8;
extern int DAT_004e0cdc;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00121830()
{
    if (DAT_004e0cdc == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<StrafeCircleTrack>("timeBegin", &StrafeCircleTrack::FUN_0011bea0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<StrafeCircleTrack>("timeEnd", &StrafeCircleTrack::FUN_0011beb0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<StrafeCircleTrack>("distanceMin", &StrafeCircleTrack::FUN_0011bed0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<StrafeCircleTrack>("distanceMax", &StrafeCircleTrack::FUN_0011bef0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<StrafeCircleTrack>("heightMin", &StrafeCircleTrack::FUN_0011bf10);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<StrafeCircleTrack>("heightMax", &StrafeCircleTrack::FUN_0011bf30);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<StrafeCircleTrack>("groundHeightCutoff", &StrafeCircleTrack::FUN_0011bf50);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<StrafeCircleTrack>("cutoffExponent", &StrafeCircleTrack::FUN_0011bf70);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool<StrafeCircleTrack>("useGroundHeightCutoff", &StrafeCircleTrack::FUN_0011bf90);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<StrafeCircleTrack>("speed", &StrafeCircleTrack::FUN_0011bfb0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamBool<StrafeCircleTrack>("useDefendLocation", &StrafeCircleTrack::FUN_0011bfc0);
        FUN_002347b0(&DAT_004e0cd8, params, 11);
    }
    DAT_004e0cdc++;
}
