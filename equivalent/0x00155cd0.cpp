// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/18)
// FUN_00155cd0 @ 0x00155cd0
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class HitThrowTrack {
public:
    void FUN_0014c790();
    void FUN_0014c7a0();
    void FUN_0014c7c0();
    void FUN_0014c7e0();
    void FUN_0014c810();
    void FUN_0014c830();
    void FUN_0014c850();
    void FUN_0014c870();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
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
extern ParamRegistry DAT_004e10d8;
extern int DAT_004e10dc;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00155cd0()
{
    if (DAT_004e10dc == 0) {
        void* params[8];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<HitThrowTrack>("timeBegin", &HitThrowTrack::FUN_0014c790);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<HitThrowTrack>("timeEnd", &HitThrowTrack::FUN_0014c7a0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamBool<HitThrowTrack>("snapToPushback", &HitThrowTrack::FUN_0014c7c0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<HitThrowTrack>("orientation", &HitThrowTrack::FUN_0014c7e0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<HitThrowTrack>("gravity", &HitThrowTrack::FUN_0014c810);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamIntConstRange<HitThrowTrack>("priority", &HitThrowTrack::FUN_0014c830);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<HitThrowTrack>("blendInTime", &HitThrowTrack::FUN_0014c850);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<HitThrowTrack>("blendOutTime", &HitThrowTrack::FUN_0014c870);
        FUN_002347b0(&DAT_004e10d8, params, 8);
    }
    DAT_004e10dc++;
}
