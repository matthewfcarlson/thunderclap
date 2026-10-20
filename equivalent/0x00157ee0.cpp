// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 6/6)
// FUN_00157ee0 @ 0x00157ee0
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
namespace motion {
class CollisionThrownObjectCondition {
public:
    void FUN_0014c5e0();
    void FUN_0014c5f0();
};
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
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
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
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

void FUN_00157ee0()
{
    if (DAT_004e108c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool<hulkfight::motion::CollisionThrownObjectCondition>("thrownObject", &hulkfight::motion::CollisionThrownObjectCondition::FUN_0014c5e0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamName<hulkfight::motion::CollisionThrownObjectCondition>("name", &hulkfight::motion::CollisionThrownObjectCondition::FUN_0014c5f0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1088), params, 2);
    }
    DAT_004e108c++;
}
