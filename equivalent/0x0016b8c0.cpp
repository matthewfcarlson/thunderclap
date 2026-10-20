// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_0016b8c0 @ 0x0016b8c0
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
namespace motion {
class TargetCharacterTemplateCondition {
public:
    void FUN_00166230();
};
}
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

void FUN_0016b8c0()
{
    if (DAT_004e1264 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamString<hulkfight::motion::TargetCharacterTemplateCondition>("text", &hulkfight::motion::TargetCharacterTemplateCondition::FUN_00166230);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1260), params, 1);
    }
    DAT_004e1264++;
}
