// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 4/4)
// FUN_00054300 @ 0x00054300
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CRageModeCondition_54300 {
public:
    void FUN_00048100();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
namespace fight {
template <class T>
class ParamBool_54300 : public ParamBoolBase {
public:
    ParamBool_54300(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00054300()
{
    if (DAT_004dc544 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_54300<::CRageModeCondition_54300>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_54300<::CRageModeCondition_54300>("rageModeOn", &::CRageModeCondition_54300::FUN_00048100);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc540), params, 1);
    }
    DAT_004dc544++;
}
