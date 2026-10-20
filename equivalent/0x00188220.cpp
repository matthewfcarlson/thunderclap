// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 18/18)
// FUN_00188220 @ 0x00188220
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class BallAndChainSpinTrack {
public:
    void FUN_001801c0();
    void FUN_001801d0();
    void FUN_001801f0();
    void FUN_00180210();
    void FUN_00180230();
    void FUN_00180250();
    void FUN_00180280();
    void FUN_001802c0();
};
}
}

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
template <class T>
class ParamVector : public ParamVectorBase {
public:
    ParamVector(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00188220()
{
    if (DAT_004e14bc == 0) {
        void* params[8];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack>("timeBegin", &hulkfight::motion::BallAndChainSpinTrack::FUN_001801c0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack>("timeEnd", &hulkfight::motion::BallAndChainSpinTrack::FUN_001801d0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamIntConstRange<hulkfight::motion::BallAndChainSpinTrack>("attachmentIndex", &hulkfight::motion::BallAndChainSpinTrack::FUN_001801f0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack>("radius", &hulkfight::motion::BallAndChainSpinTrack::FUN_00180210);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack>("height", &hulkfight::motion::BallAndChainSpinTrack::FUN_00180230);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack>("startAngle", &hulkfight::motion::BallAndChainSpinTrack::FUN_00180250);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack>("spinVelocity", &hulkfight::motion::BallAndChainSpinTrack::FUN_00180280);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamVector<hulkfight::motion::BallAndChainSpinTrack>("orient", &hulkfight::motion::BallAndChainSpinTrack::FUN_001802c0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e14b8), params, 8);
    }
    DAT_004e14bc++;
}
