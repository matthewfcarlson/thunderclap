// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 6/6)
// FUN_00157ee0 @ 0x00157ee0
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class CollisionThrownObjectCondition_157ee0 {
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
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
namespace fight {
template <class T>
class ParamBool_157ee0 : public ParamBoolBase {
public:
    ParamBool_157ee0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName_157ee0 : public ParamNameBase {
public:
    ParamName_157ee0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00157ee0()
{
    if (DAT_004e108c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_157ee0<hulkfight::motion::CollisionThrownObjectCondition_157ee0>("thrownObject", &hulkfight::motion::CollisionThrownObjectCondition_157ee0::FUN_0014c5e0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamName_157ee0<hulkfight::motion::CollisionThrownObjectCondition_157ee0>("name", &hulkfight::motion::CollisionThrownObjectCondition_157ee0::FUN_0014c5f0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1088), params, 2);
    }
    DAT_004e108c++;
}
