// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_001581b0 @ 0x001581b0
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
namespace motion {
class CollisionSourceNameCondition {
public:
    void FUN_0014c740();
    void FUN_0014c750();
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



void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001581b0()
{
    if (DAT_004e10cc == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x20);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<hulkfight::motion::CollisionSourceNameCondition>("compare", ((const char**)&DAT_00427758), (*(int*)&DAT_00427760), &hulkfight::motion::CollisionSourceNameCondition::FUN_0014c740);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamName<hulkfight::motion::CollisionSourceNameCondition>("name", &hulkfight::motion::CollisionSourceNameCondition::FUN_0014c750);
        FUN_002347b0(((ParamRegistry*)&DAT_004e10c8), params, 2);
    }
    DAT_004e10cc++;
}
