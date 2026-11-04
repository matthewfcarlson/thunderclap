// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_000535f0 @ 0x000535f0
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CCollisionPushbackVelocityCondition_535f0 {
public:
    void FUN_00047d70();
    void FUN_00047d80();
};

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
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamEnumConstList_535f0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_535f0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamFloatConstRange_535f0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_535f0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};



void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_000535f0()
{
    if (DAT_004dc484 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_535f0<::CCollisionPushbackVelocityCondition_535f0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_535f0<::CCollisionPushbackVelocityCondition_535f0>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &::CCollisionPushbackVelocityCondition_535f0::FUN_00047d70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_535f0<::CCollisionPushbackVelocityCondition_535f0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_535f0<::CCollisionPushbackVelocityCondition_535f0>("velocity", &::CCollisionPushbackVelocityCondition_535f0::FUN_00047d80);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc480), params, 2);
    }
    DAT_004dc484++;
}
