// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 6/6)
// FUN_00056830 @ 0x00056830
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CSmartPropGrabbableNameCondition {
public:
    void FUN_00047f30();
    void FUN_00047f40();
};

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



void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00056830()
{
    if (DAT_004dc4dc == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x20);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<::CSmartPropGrabbableNameCondition>("compare", ((const char**)&DAT_00427758), (*(int*)&DAT_00427760), &::CSmartPropGrabbableNameCondition::FUN_00047f30);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamName<::CSmartPropGrabbableNameCondition>("name", &::CSmartPropGrabbableNameCondition::FUN_00047f40);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc4d8), params, 2);
    }
    DAT_004dc4dc++;
}
