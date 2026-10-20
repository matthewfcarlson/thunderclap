// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 22/22)
// FUN_001876f0 @ 0x001876f0
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight { namespace motion {
class SmartPropGrabbableCondition {
public:
    void FUN_0017f2f0();
    void FUN_0017f310();
    void FUN_0017f330();
    void FUN_0017f350();
    void FUN_0017f370();
    void FUN_0017f390();
    void FUN_0017f3b0();
    void FUN_0017f3d0();
    void FUN_0017f3f0();
    void FUN_0017f410();
};
}}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
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
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
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
}

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001876f0()
{
    if (DAT_004e140c == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool<hulkfight::motion::SmartPropGrabbableCondition>("matchObjectClass", &hulkfight::motion::SmartPropGrabbableCondition::FUN_0017f2f0);
        mem = FUN_0008d690(0x20);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList<hulkfight::motion::SmartPropGrabbableCondition>("objectClass", ((const char**)&DAT_004c5fd0), 23, &hulkfight::motion::SmartPropGrabbableCondition::FUN_0017f310);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamBool<hulkfight::motion::SmartPropGrabbableCondition>("matchCargo", &hulkfight::motion::SmartPropGrabbableCondition::FUN_0017f330);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamBool<hulkfight::motion::SmartPropGrabbableCondition>("isCargo", &hulkfight::motion::SmartPropGrabbableCondition::FUN_0017f350);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamBool<hulkfight::motion::SmartPropGrabbableCondition>("matchWeaponType", &hulkfight::motion::SmartPropGrabbableCondition::FUN_0017f370);
        mem = FUN_0008d690(0x20);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamEnumConstList<hulkfight::motion::SmartPropGrabbableCondition>("weaponType", ((const char**)&DAT_004c6028), 7, &hulkfight::motion::SmartPropGrabbableCondition::FUN_0017f390);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamBool<hulkfight::motion::SmartPropGrabbableCondition>("matchWeaponizableType", &hulkfight::motion::SmartPropGrabbableCondition::FUN_0017f3b0);
        mem = FUN_0008d690(0x20);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamEnumConstList<hulkfight::motion::SmartPropGrabbableCondition>("weaponizableType", ((const char**)&DAT_004c6028), 7, &hulkfight::motion::SmartPropGrabbableCondition::FUN_0017f3d0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool<hulkfight::motion::SmartPropGrabbableCondition>("matchHasEvent", &hulkfight::motion::SmartPropGrabbableCondition::FUN_0017f3f0);
        mem = FUN_0008d690(0x20);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamEnumConstList<hulkfight::motion::SmartPropGrabbableCondition>("event", ((const char**)&DAT_00496168), 16, &hulkfight::motion::SmartPropGrabbableCondition::FUN_0017f410);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1408), params, 10);
    }
    DAT_004e140c++;
}
