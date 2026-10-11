// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 12/12)
// FUN_00179c10 @ 0x00179c10
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class ChargeTrack {
public:
    void FUN_0016e9b0();
    void FUN_0016e9c0();
    void FUN_0016e9e0();
    void FUN_0016ea00();
    void FUN_0016ea20();
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

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
extern const char* DAT_004b4d7c[3];
extern int DAT_00416640;
template <class T>
class ParamEnumConstList : public ParamEnumConstListBase {
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};

struct ParamRegistry {
};
extern ParamRegistry DAT_004e12f0;
extern int DAT_004e12f4;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00179c10()
{
    if (DAT_004e12f4 == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<ChargeTrack>("timeBegin", &ChargeTrack::FUN_0016e9b0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<ChargeTrack>("timeEnd", &ChargeTrack::FUN_0016e9c0);
        mem = FUN_0008d690(0x20);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamEnumConstList<ChargeTrack>("type", DAT_004b4d7c, DAT_00416640, &ChargeTrack::FUN_0016e9e0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamBool<ChargeTrack>("clearOnBegin", &ChargeTrack::FUN_0016ea00);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<ChargeTrack>("finalCharge", &ChargeTrack::FUN_0016ea20);
        FUN_002347b0(&DAT_004e12f0, params, 5);
    }
    DAT_004e12f4++;
}
