// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_00111f50 @ 0x00111f50
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
namespace ai {
class HulkActionRecentCondition {
public:
    void FUN_0010c1d0();
    void FUN_0010cb00();
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
class __declspec(novtable) ParamStringBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002349e0(const char* name);
    ParamStringBase(const char* name) { FUN_002349e0(name); }
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
class ParamString : public ParamStringBase {
public:
    ParamString(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};



void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00111f50()
{
    if (DAT_004e0b14 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x20);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<hulkfight::ai::HulkActionRecentCondition>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::ai::HulkActionRecentCondition::FUN_0010c1d0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamString<hulkfight::ai::HulkActionRecentCondition>("text", &hulkfight::ai::HulkActionRecentCondition::FUN_0010cb00);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0b10), params, 2);
    }
    DAT_004e0b14++;
}
