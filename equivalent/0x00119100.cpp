// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 20/20)
// FUN_00119100 @ 0x00119100
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class HasGroundPointExtendedCondition {
public:
    void FUN_00114fb0();
    void FUN_00114fd0();
    void FUN_00114fe0();
    void FUN_00115000();
    void FUN_00115020();
    void FUN_00115040();
    void FUN_00115060();
    void FUN_00115080();
    void FUN_001150b0();
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

class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
template <class T>
class ParamVector : public ParamVectorBase {
public:
    ParamVector(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00119100()
{
    if (DAT_004e0c40 == 0) {
        void* params[9];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamBool<HasGroundPointExtendedCondition>("groundPoint", &HasGroundPointExtendedCondition::FUN_00114fb0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamBool<HasGroundPointExtendedCondition>("useMyVelocity", &HasGroundPointExtendedCondition::FUN_00114fd0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamBool<HasGroundPointExtendedCondition>("useMyFacing", &HasGroundPointExtendedCondition::FUN_00114fe0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamBool<HasGroundPointExtendedCondition>("target", &HasGroundPointExtendedCondition::FUN_00115000);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<HasGroundPointExtendedCondition>("useCustomOffset", &HasGroundPointExtendedCondition::FUN_00115020);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamBool<HasGroundPointExtendedCondition>("absolute", &HasGroundPointExtendedCondition::FUN_00115040);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<HasGroundPointExtendedCondition>("distance", &HasGroundPointExtendedCondition::FUN_00115060);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<HasGroundPointExtendedCondition>("allowedHeight", &HasGroundPointExtendedCondition::FUN_00115080);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) ParamVector<HasGroundPointExtendedCondition>("customOffset", &HasGroundPointExtendedCondition::FUN_001150b0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0c3c), params, 9);
    }
    DAT_004e0c40++;
}
