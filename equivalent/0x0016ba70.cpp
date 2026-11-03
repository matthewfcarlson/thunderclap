// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_0016ba70 @ 0x0016ba70
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class InLoadedRoomCondition_16ba70 {
public:
    void FUN_001658d0();
};
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
namespace fight {
template <class T>
class ParamBool_16ba70 : public ParamBoolBase {
public:
    ParamBool_16ba70(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0016ba70()
{
    if (DAT_004e1284 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_16ba70<hulkfight::motion::InLoadedRoomCondition_16ba70>("isInLoadedRoom", &hulkfight::motion::InLoadedRoomCondition_16ba70::FUN_001658d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1280), params, 1);
    }
    DAT_004e1284++;
}
