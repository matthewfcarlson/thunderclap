// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 12/12)
// FUN_001288e0 @ 0x001288e0
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class TargetDistanceYCondition {
public:
    void FUN_001236d0();
    void FUN_001236e0();
    void FUN_001236f0();
    void FUN_00123710();
    void FUN_00123730();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
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

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001288e0()
{
    if (DAT_004e0d98 == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690(0x20);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamEnumConstList<TargetDistanceYCondition>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &TargetDistanceYCondition::FUN_001236d0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<TargetDistanceYCondition>("distance", &TargetDistanceYCondition::FUN_001236e0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamBool<TargetDistanceYCondition>("absoluteValue", &TargetDistanceYCondition::FUN_001236f0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamBool<TargetDistanceYCondition>("useHulk", &TargetDistanceYCondition::FUN_00123710);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<TargetDistanceYCondition>("useGroundPoint", &TargetDistanceYCondition::FUN_00123730);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0d94), params, 5);
    }
    DAT_004e0d98++;
}
