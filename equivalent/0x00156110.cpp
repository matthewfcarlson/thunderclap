// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 14/14)
// FUN_00156110 @ 0x00156110
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class HitOrientToPushbackTrack {
public:
    void FUN_0014cd20();
    void FUN_0014cd30();
    void FUN_0014cd50();
    void FUN_0014cd80();
    void FUN_0014cda0();
    void FUN_0014cdc0();
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
extern ParamRegistry DAT_004e1108;
extern int DAT_004e110c;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00156110()
{
    if (DAT_004e110c == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<HitOrientToPushbackTrack>("timeBegin", &HitOrientToPushbackTrack::FUN_0014cd20);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<HitOrientToPushbackTrack>("timeEnd", &HitOrientToPushbackTrack::FUN_0014cd30);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<HitOrientToPushbackTrack>("turningVelocity", &HitOrientToPushbackTrack::FUN_0014cd50);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamIntConstRange<HitOrientToPushbackTrack>("priority", &HitOrientToPushbackTrack::FUN_0014cd80);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<HitOrientToPushbackTrack>("blendInTime", &HitOrientToPushbackTrack::FUN_0014cda0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<HitOrientToPushbackTrack>("blendOutTime", &HitOrientToPushbackTrack::FUN_0014cdc0);
        FUN_002347b0(&DAT_004e1108, params, 6);
    }
    DAT_004e110c++;
}
