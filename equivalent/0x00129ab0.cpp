// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 14/14)
// FUN_00129ab0 @ 0x00129ab0
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

class TargetArcCondition {
public:
    void FUN_00123530();
    void FUN_00123550();
    void FUN_00123580();
    void FUN_00123590();
    void FUN_001235c0();
    void FUN_001235f0();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
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
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
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
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00129ab0()
{
    if (DAT_004e0d70 == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<TargetArcCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<TargetArcCondition>("angle", &TargetArcCondition::FUN_00123530);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<TargetArcCondition>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<TargetArcCondition>("arc", &TargetArcCondition::FUN_00123550);
        mem = FUN_0008d690((int)sizeof(ParamBool<TargetArcCondition>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamBool<TargetArcCondition>("useCameraDirection", &TargetArcCondition::FUN_00123580);
        mem = FUN_0008d690((int)sizeof(ParamName<TargetArcCondition>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamName<TargetArcCondition>("joint", &TargetArcCondition::FUN_00123590);
        mem = FUN_0008d690((int)sizeof(ParamVector<TargetArcCondition>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamVector<TargetArcCondition>("direction", &TargetArcCondition::FUN_001235c0);
        mem = FUN_0008d690((int)sizeof(ParamBool<TargetArcCondition>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamBool<TargetArcCondition>("useHulk", &TargetArcCondition::FUN_001235f0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0d6c), params, 6);
    }
    DAT_004e0d70++;
}
