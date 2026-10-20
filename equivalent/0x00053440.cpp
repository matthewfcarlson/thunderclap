// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_00053440 @ 0x00053440
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class CCollisionPushbackDirectionCondition {
public:
    void FUN_00047ce0();
    void FUN_00047d00();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
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
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00053440()
{
    if (DAT_004dc464 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<::CCollisionPushbackDirectionCondition>("direction", &::CCollisionPushbackDirectionCondition::FUN_00047ce0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<::CCollisionPushbackDirectionCondition>("arc", &::CCollisionPushbackDirectionCondition::FUN_00047d00);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc460), params, 2);
    }
    DAT_004dc464++;
}
