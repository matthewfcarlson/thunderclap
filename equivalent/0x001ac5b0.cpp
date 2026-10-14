// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_001ac5b0 @ 0x001ac5b0
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace scenario {
class Event_PathNameCondition {
public:
    void FUN_001aada0();
    void FUN_001aadb0();
};
}
}

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
};
namespace fight {
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
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern ParamRegistry DAT_004e17b0;
extern int DAT_004e17b4;

extern const char* DAT_00427758[1];

extern int DAT_00427760;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001ac5b0()
{
    if (DAT_004e17b4 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x20);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<hulkfight::scenario::Event_PathNameCondition>("compare", DAT_00427758, DAT_00427760, &hulkfight::scenario::Event_PathNameCondition::FUN_001aada0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamName<hulkfight::scenario::Event_PathNameCondition>("pathName", &hulkfight::scenario::Event_PathNameCondition::FUN_001aadb0);
        FUN_002347b0(&DAT_004e17b0, params, 2);
    }
    DAT_004e17b4++;
}
