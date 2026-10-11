// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 14/14)
// FUN_00112ba0 @ 0x00112ba0
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class ButtonTrack {
public:
    void FUN_0010c560();
    void FUN_0010c570();
    void FUN_0010c590();
    void FUN_0010c5b0();
    void FUN_0010c5d0();
    void FUN_0010c5f0();
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

class __declspec(novtable) ParamEnumBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumBase(const char* name) { FUN_00234cc0(name); }
};
extern char* DAT_0049ee30[];
extern char* DAT_0049ee64[];
template <class T>
class ParamEnumConstList : public ParamEnumBase {
public:
    ParamEnumConstList(const char* name, char** t, int n, void (T::*s)()) : ParamEnumBase(name) { table = t; count = n; setter = s; }
    virtual void v0();
    char** table;
    int count;
    void (T::*setter)();
    int unused1c;
};

struct ParamRegistry {
};
extern ParamRegistry DAT_004e0b88;
extern int DAT_004e0b8c;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00112ba0()
{
    if (DAT_004e0b8c == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<ButtonTrack>("timeBegin", &ButtonTrack::FUN_0010c560);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<ButtonTrack>("timeEnd", &ButtonTrack::FUN_0010c570);
        mem = FUN_0008d690(0x20);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamEnumConstList<ButtonTrack>("button", DAT_0049ee30, 13, &ButtonTrack::FUN_0010c590);
        mem = FUN_0008d690(0x20);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamEnumConstList<ButtonTrack>("state", DAT_0049ee64, 4, &ButtonTrack::FUN_0010c5b0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<ButtonTrack>("time", &ButtonTrack::FUN_0010c5d0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<ButtonTrack>("value", &ButtonTrack::FUN_0010c5f0);
        FUN_002347b0(&DAT_004e0b88, params, 6);
    }
    DAT_004e0b8c++;
}
