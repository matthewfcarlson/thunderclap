// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_0010bca0 @ 0x0010bca0
#include "decls/data/game/hulkfight/ai.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class FaceMotionTrack_10bca0 {
public:
    void FUN_0010b3f0();
    void FUN_0010b400();
};
}
}

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_10bca0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_10bca0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0010bca0()
{
    if (DAT_004e0adc == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_10bca0<hulkfight::ai::FaceMotionTrack_10bca0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_10bca0<hulkfight::ai::FaceMotionTrack_10bca0>("timeBegin", &hulkfight::ai::FaceMotionTrack_10bca0::FUN_0010b3f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_10bca0<hulkfight::ai::FaceMotionTrack_10bca0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_10bca0<hulkfight::ai::FaceMotionTrack_10bca0>("timeEnd", &hulkfight::ai::FaceMotionTrack_10bca0::FUN_0010b400);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ad8), params, 2);
    }
    DAT_004e0adc++;
}
