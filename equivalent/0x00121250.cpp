// STATUS: equivalent (tools/equiv.py level 3: 100 inputs, branch coverage 26/26)
// FUN_00121250 @ 0x00121250
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class StrafeRunTrack {
public:
    void FUN_0011bbc0();
    void FUN_0011bbd0();
    void FUN_0011bbf0();
    void FUN_0011bc10();
    void FUN_0011bc40();
    void FUN_0011bc60();
    void FUN_0011bc80();
    void FUN_0011bca0();
    void FUN_0011bcc0();
    void FUN_0011bce0();
    void FUN_0011bd00();
    void FUN_0011bd20();
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
extern ParamRegistry DAT_004e0cc0;
extern int DAT_004e0cc4;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00121250()
{
    if (DAT_004e0cc4 == 0) {
        void* params[12];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<StrafeRunTrack>("timeBegin", &StrafeRunTrack::FUN_0011bbc0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<StrafeRunTrack>("timeEnd", &StrafeRunTrack::FUN_0011bbd0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<StrafeRunTrack>("distance", &StrafeRunTrack::FUN_0011bbf0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<StrafeRunTrack>("turnRate", &StrafeRunTrack::FUN_0011bc10);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<StrafeRunTrack>("heightMin", &StrafeRunTrack::FUN_0011bc40);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<StrafeRunTrack>("heightMax", &StrafeRunTrack::FUN_0011bc60);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<StrafeRunTrack>("groundHeightCutoff", &StrafeRunTrack::FUN_0011bc80);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<StrafeRunTrack>("cutoffExponent", &StrafeRunTrack::FUN_0011bca0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool<StrafeRunTrack>("useGroundHeightCutoff", &StrafeRunTrack::FUN_0011bcc0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBool<StrafeRunTrack>("useOffset", &StrafeRunTrack::FUN_0011bce0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<StrafeRunTrack>("offset", &StrafeRunTrack::FUN_0011bd00);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<StrafeRunTrack>("speed", &StrafeRunTrack::FUN_0011bd20);
        FUN_002347b0(&DAT_004e0cc0, params, 12);
    }
    DAT_004e0cc4++;
}
