// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_0010bc00 @ 0x0010bc00
#include "decls/data/game/hulkfight/ai.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class FaceTargetTrack_10bc00 {
public:
    void FUN_0010b3d0();
    void FUN_0010b3e0();
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
class ParamFloatConstRange_10bc00 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_10bc00(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0010bc00()
{
    if (DAT_004e0ad4 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_10bc00<hulkfight::ai::FaceTargetTrack_10bc00>("timeBegin", &hulkfight::ai::FaceTargetTrack_10bc00::FUN_0010b3d0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_10bc00<hulkfight::ai::FaceTargetTrack_10bc00>("timeEnd", &hulkfight::ai::FaceTargetTrack_10bc00::FUN_0010b3e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ad0), params, 2);
    }
    DAT_004e0ad4++;
}
