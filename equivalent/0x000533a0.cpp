// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_000533a0 @ 0x000533a0
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CCollisionDirectionCondition_533a0 {
public:
    void FUN_00047ca0();
    void FUN_00047cc0();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_533a0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_533a0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_000533a0()
{
    if (DAT_004dc45c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_533a0<::CCollisionDirectionCondition_533a0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_533a0<::CCollisionDirectionCondition_533a0>("direction", &::CCollisionDirectionCondition_533a0::FUN_00047ca0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_533a0<::CCollisionDirectionCondition_533a0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_533a0<::CCollisionDirectionCondition_533a0>("arc", &::CCollisionDirectionCondition_533a0::FUN_00047cc0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc458), params, 2);
    }
    DAT_004dc45c++;
}
