// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_00187d40 @ 0x00187d40
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
namespace motion {
class SmartPropIsCargoCondition {
public:
    void FUN_0017f690();
};
}
}

class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
namespace fight {
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00187d40()
{
    if (DAT_004e145c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamIntConstRange<hulkfight::motion::SmartPropIsCargoCondition>("attachmentIndex", &hulkfight::motion::SmartPropIsCargoCondition::FUN_0017f690);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1458), params, 1);
    }
    DAT_004e145c++;
}
