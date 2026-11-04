// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_0013c460 @ 0x0013c460
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class FrameReachedCondition_13c460 {
public:
    void FUN_001399d0();
    void FUN_001399e0();
};
}
}

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_13c460 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_13c460(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName_13c460 : public ParamNameBase {
public:
    ParamName_13c460(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0013c460()
{
    if (DAT_004e0f0c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamName_13c460<hulkfight::motion::FrameReachedCondition_13c460>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamName_13c460<hulkfight::motion::FrameReachedCondition_13c460>("animation", &hulkfight::motion::FrameReachedCondition_13c460::FUN_001399d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13c460<hulkfight::motion::FrameReachedCondition_13c460>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_13c460<hulkfight::motion::FrameReachedCondition_13c460>("frame", &hulkfight::motion::FrameReachedCondition_13c460::FUN_001399e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f08), params, 2);
    }
    DAT_004e0f0c++;
}
