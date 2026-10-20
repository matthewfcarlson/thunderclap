// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_00141ae0 @ 0x00141ae0
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
namespace motion {
class WallVelocityCondition {
public:
    void FUN_0013e810();
    void FUN_0013e820();
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
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
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

void FUN_00141ae0()
{
    if (DAT_004e0f44 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x20);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<hulkfight::motion::WallVelocityCondition>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::motion::WallVelocityCondition::FUN_0013e810);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallVelocityCondition>("velocity", &hulkfight::motion::WallVelocityCondition::FUN_0013e820);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f40), params, 2);
    }
    DAT_004e0f44++;
}
