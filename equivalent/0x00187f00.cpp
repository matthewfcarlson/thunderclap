// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_00187f00 @ 0x00187f00
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class PropActorThinkingTrack_187f00 {
public:
    void FUN_0017f760();
    void FUN_0017f780();
};
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamBool_187f00 : public ParamBoolBase {
public:
    ParamBool_187f00(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamFloatConstRange_187f00 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_187f00(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00187f00()
{
    if (DAT_004e147c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_187f00<hulkfight::motion::PropActorThinkingTrack_187f00>("timeBegin", &hulkfight::motion::PropActorThinkingTrack_187f00::FUN_0017f760);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBool_187f00<hulkfight::motion::PropActorThinkingTrack_187f00>("thinking", &hulkfight::motion::PropActorThinkingTrack_187f00::FUN_0017f780);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1478), params, 2);
    }
    DAT_004e147c++;
}
