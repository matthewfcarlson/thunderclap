// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_00131560 @ 0x00131560
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
class DebugPrintCondition {
public:
    void FUN_0012e5c0();
    void FUN_0012e620();
};
}

class __declspec(novtable) ParamStringBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002349e0(const char* name);
    ParamStringBase(const char* name) { FUN_002349e0(name); }
};
namespace fight {
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

void FUN_00131560()
{
    if (DAT_004e0e68 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamString<hulkfight::DebugPrintCondition>("text", &hulkfight::DebugPrintCondition::FUN_0012e5c0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamString<hulkfight::DebugPrintCondition>("channel", &hulkfight::DebugPrintCondition::FUN_0012e620);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0e64), params, 2);
    }
    DAT_004e0e68++;
}
