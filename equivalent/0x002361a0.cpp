// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 6/6)
// FUN_002361a0 @ 0x002361a0
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace fight {
class FightNodeCondition {
public:
    void FUN_00235950();
    void FUN_00235960();
};
}

class __declspec(novtable) ParamBranchBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00235170(const char* name);
    ParamBranchBase(const char* name) { FUN_00235170(name); }
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
class ParamBranch : public ParamBranchBase {
public:
    ParamBranch(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
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
extern ParamRegistry DAT_004e5bdc;
extern int DAT_004e5be0;

extern const char* DAT_00427758[1];

extern int DAT_00427760;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_002361a0()
{
    if (DAT_004e5be0 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x20);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<fight::FightNodeCondition>("compare", DAT_00427758, DAT_00427760, &fight::FightNodeCondition::FUN_00235950);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBranch<fight::FightNodeCondition>("fightNode", &fight::FightNodeCondition::FUN_00235960);
        FUN_002347b0(&DAT_004e5bdc, params, 2);
    }
    DAT_004e5be0++;
}
