// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 6/6)
// FUN_00145b00 @ 0x00145b00
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class MotionTrailStopTrack_145b00 {
public:
    void FUN_001436c0();
    void FUN_001436e0();
};
}
}

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_145b00 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_145b00(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_145b00 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_145b00(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00145b00()
{
    if (DAT_004e0fac == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_145b00<hulkfight::motion::MotionTrailStopTrack_145b00>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_145b00<hulkfight::motion::MotionTrailStopTrack_145b00>("timeBegin", &hulkfight::motion::MotionTrailStopTrack_145b00::FUN_001436c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_145b00<hulkfight::motion::MotionTrailStopTrack_145b00>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamIntConstRange_145b00<hulkfight::motion::MotionTrailStopTrack_145b00>("slot", &hulkfight::motion::MotionTrailStopTrack_145b00::FUN_001436e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0fa8), params, 2);
    }
    DAT_004e0fac++;
}
