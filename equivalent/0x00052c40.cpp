// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_00052c40 @ 0x00052c40
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CAxisValueCondition {
public:
    void FUN_00047b00();
    void FUN_00047b10();
    void FUN_00047b20();
    void FUN_00047b50();
    void FUN_00047b60();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
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
}

struct ParamRegistry {
};
extern ParamRegistry DAT_004dc420;
extern int DAT_004dc424;
extern const char* DAT_0042773c[6];
extern int DAT_00427754;
extern const char* DAT_0049ee74[2];
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00052c40()
{
    if (DAT_004dc424 == 0) {
        void* params[5];
        void* mem;
        mem = FUN_0008d690(0x20);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<CAxisValueCondition>("axis", DAT_0049ee74, 2, &CAxisValueCondition::FUN_00047b00);
        mem = FUN_0008d690(0x20);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList<CAxisValueCondition>("compareTime", DAT_0042773c, DAT_00427754, &CAxisValueCondition::FUN_00047b10);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<CAxisValueCondition>("time", &CAxisValueCondition::FUN_00047b20);
        mem = FUN_0008d690(0x20);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamEnumConstList<CAxisValueCondition>("compareValue", DAT_0042773c, DAT_00427754, &CAxisValueCondition::FUN_00047b50);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<CAxisValueCondition>("value", &CAxisValueCondition::FUN_00047b60);
        FUN_002347b0(&DAT_004dc420, params, 5);
    }
    DAT_004dc424++;
}
