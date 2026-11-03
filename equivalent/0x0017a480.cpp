// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_0017a480 @ 0x0017a480
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class TeleportTrack_17a480 {
public:
    void FUN_0016f360();
    void FUN_0016f390();
};
}
}

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_17a480 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17a480(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamVector_17a480 : public ParamVectorBase {
public:
    ParamVector_17a480(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0017a480()
{
    if (DAT_004e1364 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_17a480<hulkfight::motion::TeleportTrack_17a480>("timeBegin", &hulkfight::motion::TeleportTrack_17a480::FUN_0016f360);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamVector_17a480<hulkfight::motion::TeleportTrack_17a480>("vector", &hulkfight::motion::TeleportTrack_17a480::FUN_0016f390);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1360), params, 2);
    }
    DAT_004e1364++;
}
