// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_0014a1e0 @ 0x0014a1e0
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class GrappleAttachedCondition_14a1e0 {
public:
    void FUN_00146920();
};
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
namespace fight {
template <class T>
class ParamBool_14a1e0 : public ParamBoolBase {
public:
    ParamBool_14a1e0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0014a1e0()
{
    if (DAT_004e0fc8 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_14a1e0<hulkfight::motion::GrappleAttachedCondition_14a1e0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_14a1e0<hulkfight::motion::GrappleAttachedCondition_14a1e0>("isAttached", &hulkfight::motion::GrappleAttachedCondition_14a1e0::FUN_00146920);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0fc4), params, 1);
    }
    DAT_004e0fc8++;
}
