// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 6/6)
// FUN_00054800 @ 0x00054800
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CClimbEdgeCondition_54800 {
public:
    void FUN_000481e0();
    void FUN_000481f0();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
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
class ParamBool_54800 : public ParamBoolBase {
public:
    ParamBool_54800(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList_54800 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_54800(const char* name, const char** n, int c, void (T::*s)())
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


void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00054800()
{
    if (DAT_004dc57c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_54800<::CClimbEdgeCondition_54800>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_54800<::CClimbEdgeCondition_54800>("edge", ((const char**)&DAT_0048f9fc), 6, &::CClimbEdgeCondition_54800::FUN_000481e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_54800<::CClimbEdgeCondition_54800>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBool_54800<::CClimbEdgeCondition_54800>("checkCorner", &::CClimbEdgeCondition_54800::FUN_000481f0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc578), params, 2);
    }
    DAT_004dc57c++;
}
