// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 22/22)
// FUN_001876f0 @ 0x001876f0
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight { namespace motion {
class SmartPropGrabbableCondition_1876f0 {
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
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
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
class ParamBool_1876f0 : public ParamBoolBase {
public:
    ParamBool_1876f0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList_1876f0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_1876f0(const char* name, const char** n, int c, void (T::*s)())
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

extern "C" void FUN_001876f0()
{
    if (DAT_004e140c == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>("matchObjectClass", &hulkfight::motion::SmartPropGrabbableCondition_1876f0::FUN_0017f2f0);
        mem = FUN_0008d690(0x20);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>("objectClass", ((const char**)&DAT_004c5fd0), 23, &hulkfight::motion::SmartPropGrabbableCondition_1876f0::FUN_0017f310);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamBool_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>("matchCargo", &hulkfight::motion::SmartPropGrabbableCondition_1876f0::FUN_0017f330);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamBool_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>("isCargo", &hulkfight::motion::SmartPropGrabbableCondition_1876f0::FUN_0017f350);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamBool_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>("matchWeaponType", &hulkfight::motion::SmartPropGrabbableCondition_1876f0::FUN_0017f370);
        mem = FUN_0008d690(0x20);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamEnumConstList_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>("weaponType", ((const char**)&DAT_004c6028), 7, &hulkfight::motion::SmartPropGrabbableCondition_1876f0::FUN_0017f390);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamBool_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>("matchWeaponizableType", &hulkfight::motion::SmartPropGrabbableCondition_1876f0::FUN_0017f3b0);
        mem = FUN_0008d690(0x20);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamEnumConstList_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>("weaponizableType", ((const char**)&DAT_004c6028), 7, &hulkfight::motion::SmartPropGrabbableCondition_1876f0::FUN_0017f3d0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>("matchHasEvent", &hulkfight::motion::SmartPropGrabbableCondition_1876f0::FUN_0017f3f0);
        mem = FUN_0008d690(0x20);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamEnumConstList_1876f0<hulkfight::motion::SmartPropGrabbableCondition_1876f0>("event", ((const char**)&DAT_00496168), 16, &hulkfight::motion::SmartPropGrabbableCondition_1876f0::FUN_0017f410);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1408), params, 10);
    }
    DAT_004e140c++;
}
