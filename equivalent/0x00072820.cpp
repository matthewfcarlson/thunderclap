// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 20/20)
// FUN_00072820 @ 0x00072820
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CWallSlideTrack {
public:
    void FUN_00068bc0();
    void FUN_00068bd0();
    void FUN_00068be0();
    void FUN_00068bf0();
    void FUN_00068c00();
    void FUN_00068c10();
    void FUN_00068c20();
    void FUN_00068c30();
    void FUN_00068c40();
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
extern ParamRegistry DAT_004dd020;
extern int DAT_004dd024;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00072820()
{
    if (DAT_004dd024 == 0) {
        void* params[9];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<CWallSlideTrack>("timeBegin", &CWallSlideTrack::FUN_00068bc0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<CWallSlideTrack>("maxTimeEnd", &CWallSlideTrack::FUN_00068bd0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<CWallSlideTrack>("friction", &CWallSlideTrack::FUN_00068be0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<CWallSlideTrack>("gravity", &CWallSlideTrack::FUN_00068bf0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<CWallSlideTrack>("deceleration", &CWallSlideTrack::FUN_00068c00);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<CWallSlideTrack>("minVelocity", &CWallSlideTrack::FUN_00068c10);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamIntConstRange<CWallSlideTrack>("priority", &CWallSlideTrack::FUN_00068c20);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<CWallSlideTrack>("blendInTime", &CWallSlideTrack::FUN_00068c30);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) ParamFloatConstRange<CWallSlideTrack>("blendOutTime", &CWallSlideTrack::FUN_00068c40);
        FUN_002347b0(&DAT_004dd020, params, 9);
    }
    DAT_004dd024++;
}
